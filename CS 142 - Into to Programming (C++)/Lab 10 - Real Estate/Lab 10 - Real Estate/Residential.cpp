#include "Residential.h"

/*
	Residential Constructor

	Calls Property constructor. Changes is_occupied from 0/1 to a boolean value.
*/
Residential::Residential(int is_rental, int value, int is_occupied, string address) 
	: Property(is_rental, value, address)
{
	if (is_occupied == 1)
		this->is_occupied = true;
	else
		this->is_occupied = false;
}


Residential::~Residential()
{
}

/*
	toString()

	Returns all the values given in the Property::toString along with Occupied or Not Occupied.
*/
string Residential::toString()
{
	stringstream output;

	output << Property::toString();

	if (is_occupied)
		output << "  Occupied" << endl;
	else
		output << "  Not occupied" << endl;

	return output.str();
}

/*
	reportTaxes()

	Returns a string with the property's tax information formatted.
*/
string Residential::reportTaxes()
{
	stringstream output;

	// Get the property value and its tax rate
	int value = get_value();
	double tax_rate;
	if (is_occupied)
		tax_rate = OCCUPIED_TAX_RATE;
	else
		tax_rate = NON_OCCUPIED_TAX_RATE;

	// Calculate taxes
	double taxes = value * tax_rate;

	// Create string
	output << get_address() << endl
		<< "  Property ID: " << get_id() << endl
		<< "  Estimated Value: " << get_value() << endl
		<< "  Taxes Due: " << taxes << endl;

	return output.str();
}