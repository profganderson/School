// Lab 7 - Restaurants
// Andy Mockler
// March 13, 2015

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "restaurant_utils.h"
#include "Restaurants.h"

/***************************************
	TEST CASES

	1.  INPUT: 1			OUTPUT: RESTAURANTS:
									Olive Garden, Cafe Rio, McDonalds, 180 Street Tacos, Rancheritos, Guru's, India Palace, Aubergine
									MENU
		INPUT: 8			OUTPUT: INVALID INPUT. Please enter an integer between 1 and 6: 
		INPUT: 10			OUTPUT: INVALID INPUT. Please enter an integer between 1 and 6:
		INPUT: 2			OUTPUT: Enter the restaurant you wish to add:
		INPUT: Outback		OUTPUT: Outback has been added to the list
									MENU
		INPUT: 3			OUTPUT: Enter the restaurant you wish to remove: 
		INPUT: McDonalds	OUTPUT: McDonalds was removed from the list.
									MENU
		INPUT: 3			OUTPUT: Enter the restaurant you wish to remove:
		INPUT: abcde		OUTPUT: Couldn't find that restaurant on the list.
									MENU
		INPUT: 1			OUTPUT: RESTAURANTS:
									Olive Garden, Cafe Rio, 180 Street Tacos, Rancheritos, India Palace, Aubergine, Outback
									MENU
		INPUT: 6			EXIT

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	2.  INPUT: 2			OUTPUT: Enter the restaurant you wish to add:
		INPUT: In-N-Out		OUTPUT: In-N-Out has been added to the list
									MENU
		INPUT: 5			OUTPUT: Wrong number of values in the list. Try adding or subtracting soe restaurants
									MENU
		INPUT: 3			OUTPUT: Enter the restaurant you wish to remove:
		INPUT: McDonalds	OUTPUT: McDonalds was removed from the list.
									MENU
		INPUT: 5			OUTPUT: *** Round 1 of 3 ***
									CONTINUE TOURNAMENT
									In-N-Out is the winner!
									MENU
		INPUT: 6			EXIT

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	3.  INPUT: 1			OUTPUT: RESTAURANTS
									Olive Garden, Cafe Rio, McDonalds, 180 Street Tacos, Rancheritos, India Palace, Guru's, Aubergine
									MENU
		INPUT: 4			OUTPUT: The list of restauarants has been shuffled.
		INPUT: 1			OUTPUT: RESTAURANTS:
									Cafe Rio, Olive Garden, Guru's, Rancheritos, India Palace, 180 Street Tacos, Aubergine, McDonalds
									MENU
		INPUT: 6			EXIT
									

***************************************/

int main()
{
	// Create a Restaurants object. Contains the vector
	// of restaurants and necessary functions.
	Restaurants restaurants = Restaurants();

	// Holds user menu choice
	int menu_choice;

	do {
		// Get a choice from the menu
		menu_choice = menu();

		// 1. Print out the restaurants
		if (menu_choice == 1) restaurants.display();

		// 2. Add a restaurant
		else if (menu_choice == 2) {
			cout << endl << "Enter the restaurant you wish to add: ";
			string input = "";
			cin.sync();
			getline(cin, input);
			restaurants.add(input);
		}

		// 3. Remove a restaurant
		else if (menu_choice == 3) {
			cout << endl << "Enter the restaurant you wish to remove: ";
			string input = "";
			cin.sync();
			getline(cin, input);
			restaurants.remove(input);
		}

		// 4. Shuffle the vector
		else if (menu_choice == 4) {
			restaurants.shuffle();
		}

		// 5. Start the tournament
		else if (menu_choice == 5) {
			restaurants.start_tournament();
		}

	} while (menu_choice != 6); // Exit if 6.
	
	return 0;
}