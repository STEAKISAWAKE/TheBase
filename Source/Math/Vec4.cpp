#include "Vec4.h"

///IVECTOR2///
iVector4 iVec4::Add(iVector4 first, iVector4 second)
{

    iVector4 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;
    out.z = first.z + second.z;
    out.w = first.w + second.w;

    return out;

}

iVector4 iVec4::Sub(iVector4 first, iVector4 second)
{

    iVector4 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;
    out.z = first.z - second.z;
    out.w = first.w - second.w;

    return out;

}

iVector4 iVec4::Mul(iVector4 first, iVector4 second)
{

    iVector4 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;
    out.z = first.z * second.z;
    out.w = first.w * second.w;

    return out;

}

iVector4 iVec4::Div(iVector4 first, iVector4 second)
{

    iVector4 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;
    out.z = first.z / second.z;
    out.w = first.w / second.w;

    return out;

}

bool iVec4::isEqual(iVector4 first, iVector4 second)
{

    if(first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w)
    {
        return true;
    }

    return false;

}

fVector4 iVec4::toFVec4(iVector4 first)
{
    return {(float)first.x, (float)first.y, (float)first.z, (float)first.w};
}



///FVECTOR2///

fVector4 fVec4::Add(fVector4 first, fVector4 second)
{
    fVector4 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;
    out.z = first.z + second.z;
    out.w = first.w + second.w;

    return out;
}

fVector4 fVec4::Sub(fVector4 first, fVector4 second)
{
    fVector4 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;
    out.z = first.z - second.z;
    out.w = first.w - second.w;

    return out;
}

fVector4 fVec4::Mul(fVector4 first, fVector4 second)
{
    fVector4 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;
    out.z = first.z * second.z;
    out.w = first.w * second.w;

    return out;
}

fVector4 fVec4::Div(fVector4 first, fVector4 second)
{
    fVector4 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;
    out.z = first.z / second.z;
    out.w = first.w / second.w;

    return out;
}
bool fVec4::isEqual(fVector4 first, fVector4 second)
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

iVector4 fVec4::toIVec4(fVector4 first)
{
    return {(int)first.x, (int)first.y, (int)first.z, (int)first.w};
}
