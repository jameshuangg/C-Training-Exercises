#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void  imperial (int i, int &inch, int &feet, int &yard)
{
	inch += i;
	feet = feet + inch / 12;
	yard = yard + feet / 3;
	feet = feet % 3;
	inch = inch % 12;
}

int main()
{
   int inch = 9, feet = 2, yard = 4, i = 0;
   cout << "Enter number of inches increased. ";
   cin >> i;
   imperial(i, inch, feet, yard);
   cout << inch << " inch  " << feet << " feet " << yard << " yard" << endl;
   return 0;
}

