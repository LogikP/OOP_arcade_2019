/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_ncurses
*/

#include <string>
#include <iostream>
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


std::string LibNcurses::Menu(std::vector<std::pair<int, std::string>> games, std::vector<std::pair<int, std::string>> libs)
{
    MyWindow ObjectWindow(0,0,0,0);

    this->window =  ObjectWindow;
    keypad(this->window.window, TRUE);
    noecho();
    refresh();
    int choice;
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
            case 10:
                wclear(window.window);
                wrefresh(window.window);
                return (games[highlight].second);
                break;
            case 'n':
            case 'N':
                wclear(game);
                wrefresh(game);
                wclear(window.window);
                wrefresh(window.window);
                return (libs[0].second);
            case 'l':
            case 'L':
                wclear(game);
                wrefresh(game);
                wclear(window.window);
                wrefresh(window.window);
                return "ChangedLib";
            case 'p':
            case 'P':
                wclear(game);
                wrefresh(game);
                wclear(window.window);
                wrefresh(window.window);
                return (libs[libs.size() - 1].second);
        }
        refresh();
     }
    this->window.clear();
    endwin();
    return ("kill");
}

std::string LibNcurses::MenuLib(std::vector<std::pair<int, std::string>> libs)
{
    MyWindow ObjectWindow(0,0,0,0);

    this->window =  ObjectWindow;
    keypad(this->window.window, TRUE);
    noecho();
    refresh();
    int choice;
    unsigned int highlight = 0;


    while (choice != 'q') {
        display_title();
        display_help();
        display_libs();
        for (unsigned int i = 0; i != libs.size(); i+= 1) {
            if (i == highlight) {
                wattron(window.window,A_REVERSE);
                wattron(window.window, COLOR_PAIR(3));
            }
            mvwprintw(window.window, i+30, 133, libs[i].second.c_str());
            wattroff(window.window, A_REVERSE);
            wattroff(window.window, COLOR_PAIR(3));
        }
        choice = wgetch(this->window.window);
        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight <= libs.size() - libs.size() - 1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight >= libs.size())
                    highlight--;
                break;
            case 10:
                wclear(window.window);
                wrefresh(window.window);
                return (libs[highlight].second);
                break;
        }
        refresh();
     }
    this->window.clear();
    endwin();
    return ("kill");
}
extern "C" LibNcurses *createDisplay() 
{
    return new LibNcurses;
}