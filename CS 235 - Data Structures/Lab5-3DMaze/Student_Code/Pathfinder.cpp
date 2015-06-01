/*
 * Pathfinder.cpp
 *
 *  Created on: May 30, 2015
 *      Author: mocklera
 */

#include <cstdlib>
#include <fstream>
#include <algorithm>
#include "Pathfinder.h"

Pathfinder::Pathfinder() {
	// Default maze is all 1s
	for ( int x = 0; x < GRID_SIZE; x++ )
	{
		for ( int y = 0; y < GRID_SIZE; y++ )
		{
			for ( int z = 0; z < GRID_SIZE; z++ )
			{
				maze[x][y][z] = 1;
			}
		}
	}
}

string Pathfinder::getMaze() {
	stringstream string_maze;

	for ( int x = 0; x < GRID_SIZE; x++)
	{
		for ( int y = 0; y < GRID_SIZE; y++)
		{
			for ( int z = 0; z < GRID_SIZE; z++)
			{
				string_maze << maze[x][y][z] << " ";
			}
		}
	}

	return string_maze.str();
}

void Pathfinder::createRandomMaze() {
	for ( int x = 0; x < GRID_SIZE; x++ )
	{
		for ( int y = 0; y < GRID_SIZE; y++ )
		{
			for ( int z = 0; z < GRID_SIZE; z++ )
			{
				if ( x == 0 && y == 0 && z == 0 ) {
					maze[x][y][z] = 1;
				} else if ( x == (GRID_SIZE - 1) && y == (GRID_SIZE - 1) && z == (GRID_SIZE - 1) ) {
					maze[x][y][z] = 1;
				} else {
					int num = rand() % 2;
					maze[x][y][z] = num;
				}
			}
		}
	}
}

bool Pathfinder::importMaze(string file_name) {
	bool imported = false;
	int new_maze[GRID_SIZE][GRID_SIZE][GRID_SIZE]; // Import will be stored in this temporary maze until we are sure there are no errors

	// Open file
	ifstream import;
	import.open(file_name.c_str());

	// Check for bad filename
	if (import.fail()) {
		import.clear();
		imported = false;
	}
	else {
		// Start copying in the new maze
		int maze_length = 0;
		int num;
		bool error = false;
		for ( int x = 0; x < GRID_SIZE; x++) {
			for ( int y = 0; y < GRID_SIZE; y++ )
			{
				for ( int z = 0; z < GRID_SIZE; z++)
				{
					if(!import.eof() && maze_length < GRID_SIZE * GRID_SIZE * GRID_SIZE) { // Make sure you haven't hit the end of the file and the maze isn't going to go out of bounds
						import >> num;
						new_maze[x][y][z] = num;
						maze_length++;
					}
					else {
						error = true;
					}
				}
			}
		}

		// Make sure there is a valid entry and exit and that the import file wasn't too large
		if ( new_maze[0][0][0] != 1 || new_maze[GRID_SIZE - 1][GRID_SIZE - 1][GRID_SIZE - 1] != 1 || !import.eof() ) {
			error = true;
		}

		if (error)
			imported = false; // Don't copy it permanently if there are errors
		else {
			// If there are no errors, then copy the imported maze into the permanent maze.
			for ( int x = 0; x < GRID_SIZE; x++ )
			{
				for ( int y = 0; y < GRID_SIZE; y++ )
				{
					for ( int z = 0; z < GRID_SIZE; z++ )
					{
						maze[x][y][z] = new_maze[x][y][z];
					}
				}
			}
			imported = true;
		}
	}

	return imported;
}

vector<string> Pathfinder::solveMaze() {

	// clear the vector
	result.clear();

	// Check if there is a valid path
	if ( check_cell(0, 0, 0) ) {
		reverse(result.begin(), result.end());
	}
	else {
		result.clear();
	}

	// Return maze to normal (no 2's)
	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE; y++)
		{
			for (int z = 0; z < GRID_SIZE; z++)
			{
				if ( maze[x][y][z] == 2 ) {
					maze[x][y][z] = 1;
				}
			}
		}
	}

	// Return the path
	return result;
}

bool Pathfinder::check_cell(int x, int y, int z) {
	bool valid;
	stringstream coordinate;

	if ( x < 0 || x > 4 || y < 0 || y > 4 || z < 0 || z > 4 ) { // Keep from going out of bounds
		valid = false;
	} else if ( x == 4 && y == 4 && z == 4 ) { // End of maze
		store_coordinate(x, y, z);
		valid = true;
	} else if ( maze[x][y][z] != 1 ) { // already visited or unvisitable
		valid = false;
	} else {
		maze[x][y][z] = 2; // Mark the space as visited

		// Check surrounding cells and store this as a valid coordinate if it can continue
		if ( check_cell(x + 1, y, z) || check_cell(x - 1, y, z)
			 || check_cell(x, y + 1, z) || check_cell(x, y - 1, z)
			 || check_cell(x, y, z + 1) || check_cell(x, y, z - 1) ){
			store_coordinate(x, y, z);
			valid = true;
		}
		else {
			valid = false;
		}

	}

	return valid;
}

void Pathfinder::store_coordinate(int x, int y, int z) {
	stringstream coordinate;
	coordinate << "(" << x << ", " << y << ", " << z << ")";
	result.push_back(coordinate.str());
}

