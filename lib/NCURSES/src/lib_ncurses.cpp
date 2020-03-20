/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_ncurses
*/

#include "lib_ncurses.hpp"

LibNcurses::LibNcurses() : window(0, 0, 0, 0)
{

}

void LibNcurses::closeWindow()
{
    this->window.clear();
    endwin();
    return;
}
static void usage_help(WINDOW *help)
{
    mvwprintw(help, 1, 5, "DESCRIPTION :\n The goal of this project is...\n\n How doeas it works ?\n\n Firt choose what category you want.\n\n for starting push ENTER and for quit monitor push \"q\"");
}

void LibNcurses::display_help()
{
    WINDOW *help;
    help= subwin(stdscr, LINES / 4 + 18, COLS / 6 + 40, 15, 10);
    usage_help(help);
    box(help, ACS_VLINE, ACS_HLINE);
    wrefresh(help);
}

void LibNcurses::initWindow()
{
    MyWindow ObjectWindow(1000,1000,1000,1000);
    this->window = ObjectWindow;
    noecho();
    keypad(this->window.window, TRUE);
    nodelay(this->window.window, TRUE);
}

int LibNcurses::InitProg()
{
    int Input;
    Input = this->window.MyGetch();
}

std::string LibNcurses::Game()
{
    return "toto";
}


std::string LibNcurses::Menu(std::vector<std::pair<int, std::string>>)
{
    display_title();
    display_help();
}

extern "C" LibNcurses *createDisplay() 
{
    return new LibNcurses;
}