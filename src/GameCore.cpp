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
    while (42)
    {
//        this->Display->initWindow();
    }
    return true;
}

GameCore::GameCore(std::string libPath)
{
    this->libToDisplay["IDisplay"] = dlopen(libPath.c_str(), RTLD_NOW);
    if (!this->libToDisplay["IDisplay"])
        throw(Error(dlerror()));
    dlerror();
    this->Libs["ADisplay"] = libPath.substr(libPath.find_last_of('_') + 1, 
    libPath.find_last_of('.') - libPath.find_last_of('_') - 1);
}

GameCore::~GameCore()
{
}