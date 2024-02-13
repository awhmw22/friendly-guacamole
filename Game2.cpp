#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
using namespace std;
void gotoxy(int x, int y);
void loadMaze();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
char getCharAtxy(short int x, short int y);
void printLogo();
void moveKillerBee();
void moveBumblebee();
void moveMiningBee();
void moveRabbitLeft();
void moveRabbitRight();
void moveRabbitUp();
void moveRabbitDown();
void eraseRabbit(int x, int y);
void eraseBee(int x, int y);
void increaseScore();
void printScore();
void header();
void printRabbit(int rx, int ry);
void printBee(int x, int y);
void chasePlayer();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void generateBullet();
void moveBullet();
void removeBullet(int x);
//Function for bullet collision with enemy
void bulletCollision();
void Menu();
void printKillerBeebullet(int, int);
void eraseKillerBeebullet(int, int);
void removeKillerBeebullet(int);
void moveKillerBeebullet();
void generateKillerBeebullet();
void killerBeebulletcollision();
void end();
void game();
void printHealth();
void minusHealth();
void printBumblebeebullet(int, int);
void eraseBumblebeebullet(int, int);
void removeBumblebeebullet(int x);
void moveBumblebeebullet();
void generateBumblebeebullet();
void bumblebeebulletcollision();

//For Rabbit
int rx = 5;
int ry = 5;
//For Bees
int bx = 94;
int by = 10;
int b1x = 1;
int b1y = 1;
int b2x = 87;
int b2y = 4;
string Killerbee_direction = "up";
string Bumblebee_direction = "right";
string Miningbee_direction = "left";
//For Firing System
int bulletX[100];
int bulletY[100];
int bulletCount = 0;

//For killer bee firing
int KillerBeebulletx[1000];
int KillerBeebullety[1000];
int KillerBeecount = 0;
//For Bumblebee firing
int Bumblebeebulletx[1000];
int Bumblebeebullety[1000];
int Bumblebeecount = 0;

