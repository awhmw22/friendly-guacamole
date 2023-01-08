#include<iostream>
using namespace std;


int main()
{
	int hours;
	cout << "Enter the number of hours per day :" << endl;
	cin >> hours;
	int days;
	cout << "Enter the number of days :" << endl;
	cin >> days;
	int workers;
	cout << "Enter the number of workers required :" << endl;
	cin >> workers;
	int final_hours= days * hours;
	cout << "The final hours required to complete the project are : " << final_hours << endl;;
	int time;
	cout << "Enter the Time taken to complete the project in hours :" << endl;
	cin >> time;
	int hrs_left=final_hours-time;
	int hrs_needed = time - final_hours;
	if (time > 270) {
		cout << "Not enough time!" << hrs_needed <<"hours needed" << endl;
		cout << "Bad luck!Project needs more time" << endl;
	}
	if (time < 270) {
		cout << "Yes!" << hrs_left << "hours left" << endl;
		cout << " Hurrah!Project has been finished in time " << endl;
	}
}