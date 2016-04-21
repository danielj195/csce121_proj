#ifndef MY_WINDOW_GUARD
#define MY_WINDOW_GUARD 1

#include "Graph.h"
#include "GUI.h"

class My_Window : public Graph_lib::Window
{
	public:
		My_Window(Point xy, int w, int h, My_Window *window);
};

#endif