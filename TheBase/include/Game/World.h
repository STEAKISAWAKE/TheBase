#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "../Utils/Vector.h"

struct _Actor;

struct _World
{
    int WorldID;

    void (*OnConstruct) (struct _World* self);
    void (*OnBeginPlay) (struct _World* self);
    void (*OnUpdate)    (struct _World* self);
    void (*OnEndPlay)   (struct _World* self);
    void (*OnDestruct)  (struct _World* self);

    vector Actors; // When creating actors give this vector the .Actor struct
};

typedef struct _World World;

void AddActor(World* self, struct _Actor* newActor); // This will call OnBeginPlay on the actor so you dont have to

#endif // WORLD_H_INCLUDED
