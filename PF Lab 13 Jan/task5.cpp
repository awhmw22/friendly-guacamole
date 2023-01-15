#include<iostream>
#include<string>
using namespace std;


int main()
{
	string fruit;
	cout << "Enter the fruit name you want to buy : " << endl;
	cin >> fruit;
	string day;
	cout << "Enter the day of your purchase : " << endl;
	cin >> day;
	float amount;
	cout << "Enter the quantity you want to buy : " << endl;
	cin >> amount;
	float price;
	if (day == "Saturday" || day == "Sunday") {
		if (fruit == "banana") {
			price = amount * 2.70;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "Apple") {
			price = amount * 1.25;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "Orange") {
			cout << "Your bill is : " << price << endl;
			price = amount * 0.90;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "grapefruit") {
			price = amount * 1.60;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "kiwi") {
			price = amount * 3.00;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "pineapple") {
			price = amount * 5.60;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "grapes") {
			price = amount * 4.20;
			cout << "Your bill is : " << price << endl;
		}
	}

	else if (day != "Saturday" || day != "Sunday") {
		if (fruit == "banana") {
			price = amount * 2.50;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "Apple") {
			price = amount * 1.20;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "Orange") {
			price = amount * 0.85;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "grapefruit") {
			price = amount * 1.45;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "kiwi") {
			price = amount * 2.70;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "pineapple") {
			price = amount * 5.50;
			cout << "Your bill is : " << price << endl;
		}
		else if (fruit == "grapes") {
			price = amount * 3.85;
			cout << "Your bill is : " << price << endl;
		}
	}
}
	