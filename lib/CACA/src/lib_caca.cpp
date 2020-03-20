/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_caca
*/

#include "lib_caca.hpp"

libCaca::libCaca() : window()
{

}

void libCaca::closeWindow()
{
    return;
}

int libCaca::InitProg()
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

std::string libCaca::Menu(std::vector<std::pair<int,std::string>> Games)
{
    int quit = 0;
    unsigned int const event_mask = CACA_EVENT_KEY_PRESS
| CACA_EVENT_RESIZE | CACA_EVENT_MOUSE_PRESS | CACA_EVENT_QUIT;

    while (!quit) {
        caca_event_t ev;
        int event = caca_get_event(window.getDisplay(), event_mask, &ev, -1);
        caca_put_str(window.getCanvas(), 0, 0, "This is a message");
        while (event) {
            if (caca_get_event_type(&ev) & CACA_EVENT_KEY_PRESS) {
                switch (caca_get_event_key_ch(&ev)) {
                    case 'q':
                    case CACA_KEY_ESCAPE:
                        quit = 1;
                        break;
                }
            } else if (caca_get_event_type(&ev) & CACA_EVENT_NONE)
                quit = 1;
            event = caca_get_event(window.getDisplay(), CACA_EVENT_KEY_PRESS, &ev, 0);
        }
        caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
        caca_clear_canvas(window.getCanvas());
        caca_refresh_display(this->window.getDisplay());
    }
    return quit == 0 ? "success" : "kill";
}

extern "C" libCaca *createDisplay() 
{
    return new libCaca;
}