int timer = 0;
int timer1 = 0;
int score = 0;
int health = 50;
int main() {
	system("cls");
	header();
	cout << endl;
	printLogo();
	cout << endl;
	Menu();
	string option;
	cin >> option;
	if (option == "1") {
		header();
		game();
	}
	else if (option == "2") {
		end();
		return 0;
	}
}
void game()
{
	system("cls");
	bool gamerunning = true;
	loadMaze();
	printScore();
	printRabbit(rx, ry);
	printBee(bx, by);
	printBee(b1x, b1y);
	printBee(b2x, b2y);
	string nextlocation;
	while (gamerunning) {
		printHealth();
		printScore();
		if (GetAsyncKeyState(VK_LEFT)) {
			moveRabbitLeft();
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			moveRabbitRight();
		}
		if (GetAsyncKeyState(VK_UP)) {
			moveRabbitUp();
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			moveRabbitDown();
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {

			break;
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			generateBullet();
		}
		moveKillerBee();
		moveBumblebee();
		moveMiningBee();

		moveKillerBeebullet();
		moveBumblebeebullet();
		if (timer1 == 5) {
			generateKillerBeebullet();
			generateBumblebeebullet();
			timer1 = 0;
		}
		if (health == 0) {
			cout << "Game Over!!!You Lost !!!" << endl;
			break;
		}
		else if (score == 100) {
			cout << "You win!!!";
			break;
		}
		moveBullet();
		bulletCollision();
		killerBeebulletcollision();
		bumblebeebulletcollision();
		timer++;
		timer1++;
		Sleep(90);
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
void loadMaze()
{

	SetConsoleTextAttribute(hConsole, 1);
 	cout << "##########################################################################################################" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "|                                                                                                        |" << endl;
	cout << "##########################################################################################################" << endl;
	/*string maze[200];
	int idx = 0;
	fstream file;
	string word;
	file.open("Maze.txt", ios::in);
	while (!file.eof()) {
		getline(file, word);
		maze[idx] = word;
		idx++;
	}
	file.close();

	for (int i = 0;i < idx;i++) {
		cout << maze[i];
		cout << endl;
	}*/
	SetConsoleTextAttribute(hConsole, 7);
}
void printLogo()
{
	cout << endl;
	cout << "                   .'.                   " << endl;
	cout << "                  /  |                   " << endl;
	cout << "                 /  /                    " << endl;
	cout << "                / ,'                     " << endl;
	cout << "     .-------.---/                       " << endl;
	cout << "    '.___.-/ o. o\\                      " << endl;
	cout << "          (    Y  )                      " << endl;
	cout << "           )     /                       " << endl;
	cout << "          /     (                        " << endl;
	cout << "         /       Y                       " << endl;
	cout << "       .-'       |                       " << endl;
	cout << "      / _        \\                      " << endl;
	cout << "     / `. '. ) /' )                      " << endl;
	cout << "    Y    )(/ /(, /                       " << endl;
	cout << "   ,|      /     )                       " << endl;
	cout << "   (|     /     /                        " << endl;
	cout << "   '\\_  (__   (__       [Bunty]         " << endl;
	cout << "       '-._,)--._,)                      " << endl;
}
void header()
{
	cout << "********************************************************************************************************* " << endl;
	cout << "*                                  BUNTY-THE FIRING RABBIT                                              * " << endl;
	cout << "********************************************************************************************************* " << endl;
}
void printRabbit(int rx, int ry)
{
	SetConsoleTextAttribute(hConsole, 2);
	int size1 = 3;
	int size2 = 3;
	char box = 153;
	char r1[size1][size2] = { {'^',' ','^'  },
							{ ' ',box,' ' },
						    { '/',' ','\\'} };
	for (int i = 0;i < size1;i++) {
		gotoxy(rx, ry + i);
		for (int j = 0;j < size2;j++) {
			cout << r1[i][j];
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 7);
}
void printBee(int x, int y)
{
	gotoxy(x, y);
	int size = 3;
	string b1[size] = {"B","B","B"};
	SetConsoleTextAttribute(hConsole, 4);
	for (int i = 0;i < size;i++) {
		cout << b1[i];
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 7);

}
void Menu() {
	cout << "Press 1 to Start Game :" << endl;
	cout << "Press 2 to Quit Game :" << endl;
	cout << endl;
	cout << "Enter your option :" << endl;
}

void eraseRabbit(int x, int y)
{
	gotoxy(x, y);
	for (int i = 0;i < 3;i++) {
		cout << " ";
	}
	cout << endl;
	gotoxy(x, y + 1);
	for (int i = 0;i < 3;i++) {
		cout << " ";
	}
	cout << endl;
	gotoxy(x, y + 2);
	for (int i = 0;i < 3;i++) {
		cout << " ";
	}
}
void eraseBee(int x, int y)
{
	gotoxy(x, y);
	for (int i = 0;i < 3;i++) {
		cout << " ";
	}
	cout << endl;
}
void moveKillerBee()
{
	if (Killerbee_direction == "up") {
		char next = getCharAtxy(bx, by - 1);
		if (next == ' ') {
			eraseBee(bx, by);
			by = by - 1;
			printBee(bx, by);
		}
		if (next == '#') {
			Killerbee_direction = "down";
		}
	}
	if (Killerbee_direction == "down") {
		char next = getCharAtxy(bx, by + 1);
		if (next == ' ') {
			eraseBee(bx, by);
			by = by + 1;
			printBee(bx, by);
		}
		if (next == '#') {
			Killerbee_direction = "up";
		}
	}
}
void moveBumblebee()
{
	if (Bumblebee_direction == "left") {
		char next = getCharAtxy(b1x - 2, b1y);
		if (next == ' ') {
			eraseBee(b1x, b1y);
			b1x = b1x - 2;
			printBee(b1x, b1y);
		}
		else if (next != ' ') {
			Bumblebee_direction = "right";

		}
	}
	if (Bumblebee_direction == "right") {
		char next = getCharAtxy(b1x + 3, b1y);
		if (next == ' ') {
			eraseBee(b1x, b1y);
			b1x = b1x + 1;
			printBee(b1x, b1y);
		}
		else if (next == '|') {
			Bumblebee_direction = "left";

		}
	}
}
void moveMiningBee()
{
	if (Miningbee_direction == "right") {
		char next = getCharAtxy(b2x + 3, b2y);
		if (next == ' ') {
			eraseBee(b2x, b2y);
			b2x = b2x + 1;
			printBee(b2x, b2y);
		}
		if (next == '|') {
			Miningbee_direction = "left";
		}
	}
	if (Miningbee_direction == "left") {
		char next = getCharAtxy(b2x - 1, b2y);
		if (next == ' ') {
			eraseBee(b2x, b2y);
			b2x = b2x - 1;
			printBee(b2x, b2y);
		}
		if (next == '|') {
			Miningbee_direction = "right";
		}
	}
}
void moveRabbitLeft()
{
	char nextlocation;
	nextlocation = getCharAtxy(rx - 1, ry);
	if (nextlocation == ' ') {
		eraseRabbit(rx, ry);
		rx = rx - 1;
		printRabbit(rx, ry);
	}
	if (nextlocation == '|' || nextlocation == '#') {
		eraseRabbit(rx, ry);
		rx = rx + 1;
		printRabbit(rx, ry);
	}
}
void moveRabbitRight()
{
	char nextlocation;
	nextlocation = getCharAtxy(rx + 4, ry);
	if (nextlocation == ' ') {
		eraseRabbit(rx, ry);
		rx = rx + 1;
		printRabbit(rx, ry);
	}
}
void moveRabbitUp()
{
	char nextlocation;
	nextlocation = getCharAtxy(rx, ry - 1);
	if (nextlocation == ' ') {
		eraseRabbit(rx, ry);
		ry = ry - 1;
		printRabbit(rx, ry);
	}
}
void moveRabbitDown()
{
	char nextlocation;
	nextlocation = getCharAtxy(rx, ry + 4);
	if (nextlocation == ' ') {
		eraseRabbit(rx, ry);
		ry = ry + 1;
		printRabbit(rx, ry);
	}
}
void printScore()
{
	gotoxy(109, 8);
	cout << "Score :" << score;
}
void increaseScore()
{
	score++;
}
void printBullet(int x, int y)
{
	gotoxy(x, y);
	SetConsoleTextAttribute(hConsole, 5);
	cout << "-" << endl;
	SetConsoleTextAttribute(hConsole, 7);
}
void eraseBullet(int x, int y) {
	gotoxy(x, y);
	cout << " ";
}
void moveBullet()
{
	char next = '\0';
	for (int i = 0;i < bulletCount;i++) {
		char next = getCharAtxy(bulletX[i] + 1, bulletY[i] + 1);
		if (next != ' ') {
			eraseBullet(bulletX[i], bulletY[i]);
			removeBullet(i);
		}
		else {
			eraseBullet(bulletX[i], bulletY[i]);
			bulletX[i] = bulletX[i] + 1;
			printBullet(bulletX[i], bulletY[i]);
		}
	}
}
void removeBullet(int x)
{
	for (int i = 0;i < bulletCount - 1; i++) {
		bulletX[i] = bulletX[i + 1];
		bulletY[i] = bulletY[i + 1];
	}
	bulletCount--;
}
void generateBullet() {
	bulletX[bulletCount] = rx + 4;
	bulletY[bulletCount] = ry;
	gotoxy(rx + 4, ry);
	cout << "-";
	bulletCount++;
}
void bulletCollision()
{
	char next = '\0';
	for (int i = 0; i < bulletCount; i++)
	{
		if (bulletX[i] + 1 == bx
			&& (bulletY[i] == by || bulletY[i] == by + 1 || bulletY[i] == by + 2 || bulletY[i] == by + 3))
		{
			increaseScore();
			printScore();
			eraseBullet(bulletX[i], bulletY[i]);
			removeBullet(i);
		}
		if (next == '|') {
			
			eraseBullet(bulletX[i], bulletY[i]);
		}
		if (next == '.' || next=='*') {
			gotoxy(bulletX[i] + 1, bulletY[i]);
		}
	}
}
void printKillerBeebullet(int x, int y)
{
	gotoxy(x, y);
	SetConsoleTextAttribute(hConsole, 6);
	cout << "*";
	SetConsoleTextAttribute(hConsole, 7);
}
void eraseKillerBeebullet(int x, int y)
{
	gotoxy(x, y);
	cout << " ";
}
void removeKillerBeebullet(int x)
{
	for (int i = x;i < KillerBeecount - 1;i++)
	{
		KillerBeebulletx[i] = KillerBeebulletx[i + 1];
		KillerBeebullety[i] = KillerBeebullety[i + 1];
	}
	KillerBeecount--;
}
void moveKillerBeebullet()
{
	for (int i = 0;i < KillerBeecount;i++)
	{
		char next = getCharAtxy(KillerBeebulletx[i], KillerBeebullety[i] + 1);
		if (next != ' ')
		{
			eraseKillerBeebullet(KillerBeebulletx[i], KillerBeebullety[i]);
			removeKillerBeebullet(i);

		}
		else
		{
			eraseKillerBeebullet(KillerBeebulletx[i], KillerBeebullety[i]);
			KillerBeebullety[i] = KillerBeebullety[i] + 1;
			printKillerBeebullet(KillerBeebulletx[i], KillerBeebullety[i]);
		}
	}
}
void generateKillerBeebullet()
{
	char next = getCharAtxy(b1x, b1y + 2);
	if (next == ' ')
	{
		KillerBeebulletx[KillerBeecount] = b1x;
		KillerBeebullety[KillerBeecount] = b1y + 2;
		KillerBeecount++;
	}
}
void killerBeebulletcollision()
{
	for (int i = 0;i < KillerBeecount;i++)
	{
		if (KillerBeebullety[i] == ry && (KillerBeebulletx[i] == rx || KillerBeebulletx[i] == rx + 1 || KillerBeebulletx[i] == rx + 2 || KillerBeebulletx[i] == rx + 3 || KillerBeebulletx[i] == rx + 4))
		{
			health--;
			eraseKillerBeebullet(KillerBeebulletx[i], KillerBeebullety[i]);
			removeKillerBeebullet(i);
		}
	}
}
void printBumblebeebullet(int x, int y) {
	gotoxy(x, y);
	SetConsoleTextAttribute(hConsole, 8);
	cout << ".";
	SetConsoleTextAttribute(hConsole, 7);
}

void eraseBumblebeebullet(int x, int y) {
	gotoxy(x, y);
	cout << " ";
}
void moveBumblebeebullet()
{
	for (int i = 0;i < Bumblebeecount;i++)
	{
		char next = getCharAtxy(Bumblebeebulletx[i] - 1, Bumblebeebullety[i]);

		if (next != ' ')
		{
			eraseBumblebeebullet(Bumblebeebulletx[i], Bumblebeebullety[i]);
			removeBumblebeebullet(i);

		}
		else
		{
			eraseBumblebeebullet(Bumblebeebulletx[i], Bumblebeebullety[i]);
			Bumblebeebulletx[i] = Bumblebeebulletx[i] - 1;
			printBumblebeebullet(Bumblebeebulletx[i], Bumblebeebullety[i]);
		}

	}
}
void generateBumblebeebullet()
{
	char next = getCharAtxy(bx - 2, by + 1);
	if (next == ' ')
	{
		Bumblebeebullety[Bumblebeecount] = by + 1;
		Bumblebeebulletx[Bumblebeecount] = bx - 1;
		gotoxy(bx - 1, by + 1);
		cout << ".";
		Bumblebeecount++;
	}
}
void removeBumblebeebullet(int x) {
	for (int i = x;i < Bumblebeecount - 1;i++)
	{
		Bumblebeebulletx[i] = Bumblebeebulletx[i + 1];
		Bumblebeebullety[i] = Bumblebeebullety[i + 1];
	}
	Bumblebeecount--;
}
void bumblebeebulletcollision()
{
	for (int i = 0;i < Bumblebeecount;i++)
	{
		if (Bumblebeebulletx[i] - 1 == rx + 5 && (Bumblebeebullety[i] == ry || Bumblebeebullety[i] == ry + 1))
		{
			minusHealth();
			eraseBumblebeebullet(Bumblebeebulletx[i], Bumblebeebullety[i]);
			removeBumblebeebullet(i);
		}
	}
}
void minusHealth() {
	health--;
}
void printHealth() {
	gotoxy(109, 10);
	cout << "HEALTH:" << health << "  ";
}
void end()
{
	cout << "********************************************************" << endl;
	cout << "                    GAME OVER(YOU QUIT)                  " << endl;
	cout << "********************************************************" << endl;
}