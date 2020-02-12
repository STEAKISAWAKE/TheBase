#include "Render.h"

#include <stdio.h>

#include "glad/glad.h"

bool Render_Init(Render* curRender)
{
	glfwInit();

	Window_Create(&curRender->window, 700, 600, "Window", false);

	glfwMakeContextCurrent(curRender->window.win);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Error could not initalize GLAD!");
		glfwTerminate();
		return false;
	}

	printf("Initalized!");

	
	return true;
}

void Render_UpdateWindow(Render* curRender)
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);	

	glfwSwapBuffers(curRender->window.win);
	glfwPollEvents();

}

void Render_Shutdown(Render* curRender)
{
	Window_Destroy(&curRender->window);


}
