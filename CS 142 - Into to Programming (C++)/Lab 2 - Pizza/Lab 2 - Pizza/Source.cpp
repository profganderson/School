#include <iostream>
#include <cmath>

using namespace std;

int main() {
	// TEST CASES
	// Guests: 30,   Tip: 15% --> 4   Large, 0 Medium, 2 Small, Area 1256.64, Area/Person 49.43, Cost 84
	// Guests: 5,    Tip: 08% --> 0   Large, 1 Medium, 2 Small, Area 427.256, Area/Person 85.45, Cost 28
	// Guests: 2497, Tip: 40% --> 356 Large, 1 Medium, 2 Small, Area 112268,  Area/Person 44.96, Cost 7353

	// CONSTANTS
	const double PI = 3.14159;
	// Number of people for each kind of pizza
	const int LARGE = 7;
	const int MEDIUM = 3;
	const int SMALL = 1;
	// Pizza Radius (diameter divided by two)
	const int RADIUS_LARGE = 20 / 2;
	const int RADIUS_MEDIUM = 16 / 2;
	const int RADIUS_SMALL = 12 / 2;
	// Pizza prices
	const double PRICE_LARGE = 14.68;
	const double PRICE_MEDIUM = 11.48;
	const double PRICE_SMALL = 7.28;

	// PART ONE
	// Get number of guests and tip amount
	cout << "How many guests are attending the event?: ";
	int guests;
	cin >> guests;
	cout << "Enter the tip amount: ";
	int tip_amount;
	cin >> tip_amount;

	// Calculate number of large pizzas. Save remainder.
	int num_large = guests / LARGE;
	int remainder = guests % LARGE;

	// Calculate number of medium pizzas. Save remainder.
	int num_medium = remainder / MEDIUM;
	remainder = remainder % MEDIUM;

	// Calculate number of small pizzas
	int num_small = remainder / SMALL;

	cout << "You need " << num_large << " large pizzas." << endl;
	cout << "You need " << num_medium << " medium pizzas." << endl;
	cout << "You need " << num_small << " small pizzas." << endl;

	// PART TWO
	// Calculate total area of pizza
	double area_large = (PI * pow(RADIUS_LARGE, 2)) * num_large;
	double area_medium = (PI * pow(RADIUS_MEDIUM, 2)) * num_medium;
	double area_small = (PI * pow(RADIUS_SMALL, 2)) * num_small;
	double total_area = area_large + area_medium + area_small;
	double portion_size = total_area / guests;

	cout << "Total area is: " << total_area << endl;
	cout << "Guests can eat: " << portion_size << endl;

	// PART THREE
	// Get tip percentage
	double tip_percentage = (tip_amount / 100.0) + 1; // Returns tip amount as a number easier to multiply (e.g. 15 --> 1.15); 100.0 to make double

	double total_cost = ( (num_small * PRICE_SMALL) + (num_medium * PRICE_MEDIUM) + (num_large * PRICE_LARGE) );
	double total_cost_with_tip = total_cost * tip_percentage;

	int rounded_cost = total_cost_with_tip + 0.5;

	cout << "Your total cost (rounded, with tip) is: " << rounded_cost << endl;

	system("pause()");

	return 0;
}