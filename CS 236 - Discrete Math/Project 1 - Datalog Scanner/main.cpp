#include "Scanner.h"

int main( int argc, char* argv[] ) {
	char* input_file = argv[1];
	char* output_file = argv[2];

	Scanner* scanner = new Scanner(input_file);
	scanner->scan();

	ofstream output(output_file);

	for (int i = 0; i < scanner->tokens->size(); i++) {
		Token t = scanner->tokens->at(i);
		std::string val = t->value;
		int line = t->line;
		std::string ttype = t->type_to_string[t->token_type];
		output << "(" << ttype << ",\"" << val << "\"," << line << ")\n";
	}

	return 0;
}
