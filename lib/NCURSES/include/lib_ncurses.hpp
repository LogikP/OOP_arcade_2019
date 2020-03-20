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

class LibNcurses : public IDisplay
{
    private:
        MyWindow window;
        WINDOW *_pacman;
        WINDOW *_nibbler;
    public:
        LibNcurses();
        void initWindow() final;
        void closeWindow() final;
        int InitProg() final;
        std::string Menu(std::vector<std::pair<int, std::string>>) final;
        std::string Game() final;
        void display_title();
        void display_help();
        void display_game();
};