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
                    return this->DOWN_KEY;
                if (event.key.code == sf::Keyboard::Up)
                    return this->UP_KEY;
                if (event.key.code == sf::Keyboard::Right)
                    return this->RIGHT_KEY;
                if (event.key.code == sf::Keyboard::Left)
                    return this->LEFT_KEY;
            }
            else
                return -1;
        }
    }
    return -1;
}