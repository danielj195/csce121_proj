#ifndef High_score_WINDOW_GUARD
#define High_score_WINDOW_GUARD 1 
#include "GUI.h"   
#include "Graph.h"
#include "My_Window.h"



using namespace Graph_lib;


struct High_score_window : My_Window 
{
    High_score_window(My_Window* prev_window, int best_score); 
	In_box  lvl;
	int highest_score;
	Button next1_button; //goes to finish window
	Button next_button; // next button

private:
    Button quit_button; // quit button
	static void cb_next(Address, Address); // callback for next button
	static void cb_next1(Address, Address); // callback for next button (for quitting the game)
    static void cb_quit(Address, Address);  // callback for the quit button
	static void cb_score(Address, Address);  // callback for the next score button button
    void next(); // changes the state to play and closes the window
	void next1(); //goes to finish window
	void quit(); // changes the state to quit and closes the window
	void score(); //places the score and initials onto the high score list and organizes
	int enter_state = 1; //Determines whether score has already been submitted
	Text title;
	Text first;
	Text second;
	Text third;
	Text fourth;
	Text fifth;
	
	
	
	public:
	In_box input_name;
	Button next_score_button;  //next score button
	void make_boxes(); //Function for making outboxes for high scores and initials
	Vector_ref<Out_box> scores;
	Vector_ref<Out_box> names;
	
};


#endif
