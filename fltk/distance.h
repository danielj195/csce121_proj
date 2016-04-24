#ifndef DISTANCE_GUARD
#define DISTANCE_GUARD 1
#include <vector>
#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Graph.h"
#include "My_Window.h"
#include "Satellite.h"

using namespace Graph_lib;


double deg_rad(double d);
double rad_deg(double d);
double y_to_latitude(double y);
double latitude_to_y(double);
double x_to_longitude(double);
double longitude_to_x(double);
double arc_length(double lat1, double lon1, double lat2, double lon2);
void score();
void longitude();
void latitude();
    

#endif
