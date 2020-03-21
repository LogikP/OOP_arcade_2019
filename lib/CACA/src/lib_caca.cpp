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

int libCaca::checkEvent(int quit, int &game)
{
    caca_event_t ev;
    unsigned int const event_mask = CACA_EVENT_KEY_PRESS
| CACA_EVENT_RESIZE | CACA_EVENT_MOUSE_PRESS | CACA_EVENT_QUIT;
    int event = caca_get_event(window.getDisplay(), event_mask, &ev, 0);

    while (event) {
        if (caca_get_event_type(&ev) & CACA_EVENT_KEY_PRESS) {
            switch (caca_get_event_key_ch(&ev)) {
                case 'q':
                case CACA_KEY_ESCAPE:
                    quit = 1;
                    break;
                case CACA_KEY_LEFT:
                case CACA_KEY_RIGHT:
                    game *= -1;
                    break;
            }
        } else if (caca_get_event_type(&ev) & CACA_EVENT_NONE)
            quit = 1;
        event = caca_get_event(window.getDisplay(), CACA_EVENT_KEY_PRESS, &ev, 0);
    }
    return quit;
}

void libCaca::displayGames(int &game)
{
    caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
    caca_put_str(window.getCanvas(), 27, 5, "Arcade Machines !");
    caca_put_str(window.getCanvas(), 20, 14, "-----------");
    caca_put_str(window.getCanvas(), 20, 15, "|");
    if (game == -1)
        caca_set_color_ansi(window.getCanvas(), CACA_RED, CACA_BLACK);
    else
        caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
    caca_put_str(window.getCanvas(), 21, 15, " NIBBLER ");
    caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
    caca_put_str(window.getCanvas(), 30, 15, "|");
    caca_put_str(window.getCanvas(), 20, 16, "-----------");
    caca_put_str(window.getCanvas(), 40, 14, "----------");
    caca_put_str(window.getCanvas(), 40, 15, "|");
    if (game == 1)
        caca_set_color_ansi(window.getCanvas(), CACA_RED, CACA_BLACK);
    else
        caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
    caca_put_str(window.getCanvas(), 41, 15, " PACMAN ");
    caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
    caca_put_str(window.getCanvas(), 49, 15, "|");
    caca_put_str(window.getCanvas(), 40, 16, "----------");
}

std::string libCaca::Menu(std::vector<std::pair<int,std::string>> Games)
{
    int game = -1;
    int quit = 0;

    while (!quit) {
        quit = checkEvent(quit, game);
        caca_clear_canvas(window.getCanvas());
        displayGames(game);
        caca_refresh_display(this->window.getDisplay());
    }
    return game == -1 ? "nibbler" : "pacman";
}

extern "C" libCaca *createDisplay() 
{
    return new libCaca;
}