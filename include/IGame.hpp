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
};
