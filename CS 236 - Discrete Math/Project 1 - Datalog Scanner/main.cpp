#include <iostream>
#include "Scanner.h"

int main( int argc, char* argv[] ) {
	std::cout << "Running Project 1..." << std::endl;
	char* input_file = argv[1];
	char* output_file = argv[2];

	Scanner* scanner = new Scanner(input_file);
	scanner->scan();

	std::cout << "Finished Scanning!" << std::endl;

	std::ofstream output(output_file);

	std::vector<Token*> tokens = scanner->getTokens();
	int num_tokens = tokens.size();
	bool has_error = false;

	for (int i = 0; i < num_tokens; i++) {
		Token* t = tokens.at(i);
		std::string val = t->value;
		int line = t->line;
		std::string ttype = t->type_to_string[t->token_type];
		if (ttype != "Error") {
			output << "(" << ttype << ",\"" << val << "\"," << line << ")\n";
		}
		else {
			output << "Input Error on line " << line;
			has_error = true;
		}
	}

	if (!has_error)
		output << "Total Tokens = " << tokens.size();

	std::cout << "Finished output!" << std::endl;

	delete scanner;
	scanner = NULL;

	return 0;
}
