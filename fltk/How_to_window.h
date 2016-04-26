#ifndef How_to_WINDOW_GUARD
#define How_to_WINDOW_GUARD 1
#include "GUI.h"   
#include "Graph.h"
#include "My_Window.h"


using namespace Graph_lib;

//image citation:  http://www.nasa.gov/content/an-astronauts-view-from-space
struct How_to_window : My_Window
 {
    How_to_window( My_Window* prev_window );

private:
    Button quit_button; // quit button
	Button next_button; // next button
	Image page_2;
	static void cb_next(Address, Address); // callback for play button
    static void cb_quit(Address, Address);  // callback for the quit button
    void next(); // changes the state to play and closes the window
	void quit(); // changes the state to quit and closes the window
	
 };

#endif