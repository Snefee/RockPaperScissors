#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {

	srand(time(0));

	string shape;	//Shape picked by a player [rock / paper / scissors]
	int shapeNumeral; //For transforming input shape by a player into a numeral
	int randomNumber = rand() % 3;	//Random number generated (0-3) so the 'enemy' chooses a random shape	[0 = rock, 1 = paper, 2 = scissors]
	string enemyShape;	//Text representation of a picked shape by a computer
	int outcome;	//Outcome of picked shapes by players	[0 = draw, 1 = computer win, 2 = player win]

	cout << "Choose rock, paper or scissors" << endl;
	cin >> shape;

	//Check if there is correct input


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
	else {
		cout << "Invalid input, try again." << endl;
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

	
	if (outcome == 0) {
		cout << "We have a draw!" << endl;
	}
	else if (outcome == 1) {
		cout << "Your enemy won!" << endl;
	}
	else if (outcome == 2) {
		cout << "You won!" << endl;
	}
	system("pause");
}