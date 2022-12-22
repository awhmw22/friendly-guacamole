#include<iostream>
using namespace std;
int main()
{
	/*Write a program that takes the megabytes from the user and converts them
into bits and prints the value on the screen. 1MB = 1024 Kb & 1KB = 1024 Bytes &
1Bytes = 8 Bits*/


	int convertedValue;
	convertedValue = 1024 * 1024 * 8 ;
	cout << "The value of one megabyte in bits is : " << convertedValue << endl;
	return 0;

}