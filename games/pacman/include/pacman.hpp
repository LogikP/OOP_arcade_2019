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
<<<<<<< HEAD
        void MovePlayer(int);
=======
        void MovePlayer();
>>>>>>> 7a7921a6378c8f8ecfe745734c4aa89be5f5b757
};