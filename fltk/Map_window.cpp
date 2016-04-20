#include "std_lib_facilities_4.h"
//#include "Map_window.h"
#include "screens.h"

using namespace Graph_lib;



Map_window::Map_window(My_Window* prev_window, int difficulty) :
	My_Window(Point(100,100),1110,600,prev_window),// difficulty),
	quit_button(Point(x_max()-80,20), 60, 40, "Quit", cb_quit),
	submit_button(Point(x_max()-120,450), 50, 50, "Enter", cb_submit),
	up_button(Point(x_max()-120,390), 50, 50, "N", cb_up),
	down_button(Point(x_max()-120,510), 50, 50, "S", cb_down),
	left_button(Point(x_max()-180,450), 50, 50, "W", cb_left),
	right_button(Point(x_max()-60,450), 50, 50, "E", cb_right),
	sat_menu_button(Point(x_max()-250,20), 75, 40, "Satellites", cb_menu),
	Map(Point(10,3),"Maps.gif"),
	sat_menu(Point(x_max()-250,20),40,40,Menu::vertical,"satellite"),
	
	/* satellites()
		:new Circle (Point(5,5), 50)
		{}, */
	moves(Point(x_max()-150,130),"Moves: "),
	score(Point(x_max()-150,190),"Score: "),
	clock(Point(x_max()-150,250),"Time: "),
	current_score(Point(x_max()-100,160),70,50,""),
	//initials(Point(x_max()-140,20),50,50,"init"),
	output_time(Point(x_max()-100,220),70,50,"")
	//num_moves(Point(x_max()-100,100),50,50,"")
	
	

{
	/* for(int i = 0; i < win4->num_satellites; ++i){
		satellites.push_back(new Graph_lib::Circle(Point(100*i,100),50));
	} */
	attach(quit_button);
	attach(submit_button);
	attach(up_button);
	attach(down_button);
	attach(left_button);
	attach(right_button);
	attach(sat_menu_button);
	attach(Map);
	attach(sat_menu);
	/* for(int i = 0; i < win4->num_satellites; ++i){
		win4->attach(satellites[i]);
		win4->redraw();
	} */
	attach(moves);
	attach(score);
	attach(clock);
	attach(current_score);
	//attach(initials);
	attach(output_time);
	//attach(num_moves);
};


void Map_window::cb_quit(Address, Address pw) 
{  
    reference_to<Map_window>(pw).quit();    
}

void Map_window::quit() // quits game
{
	
}

//submit_button
void Map_window::cb_submit(Address, Address pw) 
{  
    reference_to<Map_window>(pw).submit();    
}

void Map_window::submit() // quits game
{
	
}

//up_button
void Map_window::cb_up(Address, Address pw) 
{  
    reference_to<Map_window>(pw).up();    
}

void Map_window::up() // quits game
{
	
}

//down_button
void Map_window::cb_down(Address, Address pw) 
{  
    reference_to<Map_window>(pw).down();    
}

void Map_window::down() // quits game
{
	
}

//left_button
void Map_window::cb_left(Address, Address pw) 
{  
    reference_to<Map_window>(pw).left();    
}

void Map_window::left() // quits game
{
	
}

//right_button
void Map_window::cb_right(Address, Address pw) 
{  
    reference_to<Map_window>(pw).right();    
}

void Map_window::right() // quits game
{
	
}

//sat_menu_button
void Map_window::cb_menu(Address, Address pw) 
{  
    reference_to<Map_window>(pw).menu();    
}

void Map_window::menu() // quits game
{
	
}

void Map_window::draw_sats(int difficulty) // draws satellites
{
	for(int i = 0; i < difficulty; ++i){
		satellites.push_back(new Graph_lib::Circle(Point(100*i,100),50));
		attach(satellites[i]);
	}
}

