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
	lvl(Point(500,250), 50, 50, "level(1-8)"),
	//Vector_ref<Out_box> values(20)
	//score(Point(300,500), 50, 50, "Score"),
	input_score(Point(500,450), 50, 50,"Score"),
	score1(Point(300,75), 50, 50, ""),
	score2(Point(300,150), 50, 50, ""),
	score3(Point(300,225), 50, 50, ""),
	score4(Point(300,300), 50, 50, ""),
	score5(Point(300,375), 50, 50, ""),
	name1(Point(225,75), 50, 50, ""),
	name2(Point(225,150), 50, 50, ""),
	name3(Point(225,225), 50, 50, ""),
	name4(Point(225,300), 50, 50, ""),
	name5(Point(225,375), 50, 50, "")
	
	//top_scores(5);
	
	
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
	//attach(input_score);
	Fl_Widget::color(Color::white);
	attach(score1);
	attach(score2);
	attach(score3);
	attach(score4);
	attach(score5);
	attach(name1);
	attach(name2);
	attach(name3);
	attach(name4);
	attach(name5);

}


void High_score_window::cb_next(Address, Address pw) // button callback for next
{  
    reference_to<High_score_window>(pw).next();    
}

void High_score_window::next() // sets state to next and closes window
{
	int a = lvl.get_int();
	Map_window* win = new Map_window(this,a);
	win->draw_sats(a);
	//win->redraw();
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
	string b = input_name.get_string();
	int c = input_score.get_int();
	//std::cout << b << "\n" << c
	
	Track_scores data;
	
	
	data.scores = data.read_entries();
	data.sort_entries(b,c,data.scores);
	data.output_entries(data.scores);
	
	ostringstream ss;
	ostringstream ss1;
	ostringstream ss2;
	ostringstream ss3;
	ostringstream ss4;
	ostringstream ss5;
	ostringstream ss6;
	ostringstream ss7;
	ostringstream ss8;
	ostringstream ss9;
	
	ss << data.scores[0].initial;
	name1.put(ss.str());
	
	ss1 << data.scores[0].score;
	score1.put(ss1.str());
	
	ss2 << data.scores[1].initial;
	name2.put(ss2.str());
	
	ss3 << data.scores[1].score;
	score2.put(ss3.str());
	
	ss4 << data.scores[2].initial;
	name3.put(ss4.str());
	
	ss5 << data.scores[2].score;
	score3.put(ss5.str());
	
	ss6 << data.scores[3].initial;
	name4.put(ss6.str());
	
	ss7 << data.scores[3].score;
	score4.put(ss7.str());
	
	ss8 << data.scores[4].initial;
	name5.put(ss8.str());
	
	ss9 << data.scores[4].score;
	score5.put(ss9.str());
	
	redraw();
	*/
} 

/* int High_score_window::wait_for_button() // used to display the window and returns state.   
{
	show();
	Fl::run();
	return state;
} */
