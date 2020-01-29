#ifndef VEC2_H_INCLUDED
#define VEC2_H_INCLUDED

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

namespace iVec2
{
    iVector2 Add(iVector2, iVector2); // Addition
    iVector2 Sub(iVector2, iVector2); // Subtract
    iVector2 Mul(iVector2, iVector2); // Multiply
    iVector2 Div(iVector2, iVector2); // Divide

    bool isEqual(iVector2, iVector2); // Gets if first is equal to second

    fVector2 toFVec2(iVector2);
}

namespace fVec2
{
    fVector2 Add(fVector2, fVector2); // Addition
    fVector2 Sub(fVector2, fVector2); // Subtract
    fVector2 Mul(fVector2, fVector2); // Multiply
    fVector2 Div(fVector2, fVector2); // Divide

    bool isEqual(fVector2, fVector2); // Gets if first is equal to second

    iVector2 toIVec2(fVector2);
}


#endif // VEC2_H_INCLUDED
