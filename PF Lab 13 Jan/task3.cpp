#include<iostream>
using namespace std;


//Write a Program to display an Astrological sign or a Zodiac sign for a given date of birth.

int main()
{
	int day;
	cout << "Enter your date of birth : " << endl;
	cin >> day;
	string month;
	cout << "Enter your birth month : " << endl;
	cin >> month;
	string sign;
	if ((month == "March" && day <= 20)||(month=="April" && day<=19)) {
		sign = "Aries";
	}
	else if((month == "April" && day >19) || (month == "May" && day <= 20)) {
			sign = "Taurus";
	}
	else if ((month == "May" && day > 20) || (month == "June" && day <= 20)) {
			sign = "Gemini";
	}
	else if ((month == "June" && day > 20) || (month == "July" && day <= 22)){
			sign = "Cancer";
	}
	else if ((month == "July" && day > 22) || (month == "August" && day <= 22)){
			sign = "Leo";
	}
	else if ((month == "August" && day> 22) || (month == "September" && day <= 22)){
			sign = "Virgo";
	}
	else if ((month == "September" && day > 22) || (month == "October" && day <= 22)){
			sign = "Libra";
	}
	else if ((month == "October" && day > 22) || (month == "November" && day <= 21)){
			sign = "Scorpio";
	}
	else if ((month == "November" && day > 21) || (month == "December" && day <= 21)){
		sign = "Sagittarius";
	}
	else if ((month == "December" && day > 21) || (month == "January" && day <= 19)) {
		sign = "Capricorn";
	}
	else if ((month == "January" && day > 19) || (month == "February" && day <= 18)) {
			sign = "Aquarius";
	}
	else if ((month == "February" && day>18) || (month == "March" && day <= 20)) {
			sign = "Pisces";
	}
	cout << "Your Zodiac Sign is : " << sign << endl;
}
