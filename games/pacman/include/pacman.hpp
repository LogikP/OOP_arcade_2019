/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** pacman
*/

#pragma once
#include "../../../include/IGame.hpp"
#include "../../../include/Error.hpp"
#include <iostream>
#include <fstream>
#include <string>

class pacman : public IGame
{
    private:
        /* data */
        std::vector<std::string> _map;
    public:
        pacman();
        std::string getName() const final;
        void InitMap() final;
        std::vector<std::string> getMap() final;
        int ReceiveEvent(int, int) final;
        void saveGame(std::string) final;
        void MovePlayer(int);
};