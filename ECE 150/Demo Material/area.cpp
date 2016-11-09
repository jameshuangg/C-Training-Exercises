#include <iostream>
using namespace std;

//Function that calculates area of rectangle
float rectangle(float length, float width){
	float area = 0; 
	area = length * width;
	return area; 
}
//Function that calculates area of triangle
float triangle(float height, float base){
	//INSERT CODE HERE
	float area = 0;
	area = height * base / 2;
	return area;
}

//Function that calculates area of circle
//INSERT CODE HERE
float circle(float radius) {
	float area = 0;
	area = 3.14159 * radius * radius;
	return area;
}


//Prfloat the area. 
//Return type is "void" if no return is needed. 
void prfloatArea(float area){
	cout << "The area is: " << area << endl;
	//No return keyword here. 
}




int main(){
	//Store input shape as a char array.
	char shape[100] = {0};
	float length, width, area, height, base, radius;

	//Prompt user to enter the shape to determine area of. 
	cout << "Input shape (all lowercase letters!): ";
	cin >> shape; 
	

	//If shape is a rectangle. 
	if(shape[0] == 'r'){
		//Allow users to enter appropiate values 
		cout << "Enter length: ";
		cin >> length; 
		cout << "Enter width: ";
		cin >> width; 
		//Call rectangle function
		area = rectangle(length, width);
	}
	
	//If shape is a triangle.
	else if(shape[0] == 't'){
		cout << "Enter height: ";
		cin >> height;
		cout << "Enter base: ";
		cin >> base;
		//Call triangle function
		area = triangle(height, base);
	}
	
	//If shape is a circle.
	else if(shape[0] == 'c'){
		cout << "Enter radius: ";
		cin >> radius;
		//Call circle function
		area = circle(radius);
	}
	
	//Call prfloatArea function to output area. 
	prfloatArea(area);
}