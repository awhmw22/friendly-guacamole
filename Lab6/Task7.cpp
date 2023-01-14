#include<iostream>
using namespace std;

float checkCost(string product, string city, int quantity);
int main()
{
	string type;
	cout << "Enter the type of product : " << endl;
	cin >> type;
	string City;
	cout << "Enter the city : " << endl;
	cin >> City;
	int amount=0;
	cout << "Enter the quantity of product sold :" << endl;
	cin >> amount;
    float final_price=checkCost(type, City, amount);
	cout << "The final price is :" << final_price << endl;
}
float checkCost(string product, string city, int quantity)
{
	float cost;
	if (product == "coffee") {
		if (city == "Sophia") {
			cost = quantity * 0.50;
		}
		else if  (city == "Plovdiv") {
		cost = quantity * 0.40;
	}
		else if (city == "Varna") {
			cost = quantity * 0.45;
		}
	}
	else if (product == "water") {
		if (city == "Sophia") {
			cost = quantity * 0.80;
		}
		else if (city == "Plovdiv") {
			cost = quantity * 0.70;
		}
		else if (city == "Varna") {
			cost = quantity * 0.70;
		}
	}
		else if (product == "beer") {
			if (city == "Sophia") {
				cost = quantity * 1.20;
			}
			else if (city == "Plovdiv") {
				cost = quantity * 1.15;
			}
			else if (city == "Varna") {
				cost = quantity * 1.10;
			}
		}
		else if (product == "sweets") {
			if (city == "Sophia") {
				cost = quantity * 1.45;
			}
			else if (city == "Plovdiv") {
				cost = quantity * 1.30;
			}
			else if (city == "Varna") {
				cost = quantity * 1.35;
			}
		}
		else if (product == "peanuts") {
			if (city == "Sophia") {
				cost = quantity * 1.60;
			}
			else if (city == "Plovdiv") {
				cost = quantity * 1.50;
			}
			else if (city == "Varna") {
				cost = quantity * 1.55;
			}
		}
	return cost;
}
