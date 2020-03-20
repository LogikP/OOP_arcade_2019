/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_caca
*/

#pragma once
#include "../../../include/IDisplay.hpp"
#include "MyWindowC.hpp"

class Display : public IDisplay
{
    private:
        MyWindowC window;
    public:
        Display();
        void initWindow() final;
        void closeWindow() final;
        std::string Game() final;
        int InitProg() final;
        std::string Menu(std::vector<std::pair<int, std::string>>) final;
};