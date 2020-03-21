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


// | |              | || |              | || |              | || |              | || |              | || |              | |
// | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
//  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' 
    box(this->window.window, ACS_VLINE, ACS_HLINE);
    char const *ft_line = " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. ";
    char const *sd_line = "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |";
    char const *trd_line = "| |      __      | || |  _______     | || |     ______   | || |      __      | || |  ________    | || |  _________   | |";
    char const *fth_line = "| |     /  \     | || | |_   __ \    | || |   .' ___  |  | || |     /  \     | || | |_   ___ `.  | || | |_   ___  |  | |";
    char const *sx_line="| |    / /\ \    | || |   | |__) |   | || |  / .'   \_|  | || |    / /\ \    | || |   | |   `. \ | || |   | |_  \_|  | |";
    char const *sv_line="| |   / ____ \   | || |   |  __ /    | || |  | |         | || |   / ____ \   | || |   | |    | | | || |   |  _|  _   | |";
    char const *ht_line="| | _/ /    \ \_ | || |  _| |  \ \_  | || |  \ `.___.'\  | || | _/ /    \ \_ | || |  _| |___.' / | || |  _| |___/ |  | |";
    char const *nn_line="| ||____|  |____|| || | |____| |___| | || |   `._____.'  | || ||____|  |____|| || | |________.'  | || | |_________|  | |";
    char const *tn_line="| |              | || |              | || |              | || |              | || |              | || |              | |";
    char const *elv_line="| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |";
    char const *twv_line= " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ";
//    char const *ft_line = " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. ";
    //char const *sd_line = " | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |";
    //char const *trd_line = " | | ____    ____ | || |  ____  ____  | || |              | || |    ______    | || |  ___  ____   | || |  _______     | || |  _________   | || |   _____      | || |   _____      | || | ____    ____ | |";
/*    char const *fth_line = " | ||_   \\  /   _|| || | |_  _||_  _| | || |              | || |  .' ___  |   | || | |_  ||_  _|  | || | |_   __ \\    | || | |_   ___  |  | || |  |_   _|     | || |  |_   _|     | || ||_   \\  /   _|| |";
    char const *fft_line = " | |  |   \\/   |  | || |   \\ \\  / /   | || |              | || | / .'   \\_|   | || |   | |_/ /    | || |   | |__) |   | || |   | |_  \\_|  | || |    | |       | || |    | |       | || |  |   \\/   |  | |";
    char const *sx_line=" | |  | |\\  /| |  | || |    \\ \\/ /    | || |              | || | | |    ____  | || |   |  __'.    | || |   |  __ /    | || |   |  _|  _   | || |    | |   _   | || |    | |   _   | || |  | |\\  /| |  | |";
    char const *sv_line=" | | _| |_\\/_| |_ | || |    _|  |_    | || |              | || | \\ `.___]  _| | || |  _| |  \\ \\_  | || |  _| |  \\ \\_  | || |  _| |___/ |  | || |   _| |__/ |  | || |   _| |__/ |  | || | _| |_\\/_| |_ | |";
    char const *ht_line=" | ||_____||_____|| || |   |______|   | || |   _______    | || |  `._____.'   | || | |____||____| | || | |____| |___| | || | |_________|  | || |  |________|  | || |  |________|  | || ||_____||_____|| |";
    char const *nn_line=" | |              | || |              | || |  |_______|   | || |              | || |              | || |              | || |              | || |              | || |              | || |              | |";
    char const *tn_line=" | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |";
    char const *elv_line=" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ";
*/
    wattron(window.window,COLOR_PAIR(2));
    mvwprintw(this->window.window, 0, (COLS/2) - (202/2), ft_line);
    mvwprintw(this->window.window, 1, (COLS/2) - (202/2), sd_line);
    mvwprintw(this->window.window, 2, (COLS/2) - (202/2), trd_line);
    mvwprintw(this->window.window, 3, (COLS/2) - (202/2), fth_line);
//    mvwprintw(this->window.window, 4, (COLS/2) - (202/2), fft_line);
    mvwprintw(this->window.window, 5, (COLS/2) - (202/2), sx_line);
    mvwprintw(this->window.window, 6, (COLS/2) - (202/2), sv_line);
    mvwprintw(this->window.window, 7, (COLS/2) - (202/2), ht_line);
    mvwprintw(this->window.window, 8, (COLS/2) - (202/2), nn_line);
    mvwprintw(this->window.window, 9, (COLS/2) - (202/2), tn_line);
    mvwprintw(this->window.window, 10, (COLS/2) - (202/2), elv_line);
    mvwprintw(this->window.window, 11, (COLS/2) - (202/2), twv_line);
    wattroff(window.window, COLOR_PAIR(2));
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