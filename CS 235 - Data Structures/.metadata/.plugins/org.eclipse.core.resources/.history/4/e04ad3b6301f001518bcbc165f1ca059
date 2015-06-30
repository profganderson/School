/*
 * Scanner.h
 *
 *  Created on: Jun 29, 2015
 *      Author: mocklera
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include "Token.h"
#include <vector>
#include <fstream>

class Scanner {
public:
	Scanner(char* input_file);
	virtual ~Scanner();
	std::vector<Token*> getTokens();
private:
	void scan();
	void scan_punctuation(char token, int line, Token::TType type);
	void scan_colon();
	void scan_comment();
	void scan_string();
	void scan_id();
	bool is_keyword(std::str id);
	void clearTokens();

	std::vector<Token*> tokens;
	int line;
	std::ifstream file;
	int error;
};

#endif /* SCANNER_H_ */


/* TODO: help session
 *
 *	Reading things in:
 *		Have a line number counter in your read function and increment it every time you find a \n
 *		Break things out into functions and switches to keep complexity down
 *		Look at first character of a token to decide what it is going to be
 *			Start by doing all the 1 character things (colon and colon-dash need to be checked for, but . , ? can be done fast)
 *				If you find a . , ? mark it as a question mark, push it into the vector, and move on to the next one.
 *			You can decide on a string if you find '.
 *				Then, do a while loop until you find ' again (check for not ' || not \n)
 *					Throw back invalid if you find EOF or \n during the string!
 *			You know it is an ID if it starts with a char (you can throw this into the default of your switch)
 *				Keep reading in characters until you get to an invalid character for an ID
 *					Then, at the end, check if it is a keyword.
 * 			You should be keeping track of errors.
 *
 *	Other notes:
 *		Remember to keep checking for EOF as well as \n (Add some cases to the switch)
 *		You will have a main that will bring in the file and just hand it off to the scanner.
 */