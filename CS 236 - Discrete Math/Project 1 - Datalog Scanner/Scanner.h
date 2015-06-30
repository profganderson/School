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
	std::vector<Token> getTokens();
private:
	void scanToken();
	void scan_colon();
	void scan_comment();
	void scan_string();
	void scan_id();
	void clearTokens();

	std::vector<Token> tokens;
	int line;
	std::ifstream file;
};

#endif /* SCANNER_H_ */
