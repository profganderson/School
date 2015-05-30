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
	stringstream maze;
	const int GRID_SIZE = 5;
};

#endif /* PATHFINDER_H_ */
