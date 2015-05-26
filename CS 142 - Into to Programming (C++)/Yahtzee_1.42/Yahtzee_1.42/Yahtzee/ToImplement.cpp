/* *****************************************************************************

CS 142 - Winter 2015
Midterm 1 - Yahtzee

Student Name (First and Last): Andy Mockler
Student NetID: mocklera
Section and Instructor: Section 002 - Farrell
Development Platform (e.g. Visual Studio Express 2013" or "XCode"): Visual Studio 2013

***************************************************************************** */



#include <iostream>
#include <string>
#include <cctype>

#include "YahtC++.h"

using namespace std;


// Some constants that you may find useful
const char CHAR_YES = 'Y';
const char CHAR_NO = 'N';
const int  TURNS_PER_GAME = 13;
const int  SIDES_PER_DIE = 6;

// Some constants I am using (Andy Mockler)
const int  NUMBER_DICE_ROLLED = 5;
const int  NUM_SM_STRAIGHT_COMBINATIONS = SIDES_PER_DIE - 3;
const int  POINTS_FOR_SIXES = 6;





/* *****************************************************************************
GETYN()

DESCRIPTION - This function prompts the user for input in the form of either a
              'Y' or an 'N'.  Your program should accept either upper- or
			  lower-case Y and N.  Any other character that's given as input is
			  invalid and your program should continue to prompt the user until
			  a valid input character (a Y or an N) is received.

PARAMETERS/INPUTS:
    @PROMPT - This string parameter is used as the display prompt for the user.
	          For example, if prompt has the value "Do you want to quit?", then
			  the program will display "Do you want to quit? [Y/N]: " and wait
			  for user input.

RETURNS - Either an upper-case 'Y' or an 'N'

***************************************************************************** */

char getYN(string prompt)
{
	char input;

	do {
		// prompt and get input
		cout << prompt << " [" << CHAR_YES << "/" << CHAR_NO << "]: ";
		cin >> input;
		input = toupper(input); // Make input uppercase
	} while (input != CHAR_NO && input != CHAR_YES); // Continue prompting until user input is matches CHAR_YES or CHAR_NO

	return input;
}







/* *****************************************************************************
GETCHARINRANGE()

DESCRIPTION - This function prompts the user for input in the form of a single
              character in a specified range.  Your program should accept either
			  upper- or lower-case characers, but always return upper case.  If
			  the character that's given by the user is in the specified range
			  (you may assume that the input characters are upper-case), then
			  then it should return it (return the upper-case version if a
			  lowe-case character was entered).  If the input is not in the
			  valid range, then your program should continue to prompt the user
			  until a valid input character (in the correct range) is received.

PARAMETERS/INPUTS:
    @MIN -    An upper-case character that begins the valid range.
	@MAX -    An upper-case character that ends the valid range.

RETURNS -     An upper-case character in the specified range.


***************************************************************************** */

char getCharInRange(char min, char max)
{
	// Get user input
	char letter;
	cin >> letter;
	letter = toupper(letter); // capitalize input

	// Keep getting input until something valid is entered
	while ( letter < min || letter > max )
	{
		cout << "INVALID  Please input a character between " << min << " and " << max << ":";
		cin >> letter;
		letter = toupper(letter);
	}

	return letter;
}







/* *****************************************************************************
ISVALIDOPTION_YAHTZEE()

DESCRIPTION - This function determines whether the values on the five dice
              passed in as parameters constitute a YAHTZEE (all five dice have
			  an identical value).  For example, the values 2 2 2 2 2 represent
			  a YAHTZEE.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS - Either TRUE (if the values are all identical) or FALSE (otherwise).

***************************************************************************** */

bool isValidOption_YAHTZEE(int die1, int die2, int die3, int die4, int die5)
{
	bool is_yahtzee = false;

	// Make is_yahtzee true if all the dice are the same number (all equal to die1)
	if ( die1 == die2 && die1 == die3 && die1 == die4 && die1 == die5 ) is_yahtzee = true;

	// This will remain false if not changed to true above
	return is_yahtzee;
}





/* *****************************************************************************
ISVALIDOPTION_SMSTRAIGHT()

DESCRIPTION - This function determines whether there is a small straight.  For
              example if the dice values were 2 5 4 3 4, there is a small
			  straight 2-3-4-5 present.  Any sequence of four consecutive
			  values (each in the range 1-6) is a small straight.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     Either TRUE (if a small straight is present in the dice) or
              FALSE (otherwise).

***************************************************************************** */

