# Class 7 - July 8
#### Topics
* Predicates
* Quantifiers
* Predicate Logic Algebra

### The need for Predicates and Quantifiers

**Is the argument valid? Can you prove it using prepositional logic?**

```
All students love pizza.
Bob is a student
Therefore, Bob loves pizza.
```

It is a valid argument, but we can't prove it like we did before. We need **predicates** and **quantifiers**.

# Predicates and quantifiers

**Write the statements using predicates:**
```
Bob is a student.            ->     student(Bob)
Mary and Paul are siblings.  ->     sibling(M,P)
```

Predicates are like functions that take parameters and return a boolean.

**What do we need to know to be able to evaluate the expression `son(Jim, Bob)`?**
* Need to know when the predicate is true or false
    - "Which combinations of parameters make it true and which make it false?"

### Defining Predicates

**Definition by providing facts** 
You can provide a list of cases where the predicate is true, and all other possibilities are false.

```
Rules:
    son('Bob', 'Jim')
    son('Jim', 'Joe')

RESULTS:
son('Bob', 'Jim')                       -> True
son('Jimmy', 'Johnny')                  -> False
son('Jim', 'Joe')                       -> True
son('Bob', 'Joe')                       -> False
son('Bob', 'Joe') and son('Jim', 'Joe') -> False
```



### Universal Quantifiers (for all)

What do the expressions mean?
* `(all x) student(x)`
    - Any value can be a student (within the domain)
* `(all y) (student(y) -> smart(y))`
    - All students are smart

**The universal quantifier is just like a big `and`**. for the domain `{Bob, Jim, Joe}`, `(all x) P(x)` is really just `P(Bob) and P(Jim) and P(Joe)`.

#### Class Example

The following facts define when the son(X,Y) predicate is true. The predicate is false for all other cases. The domain is `{Bob, Jim, Joe}`.


```
Rules:
    son(Bob, Jim)
    son(Jim, Joe)

RESULTS:
(all x) son(Jim, X)      -> False (Bob)
(all x) not son(Jim, X)  -> False (Joe)
(all x) not son(X, Bob)  -> True
```




### Existential Quantifier (there exists)

What do the expressions mean?
* `(exists x) student(x)`
    - There exists a student
* `(exists y) (student y and smart(y))`
    - There exists a smart student

**The existential quantifier is just like a big `or`**.

#### Class Example

The following facts define when the son(X,Y) predicate is true. The predicate is false for all other cases. The domain is `{Bob, Jim, Joe}`.

```
Rules:
    son(Bob, Jim)
    son(Jim, Joe)

RESULTS:
(exists x) son(Jim, X)      -> True (Joe)
(exists x) not son(Jim, X)  -> True (Bob, Jim)
(exists x) not son(X, Bob)  -> False
```



### Nested Quantifiers
Does order matter for quantifiers? **YES!**

What is the truth value for each expression?
* The domain is people in the real world
* The predicate mother(X,Y) is X is the mother of Y
* The predicate of male(X) is X is male
* The predicate female(X) is X is female

```
(all x)(exists y) mother(x,y)   -> FALSE (every person is the mother of at least 1 child)

(exists x)(all y) mother(x, y)  -> FALSE (someone is the mother of everyone)

(exists x)(exists y) (mother(x, y) and male(y)) -> TRUE (there is a mother who is the mother of a male)

(all y)(exists x) mother(x,y) -> TRUE (every person has a mother)

(exists x)(all y) (mother(x,y) -> female(y)) -> TRUE (there is a mother where all the children are female)

(all x)(all y) (mother(x,y) -> male(y)) -> FALSE (Everyone who is a mother has all men)

```












