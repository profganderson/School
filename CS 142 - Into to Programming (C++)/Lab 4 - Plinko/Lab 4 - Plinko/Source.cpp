#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

/*
TEST CASES
	MENU: 
		input -1; output: INVALID
		input 1; output: *** DROP SINGLE CHIP ***
		input 2; output: *** DROP MULTIPLE CHIPS ***
		input 3; output: GOODBYE
	SINGLE:
		input: slot 4; output: PATH: [4.0 4.5 5.0 4.5 4.0 3.5 4.0 3.5 4.0 3.5 4.0 4.5 5.0] WINNINGS: $0.00
		input: slot 0; output: PATH: [0.0 0.5 1.0 0.5 1.0 0.5 1.0 1.5 2.0 1.5 1.0 1.5 2.0] WINNINGS: $1000.00
	MULTIPLE:
		input: 100 chips, slot 6; output: TOTAL WINNINGS: $43000.00 AVERAGE WINNINGS: $430.00
		input: 4 chips, slot 8; output: TOTAL WINNINGS: $2000.00 AVERAGE WINNINGS: $500
*/

int get_choice_from_menu() {
	// Get user choice
	cout << endl << "MENU: Please select one of the following options:\n  1 - Drop a single chip into one slot\n  2 - Drop multiple chips in one slot\n  3 - Quit the program\nEnter your selection now: ";
	int choice;
	cin >> choice;

	// Make sure the choice is valid
	while (choice < 1 || choice > 3)
	{
		cout << endl << "INVALID SELECTION. Please enter 1, 2, or 3" << endl;
		cout << endl << "MENU: Please select one of the following options:\n  1 - Drop a single chip into one slot\n  2 - Drop multiple chips in one slot\n  3 - Quit the program\nEnter your selection now: ";
		cin.clear();
		cin >> choice;
	}

	return choice;
}

double advance_chip(double slot) {
	// First two conditions keep chip from "falling off board"
	// Last condition generates a random number and determines if chip moves "left or right"
	if (slot == 0) {
		slot += .5;
	}
	else if (slot == 8) {
		slot -= .5;
	}
	else {
		int random = rand() % (100 + 0);
		if (random < 50) {
			slot -= .5;
		}
		else {
			slot += .5;
		}
	}

	return slot;
}

int main()
{
	double PRIZES[9] = {100, 500, 1000, 0, 10000, 0, 1000, 500, 100};
	cout << fixed << setprecision(1);
	srand(time(0)); // seed random num
	
	// Call menu for first time
	int choice = get_choice_from_menu();

	while (choice != 3){
		// Process user choice
		switch (choice)
		{
		case 1:
			cout << endl << "*** DROP SINGLE CHIP ***" << endl;

			cout << "Into which slot will you drop a chip? (Enter a number between 0 and 8)" << endl;
			double slot;
			cin >> slot;
			if (slot < 0 || slot > 8){
				cin.clear();
				cout << endl << "INVALID SLOT. Please enter an integer between 0 and 8" << endl;
				choice = get_choice_from_menu();
				break;
			}

			// Report Chip location
			cout << fixed << setprecision(1);
			cout << "PATH: [" << slot << " ";
			for (int i = 0; i < 12; i++)
			{
				// advance_chip is a function with chip-dropping logic
				slot = advance_chip(slot);
				if (i != 11){
					cout <<	slot << " ";
				}
				else {
					cout << slot;
				}
			}
			cout << "]" << endl;

			// Report money won
			cout << "WINNINGS: $" << setprecision(2) << PRIZES[(int)slot] << endl;

			choice = get_choice_from_menu();
			break;
		case 2:
			cout << endl << "*** DROP MULTIPLE CHIPS ***" << endl;
			cout << "How many chips do you want to drop?" << endl;
			int num_chips;
			cin >> num_chips;
			if (num_chips <= 0) {
				cout << endl << "INVALID NUMBER OF CHIPS. Please enter and integer greater than zero." << endl;
				choice = get_choice_from_menu();
				break;
			}

			cout << "Into which slot will you drop a chip? (Enter a number between 0 and 8)" << endl;
			cin >> slot;
			if (slot < 0 || slot > 8){
				cin.clear();
				cout << endl << "INVALID" << endl;
				choice = get_choice_from_menu();
				break;
			}

			double total_winnings = 0;
			for (int i = 0; i < num_chips; i++)
			{
				double result = slot;
				// play plinko
				for (int i = 0; i < 12; i++)
				{
					result = advance_chip(result);
				}

				// add up winnings
				total_winnings += PRIZES[(int)result];
			}

			double avg_winnings = total_winnings / num_chips;
			cout << fixed << setprecision(2);
			cout << endl << "TOTAL WINNINGS: $" << total_winnings << endl;
			cout << "AVERAGE WINNINGS: $" << avg_winnings << endl;

			choice = get_choice_from_menu();
			break;
		}
	}

	cout << "\nGOODBYE" << endl;

	system("pause");
	return 0;
}