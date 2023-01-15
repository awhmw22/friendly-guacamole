#include<iostream>
using namespace std;
/*Jack is a teacher who needs a program that helps him to compile 8th class results. He has
five subjects (English, Maths, Chemistry, Social Science, and Biology) marked in detail.
Program asks the user to enter five subjects' marks, including student name and displays
the total marks, percentage, grade (by percentage), and student name. Every subject has a
total of 100 marks.*/

int main()
{
	string name;
	cout << "Enter the student's name :" << endl;
	cin >> name;
	int mark1;
	cout << "Enter subject1 marks :" << endl;
	cin >> mark1;
	int mark2;
	cout << "Enter subject2 marks :" << endl;
	cin >> mark2;
	int mark3;
	cout << "Enter subject3 marks :" << endl;
	cin >> mark3;
	int mark4;
	cout << "Enter subject4 marks :" << endl;
	cin >> mark4;
	int mark5;
	cout << "Enter subject5 marks :" << endl;
	cin >> mark5;
	int total_marks = 500;
	int marks = mark1 + mark2 + mark3 + mark4 + mark5;
	float percentage = (marks * 100) / total_marks;
	cout << "Pecentage of student is : " << percentage << endl;
	string grade;
	if (percentage >= 90 && percentage <= 100) {
		grade = "A+";
	}
	else if (percentage >= 80 && percentage <= 90) {
		grade = "A";
	}
	else if (percentage >= 70 && percentage <= 80) {
		grade = "B+";
	}
	else if (percentage >= 60 && percentage <= 70) {
		grade = "B";
	}
	else if (percentage >= 50 && percentage <= 60) {
		grade = "C";
	}
	else if (percentage >= 40 && percentage <= 60) {
		grade = "D";
	}
	else if (percentage<40) {
		grade = "F";
	}
	cout << "Grade of student is : " << grade << endl;
}