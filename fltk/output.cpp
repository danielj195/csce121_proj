#include "output.h"
#include "std_lib_facilities_4.h"
//#include <math.h>
double deg_rad(double d) {
    return (d*M_PI)/180;
}
double rad_deg(double d) {
    return (d*180)/M_PI;
}
double radius_earth = 6378137;


double y_to_latitude(double y) {
    double y_new = 0;
    if (y<70)
        return 1-(y*.0166667)+80;
    else if (y>530)
        return (y-530)*.0166667+80;
    else if(y>=300)
        return (1/cos((y-300)/300*(M_PI/2))-1)*(-45);
    else
        return (1/cos((300-y)/300*(M_PI/2))-1)*45; //y coordinate converted to degrees (latitude)
}

double x_to_longitude(double x) {
    if (x>=400)
        return (x-400)/400*180;
    else
        return (400-x)/400*(-180); //x coordinate converted to degrees (longitude)
}

double distance_y(double y1, double y2){
    double x = y1-y2;
    double c = 180-(y1-y2);
    if (x>c)
        return x*radius_earth;
    else
        return c*radius_earth;// returns y distance in meters
}

double distance_x(double x1, double y1, double x2, double y2){
    double radius1 = cos(deg_rad(y1))*radius_earth;
    double radius2 = cos(deg_rad(y2))*radius_earth;
    double w = x1-x2;
    double z = 360-(x1-x2);
    if (w>z)
        return z;
    else
        return w;// returns x distance in degrees
}

double distance(double dx, double dy){
    return sqrt(dis_x^2+dis_y^2); //distance formula from triangle formed
}
