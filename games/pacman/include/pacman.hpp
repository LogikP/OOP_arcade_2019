/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** pacman
*/

#pragma once
#include "../../../include/IGame.hpp"

class pacman : public IGame
{
    private:
        /* data */
    public:
        pacman();
        std::string getName() const final;
        std::vector<std::string> getMap() const final;
        int SendEvent(int, int) final;
        void saveGame(std::string) final;
};