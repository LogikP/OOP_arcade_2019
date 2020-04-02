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
    return "Pacman";
}

std::vector<std::string> pacman::getMap()
{
    std::vector<std::string> map;
    std::ifstream in("./maps/nibbler-map.txt");
    std::string str;

    if (!in)
        std::cerr << "Cannot open the File : " << "nibbler-map.txt"<<std::endl;
    while (std::getline(in, str)) {
        if(str.size() > 0)
            map.push_back(str);
    }
    in.close();
    return (map);
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