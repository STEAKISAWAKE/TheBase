#ifndef VEC4_H_INCLUDED
#define VEC4_H_INCLUDED

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

namespace iVec4
{
    iVector4 Add(iVector4, iVector4); // Addition
    iVector4 Sub(iVector4, iVector4); // Subtract
    iVector4 Mul(iVector4, iVector4); // Multiply
    iVector4 Div(iVector4, iVector4); // Divide

    bool isEqual(iVector4, iVector4); // Gets if first is equal to second

    fVector4 toFVec4(iVector4);
}

namespace fVec4
{
    fVector4 Add(fVector4, fVector4); // Addition
    fVector4 Sub(fVector4, fVector4); // Subtract
    fVector4 Mul(fVector4, fVector4); // Multiply
    fVector4 Div(fVector4, fVector4); // Divide

    bool isEqual(fVector4, fVector4); // Gets if first is equal to second

    iVector4 toIVec4(fVector4);
}


#endif // VEC4_H_INCLUDED
