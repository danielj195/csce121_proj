#include "std_lib_facilities_4.h"
#include "screens.h"
<<<<<<< HEAD
#include "output.h"
=======
#include "distance.h"
<<<<<<< HEAD
//#include "timer.h"
>>>>>>> origin/master
=======
#include "Track_scores.h"

>>>>>>> origin/master

using namespace Graph_lib;

//image source
//https://en.wikipedia.org/wiki/Mercator_projection

Map_window::Map_window(My_Window* prev_window, int difficulty) :
	My_Window(Point(100,100),1110,600,prev_window),
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
	lat_val(Point(x_max()-280,100),70,50,""), 
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
	attach(output_time);
	attach(count_moves);
	attach(sat_num);
	attach(latitude);
	attach(longitude);
	attach(lat_val);
	attach(long_val);
};

Out_box Map_window::output_time(Point(1000,220),70,50,"Time: ");

void Map_window::cb_quit(Address, Address pw) //Callback for quit button
{  
    reference_to<Map_window>(pw).quit();    
}

void Map_window::quit() //proceed to quit game
{
	Track_scores data;
	data.scores = data.read_entries();
	if (best_score >= data.scores[4].score){ //Determines if score is a high score
		Fl::remove_timeout(Timer_CB);
		High_score_window* win = new High_score_window(this, best_score); //go to high score page if score is high enough
		win->lvl.hide(); //Hide certain features of highscore window
		win->next_button.hide();
		win->make_boxes();
		Track_scores data;
		data.scores = data.read_entries();
		ostringstream ss1;
		ostringstream ss2;
		for(int i = 0; i<5; ++i){ //Output scores
			ss1 << data.scores[i].initial;
			ss2 << data.scores[i].score;
			win->names[i].put(ss1.str());
			win->scores[i].put(ss2.str());
			ss1.str("");
			ss2.str("");
		}
		return;
	}
	Fl::remove_timeout(Timer_CB); 
	Finish_window* win = new Finish_window(this, best_score); //Go to Finish Window if score is not a high score
	win->report(best_score);
}

//submit_button
void Map_window::cb_submit(Address, Address pw) //Callback for submit button
{  
<<<<<<< HEAD
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
=======
    reference_to<Map_window>(pw).submit();    
>>>>>>> origin/master
}

void Map_window::submit()
{
	if (move_state[0] == 0 || move_state[1] == 0){
		++num_moves;
		if(num_moves >= 50){ //Quit the game if number of moves exceeds 50
			Fl::remove_timeout(Timer_CB);
			quit();
			return;
		}
		ostringstream ss; //Report number of moves
		ss << num_moves;
		count_moves.put(ss.str());
		move_state = {1,1,1,1,0};
		best_score = min_dist(satellites)*satellites.size(); //Calculate score
		ostringstream ss1;
		ss1 << best_score; 
		current_score.put(ss1.str());
		redraw();
	}
}

//up_button
void Map_window::cb_up(Address, Address pw) //Callback for up button
{  
    reference_to<Map_window>(pw).up();    
}

void Map_window::up() 
{
	if(move_state[0] == 1 && menu_state){  
		double g = y_to_latitude(satellites[sat_selector].y) + Step_size(num_moves);
		if (g>82){
			g = -82 + (g-82);
		}
		double y = latitude_to_y(g) - satellites[sat_selector].y; //Calculate number of pixels to move 
		satellites[sat_selector].c->move(0,-y); //Move satellite
		satellites[sat_selector].y += y;
		wrapper();
		ostringstream ss;  //Output latitude to screen
		ss << g;
		lat_val.put(ss.str());
		if(move_state[4] == 2){ //Update move state to restrict certain movements
			move_state = {1,1,1,1,0};
		}
		else{
			move_state = {0,1,0,0,1};
		}
		redraw();
	}
}

//down_button
void Map_window::cb_down(Address, Address pw) //Callback for down button
{  
    reference_to<Map_window>(pw).down();    
}

void Map_window::down() 
{
	if(move_state[1] == 1 && menu_state){
		double g = y_to_latitude(satellites[sat_selector].y) - Step_size(num_moves);
		if (g < -82){
			g = 82 + (g+82);
		}
		double y = latitude_to_y(g) - satellites[sat_selector].y; //Calculate number of pixels to move
		satellites[sat_selector].c->move(0,-y);
		satellites[sat_selector].y += y; //Move satellite
		wrapper();
		ostringstream ss;
		ss << g;
		lat_val.put(ss.str());
		if(move_state[4] == 1){ //Update move state
			move_state = {1,1,1,1,0};
		}
		else{
			move_state = {1,0,0,0,2};
		}
		redraw();
	}
}

//left_button
void Map_window::cb_left(Address, Address pw) //Callback for left button
{  
    reference_to<Map_window>(pw).left();    
}

