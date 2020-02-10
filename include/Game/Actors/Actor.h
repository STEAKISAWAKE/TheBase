#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

//The actor base file includes needed files when making actors such as the rendering file for drawing

#include "../Math/Mat4.h"

struct _Actor
{
    int ActorID;

    fMatrix4 Transform;

    void (*OnConstruct) ( struct _Actor* self ); // On created/constructed used to set variables/initalize them before usage.
    void (*OnBeginPlay) ( struct _Actor* self ); // Do logic when the actor is created.
    void (*OnUpdate)    ( struct _Actor* self ); // Updates positions and variables of the actor.
    void (*OnDraw)      ( struct _Actor* self ); // When drawing the Rendering module is used or your own engine.
    void (*OnEndPlay)   ( struct _Actor* self ); // When the actor is getting removed or the world is ending.
    void (*OnDestruct)  ( struct _Actor* self ); // Nullify pointers, delete pointers, destruction of struct iminent.

};

typedef struct _Actor Actor;

#endif // ACTOR_H_INCLUDED
