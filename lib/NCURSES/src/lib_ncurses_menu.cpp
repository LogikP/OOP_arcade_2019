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
    wattron(help,COLOR_PAIR(1));
    mvwprintw(help, 10, 15, "\t\t\t\n\n\n\n\tMove the cursor menu to select a game\n\n\tPress enter to choose a game.\
    \n\n\tIn Game :\n\n\tKey l : move to Library menu.\n\n\tFor starting push ENTER and for quit monitor push \"q\"");
    wattroff(help,COLOR_PAIR(1));
}

void LibNcurses::display_help()
{

    wattron(window.window,COLOR_PAIR(3));
    box(this->window.window, '*', '*');
    touchwin(this->window.window);
    wattroff(window.window,COLOR_PAIR(2));
    wrefresh(this->window.window);
    WINDOW *help;
    help = subwin(stdscr, LINES / 4 + 18, COLS / 6 + 40, 15, 10);
    char const *ft_line= "  _    _  ______          __  _____  _           __     __  ___  ";
    char const *sd_line= " | |  | |/ __ \\ \\        / / |  __ \\| |        /\\ \\   / / |__ \\ ";
    char const *trd_line=" | |__| | |  | \\ \\  /\\  / /  | |__) | |       /  \\ \\_/ /     ) |";
    char const *fth_line=" |  __  | |  | |\\ \\/  \\/ /   |  ___/| |      / /\\ \\   /     / / ";
    char const *fft_line=" | |  | | |__| | \\  /\\  /    | |    | |____ / ____ \\| |     |_|  ";
    char const *sx_line= " |_|  |_|\\____/   \\/  \\/     |_|    |______/_/    \\_\\_|     (_)  ";
    char const *sv_line= "                                                                 ";


    wattron(help,COLOR_PAIR(2));
    mvwprintw(help, 2, (COLS/2) - (202/2) , ft_line);
    wattroff(help, COLOR_PAIR(2));
    wattron(help,COLOR_PAIR(1));
    mvwprintw(help, 3, (COLS/2) - (202/2) , sd_line);
    wattroff(help, COLOR_PAIR(1));
    wattron(help,COLOR_PAIR(3));
    mvwprintw(help, 4, (COLS/2) - (202/2) , trd_line);
    wattroff(help,COLOR_PAIR(3));
    wattron(help,COLOR_PAIR(4));
    mvwprintw(help, 5, (COLS/2) - (202/2) , fth_line);
    wattroff(help,COLOR_PAIR(4));
    wattron(help,COLOR_PAIR(2));
    mvwprintw(help, 6, (COLS/2) - (202/2) , fft_line);
    wattroff(help, COLOR_PAIR(2));
    wattron(help,COLOR_PAIR(1));
    mvwprintw(help, 7, (COLS/2) - (202/2), sx_line);
    wattroff(help, COLOR_PAIR(1));
    wattron(help,COLOR_PAIR(3));
    mvwprintw(help, 8, (COLS/2) - (202/2) , sv_line);
    wattroff(help, COLOR_PAIR(3));
    usage_help(help);
    wattron(help,COLOR_PAIR(3));
    box(help, ACS_VLINE, ACS_HLINE);
    wattron(help,COLOR_PAIR(3));
    wrefresh(help);

}

