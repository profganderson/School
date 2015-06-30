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
	line = 0;
	file.open(input_file);
}

Scanner::~Scanner() {
	clearTokens();
}

std::vector<Token> Scanner::getTokens() {
	return tokens;
}

void Scanner::scanToken() {
	char token = file.get();
	switch (token) {
	case ',':
		Token c = new Token(token, line, Token::COMMA);
		tokens.push_back(c);
		break;
	case '.':
		Token p = new Token(token, line, Token::PERIOD);
		tokens.push_back(p);
		break;
	case '?':
		Token q = new Token(token, line, Token::Q_MARK);
		tokens.push_back(q);
		break;
	case '(':
		Token lp = new Token(token, line, Token::LEFT_PAREN);
		tokens.push_back(lp);
		break;
	case ')':
		Token rp = new Token(token, line, Token::RIGHT_PAREN);
		tokens.push_back(rp);
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
		break;
	}
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

void Scanner::scan_colon() {
	// Check if it is : or :-
	// Then create the proper token and push it into the vector
}

void Scanner::scan_comment() {

}

void Scanner::scan_string() {
	std::stringstream input_str;
	char token = file.get();
	while (token != '\'') {
		input_str << token;
		token = file.get();
	}
	Token string_token = new Token(input_str.str(), line, Token::STRING);
	tokens.push_back(string_token);
}

void Scanner::scan_id() {

}

void Scanner::clearTokens() {
	tokens.clear();
}
