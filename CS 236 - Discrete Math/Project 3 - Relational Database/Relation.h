/*
 * Relation.h
 *
 *  Created on: Jul 27, 2015
 *      Author: mocklera
 */

#ifndef RELATION_H_
#define RELATION_H_

#include <string>
#include <vector>
#include <set>
#include "Tuple.h"
#include "Scheme.h"

class Relation {
public:
	Relation(std::string name);
	virtual ~Relation();
	Relation select(int index, std::string value);
	Relation select(int index1, int index2);
	Relation project(std::vector<int> indices);
	Relation rename(std::vector<std::string> names);
	std::string to_string();
	Scheme scheme;
	std::set<Tuple> tuples;

private:
	std::string name;
};

#endif /* RELATION_H_ */





/*
 * TODO: PROJECT 4 NOTES
 * Project 4 is all about evaluating rules (we are adding more facts with them!)
 *
 * Rules are essentially joins.
 * So, first, look and see if there are any common attributes
 * Next, make a new scheme (a new relation)
 * 		Do it by writing all of the first scheme, and then anything from the second scheme that isn't already in the first one
 * Next, add tuples for the places where the shared attributes have common values
 * If they don't have anything in common, just do a product - join the two tables as they are
 * Then, after you've made the new relation, you'll project just what the rule calls for
 * And add the new tuples to your existing relations
 *
 * FUNCTIONS
 * 		new_scheme
 * 			Looks for any common attributes
 * 			Create a new scheme out of the two schemes
 * 			Return a new relation with that scheme (temporary - for adding to in the join)
 * 		join
 * 			select all the tuples where the common attributes "overlap"
 * 			push them into that temporary relation that you made
 *
 * 	Keep going through the rules until nothing changes
 * 		Set a flag and use a while loop to just do the facts until nothing changes
 * 		Have a counter in the while loop because in the output file, you have to print out "Converged after __ passes"
 *
 *
 */
