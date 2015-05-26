#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>

#include "Utilities.h"
#include "Car.h"
#include "Dealership.h"

using namespace std;

//---------------------------------------------------------------------------------------
Dealership::Dealership() 
{
	this->balance = 10000.00;
}
//---------------------------------------------------------------------------------------
int Dealership::find(string name)
{
	int index = NOTFOUND;

	// Loops through the vector and compares name to the item's name
	for (int i = 0; i < inventory.size(); i++)
	{
		// If found, set index to where it was found
		if (name == inventory[i].getName())
		{
			index = i;
		}
	}

	return index;
}
//---------------------------------------------------------------------------------------
void Dealership::print_balance()
{
	// Print the balance in #####.## format
	cout << "The current balance is $" << fixed << setprecision(2) << this->balance << endl << endl;
}
//---------------------------------------------------------------------------------------
void Dealership::print_inventory()
{
	cout << "Current Inventory:" << endl;
	// Print each item from the inventory vector using Car's toString() method
	for (int i = 0; i < inventory.size(); i++)
	{
		string car = inventory[i].toString();
		cout << endl << car << endl;
	}
}
//---------------------------------------------------------------------------------------
void Dealership::buy_car(string name, string color, double price)
{
	// Make sure the price isn't higher than your balance
	if (price > this->balance)
	{
		cout << endl << "You don't have enough money to buy that car :(" << endl;
		return;
	}

	// Make sure there is no car by the same name in the inventory
	if (find(name) != NOTFOUND)
	{
		cout << "There is already a car by that name in the inventory..." << endl;
		return;
	}

	// Subtract the price from the balance and add the car to the inventory
	this->balance -= price;
	this->inventory.push_back(Car(name, color, price));

	// Confirmation for user
	cout << endl << name << " has been added to the inventory!" << endl << endl;
}
//---------------------------------------------------------------------------------------
void Dealership::sell_car(string name)
{
	// See if the car is in the inventory
	int index = find(name);
	if (index == NOTFOUND)
	{
		cout << endl << "We couldn't find a car by that name in the inventory" << endl;
		return;
	}
	else
	{
		// Sell the car: add price to balance, remove car from vector, confirm to user
		this->balance += inventory[index].getPrice();
		inventory.erase( inventory.begin() + index);
		cout << endl << "Car sold!" << endl;
	}
}
//---------------------------------------------------------------------------------------
void Dealership::paint_car(string name)
{
	// See if the car is in the inventory
	int index = find(name);
	if (index == NOTFOUND)
	{
		cout << endl << "We couldn't find a car by that name in the inventory" << endl;
		return;
	}
	else
	{
		// Get the color they want to paint the car (but only if the car exists)
		string color;
		cout << "What color do you want to paint it?" << endl;
		getline(cin, color);
		// Paint the car using Car's paint method
		inventory[index].paint(color);
		// User confirmation
		cout << "You painted your " << name << " " << color << endl;
	}
}
//---------------------------------------------------------------------------------------
void Dealership::load_file(string filename)
{
	// Open a file stream
	ifstream input;
	input.open(filename.c_str());

	// Get the first line and add it to the current balance
	double balance;
	input >> balance;
	this->balance += balance;

	// Get the rest of the lines and add them to the inventory vector as Car objects
	while (!input.eof()) {
		string name, color;
		double price;

		input >> name >> color >> price;

		Car car = Car(name, color, price);
		this->inventory.push_back(car);
	}

	// Close file stream
	input.close();

	// User confirmation
	cout << "Successfully loaded " << filename << endl;
}
//---------------------------------------------------------------------------------------
void Dealership::save_file(string filename)
{
	// Start ouput
	ofstream output(filename);

	// Write the balance, start a new line
	output << balance;

	// Write a line for each item in the inventory
	for (int i = 0; i < inventory.size(); i++)
	{
		string name = inventory[i].getName();
		string color = inventory[i].getColor();
		double price = inventory[i].getPrice();
		output << endl << name << " " << color << " " << price;
	}

	output.close();

	// User confirmation
	cout << filename << " successfully saved!" << endl;
}
//---------------------------------------------------------------------------------------