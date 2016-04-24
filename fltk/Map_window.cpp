#include "std_lib_facilities_4.h"
//#include "Map_window.h"
#include "screens.h"
<<<<<<< HEAD
#include "output.h"
=======
#include "distance.h"
//#include "timer.h"
>>>>>>> origin/master

using namespace Graph_lib;

//image source
//https://en.wikipedia.org/wiki/Mercator_projection

Map_window::Map_window(My_Window* prev_window, int difficulty) :
	My_Window(Point(100,100),1110,600,prev_window),// difficulty),
	quit_button(Point(x_max()-80,20), 60, 40, "Quit", cb_quit),
	submit_button(Point(x_max()-120,450), 50, 50, "Enter", cb_submit),
	up_button(Point(x_max()-120,390), 50, 50, "N", cb_up),
	down_button(Point(x_max()-120,510), 50, 50, "S", cb_down),
	left_button(Point(x_max()-180,450), 50, 50, "W", cb_left),
	right_button(Point(x_max()-60,450), 50, 50, "E", cb_right),
	sat_menu_button(Point(x_max()-280,280), 75, 40, "Satellites", cb_menu),
	Map(Point(0,0),"Maps.gif"),
	sat_menu(Point(x_max()-280,280),40,40,Menu::vertical,"satellite"),
	latitude(Point(x_max()-280,95),"Latitude: "),
	longitude(Point(x_max()-280,170),"Longitude: "),
	current_score(Point(x_max()-100,160),70,50,"Score: "),
	count_moves(Point(x_max()-100,100),50,50,"Moves: "),
	sat_num(Point(x_max()-100,280),50,50,"Satellite: "),
	lat_val(Point(x_max()-280,100),70,50,""), //USE WITH LATITUTDE AND LONGITUDE!!
	long_val(Point(x_max()-280,175),70,50,"")

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
	attach(current_score);
	//attach(initials);
	attach(output_time);
	attach(count_moves);
	attach(sat_num);
	attach(latitude);
	attach(longitude);
	attach(lat_val);
	attach(long_val);
};

Out_box Map_window::output_time(Point(1000,220),70,50,"Time: ");
int quit_state = 0;
int map_w = 708;
int map_h = 600;
//int time_out = 1;

void Map_window::cb_quit(Address, Address pw) 
{  
    reference_to<Map_window>(pw).quit();    
}

void Map_window::quit() //proceed to quit game
{
	/*if (current_score > last_term in score vector){ 
		High_score_window* win = new High_score_window(this); //go to high score page if score is high enough
		return;
	}*/
	quit_state = 1;
	Finish_window* win = new Finish_window(this);
}

//submit_button
void Map_window::cb_submit(Address, Address pw) 
{  
    reference_to<Map_window>(pw).submit();
    
    double shortest_distance = 9999999999999;
    for (int i = 0; i<satellites.size(); i++){
        double lat1 = y_to_latitude(satellites[i].y);
        double lon1 = x_to_longitude(satellites[i].x);
        
        for (int j = 0; j<satellites.size(); j++){
            if (i==j)
                continue;
            double lat2 = y_to_latitude(satellites[j].y);
            double lon2 = x_to_longitude(satellites[j].x);
            if (arc_length(lon1,lat1,lon2,lat2) < shortest_distance)
                shortest_distance = arc_length(lon1,lat1,lon2,lat2);
        }
    }
    ostringstream ss;
    ss << shortest_distance;
    current_score.put(ss.str());
    redraw();
}

void Map_window::submit()
{
	/* cout<< "x = " << satellites[sat_selector].x << "\n";
	cout<< "y = " << satellites[sat_selector].y << "\n"; */
	if (is_move){
		++num_moves;
		if(num_moves >= 50){ //max number of moves
			quit();
			return;
		}
		ostringstream ss;
		ss << num_moves;
		count_moves.put(ss.str());
	}
	is_move = 0;
}

//up_button
void Map_window::cb_up(Address, Address pw) 
{  
    reference_to<Map_window>(pw).up();    
}

void Map_window::up() 
{
	is_move = 1;
	double g = y_to_latitude(satellites[sat_selector].y) + Step_size(num_moves);
	if (g>82){
		g = -82 + (g-82);
	}
	double y = latitude_to_y(g) - satellites[sat_selector].y;
	int y1 = y;
	//cout<< "latitude = " << y << "\n";
	satellites[sat_selector].c->move(0,-y1);
	satellites[sat_selector].y += y;
	wrapper();
	ostringstream ss;
	ss << g;
	lat_val.put(ss.str());
	redraw();
}

//down_button
void Map_window::cb_down(Address, Address pw) 
{  
    reference_to<Map_window>(pw).down();    
}

