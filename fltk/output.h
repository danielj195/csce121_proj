#ifndef MAP_WINDOW_GUARD
#define MAP_WINDOW_GUARD 1
#include <vector>
#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Graph.h"
#include "My_Window.h"
#include "Satellite.h"

using namespace Graph_lib;

    double deg_rad(double d);
    double rad_deg(double d)
    double y_to_latitude(double y);
    double x_to_longitude(double x, double y);
    double distance_y(double y1, double y2);
    double distance_x(double x1, double y1, double x2, double y2);
    double distance(double dx, double dy);

#endif