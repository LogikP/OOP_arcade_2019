/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** gamecore
*/

#include "GameCore.hpp"
#include "Error.hpp"

std::string GameCore::NewMenu(std::string Lib)
{
    std::string PeakGame;

    this->Display->closeWindow();
    this->Display = this->setNewLib<IDisplay>("IDisplay", Lib);
    std::vector<std::pair<int, std::string>>libs_name = this->SelectLib();
    PeakGame = this->Display->Menu(this->Games_names, libs_name);
    this->Display->initWindow();
    return PeakGame;
}

IGame *GameCore::NewGameMenu()
{
    std::string PeakGame;
    std::string path;
    std::vector<std::pair<int, std::string>>libs_name = this->SelectLib();
    if (this->libToDisplay["IGame"])
        dlclose(this->libToDisplay["IGame"]);
    PeakGame = this->Display->Menu(this->Games_names, libs_name);
    while (PeakGame == "ChangedLib")
        PeakGame = this->NewMenuLib();
    path = "./games/lib_arcade_" + PeakGame + ".so";
    this->libToDisplay["IGame"] = dlopen(path.c_str(), RTLD_NOW);
//    std::cout << path.c_str() << std::endl;
    if (!this->libToDisplay["IGame"])
        throw(Error("Can't open the New Library"));
    return createObject<IGame>(this->libToDisplay["IGame"]);
}

void GameCore::Kill(std::vector<std::string> score)
{
    this->GetHightScore(score);
}


bool GameCore::play()
{
    //char *error;
    // for(auto elem : Libs)
    // {
    //     std::cout << elem.first << " " << elem.second << std::endl;
    // }

    this->Display = createObject<IDisplay>(this->libToDisplay["IDisplay"]);
    std::vector<std::pair<int, std::string>>libs_name = this->SelectLib();
    std::string PeakGame = this->Display->Menu(this->Games_names, libs_name);
    while ((isGame(PeakGame, this->Games_names) == 0 && PeakGame != "kill") || PeakGame == "ChangedLib") {
        this->Libs["IDisplay"] = PeakGame == "ChangedLib" ? this->Libs["IDisplay"] : PeakGame;
        PeakGame = PeakGame == "ChangedLib" ? NewMenuLib() : NewMenu(PeakGame);
    }
    if (PeakGame == "kill")
        return false;
    this->Libs["IGame"] = PeakGame;
    std::string tmp = madeFormatLib(PeakGame, "games");
    this->libToDisplay["IGame"] = dlopen(tmp.c_str(), RTLD_NOW);
    this->Game = createObject<IGame>(this->libToDisplay["IGame"]);
    this->Display->initWindow();
    while (42)
    {
        std::vector<std::string> map = this->Game->getMap();
        std::vector<std::string> score = this->Game->getScore();
        this->Display->InitProg(map, score);
        this->keyCore = this->Display->getEvent();
        if (this->keyCore == 'k') {
            this->Kill(score);
            return false;
        }
        if (this->keyCore == 'p') {
            int key = 0;
            while (key == 0)
                key = this->Display->Pause();
            if (key == 'k') {
                this->Kill(score);
                return false;
            }
        }
        if (this->keyCore == 'l') {
            /////menuLib
            std::string PeakLib = this->NewMenuLib();
            // if (PeakLib == "Kill")
            //     return false;
        }
        if (this->keyCore == 'm') {
            /////menu
            this->Game = this->NewGameMenu();
            //std::vector<std::pair<int, std::string>> libs_name;
            //this->Display->Menu(this->Games_names, libs_name);
        }
        this->Game->ReceiveEvent(this->keyCore, 0);
    }
    return true;
}

GameCore::GameCore(std::string libPath)
{
    this->libToDisplay["IDisplay"] = dlopen(libPath.c_str(), RTLD_NOW);
    if (!this->libToDisplay["IDisplay"])
        throw(Error(dlerror()));
    dlerror();
    this->Libs["IDisplay"] = getNameFromLibrary(libPath);
    this->Libs_names = GetLibName();
    this->Games_names = GetGameName();
}

GameCore::~GameCore()
{
}