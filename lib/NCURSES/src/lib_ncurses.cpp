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
 //       MyWindow ObjectWindow(0,0,0,0);
   //     this->window =  ObjectWindow;
        keypad(this->window.window, TRUE);
     //   noecho();
    wrefresh(window.window);
}

void LibNcurses::PrintGameName()
{
    if (_map[0][0] == 'W') {
        char const *ft_line= "  _   _ ___ ____  ____  _     _____ ____  ";
        char const *sd_line= " | \\ | |_ _| __ )| __ )| |   | ____|  _ \\ ";
        char const *trd_line=" |  \\| || ||  _ \\|  _ \\| |   |  _| | |_) |";
        char const *fth_line=" | |\\  || || |_) | |_) | |___| |___|  _ < ";
        char const *fft_line=" |_| \\_|___|____/|____/|_____|_____|_| \\_\\";
        char const *sx_line= "                                          ";
        wattron(window.window,COLOR_PAIR(2));
        mvwprintw(this->window.window, 2, (COLS/2) - (202/2) + 78, ft_line);
        wattroff(window.window, COLOR_PAIR(2));
        wattron(window.window,COLOR_PAIR(1));
        mvwprintw(this->window.window, 3, (COLS/2) - (202/2) + 78, sd_line);
        wattroff(window.window, COLOR_PAIR(1));
        wattron(window.window,COLOR_PAIR(3));
        mvwprintw(this->window.window, 4, (COLS/2) - (202/2) + 78, trd_line);
        wattroff(window.window,COLOR_PAIR(3));
        wattron(window.window,COLOR_PAIR(4));
        mvwprintw(this->window.window, 5, (COLS/2) - (202/2) + 78, fth_line);
        wattroff(window.window,COLOR_PAIR(4));
        wattron(window.window,COLOR_PAIR(2));
        mvwprintw(this->window.window, 6, (COLS/2) - (202/2) + 78, fft_line);
        wattroff(window.window, COLOR_PAIR(2));
        wattron(window.window,COLOR_PAIR(1));
        mvwprintw(this->window.window, 7, (COLS/2) - (202/2) + 78, sx_line);
        wattroff(window.window, COLOR_PAIR(1));
        wrefresh(this->window.window);
    } else {
        char const *ft_line= "  ____   _    ____ __  __    _    _   _ ";
        char const *sd_line= " |  _ \\ / \\  / ___|  \\/  |  / \\  | \\ | |";
        char const *trd_line=" | |_) / _ \\| |   | |\\/| | / _ \\ |  \\| |";
        char const *fth_line=" |  __/ ___ \\ |___| |  | |/ ___ \\| |\\  |";
        char const *fft_line=" |_| /_/   \\_\\____|_|  |_/_/   \\_\\_| \\_|";
        char const *sx_line= "                                        ";
        wattron(window.window,COLOR_PAIR(2));
        mvwprintw(this->window.window, 2, (COLS/2) - (202/2) + 78, ft_line);
        wattroff(window.window, COLOR_PAIR(2));
        wattron(window.window,COLOR_PAIR(1));
        mvwprintw(this->window.window, 3, (COLS/2) - (202/2) + 78, sd_line);
        wattroff(window.window, COLOR_PAIR(1));
        wattron(window.window,COLOR_PAIR(3));
        mvwprintw(this->window.window, 4, (COLS/2) - (202/2) + 78, trd_line);
        wattroff(window.window,COLOR_PAIR(3));
        wattron(window.window,COLOR_PAIR(4));
        mvwprintw(this->window.window, 5, (COLS/2) - (202/2) + 78, fth_line);
        wattroff(window.window,COLOR_PAIR(4));
        wattron(window.window,COLOR_PAIR(2));
        mvwprintw(this->window.window, 6, (COLS/2) - (202/2) + 78, fft_line);
        wattroff(window.window, COLOR_PAIR(2));
        wattron(window.window,COLOR_PAIR(1));
        mvwprintw(this->window.window, 7, (COLS/2) - (202/2) + 78, sx_line);
        wattroff(window.window, COLOR_PAIR(1));
        wrefresh(this->window.window);
    }
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
            } else if (map[i][a] == '.') {
                wattron(window.window, COLOR_PAIR(4));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(4));
            } else if (map[i][a] == 'G' || map[i][a] == 'U' || map[i][a] == 'H' || map[i][a] == 'T') {
                wattron(window.window, COLOR_PAIR(2));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(2));
            } else if (map[i][a] == 'o'|| map[i][a] == '0' || map[i][a] == ' ' || map[i][a] == 'x') {
                wattron(window.window, COLOR_PAIR(3));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(3));
            } else if (map[i][a] == 'C' || map[i][a] == 'F') {
                wattron(window.window, COLOR_PAIR(4));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(4));
            } else if (map[i][a] == 'A' || map[i][a] == 'B' || map[i][a] == 'D') {
                wattron(window.window, COLOR_PAIR(4));
                mvwaddch(window.window,i + 15, a + 80, 'C');
                wattroff(window.window, COLOR_PAIR(4));
            } else if (map[i][a] == 'M') {
                wattron(window.window, COLOR_PAIR(1));
                mvwaddch(window.window,i + 15, a + 80, map[i][a]);
                wattroff(window.window, COLOR_PAIR(1));
            } else if (map[i][a] == 'I') {
                wattron(window.window, COLOR_PAIR(4));
                mvwaddch(window.window,i + 15, a + 80, '.');
                wattroff(window.window, COLOR_PAIR(4));
            } else
                mvwaddch(window.window,i, a, map[i][a]);
        }

    }
}

