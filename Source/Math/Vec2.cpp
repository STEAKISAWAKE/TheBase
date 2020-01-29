#include "Vec2.h"


///IVECTOR2///
iVector2 iVec2::Add(iVector2 first, iVector2 second)
{

    iVector2 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;

    return out;

}

iVector2 iVec2::Sub(iVector2 first, iVector2 second)
{

    iVector2 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;

    return out;

}

iVector2 iVec2::Mul(iVector2 first, iVector2 second)
{

    iVector2 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;

    return out;

}

iVector2 iVec2::Div(iVector2 first, iVector2 second)
{

    iVector2 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;

    return out;

}

bool iVec2::isEqual(iVector2 first, iVector2 second)
{

    if(first.x == second.x && first.y == second.y)
    {
        return true;
    }

    return false;

}

fVector2 iVec2::toFVec2(iVector2 first)
{
    return {(float)first.x, (float)first.y};
}



///FVECTOR2///

fVector2 fVec2::Add(fVector2 first, fVector2 second)
{
    fVector2 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;

    return out;
}

fVector2 fVec2::Sub(fVector2 first, fVector2 second)
{
    fVector2 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;    bool isEqual(iVector2, iVector2); // Gets if first is equal to second

    return out;
}

fVector2 fVec2::Mul(fVector2 first, fVector2 second)
{
    fVector2 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;

    return out;
}

fVector2 fVec2::Div(fVector2 first, fVector2 second)
{
    fVector2 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;

    return out;
}
bool fVec2::isEqual(fVector2 first, fVector2 second)
{

    if(first.x == second.x && first.y == second.y)
    {
        return true;
    }

    return false;
}

iVector2 fVec2::toIVec2(fVector2 first)
{
    return {(int)first.x, (int)first.y};
}
