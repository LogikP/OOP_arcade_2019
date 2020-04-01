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

void pacman::InitMap()
{

}

std::string pacman::getName() const
{
    return "toto";
}

std::vector<std::string> pacman::getMap() const
{
    // std::vector<std::string> tmp;
    // std::string line;
    // std::ifstream myfile("example.txt");
    // if (myfile.is_open())
    // {
    //     while (getline (myfile,line)) {}
    //     myfile.close();
    // }
    // else throw(Error("Fail to open file"));
}

int pacman::ReceiveEvent(int key, int toto)
{
    return 0;
}

void pacman::saveGame(std::string map)
{

}

//// For the dlsym Symbol /////
extern "C" pacman *createGame()
{
    return new pacman;
}