#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <stdbool.h>

#include <GLFW/glfw3.h>

struct _Window
{

	GLFWwindow* win;

};

typedef struct _Window Window;

void Window_Create(Window*, int, int, const char*, bool fullscreen); // Opens a window
void Window_Destroy(Window*); // Closes a window and destroys the pointer

#endif // WINDOW_H_INCLUDED
