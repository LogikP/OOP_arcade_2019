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
#include <unistd.h>



enum EventKey {
    UNKNOWN,
    LEFT_KEY,
    RIGHT_KEY,
    UP_KEY,
    DOWN_KEY,
    LEAVE = 'k',
    MENU = 'm',
};

enum STATUS {
    RUN,
    QUIT,
    GAME,
    LIB
};

//account_num = static_cast<int>(Suit::Hearts);

class LibSfml : public IDisplay
{
    private:
        sf::RenderWindow window;
        sf::VideoMode VideoMode = sf::VideoMode::getDesktopMode();
        std::vector<std::string> _map;
        std::vector<std::string> _score;
        sf::Texture Wall_N;
        sf::Texture Wall_P;
        sf::Texture Pacman_Left;
        sf::Texture Pacman_Right;
        sf::Texture Pacman_Up;
        sf::Texture Pacman_Down;
        sf::Texture Nibbler_Head;
        sf::Texture Nibbler_Tail;
        sf::Texture Ghost1;
        sf::Texture Ghost2;
        sf::Texture Ghost3;
        sf::Texture Ghost4;
        sf::Texture Apple;
        sf::Texture MagicCandy;
        sf::RectangleShape Vert;
        sf::RectangleShape Horiz;
        sf::Texture Candy;
        sf::Texture Background;
        std::map<std::string, sf::Sprite> ListSprite;

    public:
        LibSfml();
        void initWindow() final;
        void closeWindow() final;
        std::string Game() final;
        int getEvent() final;
        void InitProg(std::vector<std::string> map, std::vector<std::string> score) final;
        void SetSpritePos(std::string, int, int, int);
        std::string MenuLib(std::vector<std::pair<int,std::string>>) final;
        std::string Menu(std::vector<std::pair<int, std::string>>, std::vector<std::pair<int, std::string>>) final;
        void DrawMap(std::vector<std::string>);
        int bind();
};