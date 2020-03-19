/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MyWindow
*/

#pragma once
#include <curses.h>
#include <ncurses.h>

class MyWindow 
{
    private:
    public:
        MyWindow(int, int, int, int);
        ~MyWindow();
        WINDOW *window;
        int MyGetch();
        void clear();
};
