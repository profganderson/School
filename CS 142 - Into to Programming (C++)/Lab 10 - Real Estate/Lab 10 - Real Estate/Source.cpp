#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "Property.h"
#include "Residential.h"
#include "Commercial.h"

using namespace std;

bool loadProperties(vector<Property*> & vec, string filename)
{
	cout << endl << "Reading input from " << filename << "..." << endl;

	// Open filestream
	ifstream input;
	input.open(filename.c_str());

	if (input.fail()) {
		input.clear();
		cout << "Bad filename." << endl << endl;
		return false;
	}

	// Holds the position of each line in case it needs to go back to the beginning of a line for an error
	int position = 0;

	// Loop until end of file
	while (!input.eof()) {
		// Get which type it is
		string type;
		input >> type;
		
		// RESIDENTIAL
		if (type == "Residential")
		{
			// Residential components
			int rental, value, occupied;
			string address;

			// Get rental, value, and occupied from file
			input >> rental >> value >> occupied;

			// Skip leading whitespace before address & get address
			input >> ws;
			getline(input, address);

			// Skip bad lines and alert the user
			if (input.fail())
			{
				input.clear();
				string badline;
				input.seekg(position);
				getline(input, badline);
				cout << "COULD NOT READ LINE: " << badline << endl;
			}
			else {
				// Create new residential object and push it into the properties vector
				Residential* prop = new Residential(rental, value, occupied, address);
				vec.push_back(prop);
			}

		}

		// COMMERCIAL
		else if (type == "Commercial")
		{
			// Commercial components
			int rental, value, tax_discount;
			double discount_rate;
			string address;

			// Get rental, value, tax_discount, and discount_rate
			input >> rental >> value >> tax_discount >> discount_rate;

			// Skip leading whitespace before address & get address
			input >> ws;
			getline(input, address);

			// Skip bad lines and alert the user
			if (input.fail()) {
				input.clear();
				string badline;
				input.seekg(position);
				getline(input, badline);
				cout << "COULD NOT READ LINE: " << badline << endl;
			}
			else {
				// Create new commercial object and push it into the properties vector
				Commercial* prop = new Commercial(rental, value, address, tax_discount, discount_rate);
				vec.push_back(prop);
			}
		}
		else {
			string badline;
			input.seekg(position);
			getline(input, badline);
			cout << "COULD NOT READ LINE: " << badline << endl;
		}

		position = input.tellg();
	}

	// close stream
	input.close();

	return true;
}

int main()
{
	// Vector to hold all the properties we load in
	vector<Property*> properties;

	// Get file to read from 
	string filename;
	cout << "Please enter a filename to read data from: ";
	cin >> filename;

	// Read from the file. Returns false if there is an error in finding the file
	bool file_loaded = loadProperties(properties, filename);

	// If the file loaded right, print all the properties and their tax info
	if (file_loaded) {
		cout << endl << "All valid properties:" << endl;
		for (int i = 0; i < properties.size(); i++)
		{
			cout << properties[i]->toString() << endl;
		}

		cout << endl << "NOW PRINTING TAX REPORT:" << endl;
		for (int i = 0; i < properties.size(); i++)
		{
			cout << properties[i]->reportTaxes() << endl;
		}
	}

	system("pause");

	return 0;
}