/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_caca
*/

#pragma once
#include "../../../include/IDisplay.hpp"
#include "MyWindowC.hpp"
#include <string.h>

class libCaca : public IDisplay
{
    protected:
        enum STATUS {
            RUN,
            QUIT,
            GAME,
            LIB
        };
        MyWindowC window;

    public:

        libCaca();
        void initWindow() final;
        void closeWindow() final;
        std::string Game() final;
        int InitProg() final;
        std::string MenuLib(std::vector<std::pair<int, std::string>>) final;
        std::string Menu(std::vector<std::pair<int,std::string>>) final;
        int checkEvent(int, int&, int);
        void displayGames(std::string name);
};