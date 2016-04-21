#ifndef MAP_WINDOW_GUARD
#define MAP_WINDOW_GUARD 1
#include <vector>
#include "std_lib_facilities_4.h"
#include "GUI.h"   
#include "Graph.h"
#include "My_Window.h"
#include "Satellite.h"

using namespace Graph_lib;

//class Shape;

struct Map_window : My_Window  
{
    Map_window(My_Window* prev_window, int difficulty);
	void draw_sats(int difficulty); //draw satellites

private:
    Button quit_button; // quit button
	Button submit_button; //enters new coordinates
	Button up_button;
	Button down_button;
	Button left_button;
	Button right_button;
	Button sat_menu_button;
    static void cb_quit(Address, Address);  // callback for the quit button
	static void cb_submit(Address, Address); 
	static void cb_up(Address, Address); 
	static void cb_down(Address, Address); 
	static void cb_left(Address, Address); 
	static void cb_right(Address, Address); 
	static void cb_menu(Address, Address); //for menu
	static void cb_menu_buttons(Address, Address);
	static void cb_return_label(Address, Address);
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
	void select(int);
	void wrapper();
	/* void hide_menu();
	void hide_button(Address _b);
	void show_menu();
	void show_button(Address _b); */
	void return_label(Address flb);
	int sat_selector;
	int num_moves = 0;
	
	//int state = 1;  closes the window if you click the X at the top
	
	Text moves;
	Text score;
	Text clock;
	Out_box current_score;
	//Out_box initials;
	Out_box output_time;
	//Out_box num_moves;
	//Vector_ref<Text> initials;
	//Vector_ref<Text> scores;
	
};
#endif