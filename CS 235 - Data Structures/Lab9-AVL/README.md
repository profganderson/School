# Lab 9 - AVL

## Purpose
This lab assignment focuses on self-balancing binary search trees.

## Background
In computer science, an AVL tree is a self-balancing binary search tree, and it was the first such data structure to be invented. In an AVL tree, the heights of the two subtrees of any node differ by at most one. Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.

## Requirements

##### Part 1 - Creating a balanced tree
* Implement the interface creating an AVL tree. Remember to rebalance when the subtree heights are off by more than 1.

##### Part 2 - Remove from the tree
* Properly remove from the AVL tree
* Maintain balance of the tree
* Be sure to follow the conventions outlined in the Requirement Notes to keep a "properly" constructed tree

##### UML design document.

## Requirement Notes
* There are multiple correct methods for rebalancing nodes in an AVL tree; each method may result in a unique tree. Some conventions will need to be used to ensure that your tree properly matches ours. When rebalancing, refer to www.qmatica.com for more detailed information on proper balancing.
* You should remove nodes from the AVL tree in the same manner used for the BST.
* Remember to disallow duplicate entries and handle the case when the element to be removed is not in the tree
* You are required to write a separate '.h' and '.cpp' for every class you implement.
* You may NOT DISCUSS this "no help" lab assignments with ANYONE other than TAs. The TAs can help clarify requirements and review general data structure concepts. However, they will not give specific advice, nor write or debug any code.  You may use the resources specified for the midterm, but no other resources.
