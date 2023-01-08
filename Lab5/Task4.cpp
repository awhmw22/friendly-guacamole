#include<iostream>
using namespace std;
int isEvenOdish(int num1);
main()
{
    int number1, result;
    cout << "Enter a five digit number : " << endl;
    cin >> number1;
    result=isEvenOdish(number1);
    return result;
}
int isEvenOdish(int num1)
{
    int digit1 = num1 % 10;
    int d1 = num1 / 10;
    int digit2 = d1 % 10;
    int d2 = d1 / 10;
    int digit3 = d2 % 10;
    int d3 = d2 / 10;
    int digit4 = d3 % 10;
    int d4 = d3 / 10;
    int digit5 = d4 % 10;
    int sum = digit1 + digit2 + digit3 + digit4 + digit5;
    if (sum % 2 == 0) {
        cout << "number is even" << endl;
    }
    if (sum % 2 != 0) {
        cout << "number is odd" << endl;
    }
}