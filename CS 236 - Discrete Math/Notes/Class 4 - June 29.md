# Class 4 - June 29
#### Topics
* Table Driven Parsing
* Recursive Descent Parsers
* Project 2 Notes (Parser)

#### Class Example

Build a parse table for the following grammar.

```
S -> if E then S
S -> E = E
E -> number | ident
```

Table

| | if  | then | = | number | ident |
| ---- | ------------- | ------------- | ---- | ---- | ---- |
| S | if E then S  |   | | E = E | E = E |
| E |   |   | | number | ident |


# Recursive Descent Parsing

Write a recursive-descent parser for the grammar
```
    E -> T A
    A -> + T A | - T A | epsilon
    T -> ( E ) | number
```

Code
```c++
E () {
    if (token == LPAREN || token == NUMBER) {
        T(); A();
    }
    else 
        error();
}
A () {
    if (token == PLUS) {
        match(PLUS); T(); A();
    }
    else if (token == MINUS) {
        match(MINUS); T(); A();
    }
}
T () {
    if (token == LPAREN)
        match(LPAREN); E(); m(RPAREN);
    else if (token == NUMBER)
        m(num);
    else
        error();
}
match(t) {
    if (token == t)
        token = getToken(); // If what we are currently looking at is a token, then it is all good and you can move on to the next token.
    else
        error();
}
```

__Notes__
* If you have a production with epsilon, treat it like A - that is, it doesn't error out with an else.

#### Class Example

Write a recursive descent parser for the grammar:

```
S -> if E then S
S -> E = E
E -> number | ident
```

Code
```c++
S() {
    if (token == IF) {
        match(if); E(); match(then); S();
    }
    else if (token == NUMBER || token == IDENTIFIER) {
        E(); match(EQUALS); E();
    }
    else {
        error();
    }
}
E() {
    if (token == NUMBER) {
        match(NUMBER);
    } 
    else if (token == IDENTIFIER) {
        match(IDENTIFIER);
    }   
    else {
        error();
    }
}
```



# Project 2 - Datalog Parser
* Check Syntax
* Collect information
* You're given the grammar for a Datalog program
* You will write a recursive-descent parser for the grammar

**EXAMPLE**: Rules for predicate, parameter, and parameter list
__All this is done simply by going through the right side of the grammar for each non-terminal token.__
```c++

class Parser() {
public:
    Parser();
    virtual ~Parser();
private:
    error();
    predicate();
    Token current_token;
};

void Parser::predicate () {
    if(current_token == IDENTIFIER) {
        match(IDENTIFIER);
        match(LPAREN);
        parameter();
        parameterList();
        match(RPAREN);
    }
    else
        error(); // instead of having predicate() or parameter() etc. return something, just call and error function that throws and handles exceptions
}
void Parser::parameter () {
    if(current_token == STRING) {
        match(STRING);
    }
    else if (current_token == ID) {
        match(ID);
    }
    else {
        error();
    }
}
void Parser::error () {
    throw current_token;
    // When you start the parser, you will want to start it in a try...catch so you can handle this exception.
};

```

So that is part of part 1. It will output Success! or Failure!

```c++

class DATALOGPROGRAM() {
    vector<Predicate> Schemes;
    vector<Predicate> Facts;
    set<std::string> Domain;
};

class Predicate() {
    std::string name;
    vector<Param> Params;
};

class Param() {
    // Will have either name or value. And you need to know if it is a name or a value. You could do an enum, you could do this way, you could set a flag, etc.
    std::string name;
    std::string value;
};

class Rule() {
    Predicate head;
    vector<Predicate> body;
};

```

__Then, in the end, you will combine parts 1 and 2__. Don't just check for errors; you can create objects as you go. So part one becomes more like...
```c++
void predicate() {
    if (current_token == ID) {
        Predicate p = new Predicate(current_token.value);
    }
}
```

