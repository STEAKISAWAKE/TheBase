    //Returns a basic fMat4 with these settings
    fMatrix4 fMat4::Basic(fVec3 pos, fVec3 rot, fVec3 scl)
    {
        fMatrix4 Result;

        fMat4::Scale()

    }


    //Types of views
    fMatrix4 fMat4::Perspective(float Width, float Height, float ZNear, float ZFar);
    fMatrix4 fMat4::PerspectiveFov(float FOV, float Aspect, float ZNear, float ZFar);
    fMatrix4 fMat4::PerspectiveMultiFov(float FovX, float FovY, float ZNear, float ZFar);
    fMatrix4 fMat4::Orthogonal(float Width, float Height, float ZNear, float ZFar);


    //Transformations
    fMatrix4 fMat4::Translation(fMatrix4& mat, fVec3& Pos);
    fMatrix4 fMat4::Scale(fMatrix4& mat, fVec3& ScaleFactors);
    fMatrix4 fMat4::Rotation(fMatrix4& mat, fVec3& Axis, float Angle);
    fMatrix4 fMat4::RotationEuclid(fMatrix4& mat, fVec3& euclidRot);

    fMatrix4 fMat4::RotationX(fMatrix4& mat, float Theta);
    fMatrix4 fMat4::RotationY(fMatrix4& mat, float Theta);
    fMatrix4 fMat4::RotationZ(fMatrix4& mat, float Theta);



    fMatrix4 fMat4::Add(fMatrix4&, fMatrix4&);
    fMatrix4 fMat4::Sub(fMatrix4&, fMatrix4&);
    fMatrix4 fMat4::Mul(fMatrix4&, fMatrix4&);
    fMatrix4 fMat4::Div(fMatrix4&, fMatrix4&);
