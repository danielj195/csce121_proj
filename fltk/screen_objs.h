#ifndef SCREENS_GUARD
#define SCREENS_GUARD 1
#include "screens.h"
#include "High_score_window.h"
#include "Map_window.h"
#include "Splash_window.h"
#include "How_to_window.h"
//DELETE
Splash_window win(Point (100,100), 600, 400, "Earth Defender");
How_to_window win2(Point (100,100), 600, 400, "Earth Defender");
High_score_window* win3 = new High_score_window(Point (100,100), 600, 400, "Earth Defender");
//Map_window* win4 = new Map_window(Point (100,100), 1200, 600, "Earth Defender");
Map_window* win4 = nullptr;

void delete_all()
{
	delete win;
	win = nullptr;
	delete win2;
	win2 = nullptr;
	delete win3;
	win3 = nullptr;
	delete win4;
	win4 = nullptr;
}

void load_win3()
{
	delete_all();
	win3 = new High_score_window(Point(100, 100), 600, 400, "Earth Defender");
}

void load_win4(int num_satellites)
{
	delete_all();
	win4 = new Map_window(Point (100,100), 1200, 600, "Earth Defender", num_satellites);
}


#endif