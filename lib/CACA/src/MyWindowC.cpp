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
    caca_set_display_title(_dp, "Hello!");
    caca_set_color_ansi(_cv, CACA_BLACK, CACA_WHITE);
    caca_put_str(_cv, 0, 0, "This is a message");
    caca_refresh_display(_dp);
    caca_get_event(_dp, CACA_EVENT_KEY_PRESS, &_ev, -1);
    caca_free_display(_dp);
}

MyWindowC::~MyWindowC()
{
}
