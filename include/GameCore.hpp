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
#include <regex>
#include "IGame.hpp"
#include "IDisplay.hpp"
#include "Error.hpp"

class GameCore {
    private:
        IDisplay *Display;
        IGame *Game;
        std::map<std::string, std::string> Libs;
        std::map<std::string, std::string> games;
        std::map<std::string, void*> libToDisplay;
    public:
        GameCore(std::string);
        ~GameCore();
        bool play();
        template <typename T>
            void getLib();
        template <typename T>
		    T *createObject(void* library);
        template <typename T>
            void setLibIdx();
};