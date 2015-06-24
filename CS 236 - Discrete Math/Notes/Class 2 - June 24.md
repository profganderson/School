### Class 2 - June 24

# State Machines
* How does the Scanner recognize a keyword?
    * Usually, let the identifier machine pick up the keyword. Then whenever you get an identifier, check if it is a keyword.
* How do you implement a State Machine in code?
    - Store the state in a variable
    - Encode the state in the position in the code

### State in a variable approach

(Use the other one)

```c++
state = START;
input = readChar();
while (state != ACCEPT) {
    if (state == START) {
        if (input == QUOTE) {
            input = readChar();
            state = STRING;
        } else if (input == ...) {
           // ...other kinds of tokens...
        }
    } else if (state == STRING) {
        if (input == QUOTE) {
            input = readChar();
            state = ACCEPT;
        } else {
            input = readChar();
            state = STRING;
        }
    }
}
```

### State by position approach

(Use this one)

```c++
input = readChar();
// begin START state

if (input == QUOTE) {
    input = readChar();
    // now in STRING state

    while (input != QUOTE) {
        input = readChar();
        // Stay in string state
    }

    input = readChar();
} else if (input == ...) {
    //... other kinds of inputs ...
}
```

#### Project 1 Notes
* Identifier token recognition comes last
* Skip over comments
* Use an `ifstream` to read in the file (has to be **i**fsteam since input files are write protected)
    - Then you can do `ifstream in; int c = in.get();`
    - When you hit the EOF, `c` will be -1 (hence using `int c` instead of `char a`)
* Token class
    - enum TType{ID, STRING, PUNCTIATION};
    - TYPE, VALUE, LINE #

```c++

class Token {
private:
    enum TType{ID, STRING, PUNCTUATION, ...};
        // map<TType, string> m = { { ID, "ID" }. { STRING, "STRING" } }
        // So then you can do out << m[type] and it will spit out the string instead of the number in the enum
    string value;
    int line;

};

class Scanner {
public:
    Scanner();
    virtual ~Scanner();
    vector<Token> getTokens(); // Returns all the tokens (like, to the parser)
    scanToken() { // Reads the input and looks for the next token
        // skip whitespace, comments (as a function maybe)
        // Decide what kind of token it is (look at the character! You _almost_ always know from one character in this case)
            // May as well use a switch for this
            QUOTE:
                scan_quote();
            default:
                scan_identifier(); 
                // On this one, read in until you reach something that isn't a letter or number.
                // Use stdlib functions to check for whitespace, letter, number, etc.

    }
private:
    vector<Token> tokens;

};

```

# Grammars





















