/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_caca
*/

#include "lib_caca.hpp"

libCaca::libCaca() : window()
{

}

void libCaca::closeWindow()
{
    return;
}

int libCaca::InitProg()
{
    return 0;
}

std::string libCaca::Game()
{
    return "toto";
}

void libCaca::initWindow()
{
    MyWindowC test;
    this->window = test;
}

std::string libCaca::Menu(std::vector<std::pair<int,std::string>> Games)
{

}

extern "C" libCaca *createlibCaca() 
{
    return new libCaca;
}