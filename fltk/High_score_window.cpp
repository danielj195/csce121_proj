#include "Track_scores.h"
#include <vector>
#include "std_lib_facilities_4.h"
#include "screens.h"

using namespace Graph_lib;


High_score_window::High_score_window(My_Window* prev_window, int best_score) :
    My_Window(Point(100,100),600,600, prev_window),
    next_button(Point(x_max()-80,10), 70, 40, "Next", cb_next), 
	next1_button(Point(x_max()-80,10), 70, 40, "Next", cb_next1), //second next button is for quitting the game
	next_score_button(Point(480,550), 90, 40, "Enter", cb_score), 
	quit_button(Point(x_max()-80,60), 70, 40, "Quit", cb_quit), 
	title(Point(250,50),"Highscores"),
	first(Point(200,100),"1."),
	second(Point(200,175),"2."),
	third(Point(200,250),"3."),
	fourth(Point(200,325),"4."),
	fifth(Point(200,400),"5."),
	input_name(Point(500,475), 50, 50, "Initials"),
	lvl(Point(500,250), 50, 50, "level(2-8)")
	
{
    attach(quit_button);
	attach(next_button);
	attach(next1_button);
	attach(title);
	attach(first);
	attach(second);
	attach(third);
	attach(fourth);
	attach(fifth);
	attach(input_name);
	attach(lvl);
	attach(next_score_button);
	Fl_Widget::color(Color::white);
	highest_score = best_score;

}


void High_score_window::make_boxes() // Displays vector of outboxes used for high scores
{  
    for(int i = 0; i<5; ++i){
		scores.push_back(new Out_box(Point(300,75 + i*75), 50, 50, ""));
		names.push_back(new Out_box(Point(225,75 + i*75), 50, 50, ""));
		attach(scores[i]);
		attach(names[i]);
	}
	//cout<<best_score<<"\n";
}

void High_score_window::cb_next(Address, Address pw) // button callback for next
{  
    reference_to<High_score_window>(pw).next();    
}

void High_score_window::next() // Goes to Map Window when next button is clicked
{
	int a = lvl.get_int();
	int sat = 1; //default satellite number to display
	if(a<2){  //Sets default satellite numbers if level >8 or <2 is typed in inbox
		a = 2;
	}
	else if(a>8){
		a = 8;
	}
	Map_window* win = new Map_window(this,a);
	ostringstream ss;
	ss << 1;
	win->sat_num.put(ss.str());
	win->draw_sats(a);  //Draw satellites and start timer
	Fl::add_timeout(1, Map_window::Timer_CB,win);
	win->redraw();
}

//Next1 Button
void High_score_window::cb_next1(Address, Address pw) //Callback for next1 button
{  
    reference_to<High_score_window>(pw).next1();    
}

void High_score_window::next1() // Goes to Finish Window when next1 button is pressed
{
	Finish_window* win = new Finish_window(this,highest_score);
	win->report(highest_score);  //Show the final score achieved in game sesssion
}

void High_score_window::cb_quit(Address, Address pw) // button callback for quit
{  
    reference_to<High_score_window>(pw).quit();    
}

void High_score_window::quit() // quits game
{
	hide();
}
void High_score_window::cb_score(Address _b, Address pw) //callback for score button
{  
    reference_to<High_score_window>(pw).score();    
}
 void High_score_window::score()  
{
	if(enter_state == 1){
		Track_scores data;
		data.scores = data.read_entries(); //Read high scores from text file
		string str_b = input_name.get_string();
		int int_c = highest_score;    //Gather high score and user's initials
		data.sort_entries(str_b,int_c,data.scores); //Sort high scores
		data.output_entries(data.scores); //Output scores to textfile
		data.scores = data.read_entries();
		ostringstream ss1;
		ostringstream ss2;
		for(int i = 0; i<5; ++i){
			ss1 << data.scores[i].initial;  //Output scores to screen
			ss2 << data.scores[i].score;
			names[i].put(ss1.str());
			scores[i].put(ss2.str());
			ss1.str("");
			ss2.str("");
		}
		redraw();
	}
	enter_state = 0;
} 


