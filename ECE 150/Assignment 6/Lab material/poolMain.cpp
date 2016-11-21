#include <iostream>
#include "pool.h"

using namespace std;

int main(int argc, char* argv[]) 
{
  if (argc != 2) 
  {
    cerr << "Usage Error: " << argv[0] << " <filename>" << endl;
    exit(-1);
  }
  float pool[20][10];
  if (!readPool(argv[1], pool)) 
  {
    cerr << "Unable to read datafile: " << argv[1] << endl;
    exit(-1);
  }
  //open the output filebuf
  ofstream fileOut ("poolOut.csv");
  //use the printPool function
  printPool(fileOut, pool);
  fileOut.close();
  
  //use the findFaulty function
  findFaulty(pool);
  
  return 0;
}
