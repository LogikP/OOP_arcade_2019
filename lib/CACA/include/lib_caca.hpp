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
        enum EventKey {
            UNKNOWN,
            LEFT_KEY,
            RIGHT_KEY,
            UP_KEY,
            DOWN_KEY,
            LEAVE,
        };

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
        int checkEventMenuLib(int, int&, int);
        void displayNameGames(std::string name);
        int getKeyEventGame(int);

    public:

        libCaca();
        void initWindow() final;
        void closeWindow() final;
        std::string Game() final;
        int getEvent() final;
        void InitProg(std::vector<std::string> map, std::vector<std::string> score) final;
        std::string MenuLib(std::vector<std::pair<int, std::string>>) final;
        std::string Menu(std::vector<std::pair<int, std::string>>, std::vector<std::pair<int, std::string>>);
};