#include "Vec2.h"


///IVECTOR2///
iVector2 iVec2_Add(iVector2 first, iVector2 second)
{

    iVector2 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;

    return out;

}

iVector2 iVec2_Sub(iVector2 first, iVector2 second)
{

    iVector2 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;

    return out;

}

iVector2 iVec2_Mul(iVector2 first, iVector2 second)
{

    iVector2 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;

    return out;

}

iVector2 iVec2_Div(iVector2 first, iVector2 second)
{

    iVector2 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;

    return out;

}

bool iVec2_isEqual(iVector2 first, iVector2 second)
{

    if(first.x == second.x && first.y == second.y)
    {
        return true;
    }

    return false;

}

fVector2 iVec2_toFVec2(iVector2 first)
{
    fVector2 ret;

    ret.x = (float)first.x;
    ret.y = (float)first.y;

    return ret;
}



///FVECTOR2///

fVector2 fVec2_Add(fVector2 first, fVector2 second)
{
    fVector2 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;

    return out;
}

fVector2 fVec2_Sub(fVector2 first, fVector2 second)
{
    fVector2 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;    bool isEqual(iVector2, iVector2); // Gets if first is equal to second

    return out;
}

fVector2 fVec2_Mul(fVector2 first, fVector2 second)
{
    fVector2 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;

    return out;
}

fVector2 fVec2_Div(fVector2 first, fVector2 second)
{
    fVector2 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;

    return out;
}
bool fVec2_isEqual(fVector2 first, fVector2 second)
{

    if(first.x == second.x && first.y == second.y)
    {
        return true;
    }

    return false;
}

iVector2 fVec2_toIVec2(fVector2 first)
{
    iVector2 ret;

    ret.x = (int)first.x;
    ret.y = (int)first.y;

    return ret;
}
