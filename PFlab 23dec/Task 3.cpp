#include<iostream>
using namespace std;
int main()
{
	          /*A toy car accelerates from initial velocity to final velocity in some time. You have to
write the C++ program for calculating the Final Velocity. Take initial velocity,
acceleration, and time as input from the user and calculate the final velocity of the car,
and display it on the screen.*/
	float v1;
	float v2;
	cout << "Enter the initial velocity of the car in metres per second : " << endl;
	cin >> v1;
	float time;
	cout << "Enter the time taken by the car in seconds : " << endl;
	cin >> time;
	float acceleration;
	cout << "Enter the acceleration of the car in metre per square second : " << endl;
	cin >> acceleration;
	v2 = v1 + (acceleration * time);
	cout << "The final velocity of the car in metres per second is : " << v2 << endl;
	return 0;



}