/*
 * main.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: mocklera
 */

#include <iostream>
#include <string>
#include "Parser.h"
#include "Database.h"

int main(int argc, char* argv[])
{
	// Get filenames from command line
	char* input_file = argv[1];
	char* output_file = argv[2];

	// Run the scanner
	std::cout << "Running Scanner..." << std::endl;
	Scanner* scanner = new Scanner(input_file);
	scanner->scan();
	std::vector<Token*> tokens = scanner->getTokens();
	std::cout << "\tFinished Scanning!" << std::endl;

	// Run the parser
	std::cout << "Running Parser..." << std::endl;
	Parser * parser = new Parser(tokens);
	std::cout << "\tFinished Parsing!" << std::endl;

	DatalogProgram program = parser->get_program();

	// Make the database and load in the program
	Database db = Database();
	db.load(program);

	// Evaluate Schemes
	std::cout << "Evaluating Schemes..." << std::endl;
	db.evaluate_schemes();
	std::cout << "\tSchemes Evaluated!" << std::endl;

	// Evaluate Facts
	std::cout << "Evaluating Facts..." << std::endl;
	db.evaluate_facts();
	std::cout << "\tFacts Evaluated!" << std::endl;

	// Evaluate Queries
	std::cout << "Evaluating Queries..." << std::endl;
	std::string query_results = db.evaluate_queries();
	std::cout << "\tQueries Evaluated!" << std::endl;

	// Output results
	std::cout << "Outputting..." << std::endl;
	std::ofstream output(output_file);

	output << "Scheme Evaluation\n\n";
	output << "Fact Evaluation\n\n";
	output << db.relations_to_string();
	db.evaluate_rules();
	output << query_results;


	output.close();
	std::cout << "\tFinished Output!" << std::endl;

	// Clean up
	delete scanner;
	scanner = NULL;
	delete parser;
	parser = NULL;

	return 0;
}















