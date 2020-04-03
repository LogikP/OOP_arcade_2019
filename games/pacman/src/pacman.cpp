/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** pacman
*/

#include "pacman.hpp"

pacman::pacman()
{
    _init = 0;
    _score.push_back("0");
    _score.push_back("0");
}

void pacman::InitMap()
{

}

std::string pacman::getName() const
{
    return "Pacman";
}

std::vector<std::string> pacman::getScore() const
{
    return _score;
}

std::vector<std::string> pacman::getMap()
{
    std::vector<std::string> map;
    std::ifstream in("./maps/pacman-map-1.txt");
    std::string str;

    if (_init == 0) {
        if (!in)
            std::cerr << "Cannot open the File : " << "pacman-map-1.txt"<<std::endl;
        while (std::getline(in, str)) {
            if(str.size() > 0)
                map.push_back(str);
        }
        in.close();
        _init = 1;
        _map = map;
    } else
        map = _map;
    return (map);
}

void pacman::KeepMoving(int SaveLastKey)
{
    int x = GetX();
    int y = GetY();

    if (SaveLastKey == 1 && (_map[x][y - 1] == ' ' || _map[x][y - 1] == '.')) {
        if (_map[x][y - 1] == '.')
            _score[0] = std::to_string(std::atoi(_score[0].c_str()) + 10);        
        _map[x][y - 1] = 'C';
        _map[x][y] = ' ';
    } else if (SaveLastKey == 2 && (_map[x][y + 1] == ' ' || _map[x][y + 1] == '.')) {
        if (_map[x][y + 1] == '.')
            _score[0] = std::to_string(std::atoi(_score[0].c_str()) + 10);        
        _map[x][y + 1] = 'C';
        _map[x][y] = ' ';
    } else if (SaveLastKey == 3 && (_map[x - 1][y] == ' ' || _map[x - 1][y] == '.')) {
        if (_map[x - 1][y] == '.')
            _score[0] = std::to_string(std::atoi(_score[0].c_str()) + 10);        
        _map[x - 1][y] = 'C';
        _map[x][y] = ' ';
    } else if (SaveLastKey == 4 && (_map[x + 1][y] == ' ' || _map[x +1][y] == '.')) {
        if (_map[x + 1][y] == '.')
            _score[0] = std::to_string(std::atoi(_score[0].c_str()) + 10);        
        _map[x + 1][y] = 'C';
        _map[x][y] = ' ';
    }/* else if (press == 1)
        deadSnake();*/
}

void pacman::MovePlayer(int key)
{
    int x = GetX();
    int y = GetY();

    if (y == 0 || x == 0)
        return ;
    switch (key) {
        case 1:
            if (_map[x][y - 1] == ' ' || _map[x][y - 1] == '.') {
                _map[x][y - 1] = 'C';
                _map[x][y] = ' ';
            }
            break;
        case 2:
            if (_map[x][y + 1] == ' ' || _map[x][y + 1] == '.') {
                _map[x][y + 1] = 'C';
                _map[x][y] = ' ';
            }
            break;
        case 3:
            if (_map[x - 1][y] == ' '  || _map[x - 1][y] == '.') {
                _map[x - 1][y] = 'C';
                _map[x][y] = ' ';
            }
            break;
        case 4:
            if (_map[x + 1][y] == ' '  || _map[x + 1][y] == '.') {
                _map[x + 1][y] = 'C';
                _map[x][y] = ' ';
            }
            break;
    }
}

int pacman::ReceiveEvent(int key, int toto)
{
    (void)toto;
    switch (key)
    {
        case 1:
            if (SaveLastKey != 2) {
                MovePlayer(key);
                SaveLastKey = 1;
            }
            break;
        case 2:
            if (SaveLastKey != 1) {
                MovePlayer(key);
                SaveLastKey = 2;
            }
            break;
        case 3:
            if (SaveLastKey != 4) {
                MovePlayer(key);
                SaveLastKey = 3;
            }
            break;
        case 4:
            if (SaveLastKey != 3) {
                MovePlayer(key);
                SaveLastKey = 4;
            }
            break;
        case -1:
            KeepMoving(SaveLastKey);
            break;

    }
    return 0;
}

int pacman::GetX()
{
    for (unsigned int i = 0; i != _map.size(); i++) {
        for (int a = 0; _map[i][a] != '\n' && _map[i][a]; a++)
            if (_map[i][a] == 'C')
                return (i);
    }
    return (0);
}

int pacman::GetY()
{
    for (unsigned int i = 0; i != _map.size(); i++) {
        for (int a = 0; _map[i][a] != '\n' && _map[i][a]; a++)
            if (_map[i][a] == 'C')
                return (a);
    }
    return (0);
}

void pacman::saveGame(std::string map)
{

}

//// For the dlsym Symbol /////
extern "C" pacman *createGame()
{
    return new pacman;
}