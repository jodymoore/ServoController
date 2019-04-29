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
      int altitude = 8000;
      double newBearing = 0.0;

      Flight() {
        _targetHeading = 0;
        _currentHeading = 0;
      }
/*
 *  Function for simulating the flight of an autonomous controlled
 *  parachute system
 *
 */
      void flight(int targetHeading) {

        while (inFlight && altitude > 0) {

          // // get current position for bearing/heading to target
          // newBearing = bearing.bearing(newTargetPosition.lat,   newTargetPosition.lon,
          //                currentPosition.lat, currentPosition.lon)
          cout << "Alltitude: " << altitude << "\t" << "|" << "\t";
          altitude = altitude - 1000;

          cout << "Target Heading: "  << targetHeading << endl << endl;

          _targetHeading = targetHeading;
          // get current heading 


         // promt for heading using constraints
          do
         {
            cout << "* Enter Current heading in degrees *" << endl;;
            cout<< "************************************" << endl;
            cin >> _currentHeading;

          } while(_currentHeading >= 360 || _currentHeading <= 0);
           
          // if target heading
          if(_currentHeading > _targetHeading) {
              int range = _currentHeading - _targetHeading;
              cout << endl;
              cout<< "*****************************" << endl;
              cout << "*  Action: \t";
          
              if(range > 5) {
                  cout << "100% Left Turn *\n" ;
              }
              else {
                  cout << "25% Left Turn   *\n";
              }  
              cout << "*****************************" << endl;
              cout << endl;  
              StopTurn();
          }
          else if (_currentHeading < _targetHeading ) {
              int range = _targetHeading - _currentHeading;
              cout << endl;
              cout<< "*****************************" << endl;
              cout << "*  Action: \t";
              if(range > 5) {
                  cout << "100% Right Turn *\n";
              }
              else {
                  cout << "25% Right Turn  *\n";
              }  
              cout << "*****************************" << endl;
              cout << endl;   
             StopTurn();
          }
          else {
            cout<< "*************************" << endl;
            cout << "*  Action: \t";
            cout << "Full Flight *\n";
            cout<< "*************************" << endl;
            cout << endl; 
          }
          if (altitude <= 1000) {
              landingPattern(); 
              altitude = 0;
          }
        }
       
    }
/*
 *  Function for simulating the landing procedure steps
 *
 */
    void landingPattern() {

         // designate landing area
         // calculate pattern
         // enterdown wind of pattern
         // turn base leg
         // final approch
         cout << "Designate landing area ...." << endl;
          usleep(2000000);
         cout << "Calculating pattern..." << endl;
           usleep(2000000);
         cout << "Entering pattern..." << endl;
         usleep(2000000);
         cout << "Down wind leg..." << endl;
          usleep(2000000);
         cout << "Turning on base leg..." << endl;
          usleep(2000000);
         cout << "Turning on final approach..." << endl;
           usleep(2000000);
         cout << "Three...Two..One" << endl;
           usleep(2000000);
         cout << "Flare! Flare! Flare!" << endl;
           usleep(2000000);
         cout << "The Eagle Has Landed!!!" << endl;

    }

    void StopTurn() {
        usleep(1000000);
        cout<< "*************************" << endl;
        cout << "*  STOP \t";
        cout << "Full Flight *\n";
        cout<< "*************************" << endl;
        cout << endl; 
    }



};