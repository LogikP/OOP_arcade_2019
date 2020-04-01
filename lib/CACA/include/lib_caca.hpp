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
    private:
        enum STATUS {
            RUN,
            QUIT,
            GAME,
            LIB
        };
        MyWindowC window;

        int getNextLib(std::vector<std::pair<int, std::string>>);
        int getPrevLib(std::vector<std::pair<int, std::string>>);
        int checkEventMenu(int, int&, int&, int,  std::vector<std::pair<int, std::string>>);
        int checkEventGame(int);
        int checkEventMenuLib(int, int&, int);
        void displayNameGames(std::string name);

    public:

        libCaca();
        void initWindow() final;
        void closeWindow() final;
        std::string Game() final;
        int getEventCore() final;
        int getEventGame() final;
        void InitProg(std::vector<std::string>) final;
        std::string MenuLib(std::vector<std::pair<int, std::string>>) final;
        std::string Menu(std::vector<std::pair<int, std::string>>, std::vector<std::pair<int, std::string>>);
};