void Map_window::left() 
{
	if(move_state[2] == 1 && menu_state){
		double g = x_to_longitude(satellites[sat_selector].x) - Step_size(num_moves);
		if (g < -180){
			g = 180 + (g+180);
		}
		double x = longitude_to_x(g) - satellites[sat_selector].x; //Calculate number of pixels to move
		satellites[sat_selector].c->move(x,0);
		satellites[sat_selector].x += x; //move satellite
		wrapper();
		ostringstream ss;
		ss << g;
		long_val.put(ss.str());
		if(move_state[4] == 4){ //Update move state to restrict certain movements
			move_state = {1,1,1,1,0};
		}
		else{
			move_state = {0,0,0,1,3};
		}
		redraw();
	}
}

//right_button
void Map_window::cb_right(Address, Address pw) //Callback for right button
{  
    reference_to<Map_window>(pw).right();    
}

void Map_window::right() 
{
	if(move_state[3] == 1 && menu_state){
		double g = x_to_longitude(satellites[sat_selector].x) + Step_size(num_moves);
		if (g > 180){
			g = -180 + (g-180);
		}
		double x = longitude_to_x(g) - satellites[sat_selector].x; //Calculate number of pixels to move
		satellites[sat_selector].c->move(x,0); //Move satellite
		satellites[sat_selector].x += x;
		wrapper();
		ostringstream ss;
		ss << g;
		long_val.put(ss.str());
		if(move_state[4] == 3){ //Update move state
			move_state = {1,1,1,1,0};
		}
		else{
			move_state = {0,0,1,0,4};
		}
		redraw();
	}
}

//sat_menu_button
void Map_window::cb_menu(Address, Address pw) //Callback for menu button
{  
    reference_to<Map_window>(pw).menu();    
}

void Map_window::menu() 
{
	if(move_state[0] != move_state[1]){ //If a satellite is already open, restrict menu access
		return;
	} 
	sat_menu_button.hide(); //Hide menu button and show menu
	sat_menu.show();
	menu_state = 0; //Indicate that menu is open
	redraw();
}

void Map_window::cb_menu_buttons(Address _b, Address pw) //Callback for menu buttons
{

	int i = stoi(static_cast<Fl_Widget *>(_b)->label()); //Obtain label from button 
    reference_to<Map_window>(pw).select(i);
	
}

void Map_window::select(int i) //Function for menu buttons
{
	sat_selector = i - 1;  //Change current satellite
	sat_menu_button.show();
	sat_menu.hide();
	ostringstream ss;
	ss << i;
	sat_num.put(ss.str()); //Output satellite, latitude, and longitude to screen
	ss.str("");
	ss << x_to_longitude(satellites[sat_selector].x);
	long_val.put(ss.str());
	ss.str("");
	ss << y_to_latitude(satellites[sat_selector].y);
	lat_val.put(ss.str());
	menu_state = 1; //Indicate that menu is closed
	redraw();
}


void Map_window::draw_sats(int difficulty) // This function draws satellites
{
	for(int i = 0; i < difficulty; ++i){
		sat_options.push_back(new Button(Point{0,0},0,0,to_string(i+1),cb_menu_buttons)); //Add buttons to menu
		double x_cord = map_w *((double) rand() / (RAND_MAX)); //Generate random coordinates
		double y_cord = map_h *((double) rand() / (RAND_MAX));
		satellites.push_back(new Satellite{new Circle(Point(x_cord,y_cord),5),1,2}); //Add satellite to satellites vector
		satellites[i].x = x_cord - (map_w/2); //Assign coordinates to satellites
		satellites[i].y = (map_h/2) - y_cord;
		satellites[i].c->set_fill_color(Color{i});
		sat_menu.attach(sat_options[i]);
		attach(*satellites[i].c);
	}
	attach(sat_menu);
	sat_menu.hide();
}

void Map_window::wrapper()  //Allows satellites to wrap around map
{
	if(satellites[sat_selector].x < -map_w/2){  //Move to right side if beyond left edge
		satellites[sat_selector].c->move(map_w,0);
		satellites[sat_selector].x += map_w; 
	}
	else if(satellites[sat_selector].x > map_w/2){ //Move to left side if beyond right edge
		satellites[sat_selector].c->move(-map_w,0);
		satellites[sat_selector].x += -map_w;
	}
	else if (satellites[sat_selector].y < -map_h/2){ //Move to top side if beyond bottom edge
		satellites[sat_selector].c->move(0,-map_h);
		satellites[sat_selector].y += map_h;
	}
	else if (satellites[sat_selector].y > map_h/2){ //Move to bottom side if beyond top edge
		satellites[sat_selector].c->move(0,map_h);
		satellites[sat_selector].y += -map_h;
	}
}

void Map_window::Timer_CB(void *data) { // timer callback
    static int count = 300;    // keep count of timer ticks 300=5min
	--count;
	ostringstream ss1;
	ss1 << count;  //Output current time
	output_time.put(ss1.str());
	if ( count <= 0){
		Map_window* r = static_cast<Map_window*>(data);  //Quit game if timer runs out
		r->quit();
		delete r; 
    } 
	else {
        Fl::repeat_timeout(1, Timer_CB, data); // this makes it count down by 1 sec.
    }
}
double Map_window::Step_size(int moves){ //returns step size based on number of moves
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
