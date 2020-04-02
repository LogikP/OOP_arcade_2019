/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_ncurses
*/

#include "lib_sfml.hpp"

void LibSfml::initWindow()
{
    sf::FloatRect Rect;
    if (!this->Background.loadFromFile("./asset/arcade-backgrounds.jpg", sf::IntRect(0,0,1920, 1080)))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Background);
        Rect = sprite.getGlobalBounds();
        ListSprite["Background"] = sprite;
        this->window.draw(ListSprite["Background"]);
    }
    if (!this->Wall_N.loadFromFile("./asset/assets-game/bric.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Wall_N);
        Rect = sprite.getGlobalBounds();
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
        Rect = sprite.getGlobalBounds();
        ListSprite["Nibbler_Head"] = sprite;
    }
    if (!this->Nibbler_Tail.loadFromFile("./asset/assets-game/tail.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Nibbler_Tail);
        this->Nibbler_Tail.setSmooth(true);
        sprite.setScale(0.10, 0.10);
        Rect = sprite.getGlobalBounds();
        ListSprite["Nibbler_Tail"] = sprite;
    }
    if (!this->Apple.loadFromFile("./asset/assets-game/apple.bmp"))
        throw(Error("Can't find the Asset file"));
    else {
        sf::Sprite sprite;
        sprite.setTexture(this->Apple);
        this->Apple.setSmooth(true);
        sprite.setScale(0.10, 0.10);
        Rect = sprite.getGlobalBounds();
        ListSprite["Apple"] = sprite;
    }
}

LibSfml::LibSfml() : window(sf::VideoMode(VideoMode.width, VideoMode.height, VideoMode.bitsPerPixel), "Arcade", sf::Style::Fullscreen)
{

}

// void LibSfml::DrawSprite(sf::Sprite sprite)
// {
//     this->window.draw(sprite);
// }


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

std::string LibSfml::MenuLib(std::vector<std::pair<int, std::string>> Libs)
{
    this->window.clear();
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Sprite logo;
    sf::Texture T_logo;
    sf::Text Lib1;
    sf::Text Lib2;
    sf::Text Lib3;
    sf::Font font;
    sf::Event event;
    int i = 0;

    if (!font.loadFromFile("./asset/Test-Font.ttf"))
        throw(Error("Can't find the Font file"));
    if (!texture.loadFromFile("./asset/arcade-backgrounds.jpg", sf::IntRect(0,0,1920, 1080)))
        throw(Error("Can't find the Asset file"));
    if (!T_logo.loadFromFile("./asset/test-logo.png", sf::IntRect(0, 0, 600, 400)))
        throw(Error("Can't find the Asset file"));
    sprite.setTexture(texture);
    logo.setTexture(T_logo);
    logo.setPosition(sf::Vector2f(660,0));

    Lib1.setString(Libs[0].second);
    Lib1.setFillColor(sf::Color::Green);
    Lib1.setPosition(sf::Vector2f(200, 400));
    Lib1.setFont(font);
    Lib1.setCharacterSize(150);
    Lib1.setStyle(sf::Text::Bold);

    Lib2.setString(Libs[1].second);
    Lib2.setFillColor(sf::Color::Green);
    Lib2.setPosition(sf::Vector2f(1200, 400));
    Lib2.setFont(font);
    Lib2.setCharacterSize(150);
    Lib2.setStyle(sf::Text::Bold);

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
                if (event.key.code == sf::Keyboard::Right)
                {
                    Lib2.setFillColor(sf::Color::Blue);
                    Lib1.setFillColor(sf::Color::Green);
                    i = 0;
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    Lib1.setFillColor(sf::Color::Blue);
                    Lib2.setFillColor(sf::Color::Green);
                    i = 1;
                }
                if (event.key.code == sf::Keyboard::Enter && i == 0)
                {
                    this->window.clear();
                    return Libs[1].second;
                }
                if ( event.key.code == sf::Keyboard::Enter && i == 1)
                {
                    this->window.clear();
                    return Libs[0].second;
                }
            }
        }
        this->window.clear();
        this->window.draw(sprite);
        this->window.draw(logo);
        this->window.draw(Lib1);
        this->window.draw(Lib2);
        this->window.display();
    }
    return "toto";
}

