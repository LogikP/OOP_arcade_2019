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

typedef IGame *(*createGame)();
typedef IDisplay *(*createDisplay)();

class GameCore {
    private:
        IDisplay *Display;
        IGame *Game;
        std::map<std::string, std::string> Libs;
        std::map<std::string, std::string> games;
        std::map<std::string, void*> libToDisplay;
        std::vector<std::pair<int,std::string>> Libs_names;
        std::vector<std::pair<int,std::string>> Games_names;
        int keyCore = 0;
        int keyGame = 0;

    public:
        GameCore(std::string);
        ~GameCore();
        std::vector<std::pair<int,std::string>> GetLibName();
        std::vector<std::pair<int,std::string>> GetGameName();
        bool play();
        template <typename T>
            void getLib();
        template <typename T>
		    T *createObject(void* library);
        template <typename T>
            void setLibIdx();
        template <typename T>
            T *setNewLib(std::string, std::string);
        std::string NewMenu(std::string Lib);
        std::string NewMenuLib();
        std::vector<std::pair<int, std::string>> SelectLib();
        std::string getNameFromLibrary(std::string);
        std::string madeFormatLib(std::string, std::string);
};