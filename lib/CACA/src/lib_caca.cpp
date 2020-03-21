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

int libCaca::checkEvent(int quit, int &game, int size)
{
    caca_event_t ev;
    unsigned int const event_mask = CACA_EVENT_KEY_PRESS
| CACA_EVENT_RESIZE | CACA_EVENT_MOUSE_PRESS | CACA_EVENT_QUIT;
    int event = caca_get_event(window.getDisplay(),  event_mask, &ev, 0);


    while (event) {
        if (caca_get_event_type(&ev) == CACA_EVENT_KEY_PRESS) {
            switch (caca_get_event_key_ch(&ev)) {
                case CACA_KEY_UP:
                    game = game == 0 ? (size - 1) : game - 1;
                    break;
                case CACA_KEY_DOWN:
                    game = game + 1 == size ? 0 : game + 1;
                    break;
                case 'q':
                case CACA_KEY_ESCAPE:
                    quit = 1;
                    break;
            }
            if (caca_get_event_type(&ev) & CACA_EVENT_QUIT)
                quit =1;
        }
        event = caca_get_event(window.getDisplay(), CACA_EVENT_KEY_PRESS, &ev, 0);
    }
    return quit;
}

std::string getSquare(int n)
{
    std::string tmp;
    int i;

    for (i = 0; i < n; tmp[i] = '-', i++);
    tmp[i] = 0;
    return tmp;
}

void libCaca::displayGames(int &game, std::string name)
{
    int size = name.size() / 2;
    int width = caca_get_canvas_width(window.getCanvas()) - size;
    int height = caca_get_canvas_height(window.getCanvas());
    std::string square = getSquare(name.size() + 4);

    caca_put_str(window.getCanvas(), width / 2 - size, (height / 2) - 1, square.c_str());
    caca_put_str(window.getCanvas(), width / 2 - size, height / 2, "| ");
    caca_set_color_ansi(window.getCanvas(), CACA_RED, CACA_BLACK);
    caca_put_str(window.getCanvas(), (width / 2 - size) + 2, height / 2, name.c_str());
    caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
    caca_put_str(window.getCanvas(), (width / 2 - size) + name.size() + 2, height / 2, " |");
    caca_put_str(window.getCanvas(), (width / 2 - size), (height / 2) + 1, square.c_str());
}

std::string libCaca::Menu(std::vector<std::pair<int,std::string>> Games)
{
    int game = Games[0].first;
    int quit = 0;

    while (!quit) {
        int width = caca_get_canvas_width(window.getCanvas());
        int height = caca_get_canvas_height(window.getCanvas());
        if ((quit = checkEvent(quit, game, Games.size())) == 1)
            return "kill";
        caca_clear_canvas(window.getCanvas());
        caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
        caca_put_str(window.getCanvas(), width / 2 - 8, height * 0.2, "Arcade Machines !");
        displayGames(game, Games[game].second);
        caca_refresh_display(this->window.getDisplay());
    }
    return "success";
}

extern "C" libCaca *createDisplay() 
{
    return new libCaca;
}