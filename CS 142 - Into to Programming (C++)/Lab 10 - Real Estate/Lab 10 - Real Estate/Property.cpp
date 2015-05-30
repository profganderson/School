#include "Property.h"

// Initialize the static variable that counts unique IDs
int Property::id = 0;

/*
	Property constructor

	PARAMS
		int is_rental: 1 or 0 representing if a property is or is not a rental
		int value: The estimated value of the property
		string address: The address of the property
*/
Property::Property(int is_rental, int value, string address)
{
	// Change is_rental from 0 or 1 to a boolean value
	if (is_rental == 0)
		this->is_rental = false;
	else if (is_rental == 1)
		this->is_rental = true;

	// Set other variables
	this->value = value;
	this->address = address;

	// Assign the ID and increment the static variable
	this->prop_id = id; id++;
}


Property::~Property()
{
}

/*
	toString()

	RETURNS
		ID, Address, is_rental, and value in a formatted string.
*/
string Property::toString()
{
	stringstream output;

	output << "  Property id: " << prop_id << endl 
		<< "  Address: " << address << endl;
	if (is_rental)
		output << "  Rental" << endl;
	else
		output << "  Not Rental" << endl;

	output << "  Estimated Value: " << value << endl;

	return output.str();
}

/*
	Getter methods for address, value, is_rental, and get_id
*/
string Property::get_address()
{
	return address;
}

int Property::get_value()
{
	return value;
}

bool Property::get_is_rental()
{
	return is_rental;
}

int Property::get_id()
{
	return prop_id;
}