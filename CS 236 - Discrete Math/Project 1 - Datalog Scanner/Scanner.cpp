/*
 * Scanner.cpp
 *
 *  Created on: Jun 29, 2015
 *      Author: mocklera
 */

#include "Token.h"
#include "Scanner.h"
#include <sstream>

//Identifier token recognition comes last
//Skip over comments
//Use an ifstream to read in the file (has to be ifsteam since input files are write protected)
//Then you can do ifstream in; int c = in.get();
//When you hit the EOF, c will be -1 (hence using int c instead of char a)

Scanner::Scanner(char* input_file) {
	error = -1;
	line = 0;
	file.open(input_file);
}

Scanner::~Scanner() {
	clearTokens();
}

std::vector<Token*> Scanner::getTokens() {
	return tokens;
}

void Scanner::scan() {
	char token = file.get();
	while (token != EOF) {
		switch (token) {
		case ',':
			scan_punctation(token, line, Token::COMMA);
			break;
		case '.':
			scan_punctation(token, line, Token::PERIOD);
			break;
		case '?':
			scan_punctation(token, line, Token::Q_MARK);
			break;
		case '(':
			scan_punctation(token, line, Token::LEFT_PAREN);
			break;
		case ')':
			scan_punctation(token, line, Token::RIGHT_PAREN);
			break;
		case ':':
			scan_colon();
			break;
		case '#':
			scan_comment();
			break;
		case '\'':
			scan_string();
			break;
		case '\n':
			line++;
			break;
		default:
			scan_id();
			break;
		}
	}
	Token* end = new Token(char token, int line, Token::END);
	tokens.push_back(end);
	// Reads the input and looks for the next token
	//        // skip whitespace, comments (as a function maybe)
	//        // Decide what kind of token it is (look at the character! You _almost_ always know from one character in this case)
	//            // May as well use a switch for this
	//            QUOTE:
	//                scan_quote();
	//            default:
	//                scan_identifier();
	//                // On this one, read in until you reach something that isn't a letter or number.
	//                // Use stdlib functions to check for whitespace, letter, number, etc.

}

void Scanner::scan_punctation(char token, int line, Token::TType type) {
	Token* t = new Token(token, line, type);
	tokens.push_back(t);
}

void Scanner::scan_colon() {
	if ( file.peek() == '-' ) {
		// Throw out the -
		file.get();
		// Create a :- token
		Token* t = new Token(":-", line, Token::COLON_DASH);
		tokens.push_back(cd);
	}
	else {
		// Create a : token
		Token* t = new Token(':', line, Token::COLON);
	}
	tokens.push_back(t);
}

void Scanner::scan_comment() {
	// As long as the next character isn't a new line, throw it out.
	while (file.peek() != '\n') {
		file.get();
	}
}

void Scanner::scan_string() {
	std::stringstream input_str;
	char token = file.get();
	while (token != '\'') {
		input_str << token;
		token = file.get();
	}
	Token* string_token = new Token(input_str.str(), line, Token::STRING);
	tokens.push_back(string_token);
}

void Scanner::scan_id() {
	stringstream id;

	// If the first char of the ID is a digit, error out.
	if ( std::isdigit(token) ) {
		error = line;
	}
	// If the character is whitespace, ignore it
	else if ( std::isspace(token) ) {
		;
	}
	else {
		id << token;
		while ( file.peek() != ','
				&& file.peek() != '.' && file.peek() != '?'
				&& file.peek() != '(' && file.peek() != ')'
				&& file.peek() != '\n' && file.peek() != 'EOF' ) {
			id << file.get();
		}
		std::str id_str = id.str();
		if (!is_keyword(id_str)) {
			Token* t = new Token(id_str, line, Token::STRING);
			tokens.push_back(t);
		}
	}
}

bool Scanner::is_keyword(std::string id) {
	bool is_keyword;
	Token* t;

	if ( id == "SCHEMES" ) {
		t = new Token(id, line, Token::SCHEMES);
		is_keyword = true;
	}
	else if ( id == "FACTS" ) {
		t = new Token(id, line, Token::FACTS);
		is_keyword = true;
	}
	else if ( id == "RULES" ) {
		t = new Token(id, line, Token::RULES);
		is_keyword = true;
	}
	else if ( id == "QUERIES" ) {
		t = new Token(id, line, Token::QUERIES);
		is_keyword = true;
	}
	else 
		is_keyword = false;

	return is_keyword;
}

void Scanner::clearTokens() {
	tokens.clear();
}
