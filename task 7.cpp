// task 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	float charge;
	cout << "Enter the charge of particle : " << endl;
	cin >> charge;
	float time;
	cout << "Enter the time taken by the charge : " << endl;
	cin >> time;
	float current = charge / time;
	cout << "Current through the wire is : " << current << endl;
	return 0;
}