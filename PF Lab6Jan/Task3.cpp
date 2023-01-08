#include<iostream>
using namespace std;
float calculateTax(char type, float price);
int main()
{
	char vehicle_type;
	float item_price;
	calculateTax(vehicle_type, item_price);
}
float calculateTax(char type, float price)
{
	cout << "Enter vehicle type : " << endl;
	cin >> type;
	cout << "Enter price of vehicle : " << endl;
	cin >> price;
	float Tax_Amount;
	if (type == 'M') {
		Tax_Amount = price * 6 / 100;
	}
	if (type == 'E') {
		Tax_Amount = price * 8 / 100;
	}
	if (type == 'S') {
		Tax_Amount = price * 0.1;
	}
	if (type == 'V') {
		Tax_Amount = price * 12 / 100;
	}
	if (type == 'T') {
		Tax_Amount = price * 15 / 100;
	}
	float final_price = price + Tax_Amount;
	cout << "Final price of vehicle after tax is :" << final_price << endl;
	return Tax_Amount;
}   
