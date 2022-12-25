#include<iostream>
using namespace std;
int main()
{
	          /*Write a program that takes 15 numbers from the user, it adds the first 5 numbers,
multiplies the next 5 numbers, and subtract the next 5 numbers. After that, it adds the
first two results and subtracts the 3rd result, and shows the final output on the monitor
screen.*/
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	int num6;
	int num7;
	int num8;
	int num9;
	int num10;
	int num11;
	int num12;
	int num13;
	int num14;
	int num15;
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
	cout << "Enter sixth number : " << endl;
	cin >> num6;
	cout << "Enter seventh number : " << endl;
	cin >> num7;
	cout << "Enter eighth number : " << endl;
	cin >> num8;
	cout << "Enter ninth number : " << endl;
	cin >> num9;
	cout << "Enter tenth number : " << endl;
	cin >> num10;
	cout << "Enter eleventh number : " << endl;
	cin >> num11;
	cout << "Enter twelveth number : " << endl;
	cin >> num12;
	cout << "Enter thirteenth number : " << endl;
	cin >> num13;
	cout << "Enter fourteenth number : " << endl;
	cin >> num14;
	cout << "Enter fifteenth number : " << endl;
	cin >> num15;
	int sum = num1 + num2 + num3 + num4 + num5;
	cout << "Sum is : " << sum<<endl;
	int multi = num6 * num7 * num8 * num9 * num10;
	cout << "Product is : " <<multi<< endl;
	int subtract = num11 - num12 - num13 - num14 - num15;
	cout << "Difference is : " <<subtract<< endl;
	int result = sum + multi - subtract;
	cout << "The final result is : " << result << endl;
	return 0;
}