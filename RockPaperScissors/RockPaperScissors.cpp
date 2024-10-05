#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include "../HEADERS/color.hpp"
using namespace std;

int main() {
	
	//Point system
	int playerPoints = 0;
	int computerPoints = 0;

	do {
	srand(time(0));

	string shape;	//Shape picked by a player [rock / paper / scissors]
	int shapeNumeral = -1; //For transforming input shape by a player into a numeral
	int randomNumber = rand() % 3;	//Random number generated (0-3) so the 'enemy' chooses a random shape	[0 = rock, 1 = paper, 2 = scissors]
	string enemyShape;	//Text representation of a picked shape by a computer
	int outcome = -1;	//Outcome of picked shapes by players	[0 = draw, 1 = computer win, 2 = player win]


	//Check if there is correct input
	while (true) {
		cout << "Choose rock, paper or scissors" << endl;
		cin >> shape;

		if (shape == "rock" || shape == "paper" || shape == "scissors") {
			break;
		}
		else {			
			cout << "Invalid input, try again. Choose rock, paper or scissors." << endl;
			continue;
		}
		cin.clear();
		cin.ignore(10000, '\n');
	}

	//Change input string to numeral so it's easier to check the winner
	if (shape == "rock") {
		shapeNumeral = 0;
	}
	else if (shape == "paper") {
		shapeNumeral = 1;
	}
	else if (shape == "scissors") {
		shapeNumeral = 2;
	}

	//Draw
	if (randomNumber == shapeNumeral) {
		outcome = 0;
	}	
	//Paper beats rock (player win)
	else if (randomNumber == 0 && shapeNumeral == 1) {
		outcome = 2;
	}
	//Rock beats scissors (computer win)
	else if (randomNumber == 0 && shapeNumeral == 2) {
		outcome = 1;
	}	
	//Paper beats rock (computer win)
	else if (randomNumber == 1 && shapeNumeral == 0) {
		outcome = 1;
	}
	//Scissors beats paper (player win)
	else if (randomNumber == 1 && shapeNumeral == 2) {
		outcome = 2;
	}
	//Rock beats scissors (player win)
	else if (randomNumber == 2 && shapeNumeral == 0) {
		outcome = 2;
	}
	//Scissors beats paper (computer win)
	else if (randomNumber == 2 && shapeNumeral == 1) {
		outcome = 1;
	}

	if (randomNumber == 0) {
		enemyShape = "rock";
	}
	else if (randomNumber == 1) {
		enemyShape = "paper";
	}
	else if (randomNumber == 2) {
		enemyShape = "scissors";
	}

	//Determine who won and display a message
	if (outcome == 0) {
		cout << "We have a" << dye::aqua(" draw!") << endl;

		cout << "\nYou won " << playerPoints << " times." << endl;
		cout << "Your enemy won " << computerPoints << " times." << endl;
	}
	else if (outcome == 1) {
		cout << "You" << dye::red(" lost! ") << "Your enemy choose " << enemyShape << "." << endl;

		computerPoints += 1;
		cout << "\nYou won " << playerPoints << " times." << endl;
		cout << "Your enemy won " << computerPoints << " times." << endl;
	}
	else if (outcome == 2) {
		cout << "You" << dye::green(" won!") << endl;

		playerPoints += 1;
		cout << "\nYou won " << playerPoints << " times." << endl;
		cout << "Your enemy won " << computerPoints << " times." << endl;
	}
	
	cout << "\nPress " << dye::yellow("\"r\"") << " to try again... \n" << endl;
	
	system("pause");
	} while (GetKeyState('R') & 0x8000);

	return 0;
}