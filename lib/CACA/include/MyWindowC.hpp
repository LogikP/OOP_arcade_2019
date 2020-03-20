/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MyWindow
*/

#pragma once
#include <caca.h>

class MyWindowC
{
    private:
    caca_display_t *window;
    caca_canvas_t *_cv;
    caca_display_t *_dp;

    public:
    MyWindowC();
    ~MyWindowC();
    caca_display_t *getDisplay();
    caca_canvas_t *getCanvas();
};