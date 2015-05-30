#include <iostream>
#include <ctime>
#include <iomanip>
#include <limits>

using namespace std;


/**************************************************************
TEST CASES

1.  input: A		output: INVALID INPUT 
							Menu
    input: 1		output: *** DROP SINGLE CHIP ***
		 					Into which slot will you drop a chip? (Enter a number between 0 and 8)
    input: 4		output: PATH: [4.0 3.5 4.0 3.5 3.0 3.5 3.0 3.5 4.0 4.5 5.0 4.5 4.0]
							WINNINGS: 10000.00 
							Menu
	input: 4		EXIT



2.  input: 2		output: *** DROP MULTIPLE CHIPS ***
							How many chips do you want to drop?
	input: -10		output: INVALID INPUT
							Menu
	input: 2		output: *** DROP MULTIPLE CHIPS ***
							How many chips do you want to drop?
	input: 10000	output: Into which slot will you drop a chip? (Enter a number between 0 and 8)
	input: -10		output: INVALID INPUT
							Menu
	input: 2		output: *** DROP MULTIPLE CHIPS ***
							How many chips do you want to drop?
	input: 10000	output: Into which slot will you drop a chip? (Enter a number between 0 and 8)
	input: 4		output: TOTAL WINNINGS: $25748800.00
							AVERAGE WINNINGS: $2574.88
							Menu
	input: 4		EXIT



3.  input: 3		output: *** DROP MULTIPLE CHIPS INTO EACH SLOT ***
							How many chips do you want to drop?
	input: 10000	output: RESULTS FOR SLOT 0
							TOTAL WINNINGS: $8034700.00
							AVERAGE WINNINGS: $803.47

							RESULTS FOR SLOT 1
							TOTAL WINNINGS: $9981500.00
							AVERAGE WINNINGS: $998.15

							RESULTS FOR SLOT 2
							TOTAL WINNINGS: $15937700.00
							AVERAGE WINNINGS: $1593.77

							RESULTS FOR SLOT 3
							TOTAL WINNINGS: $22421900.00
							AVERAGE WINNINGS: $2242.19

							RESULTS FOR SLOT 4
							TOTAL WINNINGS: $25285000.00
							AVERAGE WINNINGS: $2528.50

							RESULTS FOR SLOT 5
							TOTAL WINNINGS: $23460400.00
							AVERAGE WINNINGS: $2346.04

							RESULTS FOR SLOT 6
							TOTAL WINNINGS: $16209500.00
							AVERAGE WINNINGS: $1620.95

							RESULTS FOR SLOT 7
							TOTAL WINNINGS: $10230200.00
							AVERAGE WINNINGS: $1023.02

							RESULTS FOR SLOT 8
							TOTAL WINNINGS: $7757100.00
							AVERAGE WINNINGS: $775.71

							Menu
	input: 4				EXIT

**************************************************************/




//////////////////////
// GLOBAL CONSTANTS //
//////////////////////
const int PRIZE_0 = 100;
const int PRIZE_1 = 500;
const int PRIZE_2 = 1000;
const int PRIZE_3 = 0;
const int PRIZE_4 = 10000;
const int PRIZE_5 = 0;
const int PRIZE_6 = 1000;
const int PRIZE_7 = 500;
const int PRIZE_8 = 100;

const int NUM_CHIP_BOUNCES = 12; // The number of time the chip "bounces" through the board
const int NUM_SLOTS = 9;
const int MAX_CHIPS = 999999999;



/******************************************************************************************
GET_VALID_INT(min, max)

DESCRIPTION
	Gets a valid integer from the user within bounds of a min and max. 

PARAMS
	@params MIN: The minimum acceptable input
	@params MAX: The maximum acceptable input

RETURNS
	User-inputted integer or -1 if user-input is invalid.

******************************************************************************************/
int get_valid_int(int min, int max)
{
	int choice;

	cin >> choice;

	if (cin.fail() || choice < min || choice > max)
	{
		cout << endl << "INVALID INPUT." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		choice = -1;
	}

	return choice;
}



/******************************************************************************************
GET_WINNINGS(slot)

DESCRIPTION
	Determines prize money won from final slot of a chip in plinko.

PARAMS
	@params SLOT: The slot in which the plinko chip fell.

RETURNS
	Integer representing amount of prize money won.

******************************************************************************************/
int get_winnings(int slot)
{
	int winnings;
	switch (slot)
	{
	case 0: winnings = PRIZE_0; break;
	case 1: winnings = PRIZE_1; break;
	case 2: winnings = PRIZE_2; break;
	case 3: winnings = PRIZE_3; break;
	case 4: winnings = PRIZE_4; break;
	case 5: winnings = PRIZE_5; break;
	case 6: winnings = PRIZE_6; break;
	case 7: winnings = PRIZE_7; break;
	case 8: winnings = PRIZE_8; break;
	}
	return winnings;
}



