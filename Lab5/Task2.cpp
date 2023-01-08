#include<iostream>
using namespace std;
void alphabet(char);

int main()
{
    char b=0;
     alphabet(b);
}
void alphabet(char)
{
    char character;
    cout << "Enter a character uppercase or lowercase :" << endl;
    cin >> character;
    if (character == 'A') {
        cout << "You have entered capital A " << endl;
    }
    if(character=='a') {
        cout << "You have entered small a"<< endl;
    }
}