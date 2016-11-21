#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

void circle(float radius, float& area, float& circumference)
{
	//start coding your function here
	area = M_PI * pow(radius, 2);
	circumference = 2 * radius * M_PI;
}

int main ()
{	
	cout << "Enter radius of circle. ";
	float radius;
	cin >> radius;
	
	float a = 0, c = 0;
	
	//Call your function here
	circle(radius, a, c);
	cout << "Area of circle = " << a << " circumference = " << c
  	     << endl;
  	     
	return 0;	
}

