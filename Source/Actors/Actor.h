#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#include "../Math/Mat4.h"

typedef struct _Actor
{
    fMatrix4 Transform;

    int ActorID;
    void (*Construct)( _Actor *self );
    void (*Init)( _Actor *self );
    void (*Update)( _Actor  *self );
    void (*Draw)( _Actor  *self );
    void (*Destroy)( _Actor  *self );
} Actor;

#endif // ACTOR_H_INCLUDED
