#ifndef MAT4_H_INCLUDED
#define MAT4_H_INCLUDED

#include "Vec3.h"

typedef struct fMatrix4_
{
    float Entries[4][4];
} fMatrix4;

namespace fMat4
{
    //Returns a basic fMat4 with these settings
    fMatrix4 Init(fVector3 pos, fVector3 rot, fVector3 scl);


    //Types of views
    fMatrix4 Perspective(float Width, float Height, float ZNear, float ZFar);
    fMatrix4 PerspectiveFov(float FOV, float Aspect, float ZNear, float ZFar);
    fMatrix4 PerspectiveMultiFov(float FovX, float FovY, float ZNear, float ZFar);
    fMatrix4 Orthogonal(float Width, float Height, float ZNear, float ZFar);

    fMatrix4 Identity();

    //Transformations
    fMatrix4 Translation(fVector3 Pos);
    fMatrix4 Scale(fVector3 ScaleFactors);
    fMatrix4 Rotation(fVector3 Axis, float Angle);
    fMatrix4 RotationEuclid(fVector3 euclidRot);

    fMatrix4 RotationX(float Theta);
    fMatrix4 RotationY(float Theta);
    fMatrix4 RotationZ(float Theta);



    fMatrix4 Add(fMatrix4, fMatrix4);
    fMatrix4 Sub(fMatrix4, fMatrix4);
    fMatrix4 Mul(fMatrix4 Left, fMatrix4 Right);
    fMatrix4 MulFloat(float, fMatrix4);
}


#endif // MAT4_H_INCLUDED
