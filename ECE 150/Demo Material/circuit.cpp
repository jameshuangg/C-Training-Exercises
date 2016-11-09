#include <iostream>
using namespace std;

//Function to calculate equivalent resistor. 
float calculateResistance(float resistor[]){
	//INSERT CODE HERE
	float temp, equivalentResistance;
	for (int i = 0; i < numOfResistors; i++) {
		temp = temp + 1.0/resistor[i];
	}
	equivalentResistance = 1.0/temp;
	cout << "Equivalent resistance = " << equivalentResistance << "Ohms";
	return equivResistance;
}

//Function to calculate current of a specified resistor #.
//INSERT CODE HERE
float current(float resistor[], int resistorNum, float voltage) {
	float current = voltage/resistor[resistorNum];
	cout << "Current of Resistor " << resistorNum+1 << " is " << current << " Amps";
	return current;
}


int main() {

	int numOfResistors = 3;                     
	float equivalentResistance, current, voltage;               
	int resistorLabel = 0;                     
	float resistor[3] = {0};
	

	//Prompt user to input the 3 resistors of their choice in the array "resistor"
	//INSERT CODE HERE
	cout << "Enter the 3 resistors";
	for(int i = 0; i < 3; i++) {
		cin >> resistor[i];
	}

	//Prompt user to input voltage (12.2 V), and the resistor number (1) to find the current of.
	//Call the calculation functions 
	//INSERT CODE HERE
	cout << "Enter voltage: " << endl;
	cin >> voltage;

	cout << "Enter resistor number to find current of: " << endl;
	cin >> resistorLabel;

	equivalentResistance = calculateResistance(resistor);
	cout << endl;
	current = calculateResistance(resistor, resistorLabel-1, voltage);
	
 	return 0;
}