#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
#include<math.h>
#include<array>

using namespace std;
const short int ROW = 3;
const short int COLUMN = 3;
//const short int X = 1;
//const short int O = -1;
const char Player1 = 'X'; 
const char Player2 = 'O';
short int turn = 0;
char board[ROW][COLUMN] = {};
short int locate1, locate2;


void gameBoard(int row1, int column1, int player);
void coordinateDisplay();
void verificationCheck();


int main() {

	coordinateDisplay(); 
	for (int turn = 0; turn < 9; turn++) {
		if (turn % 2 == 0) {
			cout << "Player 1's turn: \nPlease input the coordinates to place the X value: " << endl;
			cin >> locate1 >> locate2;
			board[locate1][locate2] = Player1;
			gameBoard(locate1, locate2, Player1);

		}
		else {
			cout << "Player 2's turn: \nPlease input the coordinates to place the X value: " << endl;
			cin >> locate1 >> locate2;
			board[locate1][locate2] = Player2;
			gameBoard(locate1, locate2, Player2);
		}
	}

	return 0;
}

void gameBoard(int row1, int column1, int player) {

	for (int i = 0; i < ROW; i++) {
		for (int n = 0; n < COLUMN; n++) {
			board[row1][column1] = player;

			if (n < 2) {
				cout << setw(2) << board[i][n] << " |";
			}
			else
				cout << setw(2) << board[i][n];
		}
			cout << endl;
	}
}

void coordinateDisplay() {
	for (int i = 0; i < 3; i++) {
		for (int n = 0; n < 3; n++) {
			if (n < 2) {
				cout << setw(2) << "(" << i << "," << n << ")" << " |";
			}
			else {
				cout << setw(2) << "(" << i << "," << n << ")";
			}
		}
		cout << endl;
	}
}
