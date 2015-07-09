/*
 * main.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: mocklera
 */

#include <iostream>
#include <string>
#include "Parser.h"

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
	Parser* parser = new Parser(tokens);
	std::cout << "\tFinished Parsing!" << std::endl;

	// Output results
	std::cout << "Outputting..." << std::endl;
	std::ofstream output(output_file);

	DatalogProgram* program = parser->get_program();
	output << program->to_string();

	output.close();
	std::cout << "\tFinished Output!" << std::endl;

	// Clean up
	delete scanner;
	scanner = NULL;
	delete parser;
	parser = NULL;

	return 0;
}















