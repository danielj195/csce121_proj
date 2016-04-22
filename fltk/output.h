#ifndef MAP_WINDOW_GUARD
#define MAP_WINDOW_GUARD 1
#include <vector>
#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Graph.h"
#include "My_Window.h"
#include "Satellite.h"

using namespace Graph_lib;

class outputs
{
    double deg_rad(double d);
    double rad_deg(double d)
    double y_to_latitude(double y);
    void score();
    void longitude();
    void latitude();
    
};
#endif