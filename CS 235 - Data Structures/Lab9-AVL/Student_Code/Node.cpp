/*
 * Node.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mocklera
 */

#include "Node.h"

// Returns the length of the longest path from the node to one of its leaves.
int Node::getHeight() {
	int height, left_height, right_height;

	// Get the left and right heights from the root
	left_height = left_child ? get_max_height(left_child) : 0;
	right_height = right_child ? get_max_height(right_child) : 0;

	// Find the maximum
	height = max(left_height, right_height);

	return height;
}

// Recursive version of getHeight() that traverses the tree and counts the height.
// Could have implemented both as one function if getHeight() weren't inherited.
int Node::get_max_height(Node* current) {
	int left_height, right_height, height;

	// Recursively count up the left and right heights of each node,
	// then returns the max to be added to the parent.
	left_height = current->left_child ? get_max_height(current->left_child) + 1 : 0;
	right_height = current->right_child ? get_max_height(current->right_child) + 1 : 0;
	height = max(left_height, right_height);

	return height;
}

int Node::get_balance() {
	int balance, left_height, right_height;

	// Find the right and left height of a node
	left_height = left_child ? get_max_height(left_child) + 1 : 0;
	right_height = right_child ? get_max_height(right_child) + 1 : 0;

	// Convert the heights to the balance (for deciding if the tree needs rearranging)
	balance = right_height - left_height;

	return balance;
}

int Node::max(int x, int y) {
	int max = (x > y) ? x : y;
	return max;
}
