#include "Mat4.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

//Returns a basic fMat4 with these settings
fMatrix4 fMat4_Init(fVector3 pos, fVector3 rot, fVector3 scl)
{
    fMatrix4 Result;
    Result = fMat4_Identity();

    Result = fMat4_Add(Result, fMat4_Translation(pos));
    Result = fMat4_Add(Result, fMat4_RotationEuclid(rot));
    Result = fMat4_Add(Result, fMat4_Scale(scl));

    return Result;
}


//Types of views
fMatrix4 fMat4_Perspective(float Width, float Height, float ZNear, float ZFar)
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

    Result.Entries[0][3] = 0.0f;
    Result.Entries[1][3] = 0.0f;
    Result.Entries[2][3] = -1.0f;
    Result.Entries[3][3] = 0.0f;
    return Result;
}

fMatrix4 fMat4_PerspectiveFov(float FOV, float Aspect, float ZNear, float ZFar)
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

fMatrix4 fMat4_PerspectiveMultiFov(float FovX, float FovY, float ZNear, float ZFar)
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

fMatrix4 fMat4_Orthogonal(float Width, float Height, float ZNear, float ZFar)
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

fMatrix4 fMat4_Identity()
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
fMatrix4 fMat4_Translation(fVector3 Pos)
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

fMatrix4 fMat4_Scale(fVector3 ScaleFactors)
{
    fMatrix4 Result;
    Result.Entries[0][0] = ScaleFactors.x;
    Result.Entries[1][0] = 0.0f;
    Result.Entries[2][0] = 0.0f;
    Result.Entries[3][0] = 0.0f;

    Result.Entries[0][1] = 0.0f;
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

fMatrix4 fMat4_Rotation(fVector3 Axis, float Angle)
{
    float c = cosf(Angle);
    float s = sinf(Angle);
    float t = 1.0f - c;

    fVector3 NormalizedAxis = fVec3_Normalize(Axis);
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

fMatrix4 fMat4_RotationEuclid(fVector3 euclidRot)
{
    return fMat4_Mul(
               fMat4_Mul(
                   fMat4_RotationY(euclidRot.y),
                   fMat4_RotationX(euclidRot.x)),
               fMat4_RotationZ(euclidRot.z)
               );
}

fMatrix4 fMat4_RotationX(float Theta)
{
    float CosT = cosf(Theta);
    float SinT = sinf(Theta);

    fMatrix4 Result = fMat4_Identity();
    Result.Entries[1][1] = CosT;
    Result.Entries[1][2] = SinT;
    Result.Entries[2][1] = -SinT;
    Result.Entries[2][2] = CosT;
    return Result;
}

fMatrix4 fMat4_RotationY(float Theta)
{
    float CosT = cosf(Theta);
    float SinT = sinf(Theta);

    fMatrix4 Result = fMat4_Identity();
    Result.Entries[0][0] = CosT;
    Result.Entries[0][2] = SinT;
    Result.Entries[2][0] = -SinT;
    Result.Entries[2][2] = CosT;
    return Result;
}

fMatrix4 fMat4_RotationZ(float Theta)
{
    float CosT = cosf(Theta);
    float SinT = sinf(Theta);

    fMatrix4 Result = fMat4_Identity();
    Result.Entries[0][0] = CosT;
    Result.Entries[0][1] = SinT;
    Result.Entries[1][0] = -SinT;
    Result.Entries[1][1] = CosT;
    return Result;
}



fMatrix4 fMat4_Add(fMatrix4 Left, fMatrix4 Right)
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

fMatrix4 fMat4_Sub(fMatrix4 Left, fMatrix4 Right)
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

fMatrix4 fMat4_Mul(fMatrix4 Left, fMatrix4 Right)
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

fMatrix4 fMat4_MulVector4(fMatrix4 Left, fVector4 Right)
{
    fMatrix4 Result = fMat4_Identity();

    for(unsigned int i = 0; i < 4; i++)
    {
        for(unsigned int i2 = 0; i2 < 4; i2++)
        {
            if(i == 1)
            {
                Result.Entries[i][i2] = Left.Entries[i][i2] * Right.x;
            }

            if(i == 2)
            {
                Result.Entries[i][i2] = Left.Entries[i][i2] * Right.y;
            }

            if(i == 3)
            {
                Result.Entries[i][i2] = Left.Entries[i][i2] * Right.z;
            }

            if(i == 4)
            {
                Result.Entries[i][i2] = Left.Entries[i][i2] * Right.w;
            }
        }
    }

    return Result;
}

fMatrix4 fMat4_MulFloat(float Left, fMatrix4 Right)
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

char* fMat4_ToString(fMatrix4 mat, char* inputStr)
{

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t i2 = 0; i2 < 4; i2++)
        {
            char buffer[12];
            snprintf(buffer, 12, "%.6f", mat.Entries[i][i2]);

            strcat(buffer, " ");
            strcat(inputStr, buffer);

        }
    }


    return inputStr;
}