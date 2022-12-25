#include<iostream>
using namespace std;
int main()
{
	/*There is a modulus operator that returns the remainder For Example if we take the
modulus of 4 with 3 it would return 1. If we take 7 % 4 it would return 3.
With the help of a modulus operator, write a program that takes a 4-digit number from the
user and sums individual digits.*/

	int num1;
	cout << "Enter a four digit number : " << endl;
	cin >> num1;
	int sum = 0;
	int remainder;
	while (num1 > 0) {
		remainder = num1 % 10;
		sum = sum + remainder;
		num1 = num1 / 10;
	}
	cout << "Sum of digits is : " << sum << endl;
	return 0;
}