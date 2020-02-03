#ifndef VEC2_H_INCLUDED
#define VEC2_H_INCLUDED

#include <stdbool.h>

//Intiger Vector2
typedef struct iVector2_
{

    int x;
    int y;

} iVector2;

//Float Vector2
typedef struct fVector2_
{

    float x;
    float y;

} fVector2;

// iVec2 //////////////////////////////////////////////
    iVector2 iVec2_Add(iVector2, iVector2); // Addition
    iVector2 iVec2_Sub(iVector2, iVector2); // Subtract
    iVector2 iVec2_Mul(iVector2, iVector2); // Multiply
    iVector2 iVec2_Div(iVector2, iVector2); // Divide

    bool iVec2_isEqual(iVector2, iVector2); // Gets if first is equal to second

    fVector2 iVec2_toFVec2(iVector2);

// fVec2 //////////////////////////////////////////////
    fVector2 fVec2_Add(fVector2, fVector2); // Addition
    fVector2 fVec2_Sub(fVector2, fVector2); // Subtract
    fVector2 fVec2_Mul(fVector2, fVector2); // Multiply
    fVector2 fVec2_Div(fVector2, fVector2); // Divide

    bool fVec2_isEqual(fVector2, fVector2); // Gets if first is equal to second

    iVector2 fVec2_toIVec2(fVector2);


#endif // VEC2_H_INCLUDED
