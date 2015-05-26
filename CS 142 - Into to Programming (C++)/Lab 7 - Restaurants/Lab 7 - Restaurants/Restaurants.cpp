#include <iostream>
#include <string>
#include <vector>

#include "restaurant_utils.h"
#include "Restaurants.h"

using namespace std;



/**
	RESTAURANTS()

	DESCRIPTION
	Constructor method for Restaurants class. Fills restaurants vector with 8 restaurants.
*/
Restaurants::Restaurants()
{
	this->restaurants = { "Olive Garden", "Cafe Rio", "McDonalds", "180 Street Tacos", "Rancheritos", "India Palace", "Guru's", "Aubergine" };
}



/**
	FIND()

	DESCRIPTION
	Searches restaurants vector for a given string value.

	PARAMS
	string query: The string you want to search for

	RETURNS
	Index of the value in the vector. Returns -1 if not found.
*/
int Restaurants::find(string query)
{
	int index = -1;
	int vector_length = restaurants.size();
	int str_compare = 0;

	for (int i = 0; i < vector_length; i++) 
	{
		str_compare = query.compare(restaurants[i]);
		if (str_compare == 0) {
			index = i;
		}
	}

	return index;
}



/**
	GET_NUMBER_ROUNDS()

	DESCRIPTION
	Checks if the size of the vector is a factor of 2. Determines number of
	rounds in the "tournament"

	RETURNS
	Returns the number of rounds in the tournament. The value is the value
	of n for 2^n items in the vector. If the number is not a factor of 2,
	returns -1.
*/
int Restaurants::get_number_rounds()
{
	// Get the initial size
	int x = restaurants.size();
	int factor = 0;

	// Check until you either get all the way to 1 or an odd number
	while (x > 1 && (x % 2) == 0) {
		x /= 2;
		factor++;
	}

	// Return -1 if it doesn't "make it" to 1
	if (x != 1)
		factor = -1;

	// Return the factor or -1
	return factor;
}



/**
	DISPLAY()

	DESCRIPTION
	Displays all the items in the restaurants vector. Comma seperated.
*/
void Restaurants::display()
{
	int num_restaurants = restaurants.size();

	cout << endl << "RESTAURANTS:" << endl;

	for (int i = 0; i < num_restaurants; i++)
	{
		cout << restaurants[i].c_str();
		if (i < num_restaurants - 1) cout << ", ";
		else cout << endl;
	}
}



/**
	ADD()

	DESCRIPTION
	Add restaurants to restaurants vector. Checks for duplicates first.

	PARAMS
	string name: The name you wish to add to the vector.
*/
void Restaurants::add(string name)
{
	if (find(name) > -1) {
		cout << endl << name << " is already on the list." << endl;
	}
	else {
		restaurants.push_back(name);
		cout << endl << name << " has been added to the list." << endl;
	}
}



/**
	REMOVE()

	DESCRIPTION
	Removes a restaurant from the vector if it is present.

	PARAMS
	string name: The name to be removed from the vector.
*/
void Restaurants::remove(string name)
{
	int index = find(name);
	if (index == -1) {
		cout << endl << "Couldn't find that restaurant on the list." << endl;
	}
	else {
		restaurants.erase(restaurants.begin() + index);
		cout << endl << name << " was removed from the list." << endl;
	}
}



/**
	SHUFFLE()

	DESCRIPTION
	Shuffles the items in the restaurants vector
*/
void Restaurants::shuffle()
{
	int size = restaurants.size();

	// Shuffle the vector
	for (int i = 0; i < size; i++)
	{
		// Get a random address inside the vector
		int switch_pos = rand() % size;

		// temp variable for switching
		string temp = restaurants[switch_pos];

		// The ol' restaurant switcharoo
		restaurants[switch_pos] = restaurants[i];
		restaurants[i] = temp;
	}

	cout << endl << "The list of restaurants has been shuffled." << endl;
}



/**
	START_TOURNAMENT()

	DESCRIPTION
	Runs a "tournament" between all the items in the vector. Checks to make
	sure the number of items in the vector is a factor of 2 before running.
	Eliminates items from the vector until only 1 remains and prints out
	the winner.
*/
void Restaurants::start_tournament()
{
	int total_rounds = get_number_rounds();
	int current_round = 0;
	
	if (total_rounds == -1) {
		cout << endl << "Wrong number of values in the list. Try adding or subtracting some restaurants." << endl;
		return;
	}
	
	while (restaurants.size() > 1)
	{
		// Start a new round, count it and output it.
		current_round++;
		cout << endl << "*** Round " << current_round << " of " << total_rounds << " ***" << endl;

		// Set number of matches for each round and initialize the
		// current round counter.
		int total_matches = restaurants.size() / 2;
		int current_match = 0;

		// Loops through each item in the vector. Important that
		// restuarants.size() is used in the check since it will
		// be changing throughout. Only needs to increment by 1
		// since 1 item will be removed each time around.
		for (int i = 0; i < restaurants.size(); i++)
		{			
			// Start a new match, count it and output it.
			current_match++;
			cout << endl << "*Match " << current_match << "/" << total_matches << "*";
			
			// Output the two restaurants
			cout << endl << "Pick One of the Following:" << endl
				<< "  1: " << restaurants[i] << endl
				<< "  2: " << restaurants[(i + 1)] << endl
				<< "Enter 1 or 2 now: ";

			// Get the user's vote
			int input = get_valid_int(1, 2, "Please enter 1 or 2: ");

			// Erase whichever one they didn't choose
			if (input == 1) {
				restaurants.erase(restaurants.begin() + i + 1);
			}
			else if (input == 2) {
				restaurants.erase(restaurants.begin() + i);
			}
		}
	}

	// Output the last remaining restaurant
	cout << endl << restaurants[0] << " is the winner!" << endl;
}