bool isValidOption_SmStraight(int die1, int die2, int die3, int die4, int die5)
{
	bool is_small_straight = false;
	int values[NUMBER_DICE_ROLLED] = { die1, die2, die3, die4, die5 };
	int roll[SIDES_PER_DIE]; // stores counters for each number
	for (int i = 0; i < SIDES_PER_DIE; i++) roll[i] = 0; // Set count to 0

	// Count how many times each number occurs and store in the roll array
	for (int i = 0; i < NUMBER_DICE_ROLLED; i++)
	{
		// gets the value shown on the die
		int value = values[i];
		// increments counter for whichever number was rolled. -1 because arrays.
		roll[value - 1]++;
	}

	// Assuming 6-side dice, checks the 3 possible small straight combinations (1-4, 2-5, 3-6)
	for (int i = 0; i < NUM_SM_STRAIGHT_COMBINATIONS; i++)
	{
		// Checks for 4 consecutive numbers
		if (roll[i] > 0 && roll[i+1] > 0 && roll[i+2] > 0 && roll[i+3] > 0) is_small_straight = true;
	}

	return is_small_straight;
}







/* *****************************************************************************
ISVALIDOPTION_3OFAKIND()

DESCRIPTION - This function determines whether there are 3 (or more) dice that
              have the same value.  For example if the dice values were
			  2 5 5 1 5, there is a 3-of-a-kind, the fives.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     Either TRUE (if 3 or more dice have the same value) or
              FALSE (otherwise).

***************************************************************************** */

bool isValidOption_3OfAKind(int die1, int die2, int die3, int die4, int die5)
{
	bool is_3_of_kind = false;
	int values[NUMBER_DICE_ROLLED] = { die1, die2, die3, die4, die5 };
	int roll[SIDES_PER_DIE]; // stores counters for each number
	for (int i = 0; i < SIDES_PER_DIE; i++) roll[i] = 0; // Set count to 0

	// Count how many times each number occurs and store in the roll array
	for (int i = 0; i < NUMBER_DICE_ROLLED; i++)
	{
		// gets the value shown on the die
		int value = values[i];
		// increments counter for whichever number was rolled. -1 because arrays.
		roll[value - 1]++;
	}

	// Check if any of the dice sides appears 3 or more times
	for (int i = 0; i < SIDES_PER_DIE; i++)
	{
		if (roll[i] > 2) is_3_of_kind = true;
	}

	return is_3_of_kind;
}



/* *****************************************************************************
POINTSFOR_SIXES()

DESCRIPTION - This function computes the number of points for sixes.  If two
              dice show sixes, then this would return 12, if four dice show
			  sixes, then this function would return 24, and so forth.

PARAMETERS/INPUTS:
    @DIE1 -   This int parameter indicates the current value of the first die.
	          The range for this value is from 1 up to SIDES_PER_DIE.
    @DIE2 -   This int parameter has the value of the second die.  Same range.
	@DIE3 -   This int parameter has the value of the third die.  Same range.
	@DIE4 -   This int parameter has the value of the fourth die.  Same range.
	@DIE5 -   This int parameter has the value of the fifth die.  Same range.

RETURNS -     The total of all dice showing a six (an int).

***************************************************************************** */

int pointsFor_Sixes(int die1, int die2, int die3, int die4, int die5)
{
	int points = 0;
	int values[NUMBER_DICE_ROLLED] = { die1, die2, die3, die4, die5 };
	int roll[SIDES_PER_DIE]; // stores counters for each number
	for (int i = 0; i < SIDES_PER_DIE; i++) roll[i] = 0; // Set count to 0

	// Count how many times each number occurs and store in the roll array
	for (int i = 0; i < NUMBER_DICE_ROLLED; i++)
	{
		// gets the value shown on the die
		int value = values[i];
		// increments counter for whichever number was rolled. -1 because arrays.
		roll[value - 1]++;
	}

	int number_of_sixes = roll[5];
	points = POINTS_FOR_SIXES * number_of_sixes; // Calculate score = 6 * (number of 6's) 

	return points;
}




