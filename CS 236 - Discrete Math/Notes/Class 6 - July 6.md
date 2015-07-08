# Class 6 - July 6

**Out of town in Idaho - Lecture notes provided by Dr. Barker.**




Valid Expressions



What's a Valid Expression?


    1. always true regardless of predicate or domain definitions

    2. also called a tautology



Which of the expressions are valid?


    (all x)cat(x) -> (exists x)cat(x)

    (all x)cat(x) -> cat(Tom)

    (all x)(cat(x) and blue(x)) -> (all x)cat(x) and (all x)blue(x)



















Classwork
You may work with a partner.


Which of the expressions are valid?


    cat(Tom) -> (exists x)cat(x)

    (exists x)cat(x) -> (all x)cat(x)

    (all x)(cat(x) or blue(x)) -> (all x)cat(x) or (all x)blue(x)





















Predicate Logic Equivalences


Distributive (x can't be a free variable in B)

(all x)A or B       <=>  (all x)(A or B)
(exists x)A and B   <=>  (exists x)(A and B)


Commutative and Associative

(all x)(A and B)    <=>  (all x)A and (all x)B
(exists x)(A or B)  <=>  (exists x)A or (exists x)B

(all x)(all y)A     <=>  (all y)(all x)A
(exists x)(exists y)A   <=>  (exists y)(exists x)A


DeMorgan's

not ((all x)A)      <=>  (exists x)(not A)
not ((exists x)A)   <=>  (all x)(not A)

















Use algebra to show the equivalence is valid.


    (exists x)P(x) -> Q <=> (all x)(P(x) -> Q)



















Classwork
You may work with a partner.


Use algebra to show the equivalence is valid.


    not (exists x) (A(x) and (B(x) or C(x))) <=>
    (all x) (A(x) -> (not B(x) and not C(x)))


























Resolution

















What's the Resolution inference rule?


    (P or A) and (not P or B) => (A or B)



Why is Resolution a valid rule?


    both (P or A) and (not P or B) must be true
    if P is false, A must be true
    if P is true, B must be true
    so either A or B must be true



Why is Resolution such a great rule?


    resolution by itself is complete
    one rule is all you need



















How do you do proofs using resolution?


    1. negate the conclusion, add it to the premises
    2. convert the premises to clauses (product of sums)
    3. repeatedly apply resolution
    4. the goal is to arrive at false



How do you convert expressions to clauses?


    1. remove -> and <->
    2. push NOTs (DeMorgans)
    3. distribute ORs over ANDs



Show how to convert the expression to clauses.


    (A or B) -> C



















Prove the argument using resolution and contradiction.

    There is an undeclared variable or
    there is a syntax error.
    If there is a syntax error,
    there is a missing semicolon or
    a variable name is misspelled.
    There is not a missing semicolon.
    There is not a misspelled variable name.
    Therefore there is an undeclared variable.

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



















Classwork
You may work with a partner.

Prove the argument using resolution and contradiction.

    If the house is next to a lake,
    the treasure is not in the kitchen.
    If the tree in the yard is an elm,
    the treasure is in the kitchen.
    The house is next to a lake.
    The tree in the yard is an elm or
    the treasure is buried under the flagpole.
    Therefore the treasure is under the flagpole.

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























Proofs using Facts and Rules



















How do Facts, Rules, and Queries relate to predicate logic?


    1. facts and rules are premises
    2. queries are conclusions



Translate the argument into predicate logic.


    All students love pizza.
    Bob is a student.
    Therefore, Bob loves pizza.



Translate the argument into facts, rules, and queries.


    All students love pizza.
    Bob is a student.
    Therefore, Bob loves pizza.



What type of quantifier applies to the variables in a rule?


    variables in a rule are implicitly universally quantified



















Prove the query using the facts and rules.


    facts:    S(Bob)
    rules:    P(x) :- S(x)
    queries:  P(Bob)



















Prove the query using the facts and rules.


    facts:     sister(ann, bob)
           parent(bob, jay)
    rules:     aunt(x,z) :- sister(x,y), parent(y,z)
    queries:   aunt(ann, jay)



















Classwork
You may work with a partner.


Prove the query using the facts and rules.


    facts:   married(jim, bea)
         child(ned, bea)
    rules:   married(y,x) :- married(x,y)
         child(x,z) :- child(x,y), married(y,z)
    queries: child(ned, jim)



















Unification



How do you use rules in a proof?


    1. match each predicate in the body with a fact
    2. assert the head as a new true statement



How do you get facts and rules to match?


    unification



What's Unification?


    find instantiations that make expressions match



What's the unifier for each pair of expressions?


    mother(Jane, Brent) and sister(Liza, Jane)
    mother(x,y) and sister(z,x) -> aunt(z,y)


    plus(X, 0, X)
    plus(4, Z, Y)


    plus(X, 0, X)
    plus(3, Z, 4)





































Resolution using Facts and Rules



















What's the process for proof using resolution and contradiction?


    1. negate the conclusion and add it to the premises
    2. convert the premises to clauses
    3. apply resolution to obtain false



















Use Resolution to prove the query using the facts and rules.


    facts:   married(jim, bea)
         child(ned, bea)

    rules:   married(y,x) :- married(x,y)
         child(x,z) :- child(x,y), married(y,z)

    queries: child(ned, jim)



















Classwork
You may work with a partner.


Use Resolution to prove the query using the facts and rules.


    facts:     sister(ann, bob)
           parent(bob, jay)

    rules:     aunt(x,z) :- sister(x,y), parent(y,z)

    queries:   aunt(ann, jay)












































