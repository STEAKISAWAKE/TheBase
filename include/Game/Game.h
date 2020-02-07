#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdbool.h>

struct _Actor;
struct _World;

struct _Game
{
    void (*OnConstruct) ( struct _Game* self );
    void (*OnBeginPlay) ( struct _Game* self );
    void (*OnUpdate)    ( struct _Game* self );
    void (*OnEndPlay)   ( struct _Game* self );
    void (*OnDestruct)  ( struct _Game* self );
};

void OpenWorld(struct _World*); // Starts this world, bool to automatically close the world
void CloseWorld(); // Closes the current world.

void 


#endif // GAME_H_INCLUDED
