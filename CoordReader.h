/*
 * Class CoordReader
 *
 */

class CoordReader {
  static const int DATA_SIZE = 100;
  int data_array[DATA_SIZE];
   
  private:
      double lat;
      double lon;
      
  public:

        CoordReader() {
          lat = 0.0;
          lon = 0.0;
        }
        
        double getLat() {
          return lat;
        }
        
        double getLon() {
          return lon;
        } 
        /*
        *  Function to read Targetposition and current position coords
        *  
        *
        */

        void Read( double lat, double lon) {

            //declare read stream
            ifstream myinfile;

            int i;
  
            //open file 
            myinfile.open("Targetposition.txt");

            if(myinfile.bad()) {
              cerr << "Unable to open TargetPosition.txt\n";
              exit(8);
            }
            
            //declare string to hold each line of text
            string line;
            int index = 0;
            //loop through myinfile while line exist
            while(getline(myinfile,line))
            {
             
              cout<< "***************************************" << endl;
              cout << "* Reading Target Position Coordinates *" << endl;
              cout<< "***************************************" << endl << endl;

              cout << line << endl << endl;
              // split line into two variables and store in lat and lon
              // data_array[index] = 
              //  lat = cReader.getLat;
              //  lon = cReader.getLon;

              index++;
            }
            
            //make sure and close ifstream
            myinfile.close();  

        }   
};