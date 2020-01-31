#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED

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

namespace iVec3
{
    iVector3 Add(iVector3, iVector3); // Addition
    iVector3 Sub(iVector3, iVector3); // Subtract
    iVector3 Mul(iVector3, iVector3); // Multiply
    iVector3 Div(iVector3, iVector3); // Divide

    iVector3 Normalize(iVector3);

    bool isEqual(iVector3, iVector3); // Gets if first is equal to second

    fVector3 toFVec3(iVector3);
}

namespace fVec3
{
    fVector3 Add(fVector3, fVector3); // Addition
    fVector3 Sub(fVector3, fVector3); // Subtract
    fVector3 Mul(fVector3, fVector3); // Multiply
    fVector3 Div(fVector3, fVector3); // Divide

    fVector3 Normalize(fVector3);

    bool isEqual(fVector3, fVector3); // Gets if first is equal to second

    iVector3 toIVec3(fVector3);
}


#endif // VEC3_H_INCLUDED
