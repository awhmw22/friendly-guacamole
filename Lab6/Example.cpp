#include<iostream>
using namespace std;
int main()
{
	float price;
	cout << "Enter the price of the dress" << endl;
	cin >> price;
	string brand;
	cout << "Enter the brand of the dress" << endl;
	cin >> brand;
		if (price <= 1500 && brand=="Outfitters") {
			cout << "Buy the dress";
		}
	else {
		cout << "Do not buy the dress";
	}
}