#ifndef High_score_WINDOW_GUARD
#define High_score_WINDOW_GUARD 1 
#include "GUI.h"   
#include "Graph.h"
#include "My_Window.h"



using namespace Graph_lib;


struct High_score_window : My_Window 
{
    High_score_window(My_Window* prev_window);//vector<Entry> top_scores);
	int wait_for_button(); // used to display the window and returns state.   

private:
    Button quit_button; // quit button
	Button next_button; // next button
	static void cb_next(Address, Address); // callback for play button
    static void cb_quit(Address, Address);  // callback for the quit button
	static void cb_score(Address, Address);  // callback for the next score button button
    void next(); // changes the state to play and closes the window
	void quit(); // changes the state to quit and closes the window
	void score(); //places the score and initials onto the high score list and organizes
	int state = 1; // closes the window if you click the X at the top
	
	Text title;
	Text first;
	Text second;
	Text third;
	Text fourth;
	Text fifth;
	In_box  lvl;
	
	
	public:
	In_box input_name;
	In_box input_score;
	Button next_score_button;  //next score button
	void make_boxes();
	Vector_ref<Out_box> scores;
	Vector_ref<Out_box> names;
	
};


#endif
