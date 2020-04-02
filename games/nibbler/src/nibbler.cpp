/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nibbler
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "nibbler.hpp"

nibbler::nibbler()
{
    _food = 0;
    _init = 0;
   // _NibblerBody.push_back(std::make_pair(2,2));
    //_NibblerBody.push_back(std::make_pair(2,3));
}
/*
int nibbler::GetNibblerSize()
{
    return (_NibblerBody.size());
}

std::vector<std::pair<int,int>> nibbler::GetNibblerBody()
{
    return (_NibblerBody);
}*/

void nibbler::InitMap()
{
}

std::string nibbler::getName() const
{
    return "toto";
}

void nibbler::addFood()
{
    int i = 0;
    int j = 0;

    srand(time(NULL));
    i += rand() % (_map.size() - 2) + 1;
    j += rand() % (_map[0].size() - 2) + 1;
    if (_map[i][j] == ' ') {
        _map[i][j] = 'x';
        _food += 1;
    } else
        addFood();
}
void nibbler::initSnake()
{
    press = 0;
    _snakeSize = 3;
    _snake.push_back(std::make_pair(1,3));
    _snake.push_back(std::make_pair(1,2));
    _snake.push_back(std::make_pair(1,1));
    _snake.push_back(std::make_pair(1,0));
}

void nibbler::deadSnake()
{
    _snake.clear();
    initSnake();
    for (int i = 1; i != (int)_map.size() - 1; i++) {
        for (int j = 1; j != (int)_map[0].size() - 2; j++) {
            if (_map[i][j] == 'o' || _map[i][j] == '0' || _map[i][j] == 'x')
                _map[i][j] = ' ';
        }
    }
    _map[1][1] = 'o';
    _map[1][2] = 'o';
    _map[1][3] = '0';
    _food = 0;
}

std::vector<std::string> nibbler::getMap()
{
    std::vector<std::string> map;
    std::ifstream in("./maps/nibbler-map.txt");
    std::string str;

    if (_init == 0) {
        if (!in)
            std::cerr << "Cannot open the File : " << "nibbler-map.txt"<<std::endl;
        while (std::getline(in, str)) {
            if(str.size() > 0)
                map.push_back(str);
        }
        in.close();
        _init = 1;
        _map = map;
        initSnake();
    } else
        map = _map;
    if (_food == 0)
        addFood();
    return (map);
}

void nibbler::KeepMoving(int SaveLastKey)
{
    int x = GetX();
    int y = GetY();

    if (SaveLastKey == 1 && (_map[x][y - 1] == ' ' || _map[x][y - 1] == 'x' || _map[x][y - 1] == 'o')) {
        if (_map[x][y - 1] == 'o')
            return;
        for (int i = _snake.size(); i != 0 ; i--) {
            _snake[i].first = _snake[i - 1].first;
            _snake[i].second = _snake[i - 1].second;
        }
        _snake[0].first = x;
        _snake[0].second = y - 1; 
        MoveSnakeBody();
    } else if (SaveLastKey == 2 && (_map[x][y + 1] == ' ' || _map[x][y + 1] == 'x' || _map[x][y + 1] == 'o')) {
            if (_map[x][y + 1] == 'o')
                return;
            for (int i = _snake.size(); i != 0 ; i--) {
            _snake[i].first = _snake[i - 1].first;
            _snake[i].second = _snake[i - 1].second;
        }
        _snake[0].first = x;
        _snake[0].second = y + 1; 
        MoveSnakeBody();
    } else if (SaveLastKey == 3 && (_map[x - 1][y] == ' ' || _map[x - 1][y] == 'x' || _map[x - 1][y] == 'o')) {
        if (_map[x - 1][y] == 'o')
            return;
        for (int i = _snake.size(); i != 0 ; i--) {
            _snake[i].first = _snake[i - 1].first;
            _snake[i].second = _snake[i - 1].second;
        }
        _snake[0].first = x - 1;
        _snake[0].second = y; 
        MoveSnakeBody();       
    } else if (SaveLastKey == 4 && (_map[x + 1][y] == ' ' | _map[x + 1][y] == 'x' || _map[x + 1][y] == 'o')) {
        if (_map[x + 1][y] == 'o')
            return;
        for (int i = _snake.size(); i != 0 ; i--) {
            _snake[i].first = _snake[i - 1].first;
            _snake[i].second = _snake[i - 1].second;
        }
        _snake[0].first = x + 1;
        _snake[0].second = y; 
        MoveSnakeBody();
    } else if (press == 1)
        deadSnake();
}

