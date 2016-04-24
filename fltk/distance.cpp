#include "distance.h"
#include "std_lib_facilities_4.h"
//#include <math.h>

double deg_rad(double d) {
    return (d*M_PI)/180;
}
double rad_deg(double d) {
    return (d*180)/M_PI;
}
double radius_earth = 6378137;
double W = 708;
double H = 600;

double y_to_latitude(double y) {

	return (2*(atan(exp(y*2*M_PI/W))-(M_PI/4)))*(180/M_PI);
	
}

double x_to_longitude(double x) {
    if (x>=W/2)
        return (x)/(W/2)*180;
    else
        return (x)/(W/2)*(180); //x coordinate converted to degrees (longitude)
}

double distance_x(double x1, double x2){
    double w = x1-x2;
    double z = 360-(x1-x2);
    if (w>z)
        return z;
    else
        return w;// returns x distance in degrees
}

double distance_y(double y1, double y2){
    double x = y1-y2;
    double c = 180-(y1-y2);
    if (x>c)
        return x;
    else
        return c;// returns y distance in degrees
}


double latitude_to_y(double lat) {
    return (W/(2*M_PI)) * log(tan(M_PI/4+deg_rad(lat)/2)); //latitude from degrees to meters
}
double longitude_to_x(double lon) {
    return deg_rad(lon)*(W/(2*M_PI)); //longitude from degrees to meters
}
