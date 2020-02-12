

#include <stdlib.h>

#include "Window.h"

#include <GLFW/glfw3.h>

void Window_Create(Window* curWindow,int width, int height, const char* name, bool fullscreen)
{


	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	curWindow->win = glfwCreateWindow(width, height, name, NULL, NULL);

}

void Window_Destroy(Window* destroyWin)
{
	glfwDestroyWindow(destroyWin->win);
}
