#include<iostream>
using namespace std;
int main()
{
	         //Write a program that takes 5 integers from the user and displays their sum on screen.
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	cout << "Enter first number : " << endl;
	cin >> num1;
	cout << "Enter second number : " << endl;
	cin >> num2;
	cout << "Enter third number : " << endl;
	cin >> num3;
	cout << "Enter fourth number : " << endl;
	cin >> num4;
	cout << "Enter fifth number : " << endl;
	cin >> num5;
	int sum = num1 + num2 + num3 + num4 + num5;
	cout << "Sum of the numbers is : " << sum << endl;
	return 0;
}