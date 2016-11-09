#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

//Write your function here
void timeIncrease(int increase, int &minutes, int &hours) {
	hours = floor(hours + (minutes + increase)/60);
	minutes = (minutes + increase) % 60;
}

int main()
{
   int minutes = 46, hours = 3, m = 0;
   cout << "Enter number of minutes past. ";
   cin >> m;
   
   //call your function here
   timeIncrease(m, minutes, hours);
   cout << hours << " hours " << minutes  << " minutes. " << endl;
   
   return 0;
}

