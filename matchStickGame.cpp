// Joshua C. Peckham and Mandan 
// 2/17/2016
// CS1
// vq6934
// Question number 6

#include<iostream>
#include<string>
using namespace std;

int main() {
	// Intro to the game
	cout << "Welcome! To the match stick challenge! \nRules: \nMust choose between 1 and 4" << endl;
	cout << "The person who chooses the last matchstick looses. \nAt the start there will be 21 Matchsticks in the box" << endl;
	//Variable to choose to play
	char doyou;
	cout << "Would you like to play: Y/N" << endl;
	cin >> doyou;

	// Initialize variables for game 
	int box = 21;
	int sticks = 0;
	int player;
	system("CLS"); // clear intro
	if (doyou == 'Y' || doyou == 'y')
	{ // Player goes first
		cout << "You will go first." << endl;

		//Game loop
		for (; box >= 1;) 
		{
			if (box == 1) { // ends game once there is only one stick left
				break;
			}
			else { 
				cout << "Choose a number that is between 1 and 4: " << endl;
				cin >> player; //Player chooses 
				system("CLS"); // Clears screen
				if (player <= 4 && player > 0) { //correct choice, completes basic math
					box -= player; // subtracts from the total number of sticks
					cout << "Sticks remaining are: " << box << endl; 
					// Computers Turn
					int sticks = 5 - player;
					box -= sticks;
					cout << "The computer chose: " << sticks << "\nThe Remaining stick in the box are: \n" << box << endl;
				}
				else {
					cout << "Invalid choice please press a key and try again" << endl;
				}
			}
		}
	}
	else if (doyou == 'N' || doyou == 'n') {
		cout << "Thank you for your time, have a good day!" << endl;
	}

	else {
		cout << "The Computer wins, please try again if you dare...Q(-.Q)" << endl; 
	}

	return 0;
}