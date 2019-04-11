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

        void Read() {
            //declare read stream
            ifstream myinfile;

            int i;
  
            //open file 
            myinfile.open("TargetPosition.txt");

            if(myinfile.bad()) {
              cerr << "Unable to open TargetPosition.txt\n";
              exit(8);
            }
            
            //declare string to hold each line of text
            string line;
            
            //loop through myinfile while line exist
            while(getline(myinfile,line))
            {
                cout << line << endl;
                cout << "****Reading Target Position Coordinates" << endl;
            }
            
            //make sure and close ifstream
            myinfile.close();  

        }   
};