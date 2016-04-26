#include "How_to_window.h"
#include "screens.h"
#include "Track_scores.h"

using namespace Graph_lib;


How_to_window::How_to_window( My_Window* prev_window) :
    My_Window(Point(100,100),600,600,prev_window),
    next_button(Point(x_max()-80,10), 70, 40, "Next", cb_next), //Initialize next button
	quit_button(Point(x_max()-80,60), 70, 40, "Quit", cb_quit), //Initialize quit button
	page_2(Point(0,0),"projectp2.gif")

{
    attach(quit_button);
	attach(next_button);
	attach(page_2);
	
}

void How_to_window::cb_next(Address, Address pw) // button callback for next
{  
    reference_to<How_to_window>(pw).next();    
}

void How_to_window::next() //Call back for next button
{
	High_score_window* win = new High_score_window(this,0); //Go to high score window when next button is clicked
	win->make_boxes();
	Track_scores data;
	data.scores = data.read_entries(); //Read high sores from text file
	ostringstream ss1;
	ostringstream ss2;
	for(int i = 0; i<5; ++i){  //Output high sores to screen
		ss1 << data.scores[i].initial;
		ss2 << data.scores[i].score;
		win->names[i].put(ss1.str());
		win->scores[i].put(ss2.str());
		ss1.str("");
		ss2.str("");
	}
	win->input_name.hide(); //Hide unwanted features
	win->next_score_button.hide();
	win->next1_button.hide();
	win->redraw();
}
void How_to_window::cb_quit(Address, Address pw) // callback for quit button
{  
    reference_to<How_to_window>(pw).quit();    
}

void How_to_window::quit() //quits the game
{
	hide();
}
