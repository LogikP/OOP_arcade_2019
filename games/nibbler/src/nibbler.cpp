/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nibbler
*/

#include "nibbler.hpp"

nibbler::nibbler()
{
   // _NibblerBody.push_back(std::make_pair(2,2));
    //_NibblerBody.push_back(std::make_pair(2,3));
}
/*
int nibbler::GetNibblerSize()
{
    return (_NibblerBody.size());
}

std::vector<std::pair<int,int>> nibbler::GetNibblerBody()
{
    return (_NibblerBody);
}*/

void nibbler::InitMap()
{

}

std::string nibbler::getName() const
{
    return "toto";
}

std::vector<std::string> nibbler::getMap() const
{
}

int nibbler::ReceiveEvent(int key, int toto)
{
    return 0;
}

void nibbler::saveGame(std::string map)
{

}

//// For the dlsym Symbol /////
extern "C" nibbler *createGame()
{
    return new nibbler;
}