int LibNcurses::Pause()
{
    WINDOW *Pause;
    Pause = subwin(stdscr, LINES / 4 + 18, COLS / 6 + 40 + 70, 15, 10);
    char const *ft_line= "  ____   _   _   _ ____  _____ ";
    char const *sd_line= " |  _ \\ / \\ | | | / ___|| ____|";
    char const *trd_line=" | |_) / _ \\| | | \\___ \\|  _|  ";
    char const *fth_line=" |  __/ ___ \\ |_| |___) | |___ ";
    char const *fft_line=" |_| /_/   \\_\\___/|____/|_____|";
    char const *sx_line= "                               ";

    wattron(Pause,COLOR_PAIR(2));
    mvwprintw(Pause, 5, (COLS/2) - (202/2) + 70 , ft_line);
    wattroff(Pause, COLOR_PAIR(2));
    wattron(Pause,COLOR_PAIR(1));
    mvwprintw(Pause, 6, (COLS/2) - (202/2) + 70 , sd_line);
    wattroff(Pause, COLOR_PAIR(1));
    wattron(Pause,COLOR_PAIR(3));
    mvwprintw(Pause, 7, (COLS/2) - (202/2) + 70, trd_line);
    wattroff(Pause,COLOR_PAIR(3));
    wattron(Pause,COLOR_PAIR(4));
    mvwprintw(Pause, 8, (COLS/2) - (202/2) + 70 , fth_line);
    wattroff(Pause,COLOR_PAIR(4));
    wattron(Pause,COLOR_PAIR(2));
    mvwprintw(Pause, 9, (COLS/2) - (202/2) + 70, fft_line);
    wattroff(Pause, COLOR_PAIR(2));
    wattron(Pause,COLOR_PAIR(1));
    mvwprintw(Pause, 10, (COLS/2) - (202/2) + 70, sx_line);
    wattroff(Pause, COLOR_PAIR(1));
    wrefresh(Pause);
    int choice = wgetch(this->window.window);
        switch (choice) {
            case 27:
                wclear(Pause);
                wrefresh(Pause);
                wclear(window.window);
                wrefresh(window.window);
                endwin();
                return ('k');
            case 32:
                wclear(Pause);
                wrefresh(Pause);
                wclear(window.window);
                wrefresh(window.window);
                return ('p');
            case 'l':
                wclear(Pause);
                wrefresh(Pause);
                wclear(window.window);
                wrefresh(window.window);
                return ('l');
            case 'm':
                wclear(Pause);
                wrefresh(Pause);
                wclear(window.window);
                wrefresh(window.window);
                return ('m');
        }
    return 0;
}

void LibNcurses::InitProg(std::vector<std::string> map, std::vector<std::string> score)
{
    _map = map;
    PrintGameName();
    PrintMap(_map);
    PrintScore(score);
}

int LibNcurses::getEvent()
{
    int choice;

        refresh();
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
                    wrefresh(window.window);
                    return (left);
            case KEY_RIGHT:
                    wclear(window.window);
                    wrefresh(window.window);
                    return (right);
            case 27:
                wclear(window.window);
                wrefresh(window.window);
                endwin();
                return (LEAVE);
            case 'l':
                wclear(window.window);
                wrefresh(window.window);
                return ('l');
            case 'm':
                wclear(window.window);
                wrefresh(window.window);
                return ('m');
            case 32:
                wclear(window.window);
                wrefresh(window.window);
                return ('p');
        }
    wclear(window.window);
    wrefresh(window.window);
    return (-1);
}

std::string LibNcurses::Game()
{
    return "toto";
}

std::string LibNcurses::getNextLibN(std::vector<std::pair<int, std::string>> libs)
{
    int i = 0;
    for (; i != (int)libs.size() && libs[i].second.compare("ncurses") <= 0; i++);
    i = i == (int)libs.size()? 0 : i;
    return libs[i].second;
}