std::string getNextLib(std::vector<std::pair<int, std::string>> libs)
{
    int i = 0;
    for (; i < (int)libs.size() && libs[i].second.compare("sfml") <= 0; i++);
    i = i == (int)libs.size() ? 0 : i;
    return libs[i].second;
}

std::string getPrevLib(std::vector<std::pair<int, std::string>> libs)
{
    int i = libs.size() - 1;
    for (; i > 0 && libs[i].second.compare("sfml") >= 0; i--);
    return libs[i].second;
}

std::string LibSfml::Menu(std::vector<std::pair<int, std::string>> Games, std::vector<std::pair<int, std::string>> Libs)
{
    this->window.clear();
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Sprite logo;
    sf::Texture T_logo;
    sf::Text Game1;
    sf::Text Game2;
    sf::Font font;
    int i = 0;

    if (!font.loadFromFile("./asset/Test-Font.ttf"))
        throw(Error("Can't find the Font file"));
    if (!texture.loadFromFile("./asset/arcade-backgrounds.jpg", sf::IntRect(0,0,1920, 1080)))
        throw(Error("Can't find the Asset file"));
    if (!T_logo.loadFromFile("./asset/test-logo.png", sf::IntRect(0, 0, 600, 400)))
        throw(Error("Can't find the Asset file"));
    sprite.setTexture(texture);
    logo.setTexture(T_logo);
    logo.setPosition(sf::Vector2f(660,0));

    Game1.setString(Games.front().second);
    Game1.setFillColor(sf::Color::Green);
    Game1.setPosition(sf::Vector2f(200, 400));
    Game1.setFont(font);
    Game1.setCharacterSize(150);
    Game1.setStyle(sf::Text::Bold);

    Game2.setString(Games.back().second);
    Game2.setFillColor(sf::Color::Green);
    Game2.setPosition(sf::Vector2f(1200, 400));
    Game2.setFont(font);
    Game2.setCharacterSize(150);
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
                if (event.key.code == sf::Keyboard::Right)
                {
                    Game2.setFillColor(sf::Color::Blue);
                    Game1.setFillColor(sf::Color::Green);
                    i = 0;
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    Game1.setFillColor(sf::Color::Blue);
                    Game2.setFillColor(sf::Color::Green);
                    i = 1;
                }
                if (event.key.code == sf::Keyboard::N)
                    return Libs.size() == 0 ? "sfml" : getNextLib(Libs);
                if (event.key.code == sf::Keyboard::L)
                    return "ChangedLib";
                if (event.key.code == sf::Keyboard::P)
                    return Libs.size() == 0 ? "sfml" : getPrevLib(Libs);
                if (event.key.code == sf::Keyboard::Enter && i == 0)
                {
                    this->window.clear();
                    return Games.back().second;
                }
                else if ( event.key.code == sf::Keyboard::Enter && i == 1)
                {
                    this->window.clear();
                    return Games.front().second;
                }
            }
        }
        this->window.clear();
        this->window.draw(sprite);
        this->window.draw(logo);
        this->window.draw(Game1);
        this->window.draw(Game2);
        this->window.display();
    }
    return "success";
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
    static int i = 0;

    for (std::string i : map) {
        pos2 = 0;
        for (char c : i) {
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

void LibSfml::InitProg(std::vector<std::string> map)
{
    this->window.clear();
    this->_map = map;
    if (this->window.isOpen())
        DrawMap(map);
    usleep(100000);
    this->window.display();
}

int LibSfml::getEvent()
{
    return this->bind();
//    return 0;
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