#include <iostream>
#include <string>

using namespace std;

int get_valid_int(int lower_bound, int upper_bound, string error_message) {
	// Get user input
	int input;
	cin >> input;

	// If they put in a non-integer or an out of bounds int, show the
	// error message and try again
	while (cin.fail() || input < lower_bound || input > upper_bound) {
		cin.clear();
		cin.ignore(999999, '\n');
		cout << error_message;
		cin >> input;
	}

	// Return a valid int
	return input;
}

int menu() {
	// Display menu
	cout << "*** MENU ***" << endl
		<< "  1 - Show Current Inventory" << endl
		<< "  2 - Show Current Balance" << endl
		<< "  3 - Buy a Car" << endl
		<< "  4 - Sell a Car" << endl
		<< "  5 - Paint a Car" << endl
		<< "  6 - Load File" << endl
		<< "  7 - Save File" << endl
		<< "  8 - Quit Program" << endl;
	// Get a menu choice
	int input = get_valid_int(1, 8, "Please enter a number between 1 and 8: ");

	// Return the menu choice
	return input;
}