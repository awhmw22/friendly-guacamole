#include<iostream>
using namespace std;
int main()
{
	                          /*Task 02(OP): Write a C++ program to ask the user to enter two integers. Then, store the
sum of those two integers in a variable and then display the sum on the screen.*/

	int num1;
	int num2;
	cout << "Enter the first integer : " << endl;
	cin >> num1;
	cout << "Enter the second integer : " << endl;
	cin >> num2;
	int sum = num1 + num2;
	cout << "The sum of two integers is : " << sum << endl;
	return 0;
}