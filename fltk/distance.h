#ifndef DISTANCE_GUARD
#define DISTANCE_GUARD 1
#include <vector>
#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Graph.h"
#include "My_Window.h"
#include "Satellite.h"

using namespace Graph_lib;


double deg_rad(double d); //Converts from degrees to radians
double rad_deg(double d); //Radians to degrees
double y_to_latitude(double y); //Y coordinate to latitude
double latitude_to_y(double); //Latitude to y coordiate
double x_to_longitude(double); //x coordinate to longitude
double longitude_to_x(double); //longitude to x coordinate
double arc_length(double lat1, double lon1, double lat2, double lon2); //Finds distance between two satellites
double min_dist(Vector_ref<Satellite>& v1); //Finds the minimum distance for a group of satellites
    

#endif