void LibNcurses::display_game()
{
    //WINDOW *game;

    game = subwin(stdscr, LINES / 4 + 18, COLS / 6 + 40, 15, 100);
    wattron(game,COLOR_PAIR(2));
    box(game, ACS_VLINE, ACS_HLINE);
    wattroff(game,COLOR_PAIR(2));
    wrefresh(game);

    char const *ft_line= "   _____          __  __ ______  _____ ";
    char const *sd_line= "  / ____|   /\\   |  \\/  |  ____|/ ____|";
    char const *trd_line=" | |  __   /  \\  | \\  / | |__  | (___  ";
    char const *fth_line=" | | |_ | / /\\ \\ | |\\/| |  __|  \\___ \\ ";
    char const *fft_line=" | |__| |/ ____ \\| |  | | |____ ____) |";
    char const *sx_line= "  \\_____/_/    \\_\\_|  |_|______|_____/ ";
    char const *sv_line= "                                       ";

    wattron(game,COLOR_PAIR(2));
    mvwprintw(game, 2, (COLS/2) - (202/2) + 15, ft_line);
    wattroff(game, COLOR_PAIR(2));
    wattron(game,COLOR_PAIR(1));
    mvwprintw(game, 3, (COLS/2) - (202/2) + 15, sd_line);
    wattroff(game, COLOR_PAIR(1));
    wattron(game,COLOR_PAIR(3));
    mvwprintw(game, 4, (COLS/2) - (202/2) + 15, trd_line);
    wattroff(game,COLOR_PAIR(3));
    wattron(game,COLOR_PAIR(4));
    mvwprintw(game, 5, (COLS/2) - (202/2) + 15, fth_line);
    wattroff(game,COLOR_PAIR(4));
    wattron(game,COLOR_PAIR(2));
    mvwprintw(game, 6, (COLS/2) - (202/2) + 15, fft_line);
    wattroff(game, COLOR_PAIR(2));
    wattron(game,COLOR_PAIR(1));
    mvwprintw(game, 7, (COLS/2) - (202/2) + 15, sx_line);
    wattroff(game, COLOR_PAIR(1));
    wattron(game,COLOR_PAIR(3));
    mvwprintw(game, 8, (COLS/2) - (202/2) + 15, sv_line);
    wattroff(game, COLOR_PAIR(3));
    refresh();
    wrefresh(game);

}

void LibNcurses::display_libs()
{
    WINDOW *game;

    game = subwin(stdscr, LINES / 4 + 18, COLS / 6 + 40, 15, 100);
    wattron(game,COLOR_PAIR(2));
    box(game, ACS_VLINE, ACS_HLINE);
    wattroff(game,COLOR_PAIR(2));
    wrefresh(game);

    char const *ft_line= "  _      _____ ____   _____ ";
    char const *sd_line= " | |    |_   _|  _ \\ / ____|";
    char const *trd_line=" | |      | | | |_) | (___  ";
    char const *fth_line=" | |      | | |  _ < \\___ \\ ";
    char const *fft_line=" | |____ _| |_| |_) |____) |";
    char const *sx_line= " |______|_____|____/|_____/ ";
    char const *sv_line= "                            ";

    wattron(game,COLOR_PAIR(2));
    mvwprintw(game, 2, (COLS/2) - (202/2) + 15, ft_line);
    wattroff(game, COLOR_PAIR(2));
    wattron(game,COLOR_PAIR(1));
    mvwprintw(game, 3, (COLS/2) - (202/2) + 15, sd_line);
    wattroff(game, COLOR_PAIR(1));
    wattron(game,COLOR_PAIR(3));
    mvwprintw(game, 4, (COLS/2) - (202/2) + 15, trd_line);
    wattroff(game,COLOR_PAIR(3));
    wattron(game,COLOR_PAIR(4));
    mvwprintw(game, 5, (COLS/2) - (202/2) + 15, fth_line);
    wattroff(game,COLOR_PAIR(4));
    wattron(game,COLOR_PAIR(2));
    mvwprintw(game, 6, (COLS/2) - (202/2) + 15, fft_line);
    wattroff(game, COLOR_PAIR(2));
    wattron(game,COLOR_PAIR(1));
    mvwprintw(game, 7, (COLS/2) - (202/2) + 15, sx_line);
    wattroff(game, COLOR_PAIR(1));
    wattron(game,COLOR_PAIR(3));
    mvwprintw(game, 8, (COLS/2) - (202/2) + 15, sv_line);
    wattroff(game, COLOR_PAIR(3));
    refresh();
    wrefresh(game);
}