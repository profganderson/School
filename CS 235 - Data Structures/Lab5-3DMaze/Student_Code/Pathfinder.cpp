/*
 * Pathfinder.cpp
 *
 *  Created on: May 30, 2015
 *      Author: mocklera
 */

#include <cstdlib>
#include <fstream>
#include "Pathfinder.h"

Pathfinder::Pathfinder() {
	// Default maze is all 1s
	for ( int i = 0; i < 5; i++ )
	{
		for ( int j = 0; j < 5; j++ )
		{
			for ( int k = 0; k < 5; k++ )
			{
				maze << "1 ";
			}
			maze << "\n";
		}
		maze << "\n\n";
	}
}

string Pathfinder::getMaze() {
	return maze.str();
}

void Pathfinder::createRandomMaze() {
	stringstream rand_maze;

	for ( int i = 0; i < 5; i++ )
	{
		for ( int j = 0; j < 5; j++ )
		{
			for ( int k = 0; k < 5; k++ )
			{
				if ( i == 0 && j == 0 && k == 0 ) {
					rand_maze << "1 ";
				} else if ( i == 4 && j == 4 && k == 4 ) {
					rand_maze << "1";
				} else {
					int num = rand() % 2;
					rand_maze << num << " ";
				}
			}
			maze << "\n";
		}
		maze << "\n\n";
	}

	maze.str( string() );
	maze.clear();
	maze << rand_maze.str();
}

bool Pathfinder::importMaze(string file_name) {
	bool imported;

	// Open file
	ifstream import;
	import.open(file_name.c_str());

	// Check for bad filename
	if (import.fail()) {
		import.clear();
		imported = false;
	}
	else {
		stringstream new_maze;
		int maze_length = 0;
		int num;

		// Make sure the first number is a 1
		import >> num;
		if ( num != 1 ) {
			imported = false;
		}
		else {
			// Add it to the new maze if it was a 1 and start reading the rest of the file
			new_maze << num << " ";
			maze_length++;

			bool error = false; // Error flag for invalid data in a cell
			while(!import.eof() && !error)
			{
				// Grab the next number
				import >> num;
				// If it is invalid, kill the loop and the import
				if (import.fail() || num < 0 || num > 1) {
					import.clear();
					error = true;
					imported = false;
				}
				// Else, add the number to the maze and increment the length
				else {
					new_maze << num << " ";
					maze_length++;
				}
			}

			// If the last number isn't a 1 or the maze is not the correct length, kill the import
			if ( num != 1 || maze_length != 125) {
				imported = false;
			}
			// Else, replace the maze with the imported maze
			else {
				maze.str( string() );
				maze.clear();
				maze << new_maze.str();
				imported = true;
			}
		}
	}

	return imported;
}

vector<string> Pathfinder::solveMaze() {
	vector<string> a;
	return a;
}
