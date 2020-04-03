/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** game_displayer_caca_lib
*/

#include <iostream>
#include "lib_caca.hpp"

void libCaca::InitProg(std::vector<std::string> map, std::vector<std::string> score)
{
    int width = caca_get_canvas_width(window.getCanvas());
    int height = caca_get_canvas_height(window.getCanvas());

    caca_clear_canvas(window.getCanvas());
    caca_set_color_ansi(window.getCanvas(), CACA_BLUE, CACA_BLACK);
    caca_put_str(window.getCanvas(), width / 2 - (map[0].size() / 2) - 13, height / 2 - 4, "Actual Score");
    caca_put_str(window.getCanvas(), width / 2 - (map[0].size() / 2) - 6 - (score[1].size() / 2), height / 2 - 2, score[0].c_str());
    caca_set_color_ansi(window.getCanvas(), CACA_RED, CACA_BLACK);
    caca_put_str(window.getCanvas(), width / 2 - (map[0].size() / 2) - 12, height / 2 + 2, "HighScore:");
    caca_put_str(window.getCanvas(), width / 2 - (map[0].size() / 2) - 7 - (score[1].size() / 2), height / 2 + 4, score[1].c_str());
    caca_set_color_ansi(window.getCanvas(), CACA_RED, CACA_BLACK);
    for (int i = 0; i < (int)map.size(); i++) {
        for (int j = 0; j < (int)map[i].size(); j++) {
            if (map[i][j] == '0' || map[i][j] == 'o') {
                caca_set_color_ansi(window.getCanvas(), CACA_GREEN, CACA_BLACK);
                caca_put_str(window.getCanvas(), width / 2 + j - (map[0].size() / 2), height / 2 + i  - (map.size() / 2), &(map[i].c_str())[j]);
                caca_set_color_ansi(window.getCanvas(), CACA_GREEN, CACA_BLACK);
            } else if (map[i][j] == 'W') {
                caca_set_color_ansi(window.getCanvas(), CACA_RED, CACA_BLACK);
                caca_put_str(window.getCanvas(), width / 2 + j - (map[0].size() / 2), height / 2 + i - (map.size() / 2), &(map[i].c_str())[j]);
                caca_set_color_ansi(window.getCanvas(), CACA_RED, CACA_BLACK);
            } else if (map[i][j] == 'x' || map[i][j] == 'M') {
                caca_set_color_ansi(window.getCanvas(), CACA_BLUE, CACA_BLACK);
                caca_put_str(window.getCanvas(), width / 2 + j - (map[0].size() / 2), height / 2 + i - (map.size() / 2), &(map[i].c_str())[j]);
                caca_set_color_ansi(window.getCanvas(), CACA_BLUE, CACA_BLACK);
            } else if (map[i][j] == 'C') {
                caca_set_color_ansi(window.getCanvas(), CACA_YELLOW, CACA_BLACK);
                caca_put_str(window.getCanvas(), width / 2 + j - (map[0].size() / 2), height / 2 + i - (map.size() / 2), &(map[i].c_str())[j]);
                caca_set_color_ansi(window.getCanvas(), CACA_YELLOW, CACA_BLACK);
            }  else
                caca_put_str(window.getCanvas(), width / 2 + j - (map[0].size() / 2), height / 2 + i - (map.size() / 2), &(map[i].c_str())[j]);
        }
    }
    caca_refresh_display(this->window.getDisplay());
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
                case CACA_KEY_ESCAPE:
                    quit = LEAVE;
                    break;
                case 'l':
                    quit = LIB_G;
                    break;
                case 'm':
                    quit = MENU_G;
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

int libCaca::getEvent()
{
    int direction = -1;

    caca_set_display_time(window.getDisplay(), 100000);
    direction = getKeyEventGame(direction);
    if (direction == LEAVE)
        return 'k';
    else if (direction == LIB_G)
        return 'l';
    else if (direction == MENU_G)
        return 'm';
    return direction;
}

std::string libCaca::Game()
{
    return "toto";
}

void libCaca::initWindow()
{
}