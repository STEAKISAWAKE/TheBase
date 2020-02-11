#include "Render.h"

void Render_Init(Render* curRender)
{
	glfwInit();

	curRender->window = CreateRenderWindow(700, 600, "Window", false);



}

void Render_UpdateWindow(Render* curRender)
{

	glfwSwapBuffers(curRender->window->win);
	glfwPollEvents();

}

void Render_Shutdown(Render* curRender)
{
	DestroyRenderWindow(curRender->window);


}
