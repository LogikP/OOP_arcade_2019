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

void LibNcurses::initWindow()
{
}

int LibNcurses::InitProg()
{
    return (0);
}

std::string LibNcurses::Game()
{
    return "toto";
}


std::string LibNcurses::Menu(std::vector<std::pair<int, std::string>> games)
{
    MyWindow ObjectWindow(0,0,0,0);

    this->window =  ObjectWindow;
    keypad(this->window.window, TRUE);
    noecho();
    refresh();
    int choice;
    std::string choices[2] = { "NIBBLER", "PACMAN" };
    unsigned int highlight = 0;

    while (choice != 'q') {
        display_title();
        display_help();
        display_game();
        for (unsigned int i = 0; i != games.size(); i+= 1) {
            if (i == highlight) {
                wattron(window.window,A_REVERSE);
                wattron(window.window, COLOR_PAIR(3));
            }
            mvwprintw(window.window, i+30, 133, games[i].second.c_str());
            wattroff(window.window, A_REVERSE);
            wattroff(window.window, COLOR_PAIR(3));
        }
        choice = wgetch(this->window.window);
        if (choice == 'q')
            break;
        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight <= games.size() - games.size() - 1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight >= games.size())
                    highlight--;
                break;
        }
        refresh();
     }
    this->window.clear();
    endwin();
    exit(0);
}

extern "C" LibNcurses *createDisplay() 
{
    return new LibNcurses;
}