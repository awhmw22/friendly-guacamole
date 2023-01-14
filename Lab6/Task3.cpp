#include<iostream>
using namespace std;

string CheckTitle(char gender, int age);

int main()
{
	char sex;
	cout << "Enter gender of the person :" << endl;
	cin >> sex;
	int Age;
	cout << "Enter the age of person :" << endl;
	cin >> Age;
	string Title=CheckTitle(sex, Age);
	cout << "Title is :" << Title;
}
string CheckTitle(char gender, int age)
{
	string title;
	if (gender == 'm' && age >= 16) {
		title = "Mr";
	}
	else if (age < 16) {
		title = "Master";
	}
	else if (gender == 'f' && age >= 16) {
		title = "Ms";
	}
	else if (age < 16) {
		title = "Miss";
	}
	return title;
}