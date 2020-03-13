/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameCore
*/

#pragma once
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <sstream>
#include <unistd.h>
#include <dirent.h>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <cxxabi.h>
#include "IDisplay.hpp"

class GameCore {
    public:
        GameCore(std::string);
        ~GameCore();
        bool play(int First = 0);
        template <typename Obj>
			Obj *createObject(void*);
    private:
        IDisplay *Display;
        std::map<std::string, std::string> libArg;
        std::map<std::string, void*> _libArg;
};