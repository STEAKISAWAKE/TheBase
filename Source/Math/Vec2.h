#ifndef VEC2_H_INCLUDED
#define VEC2_H_INCLUDED

namespace ver
{

//Intiger Vector2
typedef struct Vec2i_
{
    int x;
    int y;
} Vec2i;

//Float Vector2
typedef struct Vec2f_
{
    float x;
    float y;
} Vec2f;

//Vec2i

//Add Vec2's together
Vec2i Add(Vec2i first, Vec2i second);


//Vec2f
Vec2f Add(Vec2f first, Vec2f second);


}


#endif // VEC2_H_INCLUDED
