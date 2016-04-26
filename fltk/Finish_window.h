#ifndef FINISH_WINDOW_GUARD
#define FINISH_WINDOW_GUARD 1
#include "GUI.h"   
#include "My_Window.h"


using namespace Graph_lib;


struct Finish_window : My_Window 
{
    Finish_window(My_Window* prev_window, int best_score);
	Out_box final_score;
	void report(int best_score); //Function for reporting final score
private:
    Button quit_button; // quit button
	Button play_button; // play button
	static void cb_play(Address, Address); // callback for play button
    static void cb_quit(Address, Address);  // callback for the quit button
    void play(); // changes the state to play 
	void quit(); // changes the state to quit 
};

#endif