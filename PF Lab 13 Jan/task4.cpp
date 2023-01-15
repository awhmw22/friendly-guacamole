#include<iostream>
using namespace std;

/*Write a program that calculates and prints the bill for a cellular telephone company. The
company offers two types of service: regular and premium. Its rates vary, depending on
the type of service. The rates are computed as follows:
Regular service: $10.00 plus the first 50 minutes are free. Charges for over 50 minutes
are $0.20 per minute.
Premium service: $25.00 plus:
● For calls made during the day., the first 75 minutes are free; charges for more than
75 minutes are $0.10 per minute.
● For calls made during the night, the first 100 minutes are free; charges for more
than 100 minutes are $0.05 per minute.
Your program should prompt the user to enter a service code (type char), and the
number of minutes the service was used.
A service code of r or R means regular service; a service code of p or P
means premium service. Treat any other character as an error. Your program
should output the type of service, the number of minutes the telephone service was used,
and the amount due from the user.
For the premium service, the customer may be using the service during the
day and the night(d or D for day and n or N for the night). Therefore, to calculate the bill,
you must ask the user to input the number of minutes the service was used during the day
and the number of minutes the service was used during the night.*/

int main()
{
	char type;
	cout << "Enter your type of service : " << endl;
	cin >> type;
	float minutes;
	cout << "Enter the minutes of your call : " << endl;
	cin >> minutes;
	char time;
	cout << "(Press'N' for night and 'D' for day type) call : " << endl;
	cin >> time;
	int amount;
	char sign = '$';
	if (type == 'R'){
		if (minutes < 50) {
			amount = 10;
		}
		else if (minutes > 50) {
			amount = minutes * 10.20;
		}
	}
	else if (type == 'P') {
		if (time == 'D' && minutes < 75) {
			amount = 25;
		}
		else if (time=='D' && minutes > 75) {
			amount = minutes * 25.10;
		}
		else if (time == 'N' && minutes < 100) {
			amount = 25;
		}
		else if (time == 'N' && minutes > 100) {
			amount = minutes * 25.05;
		}
	}
	else {
		cout << "Invalid type!" << type << endl;
	}
	cout << "Your bill is : " << amount<<sign << endl;
}