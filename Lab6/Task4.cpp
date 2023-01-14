#include<iostream>
using namespace std;

string CheckSpeed(float speed);

int main()
{
	float Speed;
	cout << "Enter speed of car :" << endl;
	cin >> Speed;
	string result = CheckSpeed(Speed);
	cout << result;
}
string CheckSpeed(float speed)
{
	string Check;
	if (speed <= 10) {
		cout << "slow" << Check;
	}
	else if (speed >= 10 && speed <= 50) {
		cout << "averge" << Check;

	}
	else if (speed >= 50 && speed <= 150) {
		cout << "fast" << Check;
	}
	else if (speed >= 150 && speed <= 1000) {
		cout << "ultra-fast" << Check;
	}
	else {
		cout << "extremely fast";
	}
	return Check;
}