/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** pacman
*/

#include <ctime>
#include <chrono>
#include <iomanip>
#include "pacman.hpp"

pacman::pacman()
{
    _init = 0;
    std::ifstream in("./maps/HightScore-pacman.txt");
    std::string str;

    _score.push_back("0");
    if (!in)
        std::cerr << "Cannot open the File : " << "nibbler-map.txt"<<std::endl;
    while (std::getline(in, str)) {
        if(str.size() > 0)
            _score.push_back(str);
    }
    in.close();
    isEatable = false;
}

void pacman::InitMap()
{

}

bool pacman::Loose()
{
    return false;
}

std::string pacman::getName() const
{
    return "Pacman";
}

std::vector<std::string> pacman::getScore() const
{
    return _score;
}

bool isFoodLeft(std::vector<std::string> map)
{
    for (int i = 0; (size_t)i != map.size() - 1; i++) {
        for (int j = 0; (size_t)j != map[i].size() - 1; j++)
            if (map[i][j] == '.')
                return true;
    }
    return false;
}

void pacman::MakeGhostEatable()
{
    for (std::string str : _map) {
        for (char c : str) {
            if (c == 'G' || c == 'H' || c == 'T' || c == 'U')
                c += 32;
        }
    }
}

void pacman::MakeGhostNoEatable()
{
    for (std::string str : _map) {
        for (char c : str) {
            if (c == 'G' || c == 'H' || c == 'T' || c == 'U')
                c -= 32;
        }
    }
}


std::vector<std::string> pacman::getMap()
{
    std::vector<std::string> map;
    std::ifstream in("./maps/pacman-map-1.txt");
    std::string str;
    std::clock_t time = 0;

    if (isEatable == true) {
        time = std::clock();
        MakeGhostEatable();
    }
    else
        MakeGhostNoEatable();
    if (15000 <= double(time) / CLOCKS_PER_SEC)
        isEatable = false;
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
    if (isFoodLeft(map) == false) {
        SaveLastKey = -1;
        _init = 0;
    }
    return (map);
}

void pacman::KeepMoving(int SaveLastKey)
{
    int x = GetX();
    int y = GetY();

    if (SaveLastKey == 1 && _map[x][y - 1] != 'M') {
        if (y - 1 >= 0 && (_map[x][y - 1] == '.' || _map[x][y - 1] == 'I' || _map[x][y - 1] == 'F')) {
            _score[0] = std::to_string(std::atoi(_score[0].c_str()) + 10);
            if (_map[x][y - 1] == 'F')
                isEatable = true;
        }
        if (isEatable != true && (_map[x][y - 1] == 'G' || _map[x][y - 1] == 'U' || _map[x][y - 1] == 'H' || _map[x][y - 1] == 'T'))
            return;
        if (y - 1 >= 0)
            _map[x][y - 1] = 'A';
        else
            _map[x][_map[x].size() - 1] = 'A';
        _map[x][y] = ' ';
    } else if (SaveLastKey == 2 && _map[x][y + 1] != 'M') {
        if ((size_t)(y + 1) < _map[x].size() && (_map[x][y + 1] == '.' || _map[x][y + 1] == 'I' ||  _map[x][y + 1] == 'F')) {
            _score[0] = std::to_string(std::atoi(_score[0].c_str()) + 10);
            if (_map[x][y - 1] == 'F')
                isEatable = true;
        }
        if (isEatable != true && (_map[x][y + 1] == 'G' || _map[x][y + 1] == 'U' || _map[x][y + 1] == 'H' || _map[x][y + 1] == 'T'))
            return;
        if ((size_t)(y + 1) >= _map[x].size())
            _map[x][0] = 'C';
        else
            _map[x][y + 1] = 'C';
        _map[x][y] = ' ';
    } else if (SaveLastKey == 3 && _map[x - 1][y] != 'M') {
        if (_map[x - 1][y] == '.' || _map[x - 1][y] == 'I' || _map[x - 1][y] == 'F') {
            _score[0] = std::to_string(std::atoi(_score[0].c_str()) + 10);
            if (_map[x - 1][y] == 'F')
                isEatable = true;
        }
        if (isEatable != true && (_map[x - 1][y] == 'G' || _map[x - 1][y] == 'U' || _map[x - 1][y] == 'H' || _map[x - 1][y] == 'T'))
            return ;
        _map[x - 1][y] = 'B';
        _map[x][y] = ' ';
    } else if (SaveLastKey == 4 && _map[x + 1][y] != 'M') {
        if (_map[x + 1][y] == '.' || _map[x + 1][y] == 'I' || _map[x + 1][y] == 'F') {
            _score[0] = std::to_string(std::atoi(_score[0].c_str()) + 10);
            if (_map[x + 1][y] == 'F')
                isEatable = true;
        }
        if (isEatable != true && (_map[x + 1][y] == 'G' || _map[x + 1][y] == 'U' || _map[x + 1][y] == 'H' || _map[x + 1][y] == 'T'))
            return;
        _map[x + 1][y] = 'D';
        _map[x][y] = ' ';
    }
}

