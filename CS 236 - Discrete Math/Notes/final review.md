# Day 2

### Question 2

Simulate running Dijkstra's Algorithm on the undirected graph.
Use node c as the source node.
For each step indicate which node is marked and give the distance
values assigned to each node.


a,b 4
a,c 9
a,d 7
b,d 1
c,d 5
c,e 1
d,e 2


a. Which node is marked first.
**C** (C is the source node!)

b. Give the distance values assigned to each node after the first node
is marked and the distances are updated.
```
a b c d e
9 - 0 5 1
```

c. Which node is marked second.
**E** (the next smallest distance)

d. Give the distance values assigned to each node after the second
node is marked and the distances are updated.
```
a b c d e
9 - 0 3 1
```

e. Which node is marked third.
**D**

f. Give the distance values assigned to each node after the third node
is marked and the distances are updated.
```
a b c d e
9 4 0 3 1
```

g. Which node is marked fourth.
**B**

h. Give the distance values assigned to each node after the fourth node
is marked and the distances are updated.
```
a b c d e
8 4 0 3 1
```















