#include <sstream>
#include <stack>

#include "ExpressionManagerInterface.h"

class ExpressionManager : public ExpressionManagerInterface
{
public:
	ExpressionManager(){}
	virtual ~ExpressionManager(){}

	virtual bool isBalanced(string expression);
	virtual string postfixToInfix(string postfixExpression);
	virtual string infixToPostfix(string infixExpression);
	virtual string postfixEvaluate(string postfixExpression);

private:
	bool is_valid_input(string str);
	string type(string str);
	int to_int(string str);
	string to_str(int num);
	int get_precedence(string token);
	string OPEN_PAREN[3] = {"(", "{", "["};
	string CLOSE_PAREN[3] = {")", "}", "]"};
	string OPERATORS[5] = {"+", "-", "/", "*", "%"};
	string OPERANDS[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	string ACCEPTABLE_INPUTS[22] =
		   {"0", "1", "2", "3", "4",
			"5", "6", "7", "8", "9",
			"+", "-", "/", "*", "%",
			"(", ")", "{", "}", "[",
			"]", " "};
};
