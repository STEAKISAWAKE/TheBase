#include "Render.h"

#include <stdio.h>


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

#ifdef USING_VULKAN // If using vulkan initalize Vulkan and if it fails initalize opengl

	if (Render_Vulkan_Init(curRender))
	{
		// Debug log that vulkan initalized 
	}
	else
	{
		// Debug log that vulkan failed

		if (Render_OpenGL_Init(curRender))
		{
			 // Debug log opengl initalized instead
		}
		else // This code should hopefully never execute
		{
			// Debug log that all renderers failed to initalize
			return false;
		}

	}


#else // If not using vulkan just initalize opengl

	//Vulkan not being used here.

	if (Render_OpenGL_Init(curRender))
	{
		// Debug log opengl initalized renderer

	}
	else // This code should hopefully never execute
	{
		// Debug log could not initalize renderer
		return false;
	}

#endif



	

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

void Render_DrawMesh(Render* curRender, _Mesh* mesh, fMatrix4 transform)
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









