#include "Vec3.h"

#include <math.h>

///IVECTOR2///
iVector3 iVec3_Add(iVector3 first, iVector3 second)
{

    iVector3 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;
    out.z = first.z + second.z;

    return out;

}

iVector3 iVec3_Sub(iVector3 first, iVector3 second)
{

    iVector3 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;
    out.z = first.z - second.z;

    return out;

}

iVector3 iVec3_Mul(iVector3 first, iVector3 second)
{

    iVector3 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;
    out.z = first.z * second.z;

    return out;

}

iVector3 iVec3_Div(iVector3 first, iVector3 second)
{

    iVector3 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;
    out.z = first.z / second.z;

    return out;

}

iVector3 iVec3_Normalize(iVector3 v)
{
    int length_of_v = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

    iVector3 Ret;
    Ret.x = v.x / length_of_v;
    Ret.y =  v.y / length_of_v;
    Ret.z = v.z / length_of_v;
    return Ret;
}

bool iVec3_isEqual(iVector3 first, iVector3 second)
{

    if(first.x == second.x && first.y == second.y && first.z == second.z)
    {
        return true;
    }

    return false;

}

fVector3 iVec3_toFVec3(iVector3 first)
{
    
    fVector3 Ret;
    Ret.x = (float)first.x;
    Ret.y = (float)first.y;
    Ret.z = (float)first.z;

    return Ret;
}



///FVECTOR2///

fVector3 fVec3_Add(fVector3 first, fVector3 second)
{
    fVector3 out;

    out.x = first.x + second.x;
    out.y = first.y + second.y;
    out.z = first.z + second.z;

    return out;
}

fVector3 fVec3_Sub(fVector3 first, fVector3 second)
{
    fVector3 out;

    out.x = first.x - second.x;
    out.y = first.y - second.y;
    out.z = first.z - second.z;

    return out;
}

fVector3 fVec3_Mul(fVector3 first, fVector3 second)
{
    fVector3 out;

    out.x = first.x * second.x;
    out.y = first.y * second.y;
    out.z = first.z * second.z;

    return out;
}

fVector3 fVec3_Div(fVector3 first, fVector3 second)
{
    fVector3 out;

    out.x = first.x / second.x;
    out.y = first.y / second.y;
    out.z = first.z / second.z;

    return out;
}

fVector3 fVec3_Normalize(fVector3 v)
{
    float length_of_v = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
    
    fVector3 Ret;
    Ret.x = v.x / length_of_v;
    Ret.y =  v.y / length_of_v;
    Ret.z = v.z / length_of_v;

    return Ret;
}

bool fVec3_isEqual(fVector3 first, fVector3 second)
{

    if(first.x == second.x && first.y == second.y && first.z == second.z)
    {
        return true;
    }

    return false;
}

iVector3 fVec3_toIVec3(fVector3 first)
{

    iVector3 Ret;
    Ret.x = (int)first.x;
    Ret.y = (int)first.y;
    Ret.z = (int)first.z;

    return Ret;
}
