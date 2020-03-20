/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** gamecore
*/

#include "GameCore.hpp"
#include "Error.hpp"

bool GameCore::play()
{
    //char *error;
    // for(auto elem : this->libToDisplay)
    // {
    //     std::cout << elem.first << " " << elem.second << std::endl;
    // }

    this->Display = createObject<IDisplay>(this->libToDisplay["IDisplay"]);
    this->Display->initWindow();

    while (42)
    {
        this->Display->InitProg();
//        this->Display->Menu();
    }
    return true;
}

GameCore::GameCore(std::string libPath)
{
    this->libToDisplay["IDisplay"] = dlopen(libPath.c_str(), RTLD_NOW);
    if (!this->libToDisplay["IDisplay"])
        throw(Error(dlerror()));
    dlerror();
    this->Libs["IDisplay"] = libPath.substr(libPath.find_last_of('_') + 1, 
    libPath.find_last_of('.') - libPath.find_last_of('_') - 1);
    this->Libs_names = GetLibName();
    this->Games_names = GetGameName();
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
    if (not rep) {
        std::cout << "Erreur, le dossier n'a pas pu être ouvert." << std::endl;
        exit(EXIT_FAILURE);
    }
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
    DIR* rep = opendir(path.c_str());
    int i = 0;

    if (not rep) {
        std::cout << "Erreur, le dossier n'a pas pu être ouvert." << std::endl;
        exit(EXIT_FAILURE);
    }
    while (true) {
        struct dirent* ent = readdir(rep);
        if (not ent) break;
        if (ent->d_name[0] != '.') {
            vec.push_back(std::make_pair(i, ent->d_name));
            i++;
        }
    }
    return (vec);
}

GameCore::~GameCore()
{
}