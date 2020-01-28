#include "Vec2.h"

Vec2i Add(Vec2i first, Vec2i second)
{
    Vec2i out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;

    return out;
}

Vec2f Add(Vec2f first, Vec2f second)
{
    Vec2f out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;

    return out;
}
