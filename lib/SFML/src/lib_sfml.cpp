/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_ncurses
*/

#include "lib_sfml.hpp"

void Display::initWindow()
{
}

Display::Display() : window(sf::VideoMode(VideoMode.width, VideoMode.height, VideoMode.bitsPerPixel), "Arcade", sf::Style::Fullscreen)
{

}

void Display::Menu()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->closeWindow();
        }
    }
}

std::string Display::Game()
{
    return "toto";
}

void Display::closeWindow() {
    window.close();
}

//// For the dlsym Symbol /////
extern "C" Display *createDisplay() {
    return (new Display);
}