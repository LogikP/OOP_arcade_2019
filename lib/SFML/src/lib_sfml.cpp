/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_ncurses
*/

#include "lib_sfml.hpp"

void Display::initWindow()
{
    if (this->Menu() == "kill")
        this->closeWindow();
}

Display::Display() : window(sf::VideoMode(VideoMode.width, VideoMode.height, VideoMode.bitsPerPixel), "Arcade", sf::Style::Fullscreen)
{

}

std::string Display::Menu()
{
    window.clear();
    sf::Sprite sprite;
    sf::Texture texture;

    if (!texture.loadFromFile("./asset/5S4kgs.jpg", sf::IntRect(0,0,1920, 1080)))
        std::cerr << "error" << std::endl;
    sprite.setTexture(texture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.clear();
                    return "kill";
                }
            }
        }
        window.draw(sprite);
        window.display();
    }
    return "success";
}

std::string Display::Game()
{
    return "toto";
}

void Display::closeWindow() {
    window.close();
}

//// For the dlsym Symbol /////
extern "C" Display *createDisplay() 
{
    return new Display;
}