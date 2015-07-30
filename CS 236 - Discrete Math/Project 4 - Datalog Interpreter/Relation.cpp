/*
 * Relation.cpp
 *
 *  Created on: Jul 27, 2015
 *      Author: mocklera
 */

#include <iostream>
#include <sstream>
#include "Relation.h"

Relation::Relation() {
	this->name = "";
}

Relation::Relation(std::string name) {
	this->name = name;
}

Relation::~Relation() {}

Relation Relation::select(int index, std::string value) {
	Relation temp = Relation(this->name);
	temp.scheme = this->scheme;

	for (Tuple tuple : this->tuples) {
		if (tuple.at(index) == value) {
			temp.tuples.insert(tuple);
		}
	}

	return temp;
}

Relation Relation::select(int index1, int index2) {
	Relation temp = Relation(this->name);
	temp.scheme = this->scheme;
	temp.tuples = this->tuples;

	for (Tuple tuple : this->tuples) {
		if(tuple.at(index1) == tuple.at(index2)) {
			temp.tuples.insert(tuple);
		}
	}

	return temp;
}

Relation Relation::project(std::vector<int> indices) {
	Relation temp = Relation(this->name);

	int num_indices = indices.size();
	for (int i = 0; i < num_indices; i++) {
		temp.scheme.push_back(this->scheme.at(indices.at(i)));
	}

	for (Tuple tuple : this->tuples) {
		Tuple t;
		for (int i = 0; i < num_indices; i++) {
			t.push_back(tuple.at(indices.at(i)));
		}
		temp.tuples.insert(t);
	}

	return temp;
}

Relation Relation::rename(std::set<std::string> names) {
	Relation temp = Relation(this->name);
	temp.tuples = this->tuples;

	for (auto name : names) {
		temp.scheme.push_back(name);
	}

	return temp;
}

std::string Relation::to_string() {
	std::stringstream s;

	for (auto tuple : this->tuples) {
		if (!tuple.empty()) {
			s << " ";
			int num_attributes = this->scheme.size();
			for (int i = 0; i < num_attributes; i++) {
				s << " " << this->scheme.at(i) << "=" << tuple.at(i);
			}
			s << "\n";
		}
	}

	return s.str();
}
