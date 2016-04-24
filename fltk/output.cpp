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
        return 1-(y*.1429)+80; //.1429 is 10 degrees divided by 70 pixels
    else if (y>530)
        return (y-530)*.1429+80; // to account for the secant function going to infinity
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
    if (x<c)
        return deg_rad(x)*radius_earth; //converts degrees to radians to kilometers
    else
        return deg_rad(c)*radius_earth;// returns y distance in meters (s = r*theta)
}

double distance_x(double x1, double y1, double x2, double y2){
    double radius1 = cos(deg_rad(y1))*radius_earth;
    double radius2 = cos(deg_rad(y2))*radius_earth; //accounts for different radii at different y coordiantes
    double w = deg_rad(x1)*radius1-deg_rad(x2)*radius2; //converting degrees to raidans to kilometers
    double z = (2*M_PI)*radius_earth-(w); //degrees to radians to kilometers
    if (w<z)
        return z;
    else
        return w;// returns x distance in kilometers
}

double distance(double dx, double dy){
    return sqrt(pow(dx,2.0)+pow(dy,2.0)); //distance formula from triangle formed
}