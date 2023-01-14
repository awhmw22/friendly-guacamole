#include<iostream>
using namespace std;


int main()
{
	string temperature;
	cout << "Enter temperature of the day : " << endl;
	cin >> temperature;
	string humidity;
	cout << "Enter humidity type of the day : " << endl;
	cin >> humidity;
	if (temperature == "warm" && humidity == "dry") {
		cout << "Play Tennis";
	}
	else if (temperature == "warm" && humidity == "humid") {
		cout << "swim";
	}
	else if (temperature == "cold" && humidity == "dry") {
		cout << "Play Basketball";
	}
	else if (temperature == "cold" && humidity == "humid") {
		cout << "Watch TV";
	}
}
