/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_caca
*/

#include "lib_caca.hpp"

Display::Display() : window()
{

}

void Display::closeWindow()
{
    return;
}

int Display::InitProg()
{
    return 0;
}

std::string Display::Game()
{
    return "toto";
}

void Display::initWindow()
{
    MyWindowC test;
    this->window = test;
}

extern "C" Display *createDisplay() 
{
    return new Display;
}