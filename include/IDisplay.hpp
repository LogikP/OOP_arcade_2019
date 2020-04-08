/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IDisplay
*/

#pragma once
#include <vector>
#include <string>
#include <memory>
#include <dlfcn.h>

class IDisplay {
    public:
        virtual ~IDisplay() {}
        virtual void initWindow() = 0;
        virtual void closeWindow() = 0;
        virtual void InitProg(std::vector<std::string>, std::vector<std::string>) = 0;
        virtual std::string MenuLib(std::vector<std::pair<int, std::string>>) = 0;
        virtual std::string Menu(std::vector<std::pair<int, std::string>>, std::vector<std::pair<int, std::string>>) = 0;
        virtual std::string Game() = 0;
        virtual int Pause() = 0;
        virtual int getEvent() = 0;
        virtual std::string gameOver() = 0;
        virtual std::string GetUsername() = 0;
        virtual void setName(std::string name) = 0;
};