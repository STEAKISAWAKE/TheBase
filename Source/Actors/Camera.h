#ifndef CAMERA_INCLUDED
#define CAMERA_INCLUDED

#include "../Math/Mat4.h"

typedef struct _Camera
{
    fMatrix4 View; // Position of the camera
    fMatrix4 Projection; // Type of view the camera has (Perspective, Orthogonal)

    float FOV;

} Camera;


void CameraSetFOV(Camera&, float newFOV); // Changes the cameras
void SetCameraView(Camera&, fMatrix4 newView);
void CameraSetProjection(Camera&, fMatrix4 newProj);

#endif // CAMERA_INCLUDED
