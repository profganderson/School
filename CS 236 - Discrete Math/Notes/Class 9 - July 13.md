# Class 8 - July 13 - Midterm Review

#### Question 3
Make the grammar unambiguous.

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

#### Question 4
Give the grammar for the language recognized by the following recursive-descent parser pseudocode.

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

_Never put Epsilon in the table header; if a production has epsilon, just put it everywhere there isn't another production. Terminal symbols go across the top, non-terminals across the left._

| | = | < | > | ++ | ( | ) | 4 | # |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| E | | | | | AX | | AX | |
| X | = E | ep | ep | ep | ep | ep | ep | ep |
| A | | | | | BY | | BY | |
| Y | ep | < BY | > BY | ep | ep | ep | ep | ep |
| B | | | | | CZ | | CZ | |
| Z | ep | ep | ep | ++Z | ep | ep | ep |
| C | | | | | (E) | | 4 | |

#### Question 6
Using the algebraic laws given in the table, transform the expression into False. Do not use a truth table.Show each step of the transformation. Justify each step with a law from the table. Do not use any laws not provided in the table.

`Q and ( not(not P or Q) or not (Q or not P))`

A.
```
Q and ( not(not P or Q) or not(Q or not P))
Q and ( not(Q or not P) or not(Q or not P))         Commutative
Q and ( not(Q or not P))                            Idempotent
Q and ( not Q and notnot P )                        DeMorgan's
Q and ( not Q and P )                               Double Negation
(Q and not Q) and P                                 Associative
False and P                                         Contradiction
P and False                                         Commutative
False                                               Domination
```

#### Question 7
State whether the proposed inference rule is valid or invalid. If the rule is valid, prove it is valid using a truth table. If the rule is not valid, prove it is not valid, prove it is not valid by giving a counter example.

Dan's Rule: `A -> B, A -> C => B or C`

| ABC | A -> B | A -> C | AND PREMS | B+C CONCLUSION |
| --- | --- | --- | --- | --- |
| TTT | T | T | T | T | T |
| TTF | T | F | F | T | T |
| TFT | F | T | F | T | T |
| TFF | F | F | F | F | T |
| FTT | T | T | T | T | T |
| FTF | T | T | T | T | T |
| FFT | T | T | T | T | T |
| FFF | T | T | T | F | F |

A.
**INVALID.** Counter example: A = F, B = F, C = F.
_(The counter example just comes from the bad row of the conclusion i.e. the bottom row here)._

#### Question 8
A.
```
P -> R
R and S -> T
P
S

Conclude T
```

#### Question 9
Prove the above using proof by contradiction
```
1. not T                Proof by contradiction
2. R and S -> T         Premise
3. not (R and S)        Modus Tollens 1,2
4. not R or not S       DeMorgan's 3
5. S                    Premise
6. not R                Disjunctive Syllogism 4,5
7. P -> R               Premise
8. not P                Modus Tollens 6,7
9. P                    Premise
10. False               Contradiction 8,9
```

#### Question 10
A.
```
a. (all X) child(X, Jim)
    FALSE. x = Jim produces FALSE
b. (exists X) not child(X,Jim)
    TRUE.
c. (all X)(exists Y)(child(X,Jim) -> child(Y,X))
    TRUE.
d. (exists Y)(all X)(child(X,Jim) -> child(Y,X))
    FALSE.
e. (exists X)(all Y)(child(X,Jim) -> child(Y,X))
    TRUE.
```














