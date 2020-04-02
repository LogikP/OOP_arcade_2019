/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** gamecore
*/

#include "GameCore.hpp"
#include "Error.hpp"

std::vector<std::pair<int, std::string>> GameCore::SelectLib()
{
    std::size_t i = 0;
    int count = 0;
    std::vector<std::pair<int, std::string>> tmp;

    while (i != this->Libs_names.size())
    {
        if (this->Libs["IDisplay"] == this->Libs_names[i].second)
            i++;
        else {
            tmp.push_back(std::make_pair(count, this->Libs_names[i].second));
            i++;
            count++;
        }
        // tmp[count].first == (int)count;
        // tmp[count].second == this->Libs_names[i].second;
    }
    return tmp;
}

std::string GameCore::NewMenu(std::string Lib)
{
    std::string PeakGame;

    this->Display->closeWindow();
    this->Display = this->setNewLib<IDisplay>("IDisplay", Lib);
    std::vector<std::pair<int, std::string>>libs_name = this->SelectLib();
    PeakGame = this->Display->Menu(this->Games_names, libs_name);
    return PeakGame;
}

std::string GameCore::NewMenuLib()
{
    std::string PeakLib;
    std::string PeakGame;
    std::vector<std::pair<int, std::string>>libs_name = this->SelectLib();

    PeakLib = this->Display->MenuLib(libs_name);
    // for(auto elem : this->Libs)
    // {
    //     std::cout << elem.first << " " << elem.second << std::endl;
    // }
    if (PeakLib != "Kill") {
        this->Libs["IDisplay"] = PeakLib;
        PeakGame = NewMenu(PeakLib);
        return PeakGame;
    }
    else
        return "Kill";
}

std::string GameCore::madeFormatLib(std::string str, std::string repo)
{
    std::string tmp;
    if (repo == "lib") {
        tmp = "./lib/lib_arcade_" + str + ".so";
//        std::cout << tmp << std::endl;
        return tmp;
    }
    else if (repo == "games") {
        tmp = "./games/lib_arcade_" + str + ".so";
//        std::cout << tmp << std::endl;
        return tmp;
    }
    else
        return NULL;
}

int isGame(std::string peakGame, std::vector<std::pair<int, std::string>> names)
{
    for (int i = 0; i < (int)names.size(); i++)
        if (peakGame.compare(names[i].second.c_str()) == 0)
            return 1;
    return 0;
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
//        std::string score = Game->g
        this->Display->InitProg(map, score);
        this->keyCore = this->Display->getEvent();
        this->Game->ReceiveEvent(this->keyCore, 0);
    }
    return true;
}

template<typename T>
T *GameCore::setNewLib(std::string Interface, std::string LibName)
{
    std::string path;

    path = "./lib/lib_arcade_" + LibName + ".so";
    if (this->libToDisplay[Interface])
        dlclose(this->libToDisplay[Interface]);
    this->libToDisplay[Interface] = dlopen(path.c_str(), RTLD_NOW);
//    std::cout << path.c_str() << std::endl;
    if (!this->libToDisplay[Interface])
        throw(Error("Can't open the New Library"));
    return createObject<T>(this->libToDisplay[Interface]);
}

int CheckIfLib(std::string lib_name)
{
    if (lib_name.size() > 3 && lib_name.compare(lib_name.size()-3, 3, ".so") == 0)
        return (1);
    return (0);
}

std::vector<std::pair<int, std::string>> GameCore::GetLibName()
{
    std::vector<std::pair<int, std::string>> vec;
    std::string path = "./lib/";
    std::string name;
    DIR* rep = opendir(path.c_str());
    int i = 1;

    vec.push_back(std::make_pair(0,this->Libs["IDisplay"]));
    if (not rep)
        throw(Error("Error, impossible to open the folder"));
    while (true) {
        struct dirent* ent = readdir(rep);
        if (not ent) break;
        name = ent->d_name;
       name = name.substr(name.find_last_of('_') + 1,
           name.find_last_of('.') - name.find_last_of('_') - 1);
        if (CheckIfLib(ent->d_name) == 1 && name.compare(vec[0].second) != 0) {
            vec.push_back(std::make_pair(i, name));
            i++;
        }
    }
    return (vec);
}

std::vector<std::pair<int, std::string>> GameCore::GetGameName()
{
    std::vector<std::pair<int, std::string>> vec;
    std::string path = "./games/";
    std::string name;
    DIR* rep = opendir(path.c_str());
    int i = 0;

    if (not rep)
        throw(Error("Error, impossible to open the folder"));
    while (true) {
        struct dirent* ent = readdir(rep);
        if (not ent) break;
        name = ent->d_name;
        name = name.substr(name.find_last_of('_') + 1,
           name.find_last_of('.') - name.find_last_of('_') - 1);
        if (CheckIfLib(ent->d_name) == 1) {
            vec.push_back(std::make_pair(i, name));
            i++;
        // if (not ent) break;
        // if (ent->d_name[0] != '.') {
        //     vec.push_back(std::make_pair(i, ent->d_name));
        //     i++;
        // }
        }
    }
    return (vec);
}

std::string GameCore::getNameFromLibrary(std::string str)
{
    std::string tmp;
    tmp = str.substr(str.find_last_of('_') + 1,
    str.find_last_of('.') - str.find_last_of('_') - 1);
    return tmp;
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