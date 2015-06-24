# Class 2 - June 24
#### Topics
* State Machines
* Project 1 Advice
* Grammars
* Parse Trees


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
How does a parser know that a sequence of tokens is valid? Grammars!

Here is a grammar for simple expressions:
```
E -> (E + E)
E -> (E * E)
E -> 1
E -> x
E -> y
```

With that grammar, `(x * (1 + y))` is `E => (E * E) => (E * (E + E)) => (x * (E + E)) => (x * (1 + E)) => (c * (1 + y))`. The derivation shows that it is valid - you are proving that the string is in the valid syntax of the grammar.

##### Another Example

```
sentence -> noun-phrase verb-phrase
noun-phrase -> article noun
verb-phrase -> verb adverb
article -> a
article -> the
noun -> tree
noun -> monkey
verb -> eats
verb -> talks
adverb -> wildly
adverb -> loudly
```

**The Tree Eats Loudly**
```
sentence => noun-phrase verb-phrase => article noun verb-phrase
         => article noun verb adverb => the noun verb adverb
         => the tree verb adverb => the three eats adverb
         => the tree eats loudly
```


## Grammar Terminology
* What is a Production (Rule)?
    - What the grammar is made up of; e.g. `noun-phrase -> article noun`
* What is a metasymbol?
    - `->`
* What is a Nonterminal (Variable, Syntactic Category)?
    - The thing to the left of the metasymbol; e.g. **noun** -> tree
    - This includes things that are on the right side of an arrow but *eventually* wind up on the left side. So, `article` is a nonterminal, but `monkey` is not
* What is a Terminal?
    - A symbol that *can't* be replaced by something else; directly represents a token from the scanner. 
        + This means it only ever appears on the right, never on the left.
    - When the derivation is done, you have to be left with only terminals.
* What is the Start Symbol?
    - The nonterminal you start the derivation with; e.g. `Sentence` or `E`.


# Parse Trees

Parse trees are like derivation, but notated like a tree. So, in the E example, the first E would be broken into 5 children, then those keep getting broken into children for each character that it represents.

```
        E
     / /|\ \
    ( E * E )
      |
      x

```
