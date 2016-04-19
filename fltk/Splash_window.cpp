//#include "Splash_window.h"
#include "screens.h"
using namespace Graph_lib;


Splash_window::Splash_window(My_Window* prev_window) ://Splash_window constructor
    My_Window(Point(100,100),600,600, prev_window),
    play_button(Point(x_max()-80,10), 70, 40, "Play", cb_play),
	quit_button(Point(x_max()-80,60), 70, 40, "Quit", cb_quit),
	page_1(Point(0,0),"project.gif")
{
    attach(quit_button);
	attach(play_button);
	attach(page_1); // attached image
}

void Splash_window::cb_play(Address, Address pw) // button callback for play
{  
    reference_to<Splash_window>(pw).play();    
}

void Splash_window::play() // sets state to play and closes window
{
	//state = 0; 
	//hide();
	
	How_to_window* win = new How_to_window(this); 
	
}
void Splash_window::cb_quit(Address, Address pw) // button callback for quit
{  
    reference_to<Splash_window>(pw).quit();    
}

void Splash_window::quit() // sets state to quit and closes window
{
	state = 1;
	hide();
}
int Splash_window::wait_for_button() // used to display the window and returns state.   
{
	show();
	Fl::run();
	return state;
}
