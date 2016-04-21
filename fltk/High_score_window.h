#ifndef High_score_WINDOW_GUARD
#define High_score_WINDOW_GUARD 1 //WINDOW GUARDS NEED TO BE THE SAME!!!!!
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
	Button next_score_button;  //next score button
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
	In_box input_name;
	In_box  lvl;
	In_box input_score;
	
	public:
	Out_box score1;
	Out_box score2;
	Out_box score3;
	Out_box score4;
	Out_box score5;
	Out_box name1;
	Out_box name2;
	Out_box name3;
	Out_box name4;
	Out_box name5;
	
};


#endif
