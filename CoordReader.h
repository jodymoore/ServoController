/*
 * Class CoordReader
 *
 */
 #include <string.h>
 #include <stdio.h>

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
        */
        void Read( double &lat, double &lon, string fileName) {

            // declare read stream
            ifstream myinfile;

            int i;
  
            // open file 
            myinfile.open(fileName);

            if(myinfile.bad()) {
              cerr << "Unable to open TargetPosition.txt\n";
              exit(8);
            }
            
            // declare string to hold each line of text
            string line;
            // loop through myinfile while line exist
            getline(myinfile,line);
            
             
              cout << "\t\t\t" <<"***************************************" << endl;
              cout << "\t\t\t" << "* Reading Target Position Coordinates *" << endl;
              cout << "\t\t\t" << "***************************************" << endl << endl;

              cout << "\t\t\t" << line << endl << endl;
              // split line into two variables and store in lat and lon

               char * tab2 = new char [line.length()+1];

               strcpy(tab2, line.c_str());

               char * pch;
     
               pch = strtok(tab2," ");
              // // data_array[index] = 
       
               lat = atof(pch);
               pch = strtok(NULL, " ");

               lon = atof(pch);
                    
            // make sure and close ifstream
            myinfile.close();  

        }   

};