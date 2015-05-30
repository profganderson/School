#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Player.h"

using namespace std;

// Constructor
// Sets the player's name as passed in
// Sets wins, losses, and draws to 0
Player::Player(string name) {
	this->name = name;
	wins = 0;
	losses = 0;
	draws = 0;
}

// getWinRecord
// Calculates the player's win percentage by dividing wins by total games played
double Player::getWinRecord() {
	int totalGames = this->wins + this->losses + this->draws;
	if (totalGames == 0) {
		return 0;
	}
	else {
		return (double)wins / (double)totalGames;
	}
}

// toString
// Return their names, their wins, losses, and draws, and 
// their winning record as a percentage.
string Player::toString() {
	stringstream info;
	double winPct = getWinRecord();

	info << endl << "NAME: " << this->name << endl
		<< "WINS: " << this->wins << endl
		<< "LOSSES: " << this->losses << endl
		<< "DRAWS: " << this->draws << endl
		<< "WIN PCT: " << setprecision(2) << winPct << endl;
	return info.str();
}

// getRPSThrow
// Returns a random number between 1 and 3 representing
// rock, paper, or scissors
int Player::getRPSThrow() {
	return (rand() % 3) + 1;
}

// get_name
// Returns the player's name
string Player::get_name() {
	return this->name;
}

// win
// Increment wins
void Player::win() {
	wins++;
}

// lose
// Increment losses
void Player::lose() {
	losses++;
}

// draw
// increment draws
void Player::draw() {
	draws++;
}