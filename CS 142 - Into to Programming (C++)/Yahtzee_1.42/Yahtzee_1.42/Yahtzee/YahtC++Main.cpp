#include <iostream>
#include <string>

#include "YahtC++.h"

using namespace std;



int not_main()
{
	// Ask for player's name
	cout << "Please enter your name: ";
	string playername = getFullLine();
	cout << endl;

	cout << "Welcome to YahtC++ version 1.42, " << playername << "!" << endl << endl;

	
	// Main Loop
	bool playing = true;
	while (playing)
	{
		int totalScore = 0;

		// Play one game
		cout << "This game will consist of " << TURNS_PER_GAME << " turns." << endl << endl;

		// Loop to take all turns
		for (int turn = 1; turn <= TURNS_PER_GAME; turn++)
		{
			int score = doTurn(turn);

			totalScore += score;
			cout << endl << "TOTAL SCORE AFTER " << turn << " TURN" << (turn==1?"":"S") << " = " << totalScore << "." << endl << endl;

		}


		// Ask if player wants to play again
		char choiceYN = getYN("Play again?");
		if (choiceYN == CHAR_NO)
		{
			playing = false; // so that program exits outermost while loop
		}
	}




	system("pause()");
	return 0;
}

int main()
{
	////////////////////////
	// Test getYN 5 times //
	////////////////////////

	cout << "TESTING getYN" << endl;
	for (int i = 0; i < 5; i++)
	{
		char getYNTest = getYN("Play Again?");
		cout << getYNTest << endl;
	}




	/////////////////////////////////
	// Test getCharInRange 5 times //
	/////////////////////////////////

	cout << "TESTING getCharInRange" << endl;
	for (int i = 0; i < 5; i++)
	{
		char getCharInRangeTest;
		if (i < 3) {
			cout << "Enter a character between A and M: ";
			getCharInRangeTest = getCharInRange('A','M');
		}
		else {
			cout << "Enter a character between G and P: ";
			getCharInRangeTest = getCharInRange('G', 'P');
		}
		cout << getCharInRangeTest << endl;
	}




	////////////////////////////////////////
	// Test isValidOption_YAHTZEE 5 times //
	////////////////////////////////////////

	cout << "TESTING isValidOption_YAHTZEE" << endl;
	for (int i = 0; i < 5; i++)
	{
		int die1, die2, die3, die4, die5;
		cout << "Enter value for die 1: ";
		cin >> die1;
		cout << "Enter value for die 2: ";
		cin >> die2;
		cout << "Enter value for die 3: ";
		cin >> die3;
		cout << "Enter value for die 4: ";
		cin >> die4;
		cout << "Enter value for die 5: ";
		cin >> die5;

		bool is_yahtzee = isValidOption_YAHTZEE(die1, die2, die3, die4, die5);
		cout << is_yahtzee << "\n\n";
	}



	///////////////////////////////////////////
	// Test isValidOption_SmStraight 5 times //
	///////////////////////////////////////////

	cout << "TESTING isValidOption_SmStraight" << endl;
	for (int i = 0; i < 5; i++)
	{
		int die1, die2, die3, die4, die5;
		cout << "Enter value for die 1: ";
		cin >> die1;
		cout << "Enter value for die 2: ";
		cin >> die2;
		cout << "Enter value for die 3: ";
		cin >> die3;
		cout << "Enter value for die 4: ";
		cin >> die4;
		cout << "Enter value for die 5: ";
		cin >> die5;

		bool is_sm_straight = isValidOption_SmStraight(die1, die2, die3, die4, die5);
		cout << is_sm_straight << "\n\n";
	}




	/////////////////////////////////
	// Test isValidOption_3OfAKind //
	/////////////////////////////////

	cout << "TESTING isValidOption_3OfAKind\n\n";
	for (int i = 0; i < 5; i++)
	{
		int die1, die2, die3, die4, die5;
		cout << "Enter value for die 1: ";
		cin >> die1;
		cout << "Enter value for die 2: ";
		cin >> die2;
		cout << "Enter value for die 3: ";
		cin >> die3;
		cout << "Enter value for die 4: ";
		cin >> die4;
		cout << "Enter value for die 5: ";
		cin >> die5;

		bool is_3_of_kind = isValidOption_3OfAKind(die1, die2, die3, die4, die5);
		cout << is_3_of_kind << "\n\n";
	}



	//////////////////////////
	// Test pointsFor_Sixes //
	//////////////////////////

	cout << "TESTING pointsFor_Sixes\n\n";
	for (int i = 0; i < 5; i++) 
	{
		int die1, die2, die3, die4, die5;
		cout << "Enter value for die 1: ";
		cin >> die1;
		cout << "Enter value for die 2: ";
		cin >> die2;
		cout << "Enter value for die 3: ";
		cin >> die3;
		cout << "Enter value for die 4: ";
		cin >> die4;
		cout << "Enter value for die 5: ";
		cin >> die5;

		int points = pointsFor_Sixes(die1, die2, die3, die4, die5);
		cout << points << "\n\n";
	}
	


	cout << "\n\n\n";
	system("pause");

	return 0;
}