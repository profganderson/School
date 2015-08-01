# Class 11 - July 16
#### Topics
* Deductive Databases
* Project 3 Help (Databases)

# Evaluating facts, rules, and queries using database operations
Suppose you are given this input to evaluate:

```
Schemes:
    f(A,B)
    b(C,D)

Facts:
    f(1,1)
    f(1,2)
    f(2,3)

Rules:
    b(X,Y) :- f(X,Z),f(Z,Y)

Queries:
    b(1,X)?
```

For **schemes**, make an empty relation with the name and appropriate scheme:
```
    f       b
   A B     C D 
```

For **facts**, plug in tuples accordingly:
```
    f       b
   A B     C D 
   1 1
   1 2
   2 3
```

For **rules**, create new facts from existing facts. 

In this example, make new tuples in 'b' using tuples in 'f'. But how? Use a _join!_ (with a rename to match the rule)
```
(rename[XZ](f) |X| rename[ZY](f))

RESULT
X Z Y
1 1 1
1 1 2
1 2 3

project[XY](RESULT)

PROJ RESULT
X Y
1 1
1 2
1 3

rename[CD](PROJ RESULT)
X Y
1 1
1 2
1 3

union
    f       b
   A B     C D 
   1 1     1 1
   1 2     1 2
   2 3     1 3
```

Finally, for **queries**. We will do Select -> Project -> Rename.
```
rename(D<-X) project(D) select(C=1) b
```


# Recursive Rules
How do you know which order you should use to execute recursive rules? Especially when rules depend on each other.

### Fixed Point Algorithm
Repeatedly execute the rules in any order. Quit when no facts are created.
```
Changes = TRUE;
while Changes {
    Changes = FALSE;
    for each rule R {
        execute the relational algebra for rule R
        if rule R added tuples to any relation
            Changes = TRUE;
    }
}
```


# Project 3

You'll need a database calsse and a relation class.

```c++
class Database {
    get_relation(name); // Get a relation (table) by name
    map<name, relation> relations; // Collection of Relations
    add_relation_to_map();
};

class Relation {
    set<Tuple> tuples; // set of tuples
    string name; // you don't HAVE to have this since it'll be stored in the map in the database
    Scheme relation_scheme;
    Relation select(int index, string value); // This shouldn't modify the current relation. Create a new relation that gives the result of the operation
    Relation select(int index1, int index2);
    void project(vector<int> indices);
    void rename(); // Rename the whole scheme all at once. Wipe out all the names and replace it with a new list of names
};

class Tuple : public vector<string> {
    // That's it! Leave it empty!!
};

class Scheme : public vector<string> {
    // you don't have to use inheritance on this one..but why not?
};

```

* For each scheme, create an empty relation in the database
* Your tuple will store string; don't have it store predicates or parameters or anything like that. Just copy the string over.
    - You don't have to worry about the facts having the wrong number of arguments for the scheme :)




Iterating through a map
```
for (auto i : m)
    i.first
    i.second
```


















