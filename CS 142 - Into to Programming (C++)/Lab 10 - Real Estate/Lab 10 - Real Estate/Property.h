#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Property
{
private:
	// Static int to create unique IDs for each property created
	static int id;

	bool is_rental;
	int value;
	string address;
	int prop_id;

public:
	Property(int is_rental, int value, string address);
	~Property();

	// Getter methods
	string get_address();
	int get_value();
	bool get_is_rental();
	int get_id();

	virtual string toString();
	virtual string reportTaxes() = 0;
};