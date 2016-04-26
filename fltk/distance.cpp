#include "distance.h"
#include "std_lib_facilities_4.h"

double deg_rad(double d) {
    return (d*M_PI)/180;
}
double rad_deg(double d) {
    return (d*180)/M_PI;
}
<<<<<<< HEAD
double radius_earth = 4000; // "assume a radius of 4,000 miles" for the Earth
double W = 708;
double H = 600;

double y_to_latitude(double y) {

	return (2*(atan(exp(y*2*M_PI/W))-(M_PI/4)))*(180/M_PI); //formula came from https://en.wikipedia.org/wiki/Latitude
	
=======
double radius_earth = 4000; //radius of the earth in miles
double W = 708; //Map width
double H = 600; //Map height

double y_to_latitude(double y) {
	return (2*(atan(exp(y*2*M_PI/W))-(M_PI/4)))*(180/M_PI); //y cooridate converted to latitutde
>>>>>>> origin/master
}

double x_to_longitude(double x) {
    return (x)/(W/2)*(180); //x coordinate converted to degrees (longitude)
}

<<<<<<< HEAD
=======

double arc_length(double lon1, double lat1, double lon2, double lat2){ //Computes arc length for pair of latitude/longitude
    double phi1 = deg_rad(lat1);
    double phi2 = deg_rad(lat2);
    double dphi = deg_rad(lat2-lat1);
    double dlam = deg_rad(lon2-lon1);
    double a = sin(dphi/2)*sin(dphi/2)+cos(phi1)*cos(phi2)*sin(dlam/2)*sin(dlam/2); 
    double c = 2*atan2(sqrt(a),sqrt(1-a));
    return radius_earth*c;
}


>>>>>>> origin/master
double latitude_to_y(double lat) {
    return (W/(2*M_PI)) * log(tan(M_PI/4+deg_rad(lat)/2)); //latitude to vertical distance
}
double longitude_to_x(double lon) {
    return deg_rad(lon)*(W/(2*M_PI)); //longitude to horizontal distance
}

double min_dist(Vector_ref<Satellite>& v1){
	double shortest_distance = 1000000;
	for (int i = 0; i<v1.size(); ++i){ //Find latitude and longitude of each satellite
        double lat1 = y_to_latitude(v1[i].y);
        double lon1 = x_to_longitude(v1[i].x);
        
        for (int j = 0; j<v1.size(); ++j){
            if (i==j){
                continue;  //Skip current satellite
			}
            double lat2 = y_to_latitude(v1[j].y);  //Find latitude and longitude of second satellite
            double lon2 = x_to_longitude(v1[j].x);
            if (arc_length(lon1,lat1,lon2,lat2) < shortest_distance)
                shortest_distance = arc_length(lon1,lat1,lon2,lat2);  //Keep track of shortest distance
        }
    }
	return shortest_distance;
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



