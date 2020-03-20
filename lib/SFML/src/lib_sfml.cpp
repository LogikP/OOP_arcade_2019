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

// void LibSfml::DrawSprite(sf::Sprite sprite)
// {
//     this->window.draw(sprite);
// }

std::string LibSfml::Menu(std::vector<std::pair<int, std::string>> Games)
{
    this->window.clear();
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Sprite logo;
    sf::Texture T_logo;
    sf::Text QGame;
    sf::Text Game1;
    sf::Text Game2;
    sf::Font font;

    if (!font.loadFromFile("./asset/Test-Font.ttf"))
        throw(Error("Can't find the Font file"));
    if (!texture.loadFromFile("./asset/arcade-backgrounds.jpg", sf::IntRect(0,0,1920, 1080)))
        throw(Error("Can't find the Asset file"));
    if (!T_logo.loadFromFile("./asset/test-logo.png", sf::IntRect(0, 0, 600, 400)))
        throw(Error("Can't find the Asset file"));
    sprite.setTexture(texture);
    logo.setTexture(T_logo);
    logo.setPosition(sf::Vector2f(660,0));

    QGame.setString("Choose You're Game");
    QGame.setFillColor(sf::Color::Green);
    QGame.setPosition(sf::Vector2f(620, 260));
    QGame.setFont(font);
    QGame.setCharacterSize(70);
    QGame.setStyle(sf::Text::Bold);

//    Game1.setString(Games);
    Game1.setFillColor(sf::Color::Green);
    Game1.setPosition(sf::Vector2f(0, 260));
    Game1.setFont(font);
    Game1.setCharacterSize(70);
    Game1.setStyle(sf::Text::Bold);

//    Game2.setString(Games.data.data);
    Game2.setFillColor(sf::Color::Green);
    Game2.setPosition(sf::Vector2f(260, 0));
    Game2.setFont(font);
    Game2.setCharacterSize(70);
    Game2.setStyle(sf::Text::Bold);

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    this->window.clear();
                    return "kill";
                }
            }
        }
        this->window.draw(sprite);
        this->window.draw(logo);
        this->window.draw(QGame);
        this->window.draw(Game1);
        this->window.draw(Game2);
        this->window.display();
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