std::string LibNcurses::getPrevLibN(std::vector<std::pair<int, std::string>> libs)
{
    int i = libs.size() - 1;
    for (; i != 0 && libs[i].second.compare("ncurses") >= 0; i--);
    i = i == -1 ? (int)libs.size() - 1 : i;
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
    display_title();
   // GetUsername();
    display_help();
    display_game();

    while (choice != 27) {
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
                wclear(help);
                wrefresh(help);
                wclear(game);
                wrefresh(game);
                return (games[highlight].second);
                break;
            case 'n':
                wclear(game);
                wrefresh(game);
                wclear(help);
                wrefresh(help);
                wclear(window.window);
                wrefresh(window.window);
                return libs.size() == 0 ? "ncurses" : getNextLibN(libs);
                break;
            case 'l':
                wclear(game);
                wrefresh(game);
                wclear(help);
                wrefresh(help);
                wclear(window.window);
                wrefresh(window.window);
                return "ChangedLib";
                break;
            case 'p':
                wclear(game);
                wrefresh(game);
                wclear(help);
                wrefresh(help);
                wclear(window.window);
                wrefresh(window.window);
                return libs.size() == 0 ? "ncurses" : getPrevLibN(libs);
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
                endwin();
                return (libs[highlight].second);
                break;
        }
        refresh();
     }
    this->window.clear();
    endwin();
    return ("kill");
}

std::string LibNcurses::gameOver()
{
    WINDOW *GameOver;
    GameOver = subwin(stdscr, LINES / 4 + 18, COLS / 6 + 40 + 70, 15, 10);
    keypad(GameOver, TRUE);
    noecho();
    char const *ft_line= " _____   ___  ___  ___ _____   _____  _   _ ___________ ";
    char const *sd_line= "|  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | |  ___| ___ \\";
    char const *trd_line="| |  \\// /_\\ \\| .  . || |__   | | | || | | | |__ | |_/ /";
    char const *fth_line="| | __ |  _  || |\\/| ||  __|  | | | || | | |  __||    / ";
    char const *fft_line="| |_\\ \\| | | || |  | || |___  \\ \\_/ /\\ \\_/ / |___| |\\ \\ ";
    char const *sx_line= " \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/\\____/\\_| \\_|";

    wattron(GameOver,COLOR_PAIR(2));
    mvwprintw(GameOver, 5, (COLS/2) - (202/2) + 70 , ft_line);
    wattroff(GameOver, COLOR_PAIR(2));
    wattron(GameOver,COLOR_PAIR(1));
    mvwprintw(GameOver, 6, (COLS/2) - (202/2) + 70 , sd_line);
    wattroff(GameOver, COLOR_PAIR(1));
    wattron(GameOver,COLOR_PAIR(3));
    mvwprintw(GameOver, 7, (COLS/2) - (202/2) + 70, trd_line);
    wattroff(GameOver,COLOR_PAIR(3));
    wattron(GameOver,COLOR_PAIR(4));
    mvwprintw(GameOver, 8, (COLS/2) - (202/2) + 70 , fth_line);
    wattroff(GameOver,COLOR_PAIR(4));
    wattron(GameOver,COLOR_PAIR(2));
    mvwprintw(GameOver, 9, (COLS/2) - (202/2) + 70, fft_line);
    wattroff(GameOver, COLOR_PAIR(2));
    wattron(GameOver,COLOR_PAIR(1));
    mvwprintw(GameOver, 10, (COLS/2) - (202/2) + 70, sx_line);
    wattroff(GameOver, COLOR_PAIR(1));
    wrefresh(GameOver);
    mvwprintw(GameOver, 15, (COLS/2) - (202/2) + 70 , "\tPress 'r' to RESTART");
    mvwprintw(GameOver, 16, (COLS/2) - (202/2) + 70 , "\tPress 'm' to go to MENU");
    mvwprintw(GameOver, 17, (COLS/2) - (202/2) + 70 , "\tPress 'ESC' to ESCAPE");
    int choice = wgetch(GameOver);

    while (choice != 'r' || choice != 'm' || choice != 27) {
        switch (choice) {
            case 27:
                wclear(GameOver);
                wrefresh(GameOver);
                wclear(window.window);
                wrefresh(window.window);
                endwin();
                return ("kill");
            case 'r':
                wclear(GameOver);
                wrefresh(GameOver);
                wclear(window.window);
                wrefresh(window.window);
                return ("Restart");
            case 'm':
                wclear(GameOver);
                wrefresh(GameOver);
                wclear(window.window);
                wrefresh(window.window);
                return ("Menu");
        }
        choice = wgetch(GameOver);
    }
    return ("kill");
}

extern "C" LibNcurses *createDisplay()
{
    return new LibNcurses;
}