/*
 * Scanner.cpp
 *
 *  Created on: Jun 29, 2015
 *      Author: mocklera
 */

#include "Scanner.h"

//Identifier token recognition comes last
//Skip over comments
//Use an ifstream to read in the file (has to be ifsteam since input files are write protected)
//Then you can do ifstream in; int c = in.get();
//When you hit the EOF, c will be -1 (hence using int c instead of char a)

Scanner::Scanner() {
	// TODO Auto-generated constructor stub

}

Scanner::~Scanner() {
	// TODO Auto-generated destructor stub
}

std::vector<Token> Scanner::getTokens() {
	return tokens;
}

void Scanner::scanToken() {
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



//	input = readChar();
//	// begin START state
//
//	if (input == QUOTE) {
//	    input = readChar();
//	    // now in STRING state
//
//	    while (input != QUOTE) {
//	        input = readChar();
//	        // Stay in string state
//	    }
//
//	    input = readChar();
//	} else if (input == ...) {
//	    //... other kinds of inputs ...
//	}
}
