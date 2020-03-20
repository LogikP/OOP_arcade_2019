/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_ncurses
*/

#include "lib_sfml.hpp"

void LibSfml::initWindow()
{
    // if (this->Menu() == "kill") {
    //     this->closeWindow();
    //     exit(0);
    // }
}

LibSfml::LibSfml() : window(sf::VideoMode(VideoMode.width, VideoMode.height, VideoMode.bitsPerPixel), "Arcade", sf::Style::Fullscreen)
{

}

std::string LibSfml::Menu(std::vector<std::pair<int, std::string>> Games)
{
    window.clear();
    sf::Sprite sprite;
    sf::Texture texture;

    if (!texture.loadFromFile("./asset/5S4kgs.jpg", sf::IntRect(0,0,1920, 1080)))
        std::cerr << "error" << std::endl;
    sprite.setTexture(texture);
    sf::Event event;
    while (window.isOpen())
    {
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

int LibSfml::InitProg()
{
    return 0;
}

std::string LibSfml::Game()
{
    return "toto";
}

void LibSfml::closeWindow() 
{
    window.close();
}

//// For the dlsym Symbol /////
extern "C" LibSfml *createDisplay() 
{
    return new LibSfml;
}