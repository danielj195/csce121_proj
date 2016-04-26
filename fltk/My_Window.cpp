#include "My_Window.h"

//This class deletes the previous pointer to a window
My_Window::My_Window(Point xy, int w, int h, My_Window *window)
	: Window(xy, w, h, "Earth Defender")
{
	delete window;
}