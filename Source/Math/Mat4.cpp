#include "Mat4.h"

#include <cmath>

//Returns a basic fMat4 with these settings
fMatrix4 fMat4::Init(fVector3 pos, fVector3 rot, fVector3 scl)
{
    fMatrix4 Result;
    Result = Identity();

    Result = Add(Result, Translation(pos));
    Result = Add(Result, RotationEuclid(rot));
    Result = Add(Result, Scale(scl));

    return Result;
}


//Types of views
fMatrix4 fMat4::Perspective(float Width, float Height, float ZNear, float ZFar)
{
    fMatrix4 Result;
    Result.Entries[0][0] = 2.0f * ZNear / Width;
    Result.Entries[1][0] = 0.0f;
    Result.Entries[2][0] = 0.0f;
    Result.Entries[3][0] = 0.0f;

    Result.Entries[0][1] = 0.0f;
    Result.Entries[1][1] = 2.0f * ZNear / Height;
    Result.Entries[2][1] = 0.0f;
    Result.Entries[3][1] = 0.0f;

    Result.Entries[0][2] = 0.0f;
    Result.Entries[1][2] = 0.0f;
    Result.Entries[2][2] = ZFar / (ZNear - ZFar);
    Result.Entries[3][2] = ZFar * ZNear / (ZNear - ZFar);

    Result.Entries[0][3] = 0.0f;Mul(
    Result.Entries[1][3] = 0.0f;
    Result.Entries[2][3] = -1.0f;
    Result.Entries[3][3] = 0.0f;
    return Result;
}

fMatrix4 fMat4::PerspectiveFov(float FOV, float Aspect, float ZNear, float ZFar)
{
    float Width = 1.0f / tanf(FOV/2.0f), Height = Aspect / tanf(FOV/2.0f);

    fMatrix4 Result;
    Result.Entries[0][0] = Width;
    Result.Entries[1][0] = 0.0f;
    Result.Entries[2][0] = 0.0f;
    Result.Entries[3][0] = 0.0f;

    Result.Entries[0][1] = 0.0f;
    Result.Entries[1][1] = Height;
    Result.Entries[2][1] = 0.0f;
    Result.Entries[3][1] = 0.0f;

    Result.Entries[0][2] = 0.0f;
    Result.Entries[1][2] = 0.0f;
    Result.Entries[2][2] = ZFar / (ZNear - ZFar);
    Result.Entries[3][2] = ZFar * ZNear / (ZNear - ZFar);

    Result.Entries[0][3] = 0.0f;
    Result.Entries[1][3] = 0.0f;
    Result.Entries[2][3] = -1.0f;
    Result.Entries[3][3] = 0.0f;
    return Result;
}

fMatrix4 fMat4::PerspectiveMultiFov(float FovX, float FovY, float ZNear, float ZFar)
{
    float Width = 1.0f / tanf(FovX / 2.0f), Height = 1.0f / tanf(FovY / 2.0f);

    fMatrix4 Result;
    Result.Entries[0][0] = Width;
    Result.Entries[1][0] = 0.0f;
    Result.Entries[2][0] = 0.0f;
    Result.Entries[3][0] = 0.0f;

    Result.Entries[0][1] = 0.0f;
    Result.Entries[1][1] = Height;
    Result.Entries[2][1] = 0.0f;
    Result.Entries[3][1] = 0.0f;

    Result.Entries[0][2] = 0.0f;
    Result.Entries[1][2] = 0.0f;
    Result.Entries[2][2] = ZFar / (ZNear - ZFar);
    Result.Entries[3][2] = ZFar * ZNear / (ZNear - ZFar);

    Result.Entries[0][3] = 0.0f;
    Result.Entries[1][3] = 0.0f;
    Result.Entries[2][3] = -1.0f;
    Result.Entries[3][3] = 0.0f;
    return Result;
}

fMatrix4 fMat4::Orthogonal(float Width, float Height, float ZNear, float ZFar)
{
    fMatrix4 Result;
    Result.Entries[0][0] = 2.0f / Width;
    Result.Entries[1][0] = 0.0f;
    Result.Entries[2][0] = 0.0f;
    Result.Entries[3][0] = 0.0f;

    Result.Entries[0][1] = 0.0f;
    Result.Entries[1][1] = 2.0f / Height;
    Result.Entries[2][1] = 0.0f;
    Result.Entries[3][1] = 0.0f;

    Result.Entries[0][2] = 0.0f;
    Result.Entries[1][2] = 0.0f;
    Result.Entries[2][2] = 1.0f / (ZNear - ZFar);
    Result.Entries[3][2] = ZNear / (ZNear - ZFar);

    Result.Entries[0][3] = 0.0f;
    Result.Entries[1][3] = 0.0f;
    Result.Entries[2][3] = 0.0f;
    Result.Entries[3][3] = 1.0f;
    return Result;
}

fMatrix4 fMat4::Identity()
{
    fMatrix4 Result;

    for(unsigned int i = 0; i < 4; i++)
    {
        for(unsigned int i2 = 0; i2 < 4; i2++)
        {
            if(i == i2)
            {
                Result.Entries[i][i2] = 1.0f;
            }
            else
            {
                Result.Entries[i][i2] = 0.0f;
            }
        }
    }
    return Result;
}

//Transformations
fMatrix4 fMat4::Translation(fVector3 Pos)
{
    fMatrix4 Result;
    Result.Entries[0][0] = 1.0f;
    Result.Entries[1][0] = 0.0f;
    Result.Entries[2][0] = 0.0f;
    Result.Entries[3][0] = Pos.x;

    Result.Entries[0][1] = 0.0f;
    Result.Entries[1][1] = 1.0f;
    Result.Entries[2][1] = 0.0f;
    Result.Entries[3][1] = Pos.y;

    Result.Entries[0][2] = 0.0f;
    Result.Entries[1][2] = 0.0f;
    Result.Entries[2][2] = 1.0f;
    Result.Entries[3][2] = Pos.z;

    Result.Entries[0][3] = 0.0f;
    Result.Entries[1][3] = 0.0f;
    Result.Entries[2][3] = 0.0f;
    Result.Entries[3][3] = 1.0f;
    return Result;
}

fMatrix4 fMat4::Scale(fVector3 ScaleFactors)
{
    fMatrix4 Result;
    Result.Entries[0][0] = ScaleFactors.x;
    Result.Entries[1][0] = 0.0f;
    Result.Entries[2][0] = 0.0f;
    Result.Entries[3][0] = 0.0f;

    Result.Entries[0][1] = 0.0f;Mul(
    Result.Entries[1][1] = ScaleFactors.y;
    Result.Entries[2][1] = 0.0f;
    Result.Entries[3][1] = 0.0f;

    Result.Entries[0][2] = 0.0f;
    Result.Entries[1][2] = 0.0f;
    Result.Entries[2][2] = ScaleFactors.z;
    Result.Entries[3][2] = 0.0f;

    Result.Entries[0][3] = 0.0f;
    Result.Entries[1][3] = 0.0f;
    Result.Entries[2][3] = 0.0f;
    Result.Entries[3][3] = 1.0f;
    return Result;
}

fMatrix4 fMat4::Rotation(fVector3 Axis, float Angle)
{
    float c = cosf(Angle);
    float s = sinf(Angle);
    float t = 1.0f - c;

    fVector3 NormalizedAxis = fVec3::Normalize(Axis);
    float x = NormalizedAxis.x;
    float y = NormalizedAxis.y;
    float z = NormalizedAxis.z;

    fMatrix4 Result;
    Result.Entries[0][0] = 1 + t*(x*x-1);
    Result.Entries[0][1] = z*s+t*x*y;
    Result.Entries[0][2] = -y*s+t*x*z;
    Result.Entries[0][3] = 0.0f;

    Result.Entries[1][0] = -z*s+t*x*y;
    Result.Entries[1][1] = 1+t*(y*y-1);
    Result.Entries[1][2] = x*s+t*y*z;
    Result.Entries[1][3] = 0.0f;

    Result.Entries[2][0] = y*s+t*x*z;
    Result.Entries[2][1] = -x*s+t*y*z;
    Result.Entries[2][2] = 1+t*(z*z-1);
    Result.Entries[2][3] = 0.0f;

    Result.Entries[3][0] = 0.0f;
    Result.Entries[3][1] = 0.0f;
    Result.Entries[3][2] = 0.0f;
    Result.Entries[3][3] = 1.0f;
    return Result;
}

fMatrix4 fMat4::RotationEuclid(fVector3 euclidRot)
{
    return Mul(
               Mul(
                   RotationY(euclidRot.y),
                   RotationX(euclidRot.x)),
               RotationZ(euclidRot.z)
               );
}

fMatrix4 fMat4::RotationX(float Theta)
{
    float CosT = cosf(Theta);
    float SinT = sinf(Theta);

    fMatrix4 Result = Identity();
    Result.Entries[1][1] = CosT;
    Result.Entries[1][2] = SinT;
    Result.Entries[2][1] = -SinT;
    Result.Entries[2][2] = CosT;
    return Result;
}

fMatrix4 fMat4::RotationY(float Theta)
{
    float CosT = cosf(Theta);
    float SinT = sinf(Theta);

    fMatrix4 Result = Identity();
    Result.Entries[0][0] = CosT;
    Result.Entries[0][2] = SinT;
    Result.Entries[2][0] = -SinT;
    Result.Entries[2][2] = CosT;
    return Result;
}

fMatrix4 fMat4::RotationZ(float Theta)
{
    float CosT = cosf(Theta);
    float SinT = sinf(Theta);

    fMatrix4 Result = Identity();
    Result.Entries[0][0] = CosT;
    Result.Entries[0][1] = SinT;
    Result.Entries[1][0] = -SinT;
    Result.Entries[1][1] = CosT;
    return Result;
}



fMatrix4 fMat4::Add(fMatrix4 Left, fMatrix4 Right)
{

    fMatrix4 Result;
    for(unsigned int i = 0; i < 4; i++)
    {
        for(unsigned int i2 = 0; i2 < 4; i2++)
        {
            Result.Entries[i][i2] = Left.Entries[i][i2] + Right.Entries[i][i2];
        }
    }
    return Result;
}

fMatrix4 fMat4::Sub(fMatrix4 Left, fMatrix4 Right)
{
    fMatrix4 Result;
    for(unsigned int i = 0; i < 4; i++)
    {
        for(unsigned int i2 = 0; i2 < 4; i2++)
        {
            Result.Entries[i][i2] = Left.Entries[i][i2] - Right.Entries[i][i2];
        }
    }
    return Result;
}

fMatrix4 fMat4::Mul(fMatrix4 Left, fMatrix4 Right)
{
    fMatrix4 Result;
    for(unsigned int i = 0; i < 4; i++)
    {
        for(unsigned int i2 = 0; i2 < 4; i2++)
        {
            float Total = 0.0f;
            for(unsigned int i3 = 0; i3 < 4; i3++)
            {
                Total += Left.Entries[i][i3] * Right.Entries[i3][i2];
            }
            Result.Entries[i][i2] = Total;
        }
    }
    return Result;
}

fMatrix4 fMat4::MulFloat(float Left, fMatrix4 Right)
{
    fMatrix4 Result;
    for(unsigned int i = 0; i < 4; i++)
    {
        for(unsigned int i2 = 0; i2 < 4; i2++)
        {
            Result.Entries[i][i2] = Right.Entries[i][i2] * Left;
        }
    }
    return Result;
}

