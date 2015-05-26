#pragma once;
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;

// Shows the menu and returns a valid menu choice
int menu() {
	int menu_choice;

	cout << endl << "****** MENU ******" << endl
		<< "  1. Show Players" << endl
		<< "  2. Add Player" << endl
		<< "  3. Add To Line-up" << endl
		<< "  4. Show Line-up" << endl
		<< "  5. Fight" << endl
		<< "  6. Quit" << endl
		<< "Please enter your choice: ";
	cin >> menu_choice;

	// Handle bad inputs
	while (cin.fail() || menu_choice < 1 || menu_choice > 6) {
		cin.clear();
		cin.ignore(999999, '\n');
		cout << "Please enter a number between 1 and 6: ";
		cin >> menu_choice;
	}

	return menu_choice;
}

// Shows all players & their information
void showPlayers(vector<Player*> & vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		// Call toString on each item
		cout << vec[i]->toString();
	}
}

// Finds a player in the players vector. Returns either the index
// or -1 if not found
int find(vector<Player*> & players, string name) {
	int index = -1;

	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->get_name() == name) {
			index = i;
		}
	}

	return index;
}

// Adds a player to the vector as long as a player by the same
// name doesn't already exist
void addPlayer(vector<Player*> & vec, string name) {
	bool unique = true;

	// See if the name already exists in the vector
	if (find(vec, name) != -1)
		unique = false;

	// Check if it is unique
	if (unique) {
		Player* player = new Player(name);
		vec.push_back(player);
		cout << name << " was successfully added!" << endl;
	}
	else {
		cout << "A player by that name already exists." << endl;
	}
}

// Adds a player to the queue as long as the player exists to be added
void addToQueue(vector<Player*> & players, vector<Player*> & queue, string name) {
	// Get the index of that player
	int player = find(players, name);

	// If the player is in the players vector, add the pointer to the queue.
	if (player > -1) {
		queue.push_back(players[player]);
		cout << name << " was successfully added to the queue!" << endl;
	}
	else {
		cout << "We couldn't find any players by that name." << endl;
	}
}

// changes rock paper or scissors ints to a string value
string interpretRPS(int num) {
	string name;

	switch (num)
	{
	case 1:
		name = "rock";
		break;
	case 2:
		name = "paper";
		break;
	case 3:
		name = "scissors";
		break;
	}

	return name;
}

// Simulates a rock, paper, scissors fight
void fight(vector<Player*> & queue) {
	// First check if there are at least 2
	if (queue.size() >= 2) {

		// Get the first two players from the queue and have them play
		Player* p1 = queue[0];
		Player* p2 = queue[1];

		if (p1->get_name() == p2->get_name()) {
			p1->draw();
			cout << "It was a draw!" << endl;
		}
		else {

			int p1_throw = p1->getRPSThrow();
			int p2_throw = p2->getRPSThrow();

			// Get throws and build output
			cout << "Fight initiated between " << p1->get_name() << " and " << p2->get_name() << "!\n\n";
			cout << p1->get_name() << " throws " << interpretRPS(p1_throw) << endl;
			cout << p2->get_name() << " throws " << interpretRPS(p2_throw) << endl;

			// Determine who wins the fight
			switch (p1_throw) {

			case ROCK:
				if (p2_throw == ROCK) {
					p1->draw();
					p2->draw();
					cout << endl << "It is a draw!" << endl;
				}
				else if (p2_throw == PAPER) {
					p1->lose();
					p2->win();
					cout << endl << p2->get_name() << " wins!" << endl;
				}
				else if (p2_throw == SCISSORS) {
					p1->win();
					p2->lose();
					cout << endl << p1->get_name() << " wins!" << endl;
				}
				break;

			case PAPER:
				if (p2_throw == ROCK) {
					p1->win();
					p2->lose();
					cout << endl << p1->get_name() << " wins!" << endl;
				}
				else if (p2_throw == PAPER) {
					p1->draw();
					p2->draw();
					cout << endl << "It is a draw!" << endl;
				}
				else if (p2_throw == SCISSORS) {
					p1->lose();
					p2->win();
					cout << endl << p2->get_name() << " wins!" << endl;
				}
				break;

			case SCISSORS:
				if (p2_throw == ROCK) {
					p1->lose();
					p2->win();
					cout << endl << p2->get_name() << " wins!" << endl;
				}
				else if (p2_throw == PAPER) {
					p1->win();
					p2->lose();
					cout << endl << p1->get_name() << " wins!" << endl;
				}
				else if (p2_throw == SCISSORS) {
					p1->draw();
					p2->draw();
					cout << endl << "It is a draw!" << endl;
				}
				break;
			}
		}

		// Erase the two that just battled.
		//		Note that the second one doesn't have to be begin() + 1
		//		since it will be the first in the vector after the first
		//		call to erase.
		queue.erase(queue.begin());
		queue.erase(queue.begin());
	}
	else {
		// In case there aren't enough players
		cout << "There must be at least 2 players in the queue to start fighting!" << endl;
	}
}