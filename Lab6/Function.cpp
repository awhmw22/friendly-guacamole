#include<iostream>
using namespace std;

int isGreater(int num1, int num2, int num3);

int main()
{
	int number1, number2, number3, result;
	cout << "Enter first number :" << endl;
	cin >> number1;
	cout << "Enter second number :" << endl;
	cin >> number2;
	cout << "Enter third number :" << endl;
	cin >> number3;
  result=isGreater(number1, number2, number3);
  cout << "Greatest number is :" << result;
  return result;
}
int isGreater(int num1, int num2, int num3)
{
	int greater = num1;
	if (num1 > num2 && num1 > num3) {
		greater= num1;
	}
	else if (num2 > num1 && num2 > num3) {
		greater= num2;
	}
	else if (num3 > num1 && num3 > num2) {
		greater= num3;
	}
	else {
		greater = 0;
	}
	return greater;
}