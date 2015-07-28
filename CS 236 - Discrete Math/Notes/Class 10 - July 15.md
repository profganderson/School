# Class 10 - July 15
#### Topics
* Databases
* Relational Algebra

# Relational Databases

**What's a Database?**
* A system for storing and managing information
* A collection of relations

**What's a Relation?**
* A table in a database
* A set of tuples (no duplicates)

**What's a Tuple?**
* A row in a relation
* An ordered list of values

**What's an Attribute?**
* The name of a column in a relation
* The name of a position in a tuple

**What's a Scheme?**
* The set of column names of a relation

# Relational Algebra
Relational Algebra is a way to talk about queries.

The operands are relations, and then operators are any of the following:
* Union
* Intersection
* Difference
* Select
* Project
* Product
* Rename
* Join

### Union, Intersection, and Difference

Computer the union, intersection, and difference of R and S (remember to remove duplicates).

```
R = A B
    0 1
    2 3

S = A B
    0 1
    4 5

R union S = A B
            0 1
            2 3
            4 5

R intersect S = A B
                0 1

R - S = A B
        2 3
```

**What must be true for union, intersection, and difference to be valid?** The schemes must match up! (union compatible)

### Select
The select operator extracts rows or tuples from a relation.

### Project
The project operator extracts columns or attributes from a relation.

```
π[PN] SNAP
S N A P           P N
1 C 1 4    =>     4 C
6 L 3 8    =>     8 L
2 P 5 9           9 P
```

Remember - no duplicates!!

### Cartesian Product

Compute the product of R and S
```
R = A B
    1 2
    2 2

S = C D
    1 1
    2 2
    3 3

R x S = A B C D
        1 2 1 1
        1 2 2 2   // combines all the tuples in R with
        1 2 3 3   // all the tuples in S
        2 2 1 1
        2 2 2 2
        2 2 3 3
```

For the product operation to be valid, the relations cannot have common attribute names.

### Rename

Compute the result of the Rename operation.
```
rename[S<-X](SP)
S P
1 4
6 8
2 9

X P
1 4
6 8
2 9
```

Why is rename useful?
1. To make relations union compatible and product compatible
2. To make relations join on the desired attribute

### Natural Join
The natural join operator combines two relations into a single relation.

Compute the natural join of the relations.
```
A B
1 2
2 1
2 3

B C
1 1
1 2
2 2

A B C
1 2 2
2 1 1
2 1 2
```
