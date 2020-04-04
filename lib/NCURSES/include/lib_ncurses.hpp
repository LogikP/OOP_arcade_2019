/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_ncurses
*/

#pragma once
#include "../../../include/IDisplay.hpp"
#include "ncurses.h"
#include "curses.h"
#include "MyWindow.hpp"

enum BindingTouch
{
    left = 1,
    right = 2,
    up = 3,
    down = 4,
    LEAVE = 'k',
};

class LibNcurses : public IDisplay
{
    private:
        MyWindow window;
        WINDOW *game;
        WINDOW *help;
        //WINDOW *Pause;
        WINDOW *_nibbler;
        std::vector<std::string> _map;
        std::string getNextLibN(std::vector<std::pair<int, std::string>>);
        std::string getPrevLibN(std::vector<std::pair<int, std::string>>);

    public:
        LibNcurses();
        void initWindow() final;
        void closeWindow() final;
        int getEvent() final;
        int Pause() final;
        void InitProg(std::vector<std::string> map, std::vector<std::string> score) final;
        void PrintMap(std::vector<std::string> map);
        void PrintScore(std::vector<std::string> score);
        std::string Menu(std::vector<std::pair<int, std::string>>, std::vector<std::pair<int, std::string>>);
        std::string MenuLib(std::vector<std::pair<int, std::string>>) final;
        std::string Game() final;
        void display_title();
        void display_help();
        void display_libs();
        void display_game();
        void PrintGameName();
};