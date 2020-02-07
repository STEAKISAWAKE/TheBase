#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "vector.h"

struct _Game
{
    void (*OnConstruct) (_Game* self);
    void (*OnBeginPlay) (_Game* self);
    void (*OnUpdate)    (_Game* self);
    void (*OnEndPlay)   (_Game* self);
    void (*OnDestruct)  (_Game* self);
};

#endif // GAME_H_INCLUDED
