#include<iostream>
using namespace std;
int main()
{
	         /*A teacher wants to calculate the students' marks percentage, teachers have 5 subject
marks for every student. He needs a program that automates this process by asking 5
subjects' marks from the user and calculating the percentage of students. Total marks are
500 for 5 subjects. To guide the user, first, you need to display a message and then take
input from the user. Do it for all 5 subjects.*/
	int marks1;
	int marks2;
	int marks3;
	int marks4;
	int marks5;
	string name;
	cout << "Enter the name of student : " << endl;
	cin >> name;
	cout << "Enter subject 1 marks : " << endl;
	cin >> marks1;
	cout << "Enter subject 2 marks : " << endl;
	cin >> marks2;
	cout << "Enter subject 3 marks : " << endl;
	cin >> marks3;
	cout << "Enter subject 4 marks : " << endl;
	cin >> marks4;
	cout << "Enter subject 5 marks : " << endl;
	cin >> marks5;
	int totalmarks = 500;
	int obtainedmarks = marks1 + marks2 + marks3 + marks4 + marks5;
	float percentage;
	percentage = (obtainedmarks * 100) / totalmarks;
	cout << "The percentage of student's marks is : " << percentage << endl;
	return 0;
}