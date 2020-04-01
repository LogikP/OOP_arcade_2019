/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** game_displayer_caca_lib
*/

#include "lib_caca.hpp"

int libCaca::InitProg(std::vector<std::string> map)
{
    caca_clear_canvas(window.getCanvas());
    caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
    for (int i = 0; i < (int)map.size(); i++)
        caca_put_str(window.getCanvas(), 0, i, map[i].c_str());
    caca_refresh_display(this->window.getDisplay());
    return 0;
}

int libCaca::checkEventGame(int quit)
{
    caca_event_t ev;
    unsigned int const event_mask = CACA_EVENT_KEY_PRESS
| CACA_EVENT_RESIZE | CACA_EVENT_MOUSE_PRESS | CACA_EVENT_QUIT;
    int event = caca_get_event(window.getDisplay(),  event_mask, &ev, 0);


    while (event) {
        if (caca_get_event_type(&ev) == CACA_EVENT_KEY_PRESS) {
            switch (caca_get_event_key_ch(&ev)) {
                case CACA_KEY_RETURN:
                    quit = GAME;
                    break;
                    break;
                case 'l':
                    quit = 4;
                    break;
                case CACA_KEY_ESCAPE:
                    quit = QUIT;
                    break;
            }
            if (caca_get_event_type(&ev) & CACA_EVENT_QUIT)
                quit = QUIT;
        }
        event = caca_get_event(window.getDisplay(), CACA_EVENT_KEY_PRESS, &ev, 0);
    }
    return quit;
}

std::string libCaca::Game()
{
    int quit = 0;

    caca_set_display_title(window.getDisplay(), "Arcade");
    caca_set_color_ansi(window.getCanvas(), CACA_BLACK, CACA_WHITE);
    while (quit != LIB || quit != QUIT || quit != GAME || quit != 4) {
        quit = this->checkEventGame(quit);
        if (quit == QUIT)
            return "kill";
        caca_clear_canvas(window.getCanvas());
        caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
        caca_refresh_display(this->window.getDisplay());
    }
    return "success";
}

void libCaca::initWindow()
{
    caca_set_display_title(window.getDisplay(), "Pacman");
}
