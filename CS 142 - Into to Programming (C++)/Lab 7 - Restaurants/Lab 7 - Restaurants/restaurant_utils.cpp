#include <iostream>
#include <string>

#include "restaurant_utils.h"

using namespace std;

/**
	MENU()
  
	DESCRIPTION
	Shows the menu, gets a choice from the user, and returns the user choice

	RETURNS
	Integer representing user's choice from menu.
 */
int menu() {
	cout << endl << "*** MENU ***" << endl
		<< "  1 - Display All Restaurants" << endl
		<< "  2 - Add A Restaurant" << endl
		<< "  3 - Remove a Restaurant" << endl
		<< "  4 - Shuffle the Vector" << endl
		<< "  5 - Begin the Tournament" << endl
		<< "  6 - Quit the Program" << endl
		<< "Please enter your choice: ";

	int choice = get_valid_int(1, 6, "Please enter an integer between 1 and 6: ");

	return choice;
}


/**
	GET_VALID_INT()

	DESCRIPTION
    Gets an integer within bounds passed by the user

	PARAMS
    int lower: Lower bound for valid int
	int upper: Upper bound for valid int
	string message: An error message to be displayed when a bad type is entered.

	RETURNS
    Integer representing user's input.
*/
int get_valid_int(int lower, int upper, string message) {
	int input;
	do {
		cin >> input;

		if (cin.fail() || input < lower || input > upper)
		{
			cout << endl << "INVALID INPUT. " << message;
			cin.clear();
			cin.ignore(999999, '\n');
			input = -1;
		}
	} while (input == -1);

	return input;
}