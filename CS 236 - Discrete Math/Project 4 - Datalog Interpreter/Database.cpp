/*
 * Database.cpp
 *
 *  Created on: Jul 27, 2015
 *      Author: mocklera
 */

#include <iostream>
#include <sstream>
#include <algorithm>
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

		std::vector<Parameter> params = program.queries.at(i).params;
		Relation r_select = select(r_temp, params);
		Relation r_project = project(r_select, params);
		Relation r_rename = rename(r_project, params);


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

Relation Database::rename(Relation r, std::vector<Parameter> params) {
	std::set<std::string> variables;
	int num_parameters = params.size();
	for (int i = 0; i < num_parameters; i++) {
		Parameter param = params.at(i);
		std::string val = param.value;
		bool is_var = !param.is_string;

		bool is_duplicate;
		if (variables.find(val) == variables.end()) {
			is_duplicate = false;
		} else {
			is_duplicate = true;
		}

		if (is_var && !is_duplicate) {
			variables.insert(val);
		}
	}

	r = r.rename(variables);

	return r;
}

Relation Database::project(Relation r, std::vector<Parameter> params) {
	int num_params = params.size();
	std::vector<int> indices;

	std::set<std::string> variables;
	for (int i = 0; i < num_params; i++) {
		std::string val = params.at(i).value;
		bool is_var = !params.at(i).is_string;

		bool is_duplicate;
		if (variables.find(val) == variables.end()) {
			is_duplicate = false;
		} else {
			is_duplicate = true;
		}

		if (is_var && !is_duplicate) {
			indices.push_back(i);
			variables.insert(val);
		}
	}

	r = r.project(indices);

	return r;
}

Relation Database::select(Relation r_temp, std::vector<Parameter> params) {
	std::vector<std::string> variables;
	int num_params = params.size();
	for ( int i = 0; i < num_params; i++ ) {
		Parameter param = params.at(i);
		std::string val = param.value;

		if ( param.is_string ) {
			r_temp = r_temp.select(i, val);
		}
		else {
			bool duplicate = false;
			int index1;
			int num_var = variables.size();
			for (int k = 0; k < num_var; k++) {
				if (variables.at(k) == val) {
					index1 = k;
					duplicate = true;
				}
			}
			int index2 = i;

			if (duplicate) {
				r_temp = r_temp.select(index1, index2);
			}
			else {
				variables.push_back(val);
			}
		}
	}

	return r_temp;
}

void Database::evaluate_rules() {
	for (auto rule : program.rules) {

		Relation result;
		std::vector<Relation> temp_relations;

		for (auto predicate : rule.body) {
			std::string relation_name = predicate.name;
			Relation r = relations.at(relation_name);
			Relation r_temp = r; // temporary relation to work on

			r_temp = select(r_temp, predicate.params);
			r_temp = project(r_temp, predicate.params);
			r_temp = rename(r_temp, predicate.params);

			temp_relations.push_back(r_temp);
		}

		int num_relations = temp_relations.size();
		if ( num_relations > 1 ) {
			for (int i = 0; i < num_relations; i++) {
				Relation rel = temp_relations.at(i);
				result = rel.join();
			}

			result = join(temp_relations);
		} else {
			result = temp_relations.at(0);
		}


		// Relation r = join(rule);



		// If there are two or more predicates on the right-hand side of a rule,
		// join the intermediate results to form the single result for Step 2.
		// Thus, if p1, p2, and p3 are the intermediate results from Step 1,
		// join them (p1 |x| p2 |x| p3) into a single relation.

		// The predicates in the body of a rule may have variables that are not used
		// in the head of the rule. The variables in the head may also appear in a
		// different order than those in the body. Use a project operation on the result
		// from Step 2 to remove the columns that don't appear in the head of the rule
		// and to reorder the columns to match the order in the head.

		// Rename the relation that results from Step 3 to make it union compatible with the
		// relation that matches the head of the rule. Rename each attribute in the result from
		// Step 3 to the attribute name found in the corresponding position in the relation that
		// matches the head of the rule.

		// Union the result from Step 4 with the relation in the database whose name matches the
		// name of the head of the rule.
	}
}

Relation Database::join(std::vector<Relation> rels) {
	// Join the schemes of all the relations
	Scheme scheme;
	for (auto r : rels) {
		scheme = join_scheme(scheme, r.scheme);
	}

	Relation r = Relation();
	r.scheme = scheme;

	int num_relations = rels.size();
	for ( int i = 1; i < num_relations; i++ ) {
		for (auto tuple : rels.at(i).tuples) {
			for (auto tuple : rels.at(i - 1).tuples) {

			}
		}
	}

//	Join must be able to join two relations that have no common attribute names.
//	Join must be able to join two relations that have multiple common attribute names.
//
//	The following pseudo-code describes one way to compute the join of relations r1 and r2.
//
//		make the scheme s for the result relation
//		    (combine r1's scheme with r2's scheme)
//
//		make a new empty relation r using scheme s
//
//		for each tuple t1 in r1
//		    for each tuple t2 in r2
//
//			if t1 and t2 can join
//			    join t1 and t2 to make tuple t
//			    add tuple t to relation r
//			end if
//
//		    end for
//		end for
//	Note that the following operations used in the join should be decomposed into separate routines.
//
//	combining r1's scheme with r2's scheme
//	testing t1 and t2 to see if they can join
//	joining t1 and t2

	return r;
}

// Accepts a rule and produces a join scheme for the rule's body
Scheme Database::join_scheme (Scheme s1, Scheme s2) {
	Scheme s = Scheme();

	for (auto var1 : s1) {
		for (auto var2 : s2) {
			if (std::find(s.begin(), s.end(), var2) == s.end()) {
				s.push_back(var2);
			}
		}
	}

	return s;
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














