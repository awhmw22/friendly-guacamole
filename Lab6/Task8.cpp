#include<iostream>
#include<cmath>
using namespace std;

float CheckBudget(string category, int quantity);
int main()
{
	string Category;
	cout << "Enter ticket type :" << endl;
	cin >> Category;
	float Budget;
	int amount;
	cout << "Enter the quantity of people : " << endl;
	cin >> amount;
	Budget= CheckBudget( Category, amount);
	float N;
	cout << "Enter ticket amount in QR :" << endl;
	cin >> N;
	float rem_amount;
	if (rem_amount<N) {
		rem_amount = N - Budget;
		cout << "Yes! you have" << rem_amount << "leva left" << endl;
		floor(rem_amount);
	}
	else if(rem_amount>N){
		rem_amount = N + Budget;
		cout << "Not enough money!You need" << rem_amount << "more leva" << endl;
		floor(rem_amount);
	}
}
float CheckBudget(string category, int quantity)
{
	float budget;
	if (category == "VIP") {
		if (quantity <= 4) {
			budget = 499.99 - (499.99 * 0.75);
		}
		else if (quantity > 5 && quantity < 10) {
			budget = 499.99 - (499.99 * 0.60);
		}
		else if (quantity > 10 && quantity < 25) {
			budget = 499.99 - (499.99 * 0.50);
		}
		else if (quantity > 25 && quantity < 50) {
			budget = 499.99 - (499.99 * 0.40);
		}
		else if (quantity >= 50) {
			budget = 499.99 - (499.99 * 0.25);
		}
	}
	else if (category == "Normal") {
		if (quantity <= 4) {
			budget = 249.99 - (249.99 * 0.75);
		}
		else if (quantity > 5 && quantity < 10) {
			budget = 249.99 - (249.99 * 0.60);
		}
		else if (quantity > 10 && quantity < 25) {
			budget = 249.99 - (249.99 * 0.50);
		}
		else if (quantity > 25 && quantity < 50) {
			budget = 249.99 - (249.99 * 0.40);
		}
		else if (quantity >= 50) {
			budget = 249.99 - (249.99 * 0.25);
		}
	}
	return budget;
}
