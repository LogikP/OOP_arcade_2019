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

std::vector<std::string> nibbler::getMap()
{
    static int init = 0;
    std::vector<std::string> map;
    std::ifstream in("./maps/nibbler-map.txt");
    std::string str;

    if (init == 0) {
        if (!in)
            std::cerr << "Cannot open the File : " << "nibbler-map.txt"<<std::endl;
        while (std::getline(in, str)) {
            if(str.size() > 0)
                map.push_back(str);
        }
        in.close();
        init++;
        _map = map;
        _snake.push_back(std::make_pair(1,3));
        _snake.push_back(std::make_pair(1,2));
        _snake.push_back(std::make_pair(1,1));
        _snake.push_back(std::make_pair(1,0));
    } else
        map = _map;
    return (map);
}

void nibbler::KeepMoving(int SaveLastKey)
{
    int x = GetX();
    int y = GetY();

    if (SaveLastKey == 1 && _map[x][y - 1] == ' ') {
        for (int i = _snake.size(); i != 0 ; i--) {
            _snake[i].first = _snake[i - 1].first;
            _snake[i].second = _snake[i - 1].second;
        }
        _snake[0].first = x;
        _snake[0].second = y - 1; 
        MoveSnakeBody();
    } else if (SaveLastKey == 2 && _map[x][y + 1] == ' ') {
        for (int i = _snake.size(); i != 0 ; i--) {
            _snake[i].first = _snake[i - 1].first;
            _snake[i].second = _snake[i - 1].second;
        }
        _snake[0].first = x;
        _snake[0].second = y + 1; 
        MoveSnakeBody();
    } else if (SaveLastKey == 3 && _map[x - 1][y] == ' ') {
        for (int i = _snake.size(); i != 0 ; i--) {
            _snake[i].first = _snake[i - 1].first;
            _snake[i].second = _snake[i - 1].second;
        }
        _snake[0].first = x - 1;
        _snake[0].second = y; 
        MoveSnakeBody();       
    } else if (SaveLastKey == 4 && _map[x + 1][y] == ' ') {
        for (int i = _snake.size(); i != 0 ; i--) {
            _snake[i].first = _snake[i - 1].first;
            _snake[i].second = _snake[i - 1].second;
        }
        _snake[0].first = x + 1;
        _snake[0].second = y; 
        MoveSnakeBody();
    }
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

    _map[_snake[0].first][_snake[0].second] = '0';
    for (; i != _snake.size() - 1; i++)
        _map[_snake[i].first][_snake[i].second] = 'o';
    _map[_snake[i].first][_snake[i].second] = ' ';
}

void nibbler::MovePlayer(int key)
{
    int x = GetX();
    int y = GetY();
    
    switch (key) {
        case 1:
            if (_map[x][y - 1] == ' ') {
                for (int i = _snake.size(); i != 0 ; i--) {
                    _snake[i].first = _snake[i - 1].first;
                    _snake[i].second = _snake[i - 1].second;
                }
                _snake[0].first = x;
                _snake[0].second = y - 1; 
                MoveSnakeBody();
            }
            break;
        case 2:
            if (_map[x][y + 1] == ' ') {
         for (int i = _snake.size(); i != 0 ; i--) {
         _snake[i].first = _snake[i - 1].first;
         _snake[i].second = _snake[i - 1].second;
     }          _snake[0].first = x;
                _snake[0].second = y + 1;
                MoveSnakeBody();
            }
            break;
        case 3:
         for (int i = _snake.size(); i != 0 ; i--) {
         _snake[i].first = _snake[i - 1].first;
         _snake[i].second = _snake[i - 1].second;
     }       if (_map[x - 1][y] == ' ') {
               _snake[0].first = x - 1;
                _snake[0].second = y;
                MoveSnakeBody();
            }
            break;
        case 4:
            if (_map[x + 1][y] == ' ') {
          for (int i = _snake.size(); i != 0 ; i--) {
         _snake[i].first = _snake[i - 1].first;
         _snake[i].second = _snake[i - 1].second;
     }         _snake[0].first = x + 1;
                _snake[0].second = y;
                MoveSnakeBody();
            }
            break;            
    }
    int i = 1;
}

//// For the dlsym Symbol /////
extern "C" nibbler *createGame()
{
    return new nibbler;
}