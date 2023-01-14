#include<iostream>
using namespace std;

float discount(string day, string month, float amount);

int main()
{
	float price, result;
	cout << "Enter the price of goods :" << endl;
	cin >> price;
	string Day;
	cout << "Enter the Day :" << endl;
	cin >> Day;
	string Month;
	cout << "Enter month :" << endl;
	cin >> Month;
	result=discount( Day,  Month,  price);
	cout << "Discount is :" << result;
	return result;
}
float discount(string day, string month, float amount)
{
	float payable = amount;
	
		if (day=="Sunday"&&(month == "March" || month == "May" || month == "August")) {
			payable = amount - (amount * 0.1);
		}
	
	 else if(day=="Monday"){
			if (month == "November" || month == "December") {
				payable = amount - (amount * 0.05);
		    }
	 }
	return payable;
}