#include "Render.h"

#include <stdio.h>

#include "Mesh.h"


bool Render_Init(Render* curRender)
{
	glfwInit();

	Window_Create(&curRender->window, 700, 600, "Window", false);

	glfwMakeContextCurrent(curRender->window.win);

	switch(curRender->CurrentAPI)
	{
#ifdef USING_VULKAN
		case APIVulkan:
		if(Render_Vulkan_Init(curRender))
			return true;
		else
			return Render_OpenGL_Init(curRender);
		break;
#endif
		case APIOpenGL:
		Render_OpenGL_Shutdown(curRender);
		break;

		default:
		//TODO: Log error no compatable API
		break;
	}
	

	printf("Initalized!");

	
	return true;
}

void Render_Update(Render* curRender)
{
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	
	//glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(curRender->window.win);
	glfwPollEvents();

}

void Render_Shutdown(Render* curRender)
{
	Window_Destroy(&curRender->window);
	


	switch(curRender->CurrentAPI)
	{
#ifdef USING_VULKAN
		case APIVulkan:
		Render_Vulkan_Shutdown(curRender);
		break;
#endif
		case APIOpenGL:
		Render_OpenGL_Shutdown(curRender);
		break;

		default:
		//TODO: Log error no compatable API
		break;
	}

	glfwTerminate();

}

void Render_DrawMesh(Render* curRender, Mesh* mesh, fMatrix4 transform)
{
	
	switch(curRender->CurrentAPI)
	{
#ifdef USING_VULKAN
		case APIVulkan:
		Render_Vulkan_DrawMesh(curRender, mesh, transform);
		break;
#endif
		case APIOpenGL:
		Render_OpenGL_DrawMesh(curRender, mesh, transform);
		break;

		default:
		//TODO: Log error no compatable API
		break;
	}
	
}









