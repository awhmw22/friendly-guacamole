#include<iostream>
#include<windows.h>
using namespace std;

void printMaze();
void gotoxy(int x, int y);
void printPacman(int x, int y);
void erase(int x, int y);
char getCharAtxy(short int x, short int y);

int main()
{
	int PacmanX = 4;
	int PacmanY = 4;
	bool gamerunning = true;
	system("cls");
	printMaze();
	printPacman(PacmanX, PacmanY);
	while (gamerunning) {
		if (GetAsyncKeyState(VK_LEFT)) {
			char nextlocation = getCharAtxy(PacmanX - 1, PacmanY);
			if (nextlocation == ' ') {
				erase(PacmanX, PacmanY);
				PacmanX = PacmanX - 1;
				printPacman(PacmanX, PacmanY);
			}
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			char nextlocation = getCharAtxy(PacmanX + 1, PacmanY);
			if (nextlocation == ' ') {
				erase(PacmanX, PacmanY);
				PacmanX = PacmanX + 1;
				printPacman(PacmanX, PacmanY);
			}
		}
		if (GetAsyncKeyState(VK_UP)) {
			char nextlocation = getCharAtxy(PacmanX, PacmanY - 1);
			if (nextlocation == ' ') {
				erase(PacmanX, PacmanY);
				PacmanY = PacmanY - 1;
				printPacman(PacmanX, PacmanY);
			}
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			char nextlocation = getCharAtxy(PacmanX, PacmanY + 1);
			if (nextlocation == ' ') {
				erase(PacmanX, PacmanY);
				PacmanY = PacmanY + 1;
				printPacman(PacmanX, PacmanY);
			}
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			gamerunning = false;
		}
	}
	Sleep(200);
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
void erase(int x, int y)
{
	gotoxy(x, y);
	cout << " ";
}
void printPacman(int x, int y) {
	gotoxy(x, y);
	cout << "P";
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
