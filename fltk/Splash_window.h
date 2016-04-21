#ifndef SPLASH_WINDOW_GUARD
#define SPLASH_WINDOW_GUARD 1
#include "GUI.h"   
#include "My_Window.h"

//image from http://www.bandwidthplace.com/satellite-internet-services/

using namespace Graph_lib;


struct Splash_window : My_Window 
{
    Splash_window(My_Window* prev_window);

	//int wait_for_button(); // used to display the window and returns state.   

private:
    Button quit_button; // quit button
	Button play_button; // play button
    Image page_1; // this is the picture for part 1
	static void cb_play(Address, Address); // callback for play button
    static void cb_quit(Address, Address);  // callback for the quit button
    void play(); // changes the state to play and closes the window
	void quit(); // changes the state to quit and closes the window
	int state = 1; // closes the window if you click the X at the top
};

#endif