void pacman::MoveGhost()
{

}

void pacman::MovePlayer(int key)
{
    int x = GetX();
    int y = GetY();

    if (y == 0 || x == 0)
        return ;
    switch (key) {
        case 1:
            if (_map[x][y - 1] != 'M' || y - 1 == -1) {
                if (isEatable != true && (_map[x][y - 1] == 'G' || _map[x][y - 1] == 'U' || _map[x][y - 1] == 'H' || _map[x][y - 1] == 'T'))
                    return;
                if (y - 1 >= 0)
                    _map[x][y - 1] = 'A';
                else
                    _map[x][_map[x].size() - 1] = 'A';
                _map[x][y] = ' ';
            }
            break;
        case 2:
             if (_map[x][y + 1] != 'M' || (size_t)(y + 1) == _map[x].size()) {
                if (isEatable != true && (_map[x][y + 1] == 'G' || _map[x][y + 1] == 'U' || _map[x][y + 1] == 'H' || _map[x][y + 1] == 'T'))
                    return;
                if ((size_t)(y + 1) >= _map[x].size())
                    _map[x][0] = 'C';
                else
                    _map[x][y + 1] = 'C';
                _map[x][y] = ' ';
            }
            break;
        case 3:
             if (_map[x - 1][y] != 'M' ) {
                if (isEatable != true && (_map[x - 1][y] == 'G' || _map[x - 1][y] == 'U' || _map[x - 1][y] == 'H' || _map[x - 1][y] == 'T'))
                    return;
                _map[x - 1][y] = 'B';
                _map[x][y] = ' ';
            }
            break;
        case 4:
             if (_map[x + 1][y] != 'M' ) {
                if (isEatable != true && (_map[x + 1][y] == 'G' || _map[x + 1][y] == 'U' || _map[x + 1][y] == 'H' || _map[x + 1][y] == 'T'))
                    return;
                _map[x + 1][y] = 'D';
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

int pacman::GetX()
{
    for (unsigned int i = 0; i != _map.size(); i++) {
        for (int a = 0; _map[i][a] != '\n' && _map[i][a]; a++)
            if (_map[i][a] == 'C' || _map[i][a] == 'A' || _map[i][a] == 'B' || _map[i][a] == 'D')
                return (i);
    }
    return (0);
}

int pacman::GetY()
{
    for (unsigned int i = 0; i != _map.size(); i++) {
        for (int a = 0; _map[i][a] != '\n' && _map[i][a]; a++)
            if (_map[i][a] == 'C' || _map[i][a] == 'A' || _map[i][a] == 'B' || _map[i][a] == 'D')
                return (a);
    }
    return (0);
}

void pacman::saveGame(std::string map)
{
    map = "toto";
}

//// For the dlsym Symbol /////
extern "C" pacman *createGame()
{
    return new pacman;
}