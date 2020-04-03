/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_ncurses
*/

#include "lib_sfml.hpp"

void LibSfml::initWindow()
{
    if (!this->Background.loadFromFile("./asset/arcade-backgrounds.jpg", sf::IntRect(0,0,1920, 1080)))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Background);
        ListSprite["Background"] = sprite;
        this->window.draw(ListSprite["Background"]);
    }
    if (!this->Wall_N.loadFromFile("./asset/assets-game/bric.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Wall_N);
        this->Wall_N.setSmooth(true);
        sprite.setScale(0.20, 0.20);
        ListSprite["WallNibbler"] = sprite;
    }
    if (!this->Nibbler_Head.loadFromFile("./asset/assets-game/head.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Nibbler_Head);
        this->Nibbler_Head.setSmooth(true);
        sprite.setScale(0.15, 0.15);
        ListSprite["Nibbler_Head"] = sprite;
    }
    if (!this->Nibbler_Tail.loadFromFile("./asset/assets-game/tail.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Nibbler_Tail);
        this->Nibbler_Tail.setSmooth(true);
        sprite.setScale(0.10, 0.10);
        ListSprite["Nibbler_Tail"] = sprite;
    }
    if (!this->Apple.loadFromFile("./asset/assets-game/apple.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Apple);
        this->Apple.setSmooth(true);
        sprite.setScale(0.10, 0.10);
        ListSprite["Apple"] = sprite;
    }
}

LibSfml::LibSfml() : window(sf::VideoMode(VideoMode.width, VideoMode.height, VideoMode.bitsPerPixel), "Arcade", sf::Style::Fullscreen)
{

}

sf::Text InitText(std::vector<std::pair<int,std::string>> Vector, int i, sf::Font font, sf::Vector2f vector2f)
{
    sf::Text tmp;

    tmp.setString(Vector[i].second);
    tmp.setFillColor(sf::Color::Green);
    tmp.setPosition(vector2f);
    tmp.setFont(font);
    tmp.setCharacterSize(150);
    tmp.setStyle(sf::Text::Bold);
    return tmp;
}

void LibSfml::SetSpritePos(std::string Name, int LenLine, int pos1, int pos2)
{
    this->ListSprite[Name].setPosition(this->window.getSize().x / 2 - (LenLine * 10) + pos2 * 20, this->window.getSize().y / 8 + pos1 * 20);
    this->window.draw(this->ListSprite[Name]);
}

void LibSfml::DrawMap(std::vector<std::string> map)
{
    int pos1 = 0;
    int pos2 = 0;
    int lenLine = map[0].length();

    for (std::string str : map) {
        pos2 = 0;
        for (char c : str) {
            switch (c)
            {
                case 'W':
                    SetSpritePos("WallNibbler", lenLine, pos1, pos2);
                    break;
                case 'x':
                    SetSpritePos("Apple", lenLine, pos1,pos2);
                    break;
                case 'o':
                    SetSpritePos("Nibbler_Tail", lenLine, pos1, pos2);
                    break;
                case '0':
                    SetSpritePos("Nibbler_Head", lenLine, pos1, pos2);
                    break;
            }
            pos2++;
        }
        pos1++;
    }

}

void LibSfml::InitProg(std::vector<std::string> map, std::vector<std::string> score)
{
    this->window.clear();
    this->_map = map;
    this->_score = score;
    if (this->window.isOpen())
        DrawMap(map);
    usleep(100000);
    this->window.display();
}

int LibSfml::getEvent()
{
    return this->bind();
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