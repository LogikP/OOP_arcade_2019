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

class Display : public IDisplay
{
    private:
        MyWindow window;
    public:
        Display();
        void initWindow() final;
        void closeWindow() final;
        std::string Game() final;
        int InitProg() final;
        std::string Menu();

};