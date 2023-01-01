#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates .X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
int main()
{
	system("Cls");
	cout << "Test";
	gotoxy(14, 14);
	cout << "My name is Huzaifa";
	return 0;
}