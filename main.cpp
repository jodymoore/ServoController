#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <Bearing.h>
#include <Flight.h>
#include <CoordReader.h>

/** 
 *
 * CIS-277 
 * Jody Moore
 *
    Users input lattitude and longitude coords 
    Example: 

    New Target Position:

    
    Current Position :
    33.015794444444445 -106.01206944444445

    heading = 321 degrees

    After Heading is Calculated User can simulate recieving a new heading to 
    Steer the parachute 

    simulate getting gps coords and then getting bearing
    the system would poll every 500ms for the loop

*/

using namespace std;


double dmsToLatLon(double degrees, double minutes, double seconds, char direction);

double getRandLat(double targetLat, double startLat);

double getRandLon(double targetLon, double startLdouble);

typedef struct {
    double lat,lon;
} COORDS;


int main() {

    COORDS newTargetPosition,
           currentPosition;
    
    double NewBearing = 0.0,
           currentHeading,
           targetHeading;


    double newlat = 0.0,
           newlon = 0.0;


    newTargetPosition.lat = 0.0;
    newTargetPosition.lon = 0.0;
    currentPosition.lat = 0.0;
    currentPosition.lon = 0.0;

    CoordReader cReader;

    cReader.Read(newTargetPosition.lat, newTargetPosition.lon, "Targetposition.txt");

    cReader.Read(currentPosition.lat, currentPosition.lon, "Currentposition.txt"); 

      cout << "\t\t\t" << "************************" << endl;
      cout << "\t\t\t" << "* New Target Position  *" << endl;
      cout << "\t\t\t" << "************************" << endl << endl;
      cout << "\t\t\t" << "lat value: " << setprecision(15) 
           << newTargetPosition.lat <<  "\n"  
           << "\t\t\t" << "lon value: " << newTargetPosition.lon << endl << endl;
   
      cout << "\t\t\t" << "**********************" << endl;
      cout << "\t\t\t" << "*  Current Position  *" << endl;
      cout << "\t\t\t" << "**********************" << endl << endl;
      cout << "\t\t\t" << "lat value: " << currentPosition.lat << "\n"  
           << "\t\t\t"<< "lon value: " << currentPosition.lon <<  endl << endl;
      
    // Instance Class Bearing
    Bearing bearing;


    NewBearing = bearing.bearing(newTargetPosition.lat, newTargetPosition.lon,
                 currentPosition.lat, currentPosition.lon);

    
    cout << "\t\t\t" << "** Bearing:  " <<  NewBearing << " **"<< endl << endl;

    targetHeading = NewBearing; 
    
    // Place targetHeading into flight fuction.  
    Flight flight;
    
    // Call flight class flight function
    flight.flight(targetHeading);

}

// // Not Public
// // movement fuctions - sends input commands to drive motor.
// void turnLeft() {
    
// }

// void turnRight() {
 
// }

// void fullFlight() {

// }

// void halfBrakes() {

// }

// // logic functions 
// void getConditions() {

// }

// // helper functions for getConditions
// void getWindDirection() {

// }

// void getCurrentDirection() {

// }
