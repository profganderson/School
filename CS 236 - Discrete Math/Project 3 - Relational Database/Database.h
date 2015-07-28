/*
 * Database.h
 *
 *  Created on: Jul 27, 2015
 *      Author: mocklera
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <string>
#include <map>
#include "DatalogProgram.h"
#include "Relation.h"

class Database {
public:
	Database();
	virtual ~Database();
	void load(DatalogProgram program);
	void evaluate_schemes();
	void evaluate_facts();
	std::string evaluate_queries();
	std::string relations_to_string();

private:
	DatalogProgram program;
	std::map<std::string, Relation> relations;
	void add_scheme(int index);
	void add_fact(int index);
	void add_relation_to_map(std::string name, Relation relation);
	Relation get_relation(std::string name);
	Relation select(Relation r, int index);
	Relation project(Relation r, int index);
	Relation rename(Relation r, int index);
};

#endif /* DATABASE_H_ */
