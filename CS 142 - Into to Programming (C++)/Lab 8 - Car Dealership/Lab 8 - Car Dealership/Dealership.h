#pragma once
#include <vector>
#include "Car.h"

using namespace std;

class Dealership
{
private:
	double balance;
	vector<Car> inventory;

	//---------------------------------------------------------------------------------------
	/*
	* find
	*
	* Finds a car in the dealership inventory. Returns NOTFOUND (-1) if the car doesn't 
	*		exist in the inventory.
	*
	* Parameter: name
	*		Name of the car to be found
	*
	* Return:
	*		Integer representing the index of the item within the inventory vector
	*
	*/
	int find(string name);
	//---------------------------------------------------------------------------------------

public:
	//---------------------------------------------------------------------------------------
	/* 
	* Constructor
	*
	* Creates a Dealership object and initializes balance to 10000
	*
	*/
	Dealership();
	
	//---------------------------------------------------------------------------------------
	/*
	* print_balance
	* 
	* Prints the dealership balance.
	*
	*/
	void print_balance();
	//---------------------------------------------------------------------------------------
	/*
	* print_inventory
	* 
	* Prints the current dealership inventory.
	*
	*/
	void print_inventory();
	//---------------------------------------------------------------------------------------
	/*
	* buy_car
	*
	* Buys a car as long as it is not a duplicate and there a sufficient balance. Subtracts
	*		the car price from the balance.
	*
	* Parameter: name
	*		The name of the car being purchased
	* Parameter: color
	*		The color of the car being purchased
	* Parameter: price
	*		The price of the car being purchased
	*
	*/
	void buy_car(string name, string color, double price);
	//---------------------------------------------------------------------------------------
	/*
	* sell_car
	*
	* Sells a car from the inventory as long as it exists in the inventory. Adds the car price
	*		back to the balance.
	*
	* Parameter: name
	*		The name of the car to be sold
	*
	*/
	void sell_car(string name);
	//---------------------------------------------------------------------------------------
	/*
	* paint_car
	*
	* Paints a car from the inventory as long as it exists
	*
	* Parameter: name
	*		The name of the car to be painted
	*
	*/
	void paint_car(string name);
	//---------------------------------------------------------------------------------------
	/*
	* load_file
	*
	* Loads a file with a balance and car information. Adds the balance to the current
	*		balance and then adds each item to the inventory.
	*
	* Parameter: filename
	*		The filename of the file to be loaded
	*
	*/
	void load_file(string filename);
	//---------------------------------------------------------------------------------------
	/*
	* save_file
	*
	* Saves a file with the current balance and inventory.
	*
	* Parameter: filename
	*		A filename for the file being saved
	*
	*/
	void save_file(string filename);
	//---------------------------------------------------------------------------------------
};