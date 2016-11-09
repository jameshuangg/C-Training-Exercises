#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

//put the function header here
void coordinates(float radius, float angle, float &x, float &y)
{
	//start coding your function here
	x = radius * cos(angle);
	y = radius * sin(angle);
	
}

int main ()
{	
	cout << "Enter radius of circle. ";
	float radius = 0;
	cin >> radius;
	
	cout << "Enter angle of circle. ";
	float angle = 0;
	cin >> angle;
	
	//declare necessary variables
	float x = 0;
	float y = 0;
	//Call your function
	coordinates(radius, angle, x, y);
	//Print to the console x and y
  	cout << "X Coordinate: " << x << endl;
  	cout << "Y Coordinate: " << y << endl;
	return 0;	
}

