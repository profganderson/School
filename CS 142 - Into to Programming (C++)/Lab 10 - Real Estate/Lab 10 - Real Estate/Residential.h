#pragma once

#include "Property.h"

class Residential :
	public Property
{
private:
	// Tax Rates
	const double OCCUPIED_TAX_RATE = 0.006;
	const double NON_OCCUPIED_TAX_RATE = 0.009;

	bool is_occupied;

public:
	Residential(int is_rental, int value, int is_occupied, string address);
	~Residential();

	string toString();
	string reportTaxes();
};