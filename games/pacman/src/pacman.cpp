/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** pacman
*/

#include "pacman.hpp"

pacman::pacman()
{

}

std::string pacman::getName() const
{

}

std::vector<std::string> pacman::getMap() const
{

}

int pacman::SendEvent(int key, int toto)
{

}

void pacman::saveGame(std::string map)
{

}

//// For the dlsym Symbol /////
extern "C" pacman *createDisplay()
{
    return new pacman;
}