#ifndef OPENGLRENDER_H_INCLUDED
#define OPENGLRENDER_H_INCLUDED

#include <stdbool.h>

#include "../Math/Mat4.h"

struct _Render;
struct _Mesh;

bool Render_OpenGL_Init(struct _Render*);
void Render_OpenGL_Shutdown(struct _Render*);

void Render_OpenGL_DrawMesh(struct _Render* curRender, struct _Mesh* mesh, fMatrix4* transform);

#endif // OPENGLRENDER_H_INCLUDED
