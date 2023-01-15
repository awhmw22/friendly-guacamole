#include<iostream>
#include<windows.h>
using namespace std;

void printMaze();
void gotoxy(int x, int y);
void ShowPacamn(int x, int y);
void ShowGhost(int x, int y);
void clear(int x, int y,char Previous);
char getCharAtxy(short int x, short int y);
	
int main()
{
	int gx = 1;
	int gy = 1;
	string direction = "right";
	char PreviousChar = ' ';
	system("cls");
	printMaze();
	ShowGhost(gx, gy);
	while (true) {
		Sleep(100);
		if (direction == "right") {
			char nextlocation = getCharAtxy(gx+1, gy);
			if (nextlocation == '%') {
				direction == "left";
			}
			else if (nextlocation == ' ' || nextlocation == '.') {
				clear(gx, gy, PreviousChar);
				gx = gx + 1;
				PreviousChar = nextlocation;
				ShowGhost(gx, gy);
			}
		}
		if (direction == "left") {
			char nextlocation = getCharAtxy(gx-1, gy);
			if (nextlocation == '%') {
				direction == "right";
			}
			else if (nextlocation == ' ' || nextlocation == '.') {
				clear(gx, gy, PreviousChar);
				gx = gx - 1;
				PreviousChar = nextlocation;
				ShowGhost(gx, gy);
			}
		}
	}

}
void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
	CHAR_INFO ci;
	COORD xy = { 0, 0 };
	SMALL_RECT rect = { x, y, x, y };
	COORD coordBufSize;
	coordBufSize.X = 1;
	coordBufSize.Y = 1;
	return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
		: ' ';
}
void clear(int x, int y,char Previous)
{
	gotoxy(x, y);
	cout << Previous;
}
void ShowGhost(int x, int y) {
	gotoxy(x, y);
	cout << "G";
}
void printMaze()
{
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% " << endl;

	cout << "%                             %  " << endl;

	cout << "%                             %  " << endl;

	cout << "%                             %  " << endl;

	cout << "%                             %  " << endl;

	cout << "%                             %  " << endl;

	cout << "%                             %  " << endl;

	cout << "%                             %  " << endl;

	cout << "%                             %  " << endl;

	cout << "%                             %  " << endl;

	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% " << endl;
}