/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_sfml
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "../../../include/IDisplay.hpp"
#include "iostream"

class LibSfml : public IDisplay
{
    private:
        sf::RenderWindow window;
        sf::VideoMode VideoMode = sf::VideoMode::getDesktopMode();
    public:
        LibSfml();
        void initWindow() final;
        void closeWindow() final;
        std::string Game() final;
        int InitProg() final;
        std::string Menu() final;
};