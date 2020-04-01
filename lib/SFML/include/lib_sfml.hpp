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
#include "../../../include/Error.hpp"

class LibSfml : public IDisplay
{
    private:
        sf::RenderWindow window;
        sf::VideoMode VideoMode = sf::VideoMode::getDesktopMode();
        std::vector<std::string> _map;
    public:
        LibSfml();
        void initWindow() final;
        void closeWindow() final;
        std::string Game() final;
        int InitProg(std::vector<std::string>) final;
        void DrawSprite(sf::Sprite);
        std::string MenuLib(std::vector<std::pair<int,std::string>>) final;
        std::string Menu(std::vector<std::pair<int, std::string>>, std::vector<std::pair<int, std::string>>) final;
};