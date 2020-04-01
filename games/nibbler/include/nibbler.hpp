/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** nibbler.hpp
*/

#pragma once
#include "../../../include/IGame.hpp"
#include <vector>

class nibbler : public IGame
{
    private:
       // std::vector<std::pair<int,int>> _NibblerBody;
       // int ymax;
       // int xmax;
    public:
        nibbler();
     //   int GetNibblerSize();
   //     std::vector<std::pair<int,int>> GetNibblerBody();
        std::string getName() const final;
        std::vector<std::string> getMap() const final;
        int ReceiveEvent(int, int) final;
        void saveGame(std::string) final;
};