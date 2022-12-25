#include<iostream>
using namespace std;
int main()
{
	int days;
	int weight;
	cout << "Enter the number of days : " << endl;
	cin >> days;
	cout << "Enter the weight in kgs : " << endl;
	cin >> weight;
	cout << "weight lost in 15 days =1kgs " << endl;
	int num_days = weight * days;
	cout << "Number of days taken to loose 12 kgs of weight = " << num_days << endl;
	return 0;
}