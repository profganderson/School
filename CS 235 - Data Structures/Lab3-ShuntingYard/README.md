# Lab 3 - Shunting Yard

## Purpose
To become familiar with the use of stacks as data structures.

## Background
Develop an Expression Manager that performs several operations on infix and postfix expressions. Be able to convert from one form to the other, evaluate postfix expressions, and check for balanced parenthetical expressions.

You may also refer to Edsger Dijkstra's "Shunting-yard algorithm" for additional help, which can be viewed here.

## Requirements
Details for method constraints are found in these documents and are still a part of the requirements.

Extend the ExpressionManagerInterface.h.

##### Part 1 - Balanced Symbols Check (8 points)
* Determine whether an expression is balanced. { [ } ] is not balanced. [ ( ) ] is balanced and valid

##### Part 2 - Infix to Postfix Conversion (10 points)
* Determine if the given infix expression is valid
* Convert the infix expression into a postfix expression

##### Part 3 - Postfix to Infix Conversion (10 points)
* Determine if the given postfix expression is valid
* Convert the postfix expression into an infix expression

##### Part 4 - Postfix Expression Evaluation (10 points)
* Determine if the given postfix expression is valid
* Evaluate the given postfix expression
* Handle attempts to divide by 0

##### UML design document. (2 points)

## Requirement Notes
##### General
* You are required to create a seperate '.cpp' and '.h' for each class you implement for this lab.
* Valid expressions consist of integers; brackets, braces, and parentheses; and +, -, *, /, and %. Reject any invalid expressions.
* Your calculations should perform integer divison and produce integer results
* Valid expressions also need to satisfy standard infix or postfix requirements
* {,},(,),[, and ] are the only symbols considered for the Balanced Symbols Check
* You can assume there will be a space between every number or operator
* You must put parenthesis '()' around every part of the expression during the postfix to infix conversion. i.e. "4 2 5 + *" = "( 4 * ( 2 + 5 ) )"
* You must use the stack class pre-defined in the C++ Standard Template Library (STL). i.e. #include <stack>

##### Test Cases
* Here are some sample test cases you may use to test your program for pass off for each part. This is not a comprehensive set of tests, but it should familiarize you with the format and give you ideas for additional test cases you can use. (Lab 3 Samples.zip  Download)
 
