#include<iostream>
using namespace std;
int main()
{
	            /*A gardener is selling his harvest on the vegetables market. He is selling vegetables for N
coins per kilogram and fruits for M coins per kilogram. Write a program that calculates
the earnings of the harvest in Rupees (Rps). Assume the Rps / coin rate is fixed: 1 Rp ==
1.94 coins.
Input Data and Output Data:
Four numbers are read from the console, one per line:
● First line: vegetable price per kilogram – a floating-point number.
● Second line: fruit price per kilogram – a floating-point number.
● Third line: total kilograms of vegetables – an integer.
● Fourth line: total kilograms of fruits – an integer.
Output should be the earnings of all fruits and vegetables in Rps on the console.*/

	float N;
	cout << "Enter the price of vegetables sold in coins per kilogram : " << endl;
	cin >> N;
	float M;
	cout << "Enter the price of fruits sold in coins per kilogram : " << endl;
	cin >> M;
	int total_kgs;
	cout << "Enter the total kilograms of vegetables sold : " << endl;
	cin >> total_kgs;
	int total_kilos;
	cout << "Enter the total kilograms of fruits sold : " << endl;
	cin >> total_kilos;
	double cost=((N*total_kgs)/1.94);
	cout << "The total cost of vegetables in rupees is : " << cost << endl;
	double price = ((M * total_kilos)/1.94);
	cout << "The total price of fruits in rupees is : " << price << endl;
	double earnings = ((cost + price)/1.94);
	cout << "The total earnings of fruits and vegetables in rupees is : " << earnings << endl;
	return 0;
}