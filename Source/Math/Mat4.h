#ifndef MAT4_H_INCLUDED
#define MAT4_H_INCLUDED

#include "Vec3.h"
#include "Vec4.h"

typedef struct fMatrix4_
{
    float Entries[4][4];
} fMatrix4;

    //Returns a basic fMat4 with these settings
    fMatrix4 fMat4_Init(fVector3 pos, fVector3 rot, fVector3 scl);


    //Types of views
    fMatrix4 fMat4_Perspective(float Width, float Height, float ZNear, float ZFar);
    fMatrix4 fMat4_PerspectiveFov(float FOV, float Aspect, float ZNear, float ZFar);
    fMatrix4 fMat4_PerspectiveMultiFov(float FovX, float FovY, float ZNear, float ZFar);
    fMatrix4 fMat4_Orthogonal(float Width, float Height, float ZNear, float ZFar);

    fMatrix4 fMat4_Identity();

    //Transformations
    fMatrix4 fMat4_Translation(fVector3 Pos);
    fMatrix4 fMat4_Scale(fVector3 ScaleFactors);
    fMatrix4 fMat4_Rotation(fVector3 Axis, float Angle);
    fMatrix4 fMat4_RotationEuclid(fVector3 euclidRot);

    fMatrix4 fMat4_RotationX(float Theta);
    fMatrix4 fMat4_RotationY(float Theta);
    fMatrix4 fMat4_RotationZ(float Theta);



    fMatrix4 fMat4_Add(fMatrix4, fMatrix4);
    fMatrix4 fMat4_Sub(fMatrix4, fMatrix4);
    fMatrix4 fMat4_Mul(fMatrix4 Left, fMatrix4 Right);
    fMatrix4 fMat4_MulVector4(fMatrix4 Left, fVector4 Right);
    fMatrix4 fMat4_MulFloat(float, fMatrix4);


#endif // MAT4_H_INCLUDED
