/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MyWindow
*/

#include "MyWindowC.hpp"

MyWindowC::MyWindowC()
{
    caca_canvas_t *cv; caca_display_t *dp; caca_event_t ev;
    dp = caca_create_display(NULL);
    if(!dp) 
        return;
    cv = caca_get_canvas(dp);
    caca_set_display_title(dp, "Hello!");
    caca_set_color_ansi(cv, CACA_BLACK, CACA_WHITE);
    caca_put_str(cv, 0, 0, "This is a message");
    caca_refresh_display(dp);
    caca_get_event(dp, CACA_EVENT_KEY_PRESS, &ev, -1);
    caca_free_display(dp);
}

MyWindowC::~MyWindowC()
{
}
