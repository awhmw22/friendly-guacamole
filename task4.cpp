#include<iostream>
using namespace std;
int main()
{
	float lbs = 0.45;
	cout << lbs << endl;
	float input;
	cout << "Enter the amount in lbs : " << endl;
	cin >> input;
	float result = lbs * input;
	cout << "The amount in kgs is : " << result << endl;
	return 0;
}