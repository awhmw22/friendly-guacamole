#include<iostream>
using namespace std;

float totalIncome(string type, int rows, int cols);

int main()
{
	int r, c;
	cout << "Enter number of rows :" << endl;
	cin >> r;
	cout << "Enter number of columns :" << endl;
	cin >> c;
	string kind;
	cout << "Enter ticket type :" << endl;
	cin >> kind;
	float result=totalIncome( kind, r,  c);
	cout << result;
}
float totalIncome(string type, int rows, int cols)
{
	float total_price;
	if (type == "Premiere") {
		total_price = (rows * cols) * 12.50;
	}
	else if (type == "Normal") {
		total_price = (rows * cols) * 7.50;
	}
	else if (type == "Discount") {
		total_price = (rows * cols) * 5.50;
	}
	return total_price;
}

