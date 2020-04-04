/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibInfo
*/

#include "GameCore.hpp"


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

std::string GameCore::getNameFromLibrary(std::string str)
{
    std::string tmp;
    tmp = str.substr(str.find_last_of('_') + 1,
    str.find_last_of('.') - str.find_last_of('_') - 1);
    return tmp;
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


int CheckIfLib(std::string lib_name)
{
    if (lib_name.size() > 3 && lib_name.compare(lib_name.size()-3, 3, ".so") == 0)
        return (1);
    return (0);
}