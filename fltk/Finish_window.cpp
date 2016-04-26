#include "screens.h"

using namespace Graph_lib;


Finish_window::Finish_window(My_Window* prev_window, int best_score) :
    My_Window(Point(100,100),600,600, prev_window),
	final_score(Point(x_max()-300,300),70,50,"Final Score: "),
    play_button(Point(x_max()-400,200), 80, 40, "Play Again", cb_play),
	quit_button(Point(x_max()-200,200), 70, 40, "Quit", cb_quit)

{
    attach(quit_button);
	attach(play_button);
	attach(final_score);
}

void Finish_window::cb_play(Address, Address pw) // button callback for play
{  
    reference_to<Finish_window>(pw).play();    
}

void Finish_window::play() // sets state to play and closes window
{
	Splash_window* win = new Splash_window(this); 
	
}
void Finish_window::cb_quit(Address, Address pw) // button callback for quit
{  
    reference_to<Finish_window>(pw).quit();    
}

void Finish_window::quit() //  closes window permanently
{
	hide();
}

void Finish_window::report(int best_score){
	ostringstream ss;
	ss << best_score; //Displays session score in outbox
	final_score.put(ss.str());
	redraw();
}