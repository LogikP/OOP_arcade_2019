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
 //   window.clear();
    int xmax;
    int ymax;
    int choice;
//    for (int i = 0; i != map.size(); i++)
 //       mvprintw(i, 0, map[i]);
//    getMap();
//    keypad(this->window.window, TRUE);
//    noecho();
    wrefresh(window.window);

//        display_help();

/*    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    getmaxyx(stdscr, ymax, xmax);*/
}

void LibNcurses::PrintMap(std::vector<std::string> map)
{
    for (unsigned int i = 0; i != map.size(); i++) {
        for (int a = 0; map[i][a] != '\n' && map[i][a]; a++) {
            if (map[i][a] == 'W') {
                wattron(window.window, COLOR_PAIR(2));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(2));
            } else if (map[i][a] == '#') {
                wattron(window.window, COLOR_PAIR(3));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(3));
            }else
                mvwaddch(window.window,i, a, map[i][a]);
        }
            
    }
}

int LibNcurses::InitProg(std::vector<std::string> map)
{
    int choice;
    unsigned int highlight = 0;

    while (choice != 'q') {
     //   for (int i = 0; i != map.size(); i++)
       //     mvwprintw(window.window,i, 0, map[i].c_str());
        PrintMap(map);
        choice = wgetch(this->window.window);
    }
    wclear(window.window);
    wrefresh(window.window);
    endwin();
    exit(0);
/*    while (true) {
        clear();
        std::vector<std::pair<int,int>> dim = _snake.GetSnake();
       for (int i = 0; i != _snake.GetSnakeSize(); i++) {
           mvaddch(_snake.GetSnake()[i].first, _snake.GetSnake()[i].second, ACS_BLOCK);
       }
    }*/
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
    i = i == (int)libs.size() ? i - 1 : i;
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