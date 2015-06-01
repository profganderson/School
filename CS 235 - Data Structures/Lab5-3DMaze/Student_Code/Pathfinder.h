/*
 * Pathfinder.h
 *
 *  Created on: May 30, 2015
 *      Author: mocklera
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include <sstream>
#include "PathfinderInterface.h"

class Pathfinder: public PathfinderInterface {
public:
	Pathfinder();
	virtual ~Pathfinder(){};

	virtual string getMaze();
	virtual void createRandomMaze();
	virtual bool importMaze(string file_name);
	virtual vector<string> solveMaze();

private:
	static const int GRID_SIZE = 5;
	int maze[GRID_SIZE][GRID_SIZE][GRID_SIZE];
	vector<string> result;

	bool check_cell(int x, int y, int z);
	void store_coordinate(int x, int y, int z);
};

#endif /* PATHFINDER_H_ */
