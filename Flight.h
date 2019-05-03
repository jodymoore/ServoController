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
          cout << "\t\t\t" << "Alltitude: " << altitude << "\t" << "|" << "\t";
          altitude = altitude - 1000;

          cout << "\t" << "Target Heading: "  << targetHeading << endl << endl;

          _targetHeading = targetHeading;
          // get current heading 


         // promt for heading using constraints
          do
         {
            cout << "\t\t\t" << "* Enter Current heading in degrees 0 to 360 *" << endl;;
            cout<< "\t\t\t" << "*********************************************" << endl;
            cin >> _currentHeading;

          } while(_currentHeading >= 360 || _currentHeading <= 0);
           
          // if target heading
          if(_currentHeading > _targetHeading) {
              int range = _currentHeading - _targetHeading;
              cout << endl;
              cout<< "\t\t\t" << "*****************************" << endl;
              cout << "\t\t\t" << "*  Action: ";
          
              if(range > 5) {
                  cout << "\t" << "100% Left Turn *\n" ;
              }
              else {
                  cout << "\t" << "25% Left Turn   *\n";
              }  
              cout << "\t\t\t" << "*****************************" << endl;
              cout << "\t\t\t" << endl;  
              StopTurn();
          }
          else if (_currentHeading < _targetHeading ) {
              int range = _targetHeading - _currentHeading;
              cout << endl;
              cout<< "\t\t\t" << "*****************************" << endl;
              cout << "\t\t\t" << "*  Action: ";
              if(range > 5) {
                  cout << "\t" << "100% Right Turn *\n";
              }
              else {
                  cout << "\t" << "25% Right Turn  *\n";
              }  
              cout << "\t\t\t" << "*****************************" << endl;
              cout << endl;   
             StopTurn();
          }
          else {
            cout << "\t\t\t"<< "*************************" << endl;
            cout  << "\t\t\t"<< "*  Action: ";
            cout  << "\t"<< "Full Flight *\n";
            cout << "\t\t\t"<< "*************************" << endl;
            cout << "\t\t\t" << endl; 
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
         cout << "\t\t\t" << "Designate landing area ...." << endl;
          usleep(3000000);
         cout << "\t\t\t" << "Calculating pattern..." << endl;
           usleep(3000000);
         cout << "\t\t\t" << "Entering pattern..." << endl;
         usleep(3000000);
         cout << "\t\t\t" << "Down wind leg..." << endl;
          usleep(3000000);
         cout << "\t\t\t" << "Turning on base leg..." << endl;
          usleep(3000000);
         cout << "\t\t\t" << "Turning on final approach..." << endl;
           usleep(3000000);
         cout << "\t\t\t" << "Three...Two..One" << endl;
           usleep(3000000);
         cout << "\t\t\t" << "Flare! Flare! Flare!" << endl;
           usleep(3000000);
         cout << "\t\t\t" << "The Eagle Has Landed!!!" << endl;

    }

    void StopTurn() {
        usleep(2000000);
        cout << "\t\t\t"<< "*************************" << endl;
        cout << "\t\t\t" << "*  STOP ";
        cout << "\t"<< "Full Flight *\n";
        cout << "\t\t\t"<< "*************************" << endl;
        cout << "\t\t\t" << endl; 
    }



};