/*
 * Token.h
 *
 *  Created on: Jun 29, 2015
 *      Author: mocklera
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <map>

class Token {
public:
	enum TType{COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, END} token_type;

	Token(std::string value, int line, Token::TType type) : value(value), line(line), token_type(type) {};
	virtual ~Token();
private:
	 	 // map<TType, string> m = { { ID, "ID" }. { STRING, "STRING" } }
	     // So then you can do out << m[type] and it will spit out the string instead of the number in the enum
	std::string value;
	int line;
	std::map<TType, std::string> type_to_string;
};

#endif /* TOKEN_H_ */




/* TODO: help session
 * 	Two Classes:
 * 		Token
 * 			Has type, line number, and value (and a map to convert from enumerated back to name of type)
 * 		Scanner
 * 			Take in text file and output all tokens
 * 				Store the tokens in some kind of "list" that won't change their order (vector, queue, etc)
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
 *			If you find a comment (begins with a #)
 *				just do a while loop and keep taking it in until you hit \n again. (\n is one character)
 *
 *	Getting file names out of command line
 *		int main ( int argc, char* argv[] ) {
 *			argv[1] // is a cstr with the first filename
 *			argv[2] // a cstr with the output filename
 *				// argv[0] is the name of the program you are running. neat.
 *		}
 *
 *	Other notes:
 *		Remember to keep checking for EOF as well as \n (Add some cases to the switch)
 *		You will have a main that will bring in the file and just hand it off to the scanner.
 */