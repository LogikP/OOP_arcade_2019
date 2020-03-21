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
    stdscr = initscr();
    if (has_colors() == FALSE)
	{	endwin();
		throw("Your terminal does not support color\n");
		exit(1);
	}
    start_color();
    use_default_colors();
    noecho();
    cbreak();
    init_pair(1, COLOR_BLUE, -1);
    init_pair(3, COLOR_GREEN, -1);
    init_pair(2, COLOR_RED, -1);
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
