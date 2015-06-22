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
* **Tokens** are 1+ characters with special meaning, like `void`, `quote`, `(`, or `)`.
    - These are of different - keywords, identifiers, punctuation, string literal, number/const. integer
    - We will remember 3 things about tokens: the Lexeme, the type, and the line number
        + The **Lexeme** is what actually goes into the scanner. The **type** is what it determines it to be.
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

## Lexer, Parser, Interpretor?
* A **Lexer** receives characters, spits out tokens
* A **Parser** reads the tokens, checks grammar/syntax, and spits out a *data structure* representing the different parts of the "sentence". Relates all the tokens to each other.
    - AST = Abstract Syntax Tree
* The **Interpreter** takes the data structure from the parser and interprets the instructions. Outputs the results.


**What does the Scanner output when given this input?**

```datalog
Facts:
    childOf('Ned','Bea')
```

* A keyword `Facts`
* Punctuation `:`
* An identifier `childOf`
* Punctuation `(`
* String literal `'Ned'`
* Punctuation `,`
* String literal `'Bea'`
* Punctuation `)`
* Punctuation `.`

Keywords and punctuation must be *specifically* identified; e.g. Punctuation.LPAREN or Keyword.FACTS


# Regular Expressions
What notation is commonly used to specify Tokens? *Regular Expressions!*

**Regular Expressions** are patterns that match tokens.
* Single/multiple character(s) match themselves
* `\` is an escape character
* `|` is 'or'
* `.` is a wildcard
* `(` and `)` are for grouping (precedence)
* `*` means repeat the expression 0+ times until the input is matched
* `[^...]` is "not"
* `[]` Is used for ranges
    - `[a-zA-Z]` is "any letter"

So we can make `[a-zA-Z]([a-zA-Z]|[0-9])*` to match identifiers or `'[^']*'` to match string literals.


# State Machines
State machines implement the expressions we pull out with regex. Begins with a start state, moves through the expression, and finally arrives at an except state.

**State Machine for `letter (letter | digit)*`**

![State Machine](/images/state_machine.jpg)

* `^` or `E` here represents an empty string.
























