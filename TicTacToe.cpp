#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;

char board[3][3] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
};
char current_spot = '\0';
int current_player = 0;

void drawBoard();
bool placeValue(int position);
int whoWon();
void swap();
void Interface();

int main()
{
	system("cls");
	cout << "T I C  T A C  T O E " << endl;
	cout << endl;
	cout << endl;
	cout << "PLAYER1[X/O] :" << endl;
	cout << endl;
	cout << "PLAYER 1 will play first :" << endl;
	cout << endl;
	Interface();
}
void drawBoard()
{
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "----------\n";
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "----------\n";
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}
bool placeValue(int position)
{
	position--; // Adjusting position to match array indices (0-8)

	int row = position / 3;
	int col = position % 3;

	if (board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = current_spot;
		return true;
	}
	else
	{
		return false;
	}
}
int whoWon()
{
	for (int i = 0; i < 3; i++)
	{
		// For rows
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			return current_player;
		}
		// For columns
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return current_player;
		}
	}
	// For left diagonal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return current_player;
	}
	// For right diagonal
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return current_player;
	}

	return 0;
}
void swap()
{
	if (current_spot == 'X')
	{
		current_spot = 'O';
	}
	else
	{
		current_spot = 'X';
	}
	if (current_player == 1)
	{
		current_player = 2;
	}
	else
	{
		current_player = 1;
	}
}
void Interface()
{
	char marker_p1;
	cout << "PLAYER 1:Choose your character :" << endl;
	cin >> marker_p1;
	current_player = 1;
	current_spot = marker_p1;
	drawBoard();
	int player_won = 0;
	for (int i = 0; i < 9; i++)
	{
		cout << "It's PLAYER" << current_player << "'s turn,Enter your slot :" << endl;
		int pos;
		cin >> pos;
		if (!placeValue(pos))
		{
			cout << "This slot is filled!Try another slot !" << endl;
			i--;
			continue;
		}
		drawBoard();
		if (pos < 1 || pos > 9)
		{
			cout << "Invalid slot!!!Try another slot!!!!" << endl;
			i--;
			continue;
		}
		player_won = whoWon();
		if (player_won == 1)
		{
			cout << "PLAYER 1 wins:Congrats!!!!" << endl;
			break;
		}
		if (player_won == 2)
		{
			cout << "PLAYER 2 wins:Congrats!!!!" << endl;
			break;
		}
		swap();
	}
	if (player_won == 0)
	{
		cout << "That is a tied game!Well Played!!!!" << endl;
	}
}