#include "Commercial.h"

/*
	Commercial Constructor

	Sets all Property values as well as has_discount and discount_rate.
*/
Commercial::Commercial(int is_rental, int value, string address, int has_discount, double discount_rate)
	: Property(is_rental, value, address)
{
	if (has_discount == 1)
		this->has_discount = true;
	else
		this->has_discount = false;

	this->discount_rate = discount_rate;
}


Commercial::~Commercial()
{
}

/*
	toString()

	Outputs Property info as well as discount status and rate.
*/
string Commercial::toString() 
{
	stringstream output;

	output << Property::toString();

	if (has_discount)
		output << "  Discounted" << endl;
	else
		output << "  Not Discounted" << endl;

	output << "  Discount: " << discount_rate << endl;

	return output.str();
}


/*
reportTaxes()

Returns a string with the property's tax information formatted.
*/
string Commercial::reportTaxes()
{
	// Get the true tax value (with or without discount)
	double tax_value;
	if (has_discount)
		tax_value = get_value() * discount_rate;
	else
		tax_value = get_value();

	// Get the tax rate (rental v. non-rental)
	double tax_rate;
	if (get_is_rental())
		tax_rate = RENTAL_TAX_RATE;
	else
		tax_rate = NON_RENTAL_TAX_RATE;
	
	double taxes = tax_value * tax_rate;

	stringstream output;

	output << get_address() << endl
		<< "  Property ID: " << get_id() << endl
		<< "  Estimated Value: " << get_value() << endl
		<< "  Taxes Due: " << taxes << endl;
	
	return output.str();
}