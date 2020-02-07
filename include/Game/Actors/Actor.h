#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#include "../Math/Mat4.h"

struct _Actor
{
    int ActorID;

    fMatrix4 Transform;

    void (*OnConstruct) ( struct _Actor* self );
    void (*OnBeginPlay) ( struct _Actor* self );
    void (*OnUpdate)    ( struct _Actor* self );
    void (*OnDraw)      ( struct _Actor* self );
    void (*OnEndPlay)   ( struct _Actor* self );
    void (*OnDestruct)  ( struct _Actor* self );

};

typedef struct _Actor Actor;

#endif // ACTOR_H_INCLUDED
