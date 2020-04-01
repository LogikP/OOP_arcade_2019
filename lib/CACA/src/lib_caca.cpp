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
    caca_free_display(window.getDisplay());
    caca_free_canvas(window.getCanvas());
    return;
}

std::string getSquare(int n)
{
    std::string tmp;
    int i;

    for (i = 0; i < n; tmp[i] = '-', i++);
    tmp[i] = 0;
    return tmp;
}

void libCaca::displayNameGames(std::string name)
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

int libCaca::checkEventMenu(int quit, int &game, int &lib, int size_g, int size_l)
{
    caca_event_t ev;
    unsigned int const event_mask = CACA_EVENT_KEY_PRESS
| CACA_EVENT_RESIZE | CACA_EVENT_MOUSE_PRESS | CACA_EVENT_QUIT;
    int event = caca_get_event(window.getDisplay(),  event_mask, &ev, 0);


    while (event) {
        if (caca_get_event_type(&ev) == CACA_EVENT_KEY_PRESS) {
            switch (caca_get_event_key_ch(&ev)) {
                case CACA_KEY_UP:
                    game = game == 0 ? (size_g - 1) : game - 1;
                    break;
                case CACA_KEY_DOWN:
                    game = game + 1 == size_g ? 0 : game + 1;
                    break;
                case CACA_KEY_RETURN:
                    quit = GAME;
                    break;
                case 'n':
                case 'N':
                    lib = lib + 1 == size_l ? 0 : lib + 1;
                    quit = LIB;
                    break;
                case 'p':
                case 'P':
                    lib = lib == 0 ? (size_l - 1) : lib - 1;
                    quit = LIB;
                    break;
                case CACA_KEY_ESCAPE:
                    quit = QUIT;
                    break;
            }
            if (caca_get_event_type(&ev) & CACA_EVENT_QUIT)
                quit =1;
        }
        event = caca_get_event(window.getDisplay(), CACA_EVENT_KEY_PRESS, &ev, 0);
    }
    return quit;
}

std::string libCaca::Menu(std::vector<std::pair<int,std::string>> Games, std::vector<std::pair<int,std::string>> Libs)
{
    int game = Games[0].first;
    int lib = Libs.size() != 0 ? Libs[0].first : 0;
    int quit = 0;

    caca_set_display_title(window.getDisplay(), "Arcade");
    caca_set_color_ansi(window.getCanvas(), CACA_BLACK, CACA_WHITE);
    while (quit != LIB || quit != QUIT || quit != GAME) {
        int width = caca_get_canvas_width(window.getCanvas());
        int height = caca_get_canvas_height(window.getCanvas());
        if ((quit = checkEventMenu(quit, game, lib, Games.size(), Libs.size())) == QUIT)
            return "kill";
        if (quit == LIB)
            return Libs[lib].second;
        if (quit == GAME) {
            caca_refresh_display(this->window.getDisplay());
            return Games[game].second;
        }
        caca_clear_canvas(window.getCanvas());
        caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
        caca_put_str(window.getCanvas(), width / 2 - 8, height * 0.2, "Arcade Machines !");
        displayNameGames(Games[game].second);
        caca_refresh_display(this->window.getDisplay());
    }
    return "success";
}

extern "C" libCaca *createDisplay() 
{
    return new libCaca;
}