#include <iostream>
using namespace std;

string first(int num);
string second(int num);


int main()
{
    int num1;
    string fd, ts, df;

    while (true) {

        cout << "Enter number: ";
        cin >> num1;

        fd = second(num1);
        ts = first(num1);


        cout << ts +fd << endl;

    }

    return 0;
}

string first(int num)
{
    string first_digit;
    num = num / 10;

    if (num == 0) {
        first_digit = "";
    }
    if (num == 2) {
        first_digit = "Twenty ";
    }
    if (num == 3) {
        first_digit = "Thirty ";
    }
    if (num == 4) {
        first_digit = "Forty ";
    }
    if (num == 5) {
        first_digit = "Fifty ";
    }
    if (num == 6) {
        first_digit = "Sixty ";
    }
    if (num == 7) {
        first_digit = "Seventy ";
    }
    if (num == 8) {
        first_digit = "Eighty ";
    }
    if (num == 9) {
        first_digit = "Ninty";
    }
    return first_digit;
}

string second(int num)
{
    string second_digit;
    num = num % 10;

    if (num == 0) {
        second_digit = "";
    }
    if (num == 1) {
        second_digit = "One ";
    }
    if (num == 2) {
        second_digit = "Two ";
    }
    if (num == 3) {
        second_digit = "Three ";
    }
    if (num == 4) {
        second_digit = "Four ";
    }
    if (num == 5) {
        second_digit = "Five ";
    }
    if (num == 6) {
        second_digit = "Six ";
    }
    if (num == 7) {
        second_digit = "Seven ";
    }
    if (num == 8) {
        second_digit = "Eight ";
    }
    if (num == 9) {
        second_digit = "Nine";
    }
    return   second_digit;
}
