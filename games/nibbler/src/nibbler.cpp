/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nibbler
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
  //      std::cout << map[0] << '\n'<< std::ends;
    //    std::cout << map[1] << '\n'<< std::ends;
    return (map);
}

int nibbler::ReceiveEvent(int key, int toto)
{
  //  MovePlayer();
    return 0;
}

void nibbler::saveGame(std::string map)
{

}
/*
void MovePlayer()
{

}*/

//// For the dlsym Symbol /////
extern "C" nibbler *createGame()
{
    return new nibbler;
}