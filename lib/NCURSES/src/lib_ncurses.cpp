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
    wrefresh(window.window);
}

void LibNcurses::PrintScore(std::vector<std::string> score)
{
    char const *ft_line= "  ____   ____ ___  ____  _____ ";
    char const *sd_line= " / ___| / ___/ _ \\|  _ \\| ____|";
    char const *trd_line=" \\___ \\| |  | | | | |_) |  _|  ";
    char const *fth_line="  ___) | |__| |_| |  _ <| |___ ";
    char const *fft_line=" |____/ \\____\\___/|_| \\_\\_____|";
    char const *sx_line= "                               ";

    wattron(window.window,COLOR_PAIR(2));
    mvwprintw(this->window.window, 12, (COLS/2) - (202/2) + 15, ft_line);
    wattroff(window.window, COLOR_PAIR(2));
    wattron(window.window,COLOR_PAIR(1));
    mvwprintw(this->window.window, 13, (COLS/2) - (202/2) + 15, sd_line);
    wattroff(window.window, COLOR_PAIR(1));
    wattron(window.window,COLOR_PAIR(3));
    mvwprintw(this->window.window, 14, (COLS/2) - (202/2) + 15, trd_line);
    wattroff(window.window,COLOR_PAIR(3));
    wattron(window.window,COLOR_PAIR(4));
    mvwprintw(this->window.window, 15, (COLS/2) - (202/2) + 15, fth_line);
    wattroff(window.window,COLOR_PAIR(4));
    wattron(window.window,COLOR_PAIR(2));
    mvwprintw(this->window.window, 16, (COLS/2) - (202/2) + 15, fft_line);
    wattroff(window.window, COLOR_PAIR(2));
    wattron(window.window,COLOR_PAIR(1));
    mvwprintw(this->window.window, 17, (COLS/2) - (202/2) + 15, sx_line);
    wattroff(window.window, COLOR_PAIR(1));
    wattron(window.window,COLOR_PAIR(1));
    mvwprintw(this->window.window, 22, (COLS/2) - (202/2) + 20, "Current Score: ");
    wattroff(window.window,COLOR_PAIR(1));
    wattron(window.window,COLOR_PAIR(3));
    mvwprintw(this->window.window, 22, (COLS/2) - (202/2) + 35, score[0].c_str());
    wattroff(window.window,COLOR_PAIR(3));
    wattron(window.window,COLOR_PAIR(2));
    mvwprintw(this->window.window, 24, (COLS/2) - (202/2) + 20, "High Score: ");
    wattroff(window.window,COLOR_PAIR(2));
    wattron(window.window,COLOR_PAIR(3));
    mvwprintw(this->window.window, 24, (COLS/2) - (202/2) + 35, score[1].c_str());
    wattroff(window.window,COLOR_PAIR(3));
    wrefresh(this->window.window);
}

void LibNcurses::PrintMap(std::vector<std::string> map)
{
    for (unsigned int i = 0; i != map.size(); i++) {
        for (int a = 0; map[i][a] != '\n' && map[i][a]; a++) {
            if (map[i][a] == 'W') {
                wattron(window.window, COLOR_PAIR(2));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(2));
            } else if (map[i][a] == 'o'|| map[i][a] == '0' || map[i][a] == ' ' || map[i][a] == 'x') {
                wattron(window.window, COLOR_PAIR(3));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(3));
            } else if (map[i][a] == 'C') {
                wattron(window.window, COLOR_PAIR(4));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(4));
            } else if (map[i][a] == 'M') {
                wattron(window.window, COLOR_PAIR(1));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(1));
            } else
                mvwaddch(window.window,i, a, map[i][a]);
        }

    }
}

void LibNcurses::InitProg(std::vector<std::string> map, std::vector<std::string> score)
{
    _map = map;
    PrintMap(_map);
    PrintScore(score);
}

int LibNcurses::getEvent()
{
    int choice;

//    while (choice != 'q') {
        wtimeout(window.window, 100);
        choice = wgetch(this->window.window);
        switch (choice) {
            case KEY_UP:
                    wclear(window.window);
                    wrefresh(window.window);
                    return (up);
            case KEY_DOWN:
                    wclear(window.window);
                    wrefresh(window.window);
                    return (down);
            case KEY_LEFT:
                    wclear(window.window);
                    wrefresh(window.window);return (left);
                    return (left);
            case KEY_RIGHT:
                    wclear(window.window);
                    wrefresh(window.window);return (right);
                    return (right);
            case 27:
                    wclear(window.window);
                    wrefresh(window.window);
                    endwin();
                    exit(0);           
        }
        wclear(window.window);
        wrefresh(window.window);
        return (-1);
    wclear(window.window);
    wrefresh(window.window);
    endwin();
    exit(0);
    return (0);
}

std::string LibNcurses::Game()
{
    return "toto";
}

std::string getNextLib(std::vector<std::pair<int, std::string>> libs)
{
    int i = 0;
    for (; i < (int)libs.size() && libs[i].second.compare("ncurses") <= 0; i++);
    i = i == (int)libs.size() ? 0 : i;
    return libs[i].second;
}

std::string getPrevLib(std::vector<std::pair<int, std::string>> libs)
{
    int i = libs.size() - 1;
    for (; i > 0 && libs[i].second.compare("ncurses") >= 0; i--);
    return libs[i].second;
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

    while (choice != 27) {
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
                wclear(game);
                wrefresh(game);
                wclear(window.window);
                wrefresh(window.window);
                return libs.size() == 0 ? "ncurses" : getNextLib(libs);
                break;
            case 'l':
                wclear(game);
                wrefresh(game);
                wclear(window.window);
                wrefresh(window.window);
                return "ChangedLib";
                break;
            case 'p':
                wclear(game);
                wrefresh(game);
                wclear(window.window);
                wrefresh(window.window);
                return libs.size() == 0 ? "ncurses" : getPrevLib(libs);
                break;
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


    while (choice != 27) {
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