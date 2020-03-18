/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** createObject
*/

#include "GameCore.hpp"

typedef IGame *(*createGame)();
typedef IDisplay *(*createDisplay)();

template <>
IDisplay *GameCore::createObject<IDisplay>(void* library) 
{
    char *error;
    createDisplay createMyObject = (createDisplay)(dlsym(library, "createDisplay"));
    if ((error = dlerror()) != NULL)
    {
        fprintf(stderr, "%s\n", error);
        exit(84);
    }
    return (createMyObject());
}

template <>
IGame *GameCore::createObject<IGame>(void* game) 
{
    char *error;
    createGame createMyObject = (createGame)dlsym(game, "createGame");
    if ((error = dlerror()) != NULL)
    {
        fprintf(stderr, "%s\n", error);
        exit(84);
    }
    return (createMyObject());
}

