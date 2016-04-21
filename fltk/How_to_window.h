#ifndef How_to_WINDOW_GUARD
#define How_to_WINDOW_GUARD 1
#include "GUI.h"   
#include "Graph.h"
#include "My_Window.h"


using namespace Graph_lib;


struct How_to_window : My_Window
 {
    How_to_window( My_Window* prev_window );

	int wait_for_button(); // used to display the window and returns state.   0 means go to next window

private:
    Button quit_button; // quit button
	Button next_button; // next button
	static void cb_next(Address, Address); // callback for play button
    static void cb_quit(Address, Address);  // callback for the quit button
    void next(); // changes the state to play and closes the window
	void quit(); // changes the state to quit and closes the window
	int state = 1; // closes the window if you click the X at the top
	Text t0; //Text line 1
	Text t1;
	Text t2;
	Text t3;
	Text t4;
	Text t5;
	Text t6;
	Text t7;
 };

#endif