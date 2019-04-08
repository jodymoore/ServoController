#include <iostream>


using namespace std;
/*
 *  Class Flight
 *
 */
class Flight {
  
  private:
      int _targetHeading;
      int _currentHeading;

  public:

      bool inFlight = true;
      int altitude = 10000;
      double newBearing = 0.0;

      Flight() {
        _targetHeading = 0;
        _currentHeading = 0;
      }

      void flight(int targetHeading) {

        while (inFlight && altitude > 0) {

          // // get current position for bearing/heading to target
          // newBearing = bearing.bearing(newTargetPosition.lat,   newTargetPosition.lon,
          //                currentPosition.lat, currentPosition.lon)
          cout << "Alltitude: " << altitude << "\t\t";
          altitude = altitude - 1000;

          cout << "Target Heading: "  << targetHeading << endl << endl;

          _targetHeading = targetHeading;
          // get current heading 
    
          cout << "**** Enter  Current Heading ****" << endl;

          cout << "Enter Current heading in degrees" << endl;

          cin >> _currentHeading;

          // if target heading
          if(_currentHeading > _targetHeading) {
              int range = _currentHeading - _targetHeading;
              cout << "Action: \t";
              if(range > 5) {
                  cout << "100% Left Turn\n" ;
              }
              else {
                  cout << " 25% Left Turn\n";
              }  
              cout << endl << endl;  
          }
          else if (_currentHeading < _targetHeading ) {
              int range = _targetHeading - _currentHeading;

              if(range > 5) {
                  cout << "100% Right Turn\n";
              }
              else {
                  cout << " 25% Right Turn\n";
              }  
              cout << endl;
              
          }
          else {
            cout << "Full Flight\n" << endl;
          }
    
        }

        cout << "The Eagle Has Landed " << altitude << endl;

    }

};