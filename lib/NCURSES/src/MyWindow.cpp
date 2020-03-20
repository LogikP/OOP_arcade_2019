/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MyWindow
*/

#include <stdlib.h>
#include "MyWindow.hpp"

MyWindow::MyWindow(int lines, int colones, int x , int y)
{
    initscr();
    curs_set(0);
    window = newwin(lines, colones, x, y);
    wrefresh(window);
}

MyWindow::~MyWindow()
{
//    endwin();
}

void MyWindow::clear()
{
    delwin(this->window);
    erase();
}

int MyWindow::MyGetch()
{
    int input;
    timeout(10);
    input = getch();
    return input;
}
