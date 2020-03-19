/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_ncurses
*/

#include "lib_ncurses.hpp"

Display::Display() : window(0, 0, 0, 0)
{

}

void Display::closeWindow()
{
    this->window.clear();
    endwin();
    return;
}

void Display::initWindow()
{
    MyWindow ObjectWindow(1000,1000,1000,1000);
    this->window = ObjectWindow;
    // if (this->Menu() == "kill")
    //     exit(0);
    // return;
}

int Display::InitProg()
{
    int Input;
    Input = this->window.MyGetch();
}

std::string Display::Game()
{
    return "toto";
}


std::string Display::Menu()
{
    // initscr();
    // this->window = subwin(stdscr, 10, 10, LINES / 2, COLS /2);
   
    // //box(this->window, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
    // refresh();

    // getch();
    // endwin();
    // return "kill";
}

extern "C" Display *createDisplay() 
{
    return new Display;
}