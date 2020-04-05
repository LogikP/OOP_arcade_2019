/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameInfo
*/

#include "GameCore.hpp"

std::vector<std::pair<int, std::string>> GameCore::GetGameName()
{
    std::vector<std::pair<int, std::string>> vec;
    std::string path = "./games/";
    std::string name;
    DIR* rep = opendir(path.c_str());
    int i = 0;

    if (not rep)
        throw(Error("Error, impossible to open the folder"));
    while (true) {
        struct dirent* ent = readdir(rep);
        if (not ent) break;
        name = ent->d_name;
        name = name.substr(name.find_last_of('_') + 1,
           name.find_last_of('.') - name.find_last_of('_') - 1);
        if (CheckIfLib(ent->d_name) == 1) {
            vec.push_back(std::make_pair(i, name));
            i++;
        // if (not ent) break;
        // if (ent->d_name[0] != '.') {
        //     vec.push_back(std::make_pair(i, ent->d_name));
        //     i++;
        // }
        }
    }
    return (vec);
}

void GameCore::GetHightScore(std::vector<std::string> score)
{
    if (atoi(score[0].c_str()) > atoi(score[1].c_str()) && this->Game->getMap()[0][0] == 'W') {
        remove("./maps/HightScore-nibbler.txt");
        std::ofstream MyFile("./maps/HightScore-nibbler.txt");
        MyFile << score[0].c_str();
        MyFile.close();
    }
    if (atoi(score[0].c_str()) > atoi(score[1].c_str()) && this->Game->getMap()[0][0] == 'M') {
        remove("./maps/HightScore-pacman.txt");
        std::ofstream MyFile("./maps/HightScore-pacman.txt");
        MyFile << score[0].c_str();
        MyFile.close();
    }
}

int isGame(std::string peakGame, std::vector<std::pair<int, std::string>> names)
{
    for (int i = 0; i < (int)names.size(); i++)
        if (peakGame.compare(names[i].second.c_str()) == 0)
            return 1;
    return 0;
}
