# Class 5 - July 1
#### Topics
* Logical Expressions
* Tautologies
* Logical Equivalences

# Logical Arguments

```
A look at B
B look at C
A is trekkie
C is not a trekkie
Is a trekkie looking at a non-trekkie?
```

### Valid Arguments

```
Modus Ponens
premises:   if P then Q
            P
conclusion: Q
```

## Logical Connectives

| | |
| ---- | ---- |
| Negation | not, !, ~ |
| Conjunction | and, *, ^ |
| Disjunction | or, +, v |
| Implication | -> (conditional) |
| Equivalence | <->, iff (Biconditional) |
 
#### Class Example
Translate the following into a logical expression using R, H, G.

>If berries are ripe along the trail, hiking is safe if and only if grizzly bears have not been seen in the area.

```
    R -> ( H <-> !G )
```

>Hiking is not safe on the trail whenever grizzly bears have been seen in the area and berries are ripe along the trail

```
    ( G and R ) -> !H
```


# Tautology
**Tautology:** A logical expression that is always true (no matter what values are assigned to the variables); e.g. (P or not P)

**Contradiction:** A logical expression that is always false (no matter what values are assigned to the variables); e.g. (P and not P)

### Some Tautologies
```
P and True      <=> P                   Identity
P or False      <=> P                   Identity
P or True       <=> True                Domination
P and False     <=> False               Domination
P or P          <=> P                   Idempotent
P and P         <=> P                   Idempotent
not (not P)     <=> P                   Double Negation
P or Q          <=> Q or P              Commutative
P and Q         <=> Q and P             Commutative
(P or Q) or R   <=> P or (Q or R)       Associative
(P and Q) and R <=> P and (Q and R)     Associative
P or (Q and R)  <=> (PvQ) and (PvR)     Distributive
P and (Q or R)  <=> (P^Q) or (P^R)      Distributive
not (P and Q)   <=> not P or not Q      DeMorgan's
not (P or Q)    <=> not P and not Q     DeMorgan's
P or (P and Q)  <=> P                   Absorption
P and (P or Q)  <=> P                   Absorption
P or not P      <=> True                Negation
P and not P     <=> False               Negation
```

### Class Example

Use algebra to simplify the code

```
if ( !(v1 < v2) || odd(n) || !(v1 < v2) && odd(n) )
    statement1;
else
    statement2;
```

```
A = v1 < v2
B = odd(n)

!(A or B) or not A and B
(not A and not B) or (not A and B)      DeMorgan's
not A and (not B or B)                  Distributive (backwards)
not A and (B or not B)                  Commutative
not A and True                          Negation
not A                                   Identity

if ( !(v1 < v2) || odd(n) || !(v1 < v2) && odd(n) )
SIMPLIFIES TO
if (!(v1<v2))
```

### Another Look at Distributive Laws

Does multiply distribute over add? `a * (b + c) = a*b + a*c`
Likewise, AND distributes over OR. `P and (Q or R) <=> (P and Q) or (P and R)`

Does add distribute over multiple? NO!
OR does not distribute over AND!


# Proof by Deduction

**What is a valid argument?**
* The conclusion follows from the premises
* If the premises are true, the conclusion is true
    - '(conjunction of premises) -> conclusion' is a tautology
    - (P -> Q, P) -> Q

**What is a Fallacy?**
* An invalid argument
    - (P -> Q, not P) -> not Q














