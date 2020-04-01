/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** menu_lib
*/

#include "lib_caca.hpp"

int libCaca::checkEventMenuLib(int quit, int &game, int size)
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
                case CACA_KEY_RETURN:
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

std::string libCaca::MenuLib(std::vector<std::pair<int,std::string>> Lib)
{
    int game = Lib[0].first;
    int quit = 0;

    caca_set_display_title(window.getDisplay(), "Arcade");
    caca_set_color_ansi(window.getCanvas(), CACA_BLACK, CACA_WHITE);
    while (!quit) {
        int width = caca_get_canvas_width(window.getCanvas());
        int height = caca_get_canvas_height(window.getCanvas());
        if ((quit = checkEventMenuLib(quit, game, Lib.size())) == QUIT)
            return "kill";
        if (quit == LIB)
            return Lib[game].second;
        caca_clear_canvas(window.getCanvas());
        caca_set_color_ansi(window.getCanvas(), CACA_WHITE, CACA_BLACK);
        caca_put_str(window.getCanvas(), width / 2 - 8, height * 0.2, "Arcade Machines !");
        displayNameGames(Lib[game].second);
        caca_refresh_display(this->window.getDisplay());
    }
    return "toto";
}