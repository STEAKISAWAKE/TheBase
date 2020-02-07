#ifndef VEC4_H_INCLUDED
#define VEC4_H_INCLUDED

#ifdef __cplusplus
extern "C"
{
#include <stdbool.h>
}
#else

#include <stdbool.h>

#endif

//Intiger Vector2
typedef struct iVector4_
{

    int x;
    int y;
    int z;
    int w;

} iVector4;

//Float Vector2
typedef struct fVector4_
{

    float x;
    float y;
    float z;
    float w;

} fVector4;

// iVec4 //////////////////////////////////////////////////////
    iVector4 iVec4_Add(iVector4, iVector4); // Addition
    iVector4 iVec4_Sub(iVector4, iVector4); // Subtract
    iVector4 iVec4_Mul(iVector4, iVector4); // Multiply
    iVector4 iVec4_Div(iVector4, iVector4); // Divide

    bool iVec4_isEqual(iVector4, iVector4); // Gets if first is equal to second

    fVector4 iVec4_toFVec4(iVector4);


// fVec4 /////////////////////////////////////////////////////
    fVector4 fVec4_Add(fVector4, fVector4); // Addition
    fVector4 fVec4_Sub(fVector4, fVector4); // Subtract
    fVector4 fVec4_Mul(fVector4, fVector4); // Multiply
    fVector4 fVec4_Div(fVector4, fVector4); // Divide

    bool fVec4_isEqual(fVector4, fVector4); // Gets if first is equal to second

    iVector4 fVec4_toIVec4(fVector4);



#endif // VEC4_H_INCLUDED
