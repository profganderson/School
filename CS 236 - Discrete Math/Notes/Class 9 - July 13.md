# Class 8 - July 13 - Midterm Review

#### Question 3: Make the grammar unambiguous.
A.
```
E -> A = E
E -> A
A -> A < B | A > B
A -> B
B -> B-- | B++
B -> C
C -> (E)
C -> 4
```

#### Question 4: Give the grammar for the language recognized by the following recursive-descent parser pseudocode.
Q.
```
main () {
    token = getToken();
    E();
    if (token != Endmarker)
        error();
}
E() {
    if (token == '0' || token == '1' || token == Endmarker) {
        N();
    } else if (token == '+' || token == '-') {
        O();
        E();
        E();
    } else {
        error();
    }
}
O() {
    if (token == '+') {
        match('+');
    } else if (token == '-') {
        match('-');
    } else {
        error();
    }
}
N() {
    if (token == '0') {
        match('0');
    } else if (token == '1') {
        match('1');
    }
}
match(t) {
    if (token == t)
        token = getToken();
    else
        error();
}
```


A.
```
E -> N
E -> O E E
O -> +
O -> -
N -> 0
N -> 1
N -> epsilon
```


#### Question 5
Give the parsing table for a table-driven parser for the following grammar. The terminals in the grammar are enclosed in single quotes.

```
E -> A X
X -> '=' E
X -> epsilon
A -> B Y
```

_Never put Epsilon in the table header_

| Non-Terminals | = | < | > | ++ | ( | ) | 4 | # |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| E | | | | | A X | | A X | |
| X | = E | ep | ep | ep | ep | ep | ep | ep |
| A | | | | | B Y | | B Y | |
| Y | ep | < B Y | > B Y | ep | ep | ep | ep | ep |
| B | | | | | CZ | | CZ | |
| Z | ep | ep | ep | ++Z | ep | ep | ep |
| C | | | | | (E) | | 4 | |
















