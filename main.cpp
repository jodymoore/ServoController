#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <Bearing.h>
#include <Flight.h>
#include <CoordReader.h>
#include <helpers.h>

/*

  Users input lattitude and longitude coords 
  Example: 

  New Target Position:
  33.014377777777774 -106.01069444444444
  
  Current Position :
  33.015794444444445 -106.01206944444445

  heading = 321 degrees

  After Heading is Calculated User can simulate recieving a new heading to 
  Steer the parachute 

  simulate getting gps coords and then getting bearing
  the system would poll every 500ms fo the loop

*/

using namespace std;



double dmsToLatLon(double degrees, double minutes, double seconds, char direction);

double getRandLat(double targetLat, double startLat);

double getRandLon(double targetLon, double startLdouble);


typedef struct {
    double lat,lon;
} COORDS;


// v3 = rand() % 30 + 1985

// double getRandLat(double targetLat, double startLat) {

//   // create the random number generator:
//    Rand_double rd = new rd{startLat,targetLat};
//    double randomLat = rd{startLat,targetLat};

//    return randomLat;
// }

// double getRandLon(double targetLon, double startLon) {

//    double randomLon = (double) rand() % startLon + targetLon;

//    return randomLon;
// }


// void setTargetPos ( COORDS *targetPos ) {
//   COORDS newTargetPosition = { 4, 5}; // set coords of target position.
//   *targetPos = newTargetPosition;
// }



int main() {

    COORDS newTargetPosition,
           currentPosition;
    


    double NewBearing = 0.0,
           currentHeading,
           targetHeading;


    double newlat = 0.0,
           newlon = 0.0;

    // cin >> newTargetPosition.lat >> newTargetPosition.lon;
    
    CoordReader cReader;

    cReader.Read();

    // cout << "Enter lat, lon values seperated by a space" << endl;

    // cin >> newTargetPosition.lat >> newTargetPosition.lon;  

     
    // debugger to set precision    
    cout << "lat = " << newTargetPosition.lat << endl;

    cout << "** New Target Position ** \n"
         << "lat value: " << newTargetPosition.lat << "\n"  
         << "lon value: " << newTargetPosition.lon << endl;

    // do another read for current position coords:    TODO
    cout << "****Enter Current Position Coordinates****" << endl;

    cout << "Enter lat, lon values seperated by a space" << endl;

    cin >> currentPosition.lat >> currentPosition.lon; 

    cout << "** Current Position ** \n" 
         << "lat value: " << currentPosition.lat << "\n"  
         << "lon value: " << currentPosition.lon <<  endl;

    // Instance Class Bearing
    Bearing bearing;

    NewBearing = bearing.bearing(newTargetPosition.lat, newTargetPosition.lon,
                         currentPosition.lat, currentPosition.lon);
 
    cout << "** Bearing:" <<  NewBearing << endl;

    targetHeading = NewBearing; 

   Flight flight;

   flight.flight(targetHeading);

}





// Decimal Degrees = Degrees + minutes/60 + seconds/3600

double dmsToLatLon(double degrees, double minutes, double seconds, char direction) {
   // force toupper case
   double result = 0.0;
  int mult = 1;
  if(direction == 'W') {
       mult = (-1);
   }

   degrees = degrees + (minutes/60) + (seconds/3600);

  result = degrees * mult;
  return result;
}



/*
 * read lattitude longitude coordinates
 *
 *
 */



// movement fuctions - sends input commands to drive motor.
void turnLeft() {

}

void turnRight() {
 
}

void fullFlight() {

}

void halfBrakes() {

}

// logic functions 
void getConditions() {

}

// helper functions for getConditions
void getWindDirection() {

}

void getCurrentDirection() {

}
