/*
 * Database.cpp
 *
 *  Created on: Jul 27, 2015
 *      Author: mocklera
 */

#include <iostream>
#include <sstream>
#include "Database.h"

Database::Database() {

}

Database::~Database() {

}

void Database::load(DatalogProgram program) {
	this->program = program;
}

void Database::evaluate_schemes() {
	int num_schemes = program.schemes.size();
	for(int i = 0; i < num_schemes; i++) {
		add_scheme(i);
	}
}

void Database::add_scheme(int index) {
	std::string name = program.schemes.at(index).name;
	Relation r = Relation(name);

	int num_attributes = program.schemes.at(index).params.size();
	for (int i = 0; i < num_attributes; i++) {
		r.scheme.push_back(program.schemes.at(index).params.at(i).value);
	}

	add_relation_to_map(name, r);
}

void Database::evaluate_facts() {
	int num_facts = program.facts.size();
	for (int i = 0; i < num_facts; i++) {
		add_fact(i);
	}
}

void Database::add_fact(int index) {
	std::string name = program.facts.at(index).name;
	Tuple t = Tuple();

	int num_values = program.facts.at(index).params.size();
	for (int i = 0; i < num_values; i++) {
		t.push_back(program.facts.at(index).params.at(i).value);
	}

	relations.at(name).tuples.insert(t);
}

// i is the iterator for the queries
// j is the position of the parameter within the query
std::string Database::evaluate_queries() {
	std::stringstream s;

	s << "Query Evaluation\n\n";

	int num_queries = program.queries.size();
	for(int i = 0; i < num_queries; i++) {

		// Get the relation with the same scheme as the name of the query
		std::string relation_name = program.queries.at(i).name;
		s << program.queries.at(i).to_string() << "? ";

		Relation r = relations.at(relation_name);
		Relation r_temp = r; // Create a temporary relation to work on


		Relation r_select = select(r_temp, i);
		Relation r_project = project(r_select, i);
		Relation r_rename = rename(r_project, i);

		// Print out result
		if ( r_select.tuples.size() > 0 ) {
			s << "Yes(" << r_select.tuples.size() << ")\n";

			s << "select\n";
			s << r_select.to_string();

			s << "project\n";
			s << r_project.to_string();

			s << "rename\n";
			s << r_rename.to_string();

		} else {
			s << "No\n";
		}
		s << "\n";
	}
	return s.str();
}

Relation Database::rename(Relation r, int i) {
	std::vector<std::string> variables;
	int num_parameters = program.queries.at(i).params.size();
	for (int j = 0; j < num_parameters; j++) {
		bool is_var = !program.queries.at(i).params.at(j).is_string;
		bool duplicate = false;

		int num_var = variables.size();
		for ( int k = 0; k < num_var; k++ ) {
			if ( variables.at(k) == program.queries.at(i).params.at(j).value) {
				duplicate = true;
			}
		}

		if (is_var && !duplicate) {
			variables.push_back(program.queries.at(i).params.at(j).value);
		}
	}

	r = r.rename(variables);

	return r;
}

Relation Database::project(Relation r, int i) {
	int num_parameters = program.queries.at(i).params.size();
	std::vector<int> indices;

	std::vector<std::string> variables;
	for (int j = 0; j < num_parameters; j++) {
		bool is_var = !program.queries.at(i).params.at(j).is_string;
		bool duplicate = false;

		int num_var = variables.size();
		for ( int k = 0; k < num_var; k++ ) {
			if ( variables.at(k) == program.queries.at(i).params.at(j).value) {
				duplicate = true;
			}
		}

		if (is_var && !duplicate) {
			indices.push_back(j);
			variables.push_back(program.queries.at(i).params.at(j).value);
		}
	}

	r = r.project(indices);

	return r;
}

Relation Database::select(Relation r_temp, int i) {

	// Iterate over the parameters of the query
	int num_parameters = program.queries.at(i).params.size();
	std::vector<std::string> variables;
	for (int j = 0; j < num_parameters; j++) {
		std::string parameter = program.queries.at(i).params.at(j).value;

		if ( program.queries.at(i).params.at(j).is_string ) {
			r_temp = r_temp.select(j, parameter);
		}
		else {
			bool duplicate = false;
			int index1;
			int num_var = variables.size();
			for (int k = 0; k < num_var; k++) {
				if (variables.at(k) == parameter) {
					index1 = k;
					duplicate = true;
				}
			}
			int index2 = j;

			if (duplicate) {
				r_temp = r_temp.select(index1, index2);
			}
			else {
				variables.push_back(parameter);
			}
		}
	}

	return r_temp;
}

void Database::add_relation_to_map(std::string name, Relation relation) {
	relations.insert(std::pair<std::string, Relation>(name, relation));
}

Relation Database::get_relation(std::string name) {
	Relation r = relations.at(name);
	return r;
}

std::string Database::relations_to_string() {
	std::stringstream s;

	for (auto item : relations) {
		std::string name = item.first;
		s << name << "\n";

		Relation r = item.second;
		int num_attributes = r.scheme.size();
		for (auto tuple : r.tuples) {
			s << " ";
			for (int i = 0; i < num_attributes; i++) {
				s << " " << r.scheme.at(i) << "=" << tuple.at(i);
			}
			s << "\n";
		}
		s << "\n";
	}

	return s.str();
}














