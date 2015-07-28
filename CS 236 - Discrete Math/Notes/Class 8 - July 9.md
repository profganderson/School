# Class 8 - July 9
#### Topics
* Resolution

# Resolution
Whats the resolution inference rule? 

```
(P or A) and (not P or B) => (A or B)
```

Why is resolution a valid rule?
* Both `(P or A)` and `(not P or B)` must be true
* If P is false, A must be true
* If P is true, B must be true
* So, either A or B must be true

**Why is Resolution such a great rule?** By itself, it is complete - one rule is all you need!

### Proofs with resolution

##### Negate the conclusion, add it to the premises

##### Convert the premises to clauses (product of sums)

1. remove -> and <->
2. push NOTs (DeMorgans)
3. distribute ORs over ANDs 

```
(A or B) -> C
not (A or B) or C
(not A and not B) or C
(not A or C) and (not B or C)
```

##### Repeatedly apply resolution

##### The goal is to arrive at false

#### Example 1

Prove the argument using resolution and contradiction.

* There is an undeclared variable or there is a syntax error.
* If there is a syntax error, there is a missing semicolon or a variable name is misspelled.
* There is not a missing semicolon.
* There is not a misspelled variable name.
* Therefore, there is an undeclared variable.

```
U  undeclared variable
E  syntax error
S  missing semicolon
V  misspelled variable name

premises:
    U or E
    E -> (S or V)
    not S
    not V

conclusion:
    U

1. not U                 Proof by Contradiction
2. U or E                Premise
3. Not E or S or V       Premise
4. U or S or V           Resolution on 2 & 3
5. S or V                Resolution on 1 & 4
6. Not S                 Premise
7. V                     Resolution on 5 & 6
8. Not V                 Premise
9. False                  Resolution 7 & 8
```


#### Example 2

Prove the argument using resolution and contradiction.

If the house is next to a lake, the treasure is not in the kitchen.
If the tree in the yard is an elm, the treasure is in the kitchen.
The house is next to a lake.
The tree in the yard is an elm or the treasure is buried under the flagpole.
Therefore the treasure is under the flagpole.

```
L  house is next to lake
K  treasure is in kitchen
E  tree is an elm
P  treasure is under flagpole

premises:
    L -> not K
    E -> K
    L
    E or P

conclusion:
    P

1. not P                Proof by Contradiction
2. not L or not K       Premise
3. not E or K           Premise
4. not L or not E       Resolution 2,3
5. L                    Premise
6. not E                Resolution 4,5
7. E or P               Premise
8. P                    Resolution 6,7
9. false                Resolution 1,8  

1. not P                Proof by Contradiction
2. not L or not K       Premise
3. E or P               Premise
4. not E or K           Premise
5. E                    Resolution 1,3
6. K                    Resolution 4,5
7. not L                Resolution 6,2
8. L                    Premise
9. False                Resolution 7,8
```


# Facts, Rules, and Queries in Datalog

How do facts, rules, and queries relate to predicate logic?
1. Facts and Rules are premises
2. Queries are conclusions

| Argument | Predicate Logic | Facts, Rules, Queries (Datalog) |
| ----- | ----- | ----- |
| All students love pizza | `(all x)(S(x) -> P(x))` | `Rules: P(X) :- S(X).` |
| Bob is a student | `S(Bob)` | `Facts: S(Bob)` |
| Therefore, Bob loves pizza. | `P(Bob)` | `Queries: P(Bob)?` |

The variables in a rule are implicitly universally quantified.

### Proof of the query with facts and rules

```
Facts:
    S(Bob)
Rules:
    P(x) :- S(x).
Queries:
    P(Bob)?

Prove P(Bob)

1. S(Bob)               Fact (Premise)
2. P(x) :- S(x)         Rule (Premise)
3. P(Bob) :- S(Bob)     Instantiation of line 2 (or Unification 1,2 or Substitution)
4. P(Bob)               Modus Ponens 1,3
```






















