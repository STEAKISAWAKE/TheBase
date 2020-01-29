#include "Vec3.h"

///IVECTOR2///
iVector3 iVec3::Add(iVector3 first, iVector3 second)
{

    iVector3 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;
    out.z = first.z + second.z;

    return out;

}

iVector3 iVec3::Sub(iVector3 first, iVector3 second)
{

    iVector3 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;
    out.z = first.z - second.z;

    return out;

}

iVector3 iVec3::Mul(iVector3 first, iVector3 second)
{

    iVector3 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;
    out.z = first.z * second.z;

    return out;

}

iVector3 iVec3::Div(iVector3 first, iVector3 second)
{

    iVector3 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;
    out.z = first.z / second.z;

    return out;

}

bool iVec3::isEqual(iVector3 first, iVector3 second)
{

    if(first.x == second.x && first.y == second.y && first.z == second.z)
    {
        return true;
    }

    return false;

}

fVector3 iVec3::toFVec3(iVector3 first)
{
    return {(float)first.x, (float)first.y, (float)first.z};
}



///FVECTOR2///

fVector3 fVec3::Add(fVector3 first, fVector3 second)
{
    fVector3 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;
    out.z = first.z + second.z;

    return out;
}

fVector3 fVec3::Sub(fVector3 first, fVector3 second)
{
    fVector3 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;
    out.z = first.z - second.z;

    return out;
}

fVector3 fVec3::Mul(fVector3 first, fVector3 second)
{
    fVector3 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;
    out.z = first.z * second.z;

    return out;
}

fVector3 fVec3::Div(fVector3 first, fVector3 second)
{
    fVector3 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;
    out.z = first.z / second.z;

    return out;
}
bool fVec3::isEqual(fVector3 first, fVector3 second)
{

    if(first.x == second.x && first.y == second.y && first.z == second.z)
    {
        return true;
    }

    return false;
}

iVector3 fVec3::toIVec3(fVector3 first)
{
    return {(int)first.x, (int)first.y, (int)first.z};
}