void Map_window::down() 
{
	is_move = 1;
	double g = y_to_latitude(satellites[sat_selector].y) - Step_size(num_moves);
	if (g < -82){
		g = 82 + (g+82);
	}
	double y = latitude_to_y(g) - satellites[sat_selector].y;
	int y1 = y;
	satellites[sat_selector].c->move(0,-y1);
	satellites[sat_selector].y += y;
	wrapper();
	ostringstream ss;
	ss << g;
	lat_val.put(ss.str());
	redraw();
}

//left_button
void Map_window::cb_left(Address, Address pw) 
{  
    reference_to<Map_window>(pw).left();    
}

void Map_window::left() 
{
	is_move = 1;
	double g = x_to_longitude(satellites[sat_selector].x) - Step_size(num_moves);
	if (g < -180){
		g = 180 + (g+180);
	}
	double x = longitude_to_x(g) - satellites[sat_selector].x;
	int x1 = x;
	satellites[sat_selector].c->move(x1,0);
	satellites[sat_selector].x += x;
	wrapper();
	ostringstream ss;
	ss << g;
	long_val.put(ss.str());
	//cout << "longtiude = " << x_to_longitude(satellites[sat_selector].x) << "\n";
	redraw();
}

//right_button
void Map_window::cb_right(Address, Address pw) 
{  
    reference_to<Map_window>(pw).right();    
}

void Map_window::right() 
{
	is_move = 1;
	double g = x_to_longitude(satellites[sat_selector].x) + Step_size(num_moves);
	if (g > 180){
		g = -180 + (g-180);
	}
	double x = longitude_to_x(g) - satellites[sat_selector].x;
	int x1 = x;
	satellites[sat_selector].c->move(x1,0);
	satellites[sat_selector].x += x;
	wrapper();
	ostringstream ss;
	ss << g;
	long_val.put(ss.str());
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
	ostringstream ss;
	ss << i;
	sat_num.put(ss.str());
	ss.str("");
	ss << x_to_longitude(satellites[sat_selector].x);
	long_val.put(ss.str());
	ss.str("");
	ss << y_to_latitude(satellites[sat_selector].y);
	lat_val.put(ss.str());
	redraw();
}


void Map_window::draw_sats(int difficulty) // draws satellites
{
	for(int i = 0; i < difficulty; ++i){
		//int selector = sat_selector;
		sat_options.push_back(new Button(Point{0,0},0,0,to_string(i+1),cb_menu_buttons));
		double x_cord = map_w *((double) rand() / (RAND_MAX));
		double y_cord = map_h *((double) rand() / (RAND_MAX));
		satellites.push_back(new Satellite{new Circle(Point(x_cord,y_cord),5),1,2});
		satellites[i].x = x_cord - (map_w/2);
		satellites[i].y = (map_h/2) - y_cord;
		satellites[i].c->set_fill_color(Color{i});
		sat_menu.attach(sat_options[i]);
		attach(*satellites[i].c);
	}
	attach(sat_menu);
	sat_menu.hide();
	//redraw();
}

void Map_window::wrapper()
{
	if(satellites[sat_selector].x < -map_w/2){
		satellites[sat_selector].c->move(map_w,0);
		satellites[sat_selector].x += map_w; 
	}
	else if(satellites[sat_selector].x > map_w/2){
		satellites[sat_selector].c->move(-map_w,0);
		satellites[sat_selector].x += -map_w;
	}
	else if (satellites[sat_selector].y < -map_h/2){
		satellites[sat_selector].c->move(0,-map_h);
		satellites[sat_selector].y += map_h;
	}
	else if (satellites[sat_selector].y > map_h/2){
		satellites[sat_selector].c->move(0,map_h);
		satellites[sat_selector].y += -map_h;
	}
}

void Map_window::Timer_CB(void *data) {              // timer callback
    static int count = 300;    // keep count of timer ticks 300=5min
	--count;
	ostringstream ss1;
	ss1 << count;
	output_time.put(ss1.str());
	if ( count <= 0){
		
		Map_window* r = static_cast<Map_window*>(data);
		r->quit();
		Fl::remove_timeout(Timer_CB, data);
	}
	else if(quit_state == 1) {
        Fl::remove_timeout(Timer_CB, data);
    } 
	else {
        Fl::repeat_timeout(1, Timer_CB, data); // this makes it count down by 1 sec.
    }
}
double Map_window::Step_size(int moves){
	if(moves>=40){
		return 1.0;
	}
	else if(moves>=30){
		return 5.0;
	}
	else if(moves>=20){
		return 10.0;
	}
	else if(moves>=10){
		return 15;
	}
	else{
		return 20;
	}
}