/******************************************************************************************
ADVANCE_CHIP(slot)

DESCRIPTION
	Advances the plinko chip. Randomly chooses if it will go right or left as it falls 
	through the board. Also keeps chips from "falling off" the board.

PARAMS
	@params SLOT  : The chip's current slot.
	@params PRINT : Whether or not to print the chip's location 

RETURNS
	Double representing the new current position of the chip.

******************************************************************************************/
double advance_chip(double slot, bool print) {
	if (print) { std::cout << "PATH: [" << slot << " "; }
	
	for (int i = 0; i < NUM_CHIP_BOUNCES; i++)
	{
		if (slot == 0) {
			slot += 0.5;
		}
		else if (slot == 8) {
			slot -= 0.5;
		}
		else {
			int random = rand() % (100 + 0);
			if (random < 50) {
				slot -= 0.5;
			}
			else {
				slot += 0.5;
			}
		}

		// Print if the print param is passed as true
		if (print)
		{
			if (i != (NUM_CHIP_BOUNCES - 1)) { // Put a space after the number as long as it isn't the last number to be printed before the ]
				std::cout << slot << " ";
			}
			else {
				std::cout << slot;
			}
		}
	}

	if (print) { std::cout << "]" << endl; }
	
	return slot;
}



/******************************************************************************************
DROP_SINGLE_CHIP(slot)

DESCRIPTION
	Drops 1 chip into 1 slot. Outputs the path of the chip as it falls through the board.

PARAMS
	@params SLOT: The initial slot the user wishes to drop a chip into.

RETURNS
	Integer representing the final slot the chip fell into.

******************************************************************************************/
int drop_single_chip(double slot) {
	cout << fixed << setprecision(1);
	advance_chip(slot, true);
	return slot;
}



/******************************************************************************************
DROP_MULTIPLE_CHIPS(slot, num_chips)

DESCRIPTION
	Drops multiple chips into one slot. Outputs total and average winnings from all chips.

PARAMS
	@params SLOT      : The initial slot the user wishes to drop a chip into.
	@params NUM_CHIPS : The number of chips a user wishes to drop

RETURNS
	Void. Prints Total and Average winnings.

******************************************************************************************/
void drop_multiple_chips(int slot, int num_chips)
{
	double total_winnings = 0;
	for (int i = 0; i < num_chips; i++)
	{
		int result = advance_chip(slot, false);
		total_winnings += get_winnings(result);
	}

	cout << fixed << setprecision(2);
	cout << endl << "TOTAL WINNINGS: $" << total_winnings << endl;
	double avg_winnings = total_winnings / num_chips;
	cout << "AVERAGE WINNINGS: $" << avg_winnings << endl;
}

int main() {
	int choice;

	do {
		int final_slot = 0;
		double winnings = 0;
		double slot = 0;
		int num_chips = 0;

		cout << endl << "MENU: Please select one of the following options:" << endl;
		cout << "  1 - Drop a single chip into one slot" << endl;
		cout << "  2 - Drop multiple chips into one slot" << endl;
		cout << "  3 - Drop multiple chips into each slot" << endl;
		cout << "  4 - Quit the program" << endl;
		cout << "Enter your selection now: ";

		choice = get_valid_int(1, 4);

		switch (choice)
		{
		case -1: break; // This means there was an invalid menu input. Loops back to the menu.

		////////////////////////
		// DROP A SINGLE CHIP //
		////////////////////////
		case 1:
			cout << endl << "*** DROP SINGLE CHIP ***" << endl;
			cout << "Into which slot will you drop a chip? (Enter a number between 0 and 8)" << endl;
			slot = get_valid_int(0, 8);
			if (slot == -1) { break; }
			final_slot = drop_single_chip(slot);
			winnings = get_winnings(final_slot);
			cout << "WINNINGS: $" << setprecision(2) << winnings << endl;
			break;

		/////////////////////////
		// DROP MULTIPLE CHIPS //
		/////////////////////////
		case 2:
			cout << endl << "*** DROP MULTIPLE CHIPS ***" << endl;
			cout << "How many chips do you want to drop?" << endl;
			num_chips = get_valid_int(1, MAX_CHIPS);
			if (num_chips == -1) { break; }
			cout << "Into which slot will you drop a chip? (Enter a number between 0 and 8)" << endl;
			slot = get_valid_int(0, 8);
			if (slot == -1) { break; }
			drop_multiple_chips(slot, num_chips);
			break;

		////////////////////////////////////////
		// DROP MULTIPLE CHIPS INTO EACH SLOT //
		////////////////////////////////////////
		case 3:
			cout << endl << "*** DROP MULTIPLE CHIPS INTO EACH SLOT ***" << endl;
			cout << "How many chips do you want to drop?" << endl;
			num_chips = get_valid_int(1, MAX_CHIPS);
			if (num_chips == -1) { break; }
			for (int slot = 0; slot < NUM_SLOTS; slot++)
			{
				cout << endl << "RESULTS FOR SLOT " << slot;
				drop_multiple_chips(slot, num_chips);
			}
			break;
		}
	} while (choice != 4);

	system("pause");

	return 0;
}