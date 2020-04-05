/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MyWindow
*/

#include <iostream>
#include "MyWindowC.hpp"

MyWindowC::MyWindowC()
{
    _cv = caca_create_canvas(0, 0);
    if (!_cv)
        return;
    _dp = caca_create_display(_cv);
    if(!_dp)
        return;
}

MyWindowC::~MyWindowC()
{
    caca_free_display(_dp);
    caca_free_canvas(_cv);
}

caca_display_t *MyWindowC::getDisplay()
{
    return _dp;
}

caca_canvas_t *MyWindowC::getCanvas()
{
    return _cv;
}