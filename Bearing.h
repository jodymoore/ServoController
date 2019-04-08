/*
 * Class Bearing
 *
 */


class Bearing {
  

  const double PI  = 3.141592653589793238463;

  private:
      int _bearing;
      int _heading;
      
  public:

        Bearing() {
          _bearing = 0;
          _heading = 0;
        }
        
        double getBearing() {
          return _bearing;
        }
        
        double getHeading() {
          return _heading;
        } 
  

  /* 
  Code Snippet From
  https://gis.stackexchange.com/questions/252672/calculate-bearing-between-two-decimal-gps-coordinates-arduino-c 
  */

  double bearing(double lat, double lon, double lat2, double lon2){

      double teta1 = radians(lat);
      double teta2 = radians(lat2);
      double delta1 = radians(lat2-lat);
      double delta2 = radians(lon2-lon);

      //==================Heading Formula Calculation================//

      double y = sin(delta2) * cos(teta2);
      double x = cos(teta1)*sin(teta2) - sin(teta1)*cos(teta2)*cos(delta2);
      double brng = atan2(y,x);
      brng = degrees(brng);// radians to degrees
      brng = (((int)brng + 360) % 360 ); 

      // Serial.print("Heading GPS: ");
      // Serial.println(brng);

      return brng;
  }

  double radians(double n) {
    return n * (PI / 180);
  }

  double degrees(double n) {
    return n * (180 / PI);
  }

};