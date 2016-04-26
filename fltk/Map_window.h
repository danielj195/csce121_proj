#ifndef MAP_WINDOW_GUARD
#define MAP_WINDOW_GUARD 1
#include <vector>
#include "std_lib_facilities_4.h"
#include "GUI.h"   
#include "Graph.h"
#include "My_Window.h"
#include "Satellite.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <iostream>

using namespace Graph_lib;



struct Map_window : My_Window  
{
    Map_window(My_Window* prev_window, int difficulty);
	void draw_sats(int difficulty); //draws satellites on map
	Out_box sat_num; //Output number of satellites
	static void Timer_CB(void *data); //Callback for timer
	int best_score;

private:
    Button quit_button; // quit button
	Button submit_button; //enters new coordinates
	Button up_button;
	Button down_button;
	Button left_button;
	Button right_button;
	Button sat_menu_button;
    static void cb_quit(Address, Address);  
	static void cb_submit(Address, Address); 
	static void cb_up(Address, Address); 
	static void cb_down(Address, Address); 
	static void cb_left(Address, Address); 
	static void cb_right(Address, Address); 
	static void cb_menu(Address, Address); 
	static void cb_menu_buttons(Address, Address);
	
	Image Map;
	Menu sat_menu;
	Vector_ref<Satellite> satellites; //satellites
	Vector_ref<Button> sat_options; //menu selections
	void quit(); // changes the state to quit and closes the window
	void submit(); //places the score and initials onto the high score 
	void up(); //places the score and initials onto the high score 
	void down(); //places the score and initials onto the high score 
	void left(); //places the score and initials onto the high score 
	void right(); //places the score and initials onto the high score 
	void menu();	//open menu
	void select(int);  //Selects a satellite from menu
	void wrapper(); //Allows satellite to wrap around map
	double Step_size(int); //Returns the allowable change in position based on number of moves
	
	
	int sat_selector = 0;
	int num_moves = 0;
	bool menu_state = 1; //Used to determine if menu is open
	
	vector<int> move_state = {1,1,1,1,0}; //Boolean values that determine where a satellite can move
	int map_w = 708; //map width
	int map_h = 600; //map height
	
	Text latitude;
	Text longitude;
	
	Out_box current_score;
	static Out_box output_time;
	Out_box count_moves; //Output number of moves
	Out_box lat_val;
	Out_box long_val;

	
};

#endif