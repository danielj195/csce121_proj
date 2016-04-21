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
	//sat_selector = 0;

{
	
	attach(quit_button);
	attach(submit_button);
	attach(up_button);
	attach(down_button);
	attach(left_button);
	attach(right_button);
	attach(sat_menu_button);
	attach(Map);
	attach(sat_menu);
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

void Map_window::submit() 
{
	++num_moves;
}

//up_button
void Map_window::cb_up(Address, Address pw) 
{  
    reference_to<Map_window>(pw).up();    
}

void Map_window::up() 
{
	int y = -10;
	satellites[sat_selector].c->move(0,y);
	satellites[sat_selector].y += y;
	wrapper();
	redraw();
}

//down_button
void Map_window::cb_down(Address, Address pw) 
{  
    reference_to<Map_window>(pw).down();    
}

void Map_window::down() 
{
	int y = 10;
	satellites[sat_selector].c->move(0,y);
	satellites[sat_selector].y += y;
	wrapper();
	redraw();
}

//left_button
void Map_window::cb_left(Address, Address pw) 
{  
    reference_to<Map_window>(pw).left();    
}

void Map_window::left() 
{
	int x = -10;
	satellites[sat_selector].c->move(x,0);
	satellites[sat_selector].x += x;
	wrapper();
	redraw();
}

//right_button
void Map_window::cb_right(Address, Address pw) 
{  
    reference_to<Map_window>(pw).right();    
}

void Map_window::right() 
{
	int x = 10;
	satellites[sat_selector].c->move(x,0);
	satellites[sat_selector].x += x;
	wrapper();
	redraw();
}

//sat_menu_button
void Map_window::cb_menu(Address, Address pw) 
{  
    reference_to<Map_window>(pw).menu();    
}

void Map_window::menu() 
{
	sat_menu_button.hide();
	sat_menu.show();
	redraw();
}

void Map_window::cb_menu_buttons(Address _b, Address pw)
{

	int i = stoi(static_cast<Fl_Widget *>(_b)->label());
    reference_to<Map_window>(pw).select(i);
	
}

void Map_window::select(int i)
{
	sat_selector = i - 1;
	sat_menu_button.show();
	sat_menu.hide();
	redraw();
}


void Map_window::draw_sats(int difficulty) // draws satellites
{
	for(int i = 0; i < difficulty; ++i){
		//int selector = sat_selector;
		sat_options.push_back(new Button(Point{0,0},0,0,to_string(i+1),cb_menu_buttons));
		int x_cord = 800*((double) rand() / (RAND_MAX));
		int y_cord = 600*((double) rand() / (RAND_MAX));
		satellites.push_back(new Satellite{new Circle(Point(x_cord,y_cord),5),1,2,3});
		satellites[i].x = x_cord;
		satellites[i].y = y_cord;
		satellites[i].c->set_fill_color(Color{50+i*16});
		sat_menu.attach(sat_options[i]);
		attach(*satellites[i].c);
	}
	attach(sat_menu);
	sat_menu.hide();
	redraw();
}

void Map_window::wrapper()
{
	if(satellites[sat_selector].x < 0){
		satellites[sat_selector].c->move(800,0);
		satellites[sat_selector].x += 800; 
	}
	else if(satellites[sat_selector].x > 800){
		satellites[sat_selector].c->move(-800,0);
		satellites[sat_selector].x += -800;
	}
	else if (satellites[sat_selector].y < 0){
		satellites[sat_selector].c->move(0,600);
		satellites[sat_selector].y += 600;
	}
	else if (satellites[sat_selector].y > 600){
		satellites[sat_selector].c->move(0,-600);
		satellites[sat_selector].y += -600;
	}
}

