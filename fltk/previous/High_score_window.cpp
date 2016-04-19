#include "High_score_window.h"
#include "Track_scores.h"
#include <vector>

using namespace Graph_lib;


High_score_window::High_score_window(Point xy, int w, int h, const string& win_title) ://, vector<Entry> top_scores) ://High_score_window constructor
    Window(Point(100,100),600,600,win_title),
    next_button(Point(x_max()-80,10), 70, 40, "Next", cb_next), //button location
	next_score_button(Point(480,550), 90, 40, "Enter Score", cb_next), //button location
	quit_button(Point(x_max()-80,60), 70, 40, "Quit", cb_quit), // button location
	title(Point(250,50),"Highscores"),
	input_name(Point(500,350), 50, 50, "Initials"),
	lvl(Point(500,250), 50, 50, "level(1-8)"),
	//score(Point(300,500), 50, 50, "Score"),
	input_score(Point(500,450), 50, 50,"Score")
	//top_scores(5);
	
	
{
    attach(quit_button);
	attach(next_button);
	attach(title);
	attach(input_name);
	attach(lvl);
	attach(next_score_button);
	attach(input_score);
	Fl_Widget::color(Color::white);
	/*  for(int i = 0; i< top_initials.size()&& i<5; ++i)
		{
			initials.push_back(new Text(Point(150,40*i+120), top_initials[i]));
			attach(initials[i]);
			//initials[i].set_font(Graph_lib::Font:: what you want);
			//initials[i].set_font_size(int);
		}
	 for(int i = 0; i < top_scores.size()&& i<5; ++i)
	 {
		 scores.push_back(new Text(Point(300,40*i+120), to_string(top_scores[i])));
			attach(scores[i]);
			//scores[i].set_font(Graph_lib::Font:: what you want);
			//scores[i].set_font_size(int);
	 } */

}


void High_score_window::cb_next(Address, Address pw) // button callback for next
{  
    reference_to<High_score_window>(pw).next();    
}

void High_score_window::next() // sets state to next and closes window
{
	state = 0; 
	hide();
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
void High_score_window::score() // 
{
	
}
/*High_score_window::Entry High_score_window::make_entry(string a, int b) // button callback for score
{  
	Entry c = {a,b};
	return c;
}
bool High_score_window::compare_scores(const Entry& a, const Entry& b)
{
    return a.score < b.score;
}
void High_score_window::sort_scores(vector<Entry>& a)
{
	sort(a.begin(),a.end(),compare_scores);
}
 void High_score_window::read_scores(string a)
{
	ifstream ist{a}
	if(!ost)error("can't open input file",a);
	
} 
void High_score_window::get_score(vector<pair<string,int>> top_scores2)//vector<Entry>& a) // button callback for score
{  
	//a.push_back(make_entry(input_name.get_string(),input_score.get_int()));
	top_scores2.push_back(make_pair(input_name.get_string(),input_score.get_int()));
}*/
int High_score_window::wait_for_button() // used to display the window and returns state.   
{
	show();
	Fl::run();
	return state;
}
