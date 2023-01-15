#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int exam_hrs;
	cout << "Enter hours of exam starting time : " << endl;
	cin >> exam_hrs;
	int exam_mints;
	cout << "Enter minutes of exam time : " << endl;
	cin >> exam_mints;
	int arrival_hrs;
	cout << "Enter the time in hours of student's arrival : " << endl;
	cin >> arrival_hrs;
	int arrival_mints;
	cout<<"Enter the time in minutes of student's arrival : " << endl;
	cin >> arrival_mints;
	int exam_time = exam_hrs * 60 + exam_mints;
	int arrival_time = arrival_hrs * 60 + arrival_mints;
	int difference = arrival_time - exam_time;
	if (difference <= -30) {
		cout << "The student has reached earlier by : " << endl;
		difference = abs(difference);
		cout << difference / 60 << "hours" << ":" << difference % 60 << "minutes" << endl;
	}
	else if (difference >= -30 && difference <= 0) {
		cout << "The student has reached on time " << endl;
	}
	else {
		cout << "The student has reached late by : " << endl;
		cout << difference / 60 << "hours" << ":" << difference % 60 << "minutes" << endl;
	}
	return 0;
}
