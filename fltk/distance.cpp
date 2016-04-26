#include "distance.h"
#include "std_lib_facilities_4.h"
//#include <math.h>

double deg_rad(double d) {
    return (d*M_PI)/180;
}
double rad_deg(double d) {
    return (d*180)/M_PI;
}
double radius_earth = 4000; // "assume a radius of 4,000 miles" for the Earth
double W = 708;
double H = 600;

double y_to_latitude(double y) {

	return (2*(atan(exp(y*2*M_PI/W))-(M_PI/4)))*(180/M_PI); //formula came from https://en.wikipedia.org/wiki/Latitude
	
}

double x_to_longitude(double x) {
    if (x>=W/2)
        return (x)/(W/2)*180;
    else
        return (x)/(W/2)*(180); //x coordinate converted to degrees (longitude)
}

double latitude_to_y(double lat) {
    return (W/(2*M_PI)) * log(tan(M_PI/4+deg_rad(lat)/2)); //latitude from degrees to meters
}
double longitude_to_x(double lon) {
    return deg_rad(lon)*(W/(2*M_PI)); //longitude from degrees to meters
}

double arc_length(double lon1, double lat1, double lon2, double lat2){
    double phi1 = deg_rad(lat1);
    double phi2 = deg_rad(lat2); //converting degrees to radians
    double dphi = deg_rad(lat2-lat1);
    double dlam = deg_rad(lon2-lon1);
    double a = sin(dphi/2)*sin(dphi/2)+cos(phi1)*cos(phi2)*sin(dlam/2)*sin(dlam/2);
    double c = 2*atan2(sqrt(a),sqrt(1-a));
    return radius_earth*c; //above formulas taken from http://www.movable-type.co.uk/scripts/latlong.html
}



