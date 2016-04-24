#include "How_to_window.h"
#include "screens.h"
#include "Track_scores.h"
//#include "My_Window.h"

using namespace Graph_lib;


How_to_window::How_to_window( My_Window* prev_window) ://How_to_window constructor
    My_Window(Point(100,100),600,600,prev_window),
    next_button(Point(x_max()-80,10), 70, 40, "Next", cb_next),
	quit_button(Point(x_max()-80,60), 70, 40, "Quit", cb_quit),
	t0(Point(75,150),"Citizen we need your help.  We have just received a distress call from"),// text line 1
	t1(Point(75,165),"our outpost on Mars. They have reported a massive fleet of aliens space"),// "" 2
	t2(Point(75,180),"craft headed towards Earth.  Help position the shield generators around"),// "" 3
	t3(Point(75,195),"the planet to fend of the imminent alien invasion."),// "" 4
	
	t4(Point(75,220),"How to Play"),// "" 5
	t5(Point(75,235),"You will have 5 minutes and 50 moves to position the shield generators"),// "" 6
	t6(Point(75,250),"around the planet.  First click the satellite button to select the"),// "" 7
	t7(Point(75,265),"satellite you would like to move.  Then use the arrow buttons to move"),
	t8(Point(75,280),"the satellite.  Once you move the satellite Click the Enter button to"),
	t9(Point(75,295),"record your move.  Click the Quit button if you are are satisfied with"),
	t10(Point(75,310),"your movements or wait 5 minutes to end the game.  ")
{
    attach(quit_button);
	attach(next_button);
	attach(t0); // attached text 1
	attach(t1);
	attach(t2);
	attach(t3);
	attach(t4);
	attach(t5);
	attach(t6);
	attach(t7);
	attach(t8);
	attach(t9);
	attach(t10);
	Fl_Widget::color(Color::white); //background color
}

void How_to_window::cb_next(Address, Address pw) // button callback for next
{  
    reference_to<How_to_window>(pw).next();    
}

void How_to_window::next() // sets state to next and closes window
{
	High_score_window* win = new High_score_window(this);
	win->make_boxes();
	Track_scores data;
	data.scores = data.read_entries();
	//data.sort_entries(b,c,data.scores);
	//data.output_entries(data.scores);
	ostringstream ss1;
	ostringstream ss2;
	for(int i = 0; i<5; ++i){
		ss1 << data.scores[i].initial;
		ss2 << data.scores[i].score;
		win->names[i].put(ss1.str());
		win->scores[i].put(ss2.str());
		ss1.str("");
		ss2.str("");
	}
	win->input_score.hide();
	win->input_name.hide();
	win->next_score_button.hide();
	redraw();
}
void How_to_window::cb_quit(Address, Address pw) // button callback for quit
{  
    reference_to<How_to_window>(pw).quit();    
}

void How_to_window::quit() // sets state to quit and closes window
{
	hide();
}
