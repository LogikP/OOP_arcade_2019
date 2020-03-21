/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** lib_ncurses_menu.cpp
*/

#include "lib_ncurses.hpp"
#include <curses.h>
#include <time.h>

void LibNcurses::display_title()
{
    box(this->window.window, ACS_VLINE, ACS_HLINE);
    char const *ft_line= " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. ";
    char const *sd_line= "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |";
    char const *trd_line="| |      __      | || |  _______     | || |     ______   | || |      __      | || |  ________    | || |  _________   | |";
    char const *fth_line="| |     /  \\     | || | |_   __ \\    | || |   .' ___  |  | || |     /  \\     | || | |_   ___ `.  | || | |_   ___  |  | |";
    char const *fft_line="| |    / /\\ \\    | || |   | |__) |   | || |  / .'   \\_|  | || |    / /\\ \\    | || |   | |   `. \\ | || |   | |_  \\_|  | |";
    char const *sx_line= "| |   / ____ \\   | || |   |  __ /    | || |  | |         | || |   / ____ \\   | || |   | |    | | | || |   |  _|  _   | |";
    char const *sv_line= "| | _/ /    \\ \\_ | || |  _| |  \\ \\_  | || |  \\ `.___.'\\  | || | _/ /    \\ \\_ | || |  _| |___.' / | || |  _| |___/ |  | |";
    char const *ht_line= "| ||____|  |____|| || | |____| |___| | || |   `._____.'  | || ||____|  |____|| || | |________.'  | || | |_________|  | |";
    char const *nn_line= "| |              | || |              | || |              | || |              | || |              | || |              | |";
    char const *tn_line= "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |";
    char const *elv_line=" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ";

    wattron(window.window,COLOR_PAIR(2));
    mvwprintw(this->window.window, 2, (COLS/2) - (202/2) + 35, ft_line);
    wattroff(window.window, COLOR_PAIR(2));
    wattron(window.window,COLOR_PAIR(1));
    mvwprintw(this->window.window, 3, (COLS/2) - (202/2) + 35, sd_line);
    wattroff(window.window, COLOR_PAIR(1));
    wattron(window.window,COLOR_PAIR(3));
    mvwprintw(this->window.window, 4, (COLS/2) - (202/2) + 35, trd_line);
    wattroff(window.window,COLOR_PAIR(3));
    wattron(window.window,COLOR_PAIR(4));
    mvwprintw(this->window.window, 5, (COLS/2) - (202/2) + 35, fth_line);
    wattroff(window.window,COLOR_PAIR(4));
    wattron(window.window,COLOR_PAIR(2));
    mvwprintw(this->window.window, 6, (COLS/2) - (202/2) + 35, fft_line);
    wattroff(window.window, COLOR_PAIR(2));
    wattron(window.window,COLOR_PAIR(1));
    mvwprintw(this->window.window, 7, (COLS/2) - (202/2) + 35, sx_line);
    wattroff(window.window, COLOR_PAIR(1));
    wattron(window.window,COLOR_PAIR(3));
    mvwprintw(this->window.window, 8, (COLS/2) - (202/2) + 35, sv_line);
    wattroff(window.window, COLOR_PAIR(3));
    wattron(window.window,COLOR_PAIR(4));
    mvwprintw(this->window.window, 9, (COLS/2) - (202/2) + 35, ht_line);
    wattroff(window.window,COLOR_PAIR(4));
    wattron(window.window,COLOR_PAIR(2));
    mvwprintw(this->window.window, 10, (COLS/2) - (202/2) + 35, nn_line);
    wattroff(window.window,COLOR_PAIR(2));
    wattron(window.window,COLOR_PAIR(1));
    mvwprintw(this->window.window, 11, (COLS/2) - (202/2) + 35, tn_line);
    wattroff(window.window,COLOR_PAIR(1));
    wattron(window.window,COLOR_PAIR(3));
    mvwprintw(this->window.window, 12, (COLS/2) - (202/2) +35, elv_line);
    wattroff(window.window,COLOR_PAIR(3));
    wrefresh(this->window.window);

}

static void usage_help(WINDOW *help)
{
    mvwprintw(help, 1, 5, "\t\t\tHOW TO PLAY :\n\n\n\n\tMove the cursor menu to select a game\n\n\tPress enter to choose a game.\
    \n\n\tIn Game :\n\n\tKey 2 : move to previous graphical library.\n\n\tFor starting push ENTER and for quit monitor push \"q\"");
}

void LibNcurses::display_help()
{

    box(this->window.window, '*', '*');
    touchwin(this->window.window);
    wrefresh(this->window.window);
    WINDOW *help;
    help = subwin(stdscr, LINES / 4 + 18, COLS / 6 + 40, 15, 10);
    usage_help(help);
    box(help, ACS_VLINE, ACS_HLINE);
    wrefresh(help);

}

void LibNcurses::display_game()
{
    WINDOW *game;

    game = subwin(stdscr, LINES / 4 + 18, COLS / 6 + 40, 15, 100);
    box(game, ACS_VLINE, ACS_HLINE);
    attron(COLOR_PAIR(2));
    mvprintw(16, 125, "GAMES :");
    attroff(COLOR_PAIR(2));
    refresh();
    wrefresh(game);

}