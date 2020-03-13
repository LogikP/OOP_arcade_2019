/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** gamecore
*/

#include "GameCore.hpp"
#include "Error.hpp"

bool GameCore::play(int First)
{
    return true;
}

GameCore::GameCore(std::string libPath)
{
    _libArg["IDisplay"] = dlopen(libPath.c_str(), RTLD_NOW);
    if (!_libArg["IDisplay"])
        throw(Error(dlerror()));
    libArg["ADisplay"] = libPath.substr(libPath.find_last_of('_') + 1, 
    libPath.find_last_of('.') - libPath.find_last_of('_') - 1);
    _libArg["IGame"] = NULL;
}

GameCore::~GameCore()
{

}