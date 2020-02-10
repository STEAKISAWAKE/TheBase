#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "../Utils/Vector.h"

struct _Actor;

//Not tested
#define CreateActor(Type, CurWorld, OnConstructFunc, OnBeginPlayFunc, OnUpdateFunc, OnEndPlayFunc, OnDestructFunc) {      \
    Type* newActor = new Type;                        \
    newActor->Base->OnConstruct = OnConstructFunc;    \
    newActor->Base->OnBeginPlay = OnBeginPlayFunc;    \
    newActor->Base->OnUpdate = OnUpdateFunc;          \
    newActor->Base->OnEndPlay = OnEndPlayFunc;        \
    newActor->Base->OnDestruct = OnDestructFunc;      \
                                                      \
    newActor->Base->World = CurWorld;                 \
    newActor->Base->OnConstruct();                    \
    newActor;                                         \
}




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
