/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame
*/

#pragma once
#include <string>

class IGame {
    virtual ~IGame();
    virtual  std::string getName() const = 0;
    virtual std::vector<std::string> getMap() const = 0;
    virtual int SendEvent(int, int) = 0;
    virtual void saveGame(std::string) = 0;
};
