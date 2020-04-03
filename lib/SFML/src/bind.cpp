/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** bind
*/

#include "lib_sfml.hpp"

int LibSfml::bind()
{
    if(this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Down)
                    return DOWN_KEY;
                if (event.key.code == sf::Keyboard::Up)
                    return UP_KEY;
                if (event.key.code == sf::Keyboard::Right)
                    return RIGHT_KEY;
                if (event.key.code == sf::Keyboard::Left)
                    return LEFT_KEY;
                if (event.key.code == sf::Keyboard::Escape)
                    return LEAVE;
                if (event.key.code == sf::Keyboard::M)
                    return MENU;
            }
            else
                return -1;
        }
    }
    return -1;
}