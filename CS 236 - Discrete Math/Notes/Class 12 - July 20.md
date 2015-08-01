# Class 12 - July 20


# Power Sets
Whats the power set of a set?
**The power set is the set of all possible subsets.**

`A = {2, 4, 8}`
Give the power set of A.
```
2^A = {{}, {2}, {4}, {8}, {2,4}, {2,8}, {4,8}, {2,4,8}}
|A| = 3         // |A| is the cardinality of A or the number of elements
|2^A| = 8
```

We can see here that exists a cardinality relationship of `|2^x| = 2^|x|`

There are 2 approaches to building a set
1. Make a container and actually put objects in it
2. Build a bit string

### Bit Strings
Consider the set of the days of the week. Suppose you need to write code that works with subsets of this set.

`{Sun, Mon, Tue, Wed, Thu, Fri, Sat}`

Give bit strings for `S = {Mon, Wed, Fri}` and `T = {Tue, Thu}`.

```
int S = 0101010 // 0 for items not in the set S, 1 for items found in set S (from the domain)

int T = 0010100
```

How do you compute union, intersection, difference, and complement using bit strings?
```
S union T = 0111110         // S | T in C++
S intersect T = 0000000     // S & T in C++
S difference T = 0101010    // S&~T in C++
complement S = 1010101      // ~S in C++
```


#### Class Example

Give the power set of B for `B = {x, y}`.
Give the bit strings for the sets:
`{Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec}`
`J = {Jan, Mar, May, Jul, Aug, Oct, Dec}`
`K = {Jan, Feb, Mar, Apr, Sep, Oct, Nov, Dec}`

A.
```
2^B = {{}, {x}, {y}, {x,y}}
J = 101010110101
K = 111100001111
```


# Binary Relations

What is a binary relation?
* A representation of the relationships between members of two sets
* A subset of the cartesian product of the two sets
* A binary relation from A to B is a set of pairs, where the first element of each pair comes from A and the second element comes from B

### Table Representation

Give the matrix or table representation for the relation.
1. row for each domain value
2. column for each range value
3. entry is 1 when the pair is in the relation
4. entry is 0 when the pair is not in the relation

`{(B, 5), (B, 6), (A, 5), (J, 6)}`

```
    5 | 6
----------    
B | 1 | 1
A | 1 | 0
J | 0 | 1
```


### Graph Representation

Give the graph representation for the relation.
1. node for each domain value
2. node for each range value
3. directed edge from x to y if (x,y) is in the relation


# Properties of Relations

**Relations on a set**
The relations in this section are defined on a set (the domain and the range are the same set).

### Reflexive
The relation is reflexive if it contains (x,x) for every x in the domain. Every member of the domain is related to itself.

For example, in the relation of 'less-than-or-equal' in the set of integers would have reflexive relations at (1,1), (2,2), etc.

But S = {(1,1), (1,2), (2,1)} defined on {1, 2, 3, 4} is not because there is no (2,2) or (3,3) or (4,4)

**What is true about the matrix of a reflexive relation?** The main diagonal is all ones; off the diagonal can be whatever, but the main diagonal must _all_ be ones.

**What is true about the graph of a reflexive relation?** Every node has a loop.

### Symmetric
The relation is **symmetric** if the relation contains (x,y) as well as (y,x).

The relation is **antisymmetric** if the relation contains (x,y) and does not contain (y,x) unless y and x are the same item.

You don't have to look at the entire domain for symmetry, just the pairs in the set.






















