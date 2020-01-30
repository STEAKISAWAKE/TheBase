#ifndef MAT4_H_INCLUDED
#define MAT4_H_INCLUDED

#include "Vec3.h"

typedef struct fMatrix4_
{
    float[4][4] Entries;
} fMatrix4;

namespace fMat4
{
    //Returns a basic fMat4 with these settings
    fMatrix4 Basic(fVec3 pos, fVec3 rot, fVec3 scl);


    //Types of views
    fMatrix4 Perspective(float Width, float Height, float ZNear, float ZFar);
    fMatrix4 PerspectiveFov(float FOV, float Aspect, float ZNear, float ZFar);
    fMatrix4 PerspectiveMultiFov(float FovX, float FovY, float ZNear, float ZFar);
    fMatrix4 Orthogonal(float Width, float Height, float ZNear, float ZFar);


    //Transformations
    fMatrix4 Translation(fMatrix4& mat, fVec3& Pos);
    fMatrix4 Scale(fMatrix4& mat, fVec3& ScaleFactors);
    fMatrix4 Rotation(fMatrix4& mat, fVec3& Axis, float Angle);
    fMatrix4 RotationEuclid(fMatrix4& mat, fVec3& euclidRot);

    fMatrix4 RotationX(fMatrix4& mat, float Theta);
    fMatrix4 RotationY(fMatrix4& mat, float Theta);
    fMatrix4 RotationZ(fMatrix4& mat, float Theta);



    fMatrix4 Add(fMatrix4&, fMatrix4&);
    fMatrix4 Sub(fMatrix4&, fMatrix4&);
    fMatrix4 Mul(fMatrix4&, fMatrix4&);
    fMatrix4 Div(fMatrix4&, fMatrix4&);
}


#endif // MAT4_H_INCLUDED
