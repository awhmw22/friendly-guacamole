#include<iostream>
using namespace std;
char CalculateGrade(int marks);
int main()
{
	int Marks;
	cout << "Enter marks" << endl;
	cin >> Marks;
	char result= CalculateGrade( Marks);
	cout << "Grade is :" << result;
	return result;
}
char CalculateGrade(int marks)
{
	char grade;
	if (marks < 50) {
		grade = 'F';
	}
	else if (marks >= 50 && marks <= 60) {
		grade = 'E';
	}
	else if (marks >= 60 && marks <= 70) {
		grade = 'D';
	}
	else if (marks >= 70 && marks <= 80) {
		grade = 'C';
	}
	else if (marks >= 80 && marks <= 85) {
		grade = 'B';
	}
	else {
		grade = 'A';
	}
	return grade;
}