/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MyWindow
*/

#include "MyWindowC.hpp"

MyWindowC::MyWindowC()
{
    _dp = caca_create_display(NULL);
    if(!_dp) 
        return;
    _cv = caca_get_canvas(_dp);
    caca_set_display_title(_dp, "Arcade");
    caca_set_color_ansi(_cv, CACA_BLACK, CACA_WHITE);
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