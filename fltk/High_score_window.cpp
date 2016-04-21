//#include "High_score_window.h"
#include "Track_scores.h"
#include <vector>
#include "std_lib_facilities_4.h"
//#include "Map_window.h"
#include "screens.h"

using namespace Graph_lib;


High_score_window::High_score_window(My_Window* prev_window) ://, vector<Entry> top_scores) ://High_score_window constructor
    My_Window(Point(100,100),600,600, prev_window),
    next_button(Point(x_max()-80,10), 70, 40, "Next", cb_next), //button location
	next_score_button(Point(480,550), 90, 40, "Enter Score", cb_score), //button location
	quit_button(Point(x_max()-80,60), 70, 40, "Quit", cb_quit), // button location
	title(Point(250,50),"Highscores"),
	first(Point(200,100),"1."),
	second(Point(200,175),"2."),
	third(Point(200,250),"3."),
	fourth(Point(200,325),"4."),
	fifth(Point(200,400),"5."),
	input_name(Point(500,350), 50, 50, "Initials"),
	lvl(Point(500,250), 50, 50, "level(2-8)"),
	//Vector_ref<Out_box> values(20)
	//score(Point(300,500), 50, 50, "Score"),
	input_score(Point(500,450), 50, 50,"Score")
	
	
{
    attach(quit_button);
	attach(next_button);
	attach(title);
	attach(first);
	attach(second);
	attach(third);
	attach(fourth);
	attach(fifth);
	attach(input_name);
	attach(lvl);
	attach(next_score_button);
	attach(input_score);
	Fl_Widget::color(Color::white);

}


void High_score_window::make_boxes() // button callback for next
{  
    for(int i = 0; i<5; ++i){
		scores.push_back(new Out_box(Point(300,75 + i*75), 50, 50, ""));
		names.push_back(new Out_box(Point(225,75 + i*75), 50, 50, ""));
		attach(scores[i]);
		attach(names[i]);
	}
}

void High_score_window::cb_next(Address, Address pw) // button callback for next
{  
    reference_to<High_score_window>(pw).next();    
}

void High_score_window::next() // sets state to next and closes window
{
	int a = lvl.get_int();
	int sat = 1; //default sat number
	if(a<2){
		a = 2;
	}
	else if(a>8){
		a = 8;
	}
	Map_window* win = new Map_window(this,a);
	ostringstream ss;
	ss << 1;
	win->sat_num.put(ss.str());
	win->draw_sats(a);
	win->redraw();
}
void High_score_window::cb_quit(Address, Address pw) // button callback for quit
{  
    reference_to<High_score_window>(pw).quit();    
}

void High_score_window::quit() // sets state to quit and closes window
{
	state = 1;
	hide();
}
void High_score_window::cb_score(Address, Address pw) // button callback for score
{  
    reference_to<High_score_window>(pw).score();    
}
 void High_score_window::score()  
{
	/*
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
	redraw();
	*/
} 


