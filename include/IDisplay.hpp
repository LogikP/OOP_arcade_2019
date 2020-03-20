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
        virtual int InitProg() = 0;
        virtual std::string Menu() = 0;
        //virtual std::string end(std::string) = 0;
        virtual std::string Game() = 0;
};
