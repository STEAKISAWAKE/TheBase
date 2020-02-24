#ifndef OPENGLRENDER_H_INCLUDED
#define OPENGLRENDER_H_INCLUDED

#include <stdbool.h>



struct _Render;
struct _Mesh;

bool Render_OpenGL_Init(struct _Render*);
void Render_OpenGL_Shutdown(struct _Render*);

void Render_OpenGL_DrawMesh(Render* curRender, Mesh* mesh, Mat4f* transform);

#endif // OPENGLRENDER_H_INCLUDED
