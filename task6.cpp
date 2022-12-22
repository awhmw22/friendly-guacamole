// task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int length;
	cout << "Enter the length of each side of the rectangle : " << endl;
	cin >> length;
	int width;
	cout << "Enter the width of each side of the rectangle : " << endl;
	cin >> width;
	int Area = length * width;
	cout << "The area of rectangle is : " << Area << endl;
	return 0;
}
