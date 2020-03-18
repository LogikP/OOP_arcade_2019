/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "GameCore.hpp"
#include "Error.hpp"

void Format_Error(int ac)
{
    if (ac != 2)
        throw(Error("Usage:\n\t./arcade {path to a dynamic graphic library}"));
}

int main(int ac, char **av)
{
    try
    {
        Format_Error(ac);
        GameCore myGame(av[1]);
        while(myGame.play()){};
    }
    catch (Error &error)
    {
        std::cerr << error.SendMessage() << std::endl;
        return 84;
    }
    return 0;
}