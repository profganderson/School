#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player {
private:
	string name;
	int wins;
	int losses;
	int draws;

public:
	// Returns player's name, wins, losses, draws, and win percent
	string toString();

	// Returns just the player's name
	string get_name();

	// Returns a random number between 1 and 3 representing rock, paper, or scissors
	int getRPSThrow();

	// Calculates the player's win percentage
	double getWinRecord();

	// Increment wins
	void win();

	// Increment losses
	void lose();

	// Increment draws
	void draw();

	// Constructor
	Player(string name);
};