int nibbler::ReceiveEvent(int key, int toto)
{
    switch (key)
    {
        case 1:
            MovePlayer(key);
            SaveLastKey = 1;
            break;
        case 2:
            MovePlayer(key);
            SaveLastKey = 2;
            break;
        case 3:
            MovePlayer(key);
            SaveLastKey = 3;
            break;
        case 4:
            MovePlayer(key);
            SaveLastKey = 4;
            break;
        case -1:
            KeepMoving(SaveLastKey);
            break;

    }
    return 0;
}

void nibbler::saveGame(std::string map)
{

}

int nibbler::GetX()
{
    for (unsigned int i = 0; i != _map.size(); i++) {
        for (int a = 0; _map[i][a] != '\n' && _map[i][a]; a++)
            if (_map[i][a] == '0')
                return (i);
    }
    return (0);
}

int nibbler::GetY()
{
    for (unsigned int i = 0; i != _map.size(); i++) {
        for (int a = 0; _map[i][a] != '\n' && _map[i][a]; a++)
            if (_map[i][a] == '0')
                return (a);
    }
    return (0);
}

void nibbler::MoveSnakeBody()
{
    int i = 1;

    if (_map[_snake[0].first][_snake[0].second] == 'x') {
        _food -= 1;
        _snakeSize++;
        _snake.push_back(std::make_pair(1,_snakeSize));
    }
    _map[_snake[0].first][_snake[0].second] = '0';
    for (; i != _snake.size() - 1; i++)
        _map[_snake[i].first][_snake[i].second] = 'o';
    _map[_snake[i].first][_snake[i].second] = ' ';
}

void nibbler::MovePlayer(int key)
{
    int x = GetX();
    int y = GetY();

    press = 1;
    switch (key) {
        case 1:
            if (_map[x][y - 1] == ' ' || _map[x][y - 1] == 'x') {
                for (int i = _snake.size(); i != 0 ; i--) {
                    _snake[i].first = _snake[i - 1].first;
                    _snake[i].second = _snake[i - 1].second;
                }
                _snake[0].first = x;
                _snake[0].second = y - 1; 
                MoveSnakeBody();
            } else
                deadSnake();
            break;
        case 2:
            if (_map[x][y + 1] == ' ' || _map[x][y + 1] == 'x') {
         for (int i = _snake.size(); i != 0 ; i--) {
         _snake[i].first = _snake[i - 1].first;
         _snake[i].second = _snake[i - 1].second;
     }          _snake[0].first = x;
                _snake[0].second = y + 1;
                MoveSnakeBody();
            } else
                deadSnake();
            break;
        case 3:
         for (int i = _snake.size(); i != 0 ; i--) {
         _snake[i].first = _snake[i - 1].first;
         _snake[i].second = _snake[i - 1].second;
     }       if (_map[x - 1][y] == ' ' || _map[x - 1][y] == 'x') {
               _snake[0].first = x - 1;
                _snake[0].second = y;
                MoveSnakeBody();
            } else
                deadSnake();
            break;
        case 4:
            if (_map[x + 1][y] == ' ' || _map[x + 1][y] == ' ') {
          for (int i = _snake.size(); i != 0 ; i--) {
         _snake[i].first = _snake[i - 1].first;
         _snake[i].second = _snake[i - 1].second;
     }         _snake[0].first = x + 1;
                _snake[0].second = y;
                MoveSnakeBody();
            } else
                deadSnake();
            break;            
    }
}

//// For the dlsym Symbol /////
extern "C" nibbler *createGame()
{
    return new nibbler;
}