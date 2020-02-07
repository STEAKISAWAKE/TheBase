#include "World.h"

#include "../Actors/Actor.h"

void AddActor(World* self, struct _Actor* newActor)
{
    newActor->OnConstruct(newActor);
    vector_add(&self->Actors, newActor);
    newActor->OnBeginPlay(newActor);
}
