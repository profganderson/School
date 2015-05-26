#include "ExpressionManager.h"

bool ExpressionManager::is_valid_input(string str)
{
	bool valid_expression = true;
	stringstream sstr(str);

	string input;
	while( !sstr.eof() && valid_expression == true)
	{
		sstr >> input;
		bool valid_token = true;

		for (int i = 0; i < input.length() && valid_token == true; i++)
		{
			string sub = input.substr(i, 1);
			valid_token = false;
			for (int j = 0; j < 21 && valid_token == false; j++)
			{
				if (sub == ACCEPTABLE_INPUTS[j]) {
					valid_token = true;
				}
			}
		}

		valid_expression = valid_token;
	}

	return valid_expression;
}

string ExpressionManager::type(string str)
{
	string type = "";

	for (int j = 0; j < str.length() && type != "invalid"; j++)
	{
		for (int i = 0; i < 3 && type == ""; i++)
		{
			if (str.substr(j, 1) == OPEN_PAREN[i]) {
				type = "open_paren";
			}
			else if (str.substr(j, 1) == CLOSE_PAREN[i]) {
				type = "close_paren";
			}
		}

		for (int i = 0; i < 5 && type == ""; i++)
		{
			if ( str.substr(j, 1) == OPERATORS[i] ) {
				type = "operator";
			}
		}

		for (int i = 0; i < 10 && type == ""; i++)
		{
			if ( str.substr(j, 1) == OPERANDS[i] )
			{
				type = "operand";
			}
		}

		if (type == "") {
			type = "invalid";
		}
	}

	return type;
}

bool ExpressionManager::isBalanced(string expression)
{
	// Initialize needed variables
	bool balanced = true;
	stack<string> stack;
	stringstream exp(expression);

	string item; // Will hold each item as it is pulled out of the string
	while ( !exp.eof() && balanced == true )
	{
		exp >> item;
		for (int i = 0; i < 3; i++)
		{
			if (item == OPEN_PAREN[i]) {
				stack.push(item);
			}
			else if (item == CLOSE_PAREN[i]) {
				string match;
				if (stack.size() > 0) {
					string match = stack.top();
					if (match != OPEN_PAREN[i]) {
						balanced = false;
					}
					stack.pop();
				}
				else
					balanced = false;
			}
		}
	}

	if (stack.size() > 0) balanced = false;

	return balanced;
}

string ExpressionManager::postfixToInfix(string postfixExpression)
{
	stringstream exp(postfixExpression);
	stack<string> operands;
	string result = "";

	if ( !is_valid_input(postfixExpression) ) result = "invalid";

	string token;
	while ( !exp.eof() && result != "invalid")
	{
		exp >> token;

		string type = this->type(token);
		if (type == "open_paren" || type == "close_paren") {
			result = "invalid";
		}
		else if (type == "operand") {
			operands.push(token);
		}
		else if (type == "operator") {
			if ( operands.size() < 2 ) {
				result = "invalid";
			}
			else {
				string right_operand = operands.top();
				operands.pop();
				string left_operand = operands.top();
				operands.pop();

				result = "( " + left_operand + " " + token + " " + right_operand + " )";

				operands.push(result);
			}
		}
		else {
			result = "invalid";
		}
	}

	if ( operands.size() != 1 ) {
		result = "invalid";
	}

	return result;
}

string ExpressionManager::infixToPostfix(string infixExpression)
{
	stringstream exp(infixExpression);
	stack<string> operators;
	stack<string> operands;
	string result = "";
	string token;

	if ( !isBalanced(infixExpression) ) result = "invalid";
	if ( !is_valid_input(infixExpression) ) result = "invalid";

	bool first = true;
	while (exp >> token && result != "invalid") {

		string type = this->type(token);
		if (first) {
			if (type != "open_paren" && type != "operand")
				result = "invalid";
			first = false;
		}

		if (result == "invalid") {}
		else if (type == "operand") {
			operands.push(token);
		}
		else if (type == "open_paren") {
			operators.push(token);
		}
		else if (type == "close_paren") {
			while (operators.size() > 0 && operators.top() != "(") {
				string right_operand = operands.top();
				operands.pop();
				string left_operand = operands.top();
				operands.pop();
				string op = operators.top();
				operators.pop();

				string eval = left_operand + " " + right_operand + " " + op;
				operands.push(eval);
			}
			operators.pop(); // pop off the open paren
		}
		else if (type == "operator") {
			if (operators.size() == 0) {
				operators.push(token);
			}
			else {
				if (get_precedence(token) > get_precedence(operators.top())) {
					operators.push(token);
				}
				else {
					while (operators.size() > 0
							&& (get_precedence(token) <= get_precedence(operators.top()))
							&& operators.top() != "("
							&& result != "invalid") {
						if (operands.size() >= 2) {
							string right_operand = operands.top();
							operands.pop();
							string left_operand = operands.top();
							operands.pop();
							string op = operators.top();
							operators.pop();

							result = left_operand + " " + right_operand + " " + op;
							operands.push(result);
						}
						else {
							result = "invalid";
						}
					}
					operators.push(token);
				}
			}
		}
		else {
			result = "invalid";
		}
	}
	if (result != "invalid") {
		while (operands.size() >= 2) {
			string right_operand = operands.top();
			operands.pop();
			string left_operand = operands.top();
			operands.pop();
			string op = operators.top();
			operators.pop();

			string eval = left_operand + " " + right_operand + " " + op;
			operands.push(eval);
		}
		result = operands.top();
		while (operators.size() > 0) {
			string op = operators.top();
			operators.pop();
			result += " ";
			result += op;
		}
	}
	return result;
}

string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	stringstream exp(postfixExpression);
	stack<int> operands;
	string result = "";

	if ( !is_valid_input(postfixExpression) ) result = "invalid";

	string token;
	while ( !exp.eof() && result != "invalid")
	{
		exp >> token;

		string type = this->type(token);
		if (type == "open_paren" || type == "close_paren") {
			result = "invalid";
		}
		else if (type == "operand") {
			int op = to_int(token);
			operands.push(op);
		}
		else if (type == "operator") {
			if ( operands.size() < 2 ) {
				result = "invalid";
			}
			else {
				int right_operand = operands.top();
				operands.pop();
				int left_operand = operands.top();
				operands.pop();

				int res; // the result of the operation
				if ( token == "+" ) res = left_operand + right_operand;
				else if ( token == "-" ) res = left_operand - right_operand;
				else if ( token == "*" ) res = left_operand * right_operand;
				// Don't divide by 0
				else if ( right_operand == 0 ) {
					res = 0;
					result = "invalid";
				}
				else if ( token == "/" ) res = left_operand / right_operand;
				else if ( token == "%" ) res = left_operand % right_operand;
				operands.push(res);
			}
		}
		else {
			result = "invalid";
		}
	}

	if ( operands.size() != 1 ) {
		result = "invalid";
	}

	if (result != "invalid")
		result = to_str(operands.top());

	return result;
}

int ExpressionManager::to_int(string str)
{
	stringstream in(str);
	int result;
	in >> result;
	return result;
}

string ExpressionManager::to_str(int num)
{
	stringstream in;
	in << num;
	string result;
	in >> result;
	return result;
}

int ExpressionManager::get_precedence(string token)
{
	int precedence = 1;

	for (int i = 0; i < 3; i++)
	{
		if (token == OPEN_PAREN[i]) precedence = 0;
	}

	if (token == "/" || token == "*" || token == "%") precedence = 2;

	return precedence;
}
