#pragma once
#include "Property.h"
class Commercial :
	public Property
{
private:
	// Tax rates
	const double RENTAL_TAX_RATE = 0.012;
	const double NON_RENTAL_TAX_RATE = 0.01;

	bool has_discount;
	double discount_rate;

public:
	Commercial(int is_rental, int value, string address, int has_discount, double discount_rate);
	~Commercial();

	string toString();
	string reportTaxes();
};