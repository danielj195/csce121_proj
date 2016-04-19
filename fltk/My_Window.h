#ifndef High_score_WINDOW_GUARD
#define High_score_GUARD 1

#include "Graph.h"

class My_Window : public Graph_lib::Window
{
	public:
		My_Window(Point xy, int w, int h, My_Window *window);
}

#endif