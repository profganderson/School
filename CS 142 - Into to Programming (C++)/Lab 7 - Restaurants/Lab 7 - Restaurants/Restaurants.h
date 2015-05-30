#include <string>
#include <vector>

#pragma once

using namespace std;

class Restaurants {
public:
	Restaurants();
	int find(string query);
	void display();
	void add(string name);
	void remove(string name);
	void shuffle();
	void start_tournament();
	
private:
	int get_number_rounds(); // Checks if there are 2^n items in the vector. If so, returns n. If not, returns -1

	vector<string> restaurants;

};
