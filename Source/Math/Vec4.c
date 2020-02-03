#include "Vec4.h"

///IVECTOR2///
iVector4 iVec4_Add(iVector4 first, iVector4 second)
{

    iVector4 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;
    out.z = first.z + second.z;
    out.w = first.w + second.w;

    return out;

}

iVector4 iVec4_Sub(iVector4 first, iVector4 second)
{

    iVector4 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;
    out.z = first.z - second.z;
    out.w = first.w - second.w;

    return out;

}

iVector4 iVec4_Mul(iVector4 first, iVector4 second)
{

    iVector4 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;
    out.z = first.z * second.z;
    out.w = first.w * second.w;

    return out;

}

iVector4 iVec4_Div(iVector4 first, iVector4 second)
{

    iVector4 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;
    out.z = first.z / second.z;
    out.w = first.w / second.w;

    return out;

}

bool iVec4_isEqual(iVector4 first, iVector4 second)
{

    if(first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w)
    {
        return true;
    }

    return false;

}

fVector4 iVec4_toFVec4(iVector4 first)
{
    return {(float)first.x, (float)first.y, (float)first.z, (float)first.w};
}



///FVECTOR2///

fVector4 fVec4_Add(fVector4 first, fVector4 second)
{
    fVector4 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;
    out.z = first.z + second.z;
    out.w = first.w + second.w;

    return out;
}

fVector4 fVec4_Sub(fVector4 first, fVector4 second)
{
    fVector4 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;
    out.z = first.z - second.z;
    out.w = first.w - second.w;

    return out;
}

fVector4 fVec4_Mul(fVector4 first, fVector4 second)
{
    fVector4 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;
    out.z = first.z * second.z;
    out.w = first.w * second.w;

    return out;
}

fVector4 fVec4_Div(fVector4 first, fVector4 second)
{
    fVector4 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;
    out.z = first.z / second.z;
    out.w = first.w / second.w;

    return out;
}
bool fVec4_isEqual(fVector4 first, fVector4 second)
{

    if(
        first.x == second.x &&
        first.y == second.y &&
        first.z == second.z &&
        first.w == second.w
    )
    {
        return true;
    }

    return false;
}

iVector4 fVec4_toIVec4(fVector4 first)
{
    return {(int)first.x, (int)first.y, (int)first.z, (int)first.w};
}
