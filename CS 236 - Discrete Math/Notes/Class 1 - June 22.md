### Class 1 - June 22, 2015

# Scanners
* Scanning is like low-level parsing
* Sometimes called a tokenizer, lexer, lexical analyzer

**How do you read and process the following code?**

```c++
void quote() {
    print(
        "First, solve the problem. Then, write the code." +
        " - John Johnson"
    );
}
```

* The tokenizing process reads the code - everything as seperate characters - and looks for **tokens**
* **Tokens ** are 1+ characters with special meaning, like `void`, `quote`, `(`, or `)`.
    - These are of different - keywords, identifiers, punctuation, string literal, number/const. integer
* They are the natural parts in which to break the input

**How about this?**

```datalog
Schemes:
    childOf(X,Y)
    marriedTo(X,Y)
Facts:
    marriedTo('Zed', 'Bea').
    marriedTo('Jack', 'Jill').
    marriedTo('Ned','Jan').
    childOf('Jill','Zed').
    childOf('Ned','Bea').
    childOf('Tim','Jack').
    childOf('Sue','Jack').
Rules:
    childOf(X, Y) :- childOf(X,Z), marriedTo(Y,Z).
    marriedTo(X,Y) :- marriedTo(Y,X).
Queries:
    marriedTo('Bea','Zed')?
    childOf('Jill','Bea')?
```

* Keywords
    - Schemes, Facts, Rules, Queries
* Punctuation
    - : . ? :- ( ) '
* Identifier
    - childOf, marriedTo

### Lexer, Parser, Interpretor?
* A **Lexer** receives characters, spits out tokens
* A **Parser** reads the tokens, checks grammar/syntax, and spits out a *data structure* representing the different parts of the "sentence". Relates all the tokens to each other.
    - AST = Abstract Syntax Tree
* The **Interpreter** takes the data structure from the parser and interprets the instructions. Outputs the results.