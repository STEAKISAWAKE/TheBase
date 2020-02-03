#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED

#include <stdbool.h>

//Intiger Vector2
typedef struct iVector3_
{

    int x;
    int y;
    int z;

} iVector3;

//Float Vector2
typedef struct fVector3_
{

    float x;
    float y;
    float z;

} fVector3;

// iVec3 //////////////////////////////////////////////////
    iVector3 iVec3_Add(iVector3, iVector3); // Addition
    iVector3 iVec3_Sub(iVector3, iVector3); // Subtract
    iVector3 iVec3_Mul(iVector3, iVector3); // Multiply
    iVector3 iVec3_Div(iVector3, iVector3); // Divide

    iVector3 iVec3_Normalize(iVector3);

    bool iVec3_isEqual(iVector3, iVector3); // Gets if first is equal to second

    fVector3 iVec3_toFVec3(iVector3);


// fVec3 //////////////////////////////////////////////////
    fVector3 fVec3_Add(fVector3, fVector3); // Addition
    fVector3 fVec3_Sub(fVector3, fVector3); // Subtract
    fVector3 fVec3_Mul(fVector3, fVector3); // Multiply
    fVector3 fVec3_Div(fVector3, fVector3); // Divide

    fVector3 fVec3_Normalize(fVector3);

    bool fVec3_isEqual(fVector3, fVector3); // Gets if first is equal to second

    iVector3 fVec3_toIVec3(fVector3);


#endif // VEC3_H_INCLUDED
