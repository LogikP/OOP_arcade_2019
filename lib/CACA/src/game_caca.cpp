/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** game_displayer_caca_lib
*/

#include <iostream>
#include "lib_caca.hpp"

int libCaca::checkEventGame(int quit)
{
    caca_event_t ev;
    unsigned int const event_mask = CACA_EVENT_KEY_PRESS
| CACA_EVENT_RESIZE | CACA_EVENT_MOUSE_PRESS | CACA_EVENT_QUIT;
    int event = caca_get_event(window.getDisplay(),  event_mask, &ev, 0);


    while (event) {
        if (caca_get_event_type(&ev) == CACA_EVENT_KEY_PRESS) {
            switch (caca_get_event_key_ch(&ev)) {
                case CACA_KEY_ESCAPE:
                    std::cout << "leave" << std::endl;
                    quit = QUIT;
                    break;
            }
            if (caca_get_event_type(&ev) & CACA_EVENT_QUIT) {
                quit = 1;
            }
        }
        event = caca_get_event(window.getDisplay(), CACA_EVENT_KEY_PRESS, &ev, 0);
    }
    return quit;
}

void libCaca::InitProg(std::vector<std::string> map)
{
    int quit = 0;

    caca_clear_canvas(window.getCanvas());
    for (int i = 0; i < (int)map.size(); i++) {
        for (int j = 0; j < (int)map[i].size(); j++) {
            if ((map[i][j] == '#')) {
                caca_set_color_ansi(window.getCanvas(), CACA_GREEN, CACA_BLACK);
                caca_put_str(window.getCanvas(), j, i, &(map[i].c_str())[j]);
                caca_set_color_ansi(window.getCanvas(), CACA_GREEN, CACA_BLACK);
            } else if (map[i][j] == 'W') {
                caca_set_color_ansi(window.getCanvas(), CACA_RED, CACA_BLACK);
                caca_put_str(window.getCanvas(), j, i, &(map[i].c_str())[j]);
                caca_set_color_ansi(window.getCanvas(), CACA_RED, CACA_BLACK);    
            } else
                caca_put_str(window.getCanvas(), j, i, &(map[i].c_str())[j]);
        }
    }
    caca_refresh_display(this->window.getDisplay());
    quit = checkEventGame(quit);
    if (quit == QUIT)
        exit(0);
}

int libCaca::getKeyEventGame(int quit)
{
    caca_event_t ev;
    unsigned int const event_mask = CACA_EVENT_KEY_PRESS
| CACA_EVENT_RESIZE | CACA_EVENT_MOUSE_PRESS | CACA_EVENT_QUIT;
    int event = caca_get_event(window.getDisplay(),  event_mask, &ev, 0);

    while (event) {
        if (caca_get_event_type(&ev) == CACA_EVENT_KEY_PRESS) {
            switch (caca_get_event_key_ch(&ev)) {
                case CACA_KEY_UP:
                    std::cout << "up" << std::endl;
                    quit = UP_KEY;
                    break;
                case CACA_KEY_DOWN:
                    quit = DOWN_KEY;
                    break;
                case CACA_KEY_LEFT:
                    quit = LEFT_KEY;
                    break;
                case CACA_KEY_RIGHT:
                    quit = RIGHT_KEY;
                    break;
            }
            if (caca_get_event_type(&ev) & CACA_EVENT_QUIT) {
                quit = 1;
            }
        }
        event = caca_get_event(window.getDisplay(), CACA_EVENT_KEY_PRESS, &ev, 0);
    }
    return quit;
}

int libCaca::getEventGame()
{
    int direction = -1;

    //caca_clear_canvas(window.getCanvas());
//    caca_refresh_display(this->window.getDisplay());
    direction = getKeyEventGame(direction);
    if (direction == UP_KEY)
        std::cout << "lol: " << direction << std::endl;
    return direction;
}

int libCaca::getEventCore()
{
    return 0;
}

std::string libCaca::Game()
{
    return "toto";
}

void libCaca::initWindow()
{
}