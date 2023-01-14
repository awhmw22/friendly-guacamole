#include<iostream>
using namespace std;

float lowestPrice(int n, string period);

int main()
{
	int number;
	cout << "Enter the number of kilometres :" << endl;
	cin >> number;
	string time;
	cout << "Enter the time of the day :" << endl;
	cin >> time;
	float result;
	result = lowestPrice(number, time);
	cout << "Cheapest price is :" << result;
}
float lowestPrice(int n, string period)
{
	float price;
	if (period == "day") {
		price = (0.79 * n) + 0.70;
	}
	else if (period == "night") {
		price = (0.90 * n) + 0.70;
	}

	else if (n >= 20 && n <= 99) {

		price = 0.09 * n;
	}
	else if (n >= 100) {
		price = 0.06 * n;
	}
	return price;
}
