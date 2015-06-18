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

	left_height = left_child ? get_max_height(left_child) : 0;
	right_height = right_child ? get_max_height(right_child) : 0;

	height = max(left_height, right_height);

	return height;
}

int Node::get_max_height(Node* current) {
	int left_height = 0;
	int right_height = 0;
	int height = 0;

	left_height = current->left_child ? get_max_height(current->left_child) + 1 : 0;
	right_height = current->right_child ? get_max_height(current->right_child) + 1 : 0;

	if ( right_height > left_height )
		height = right_height;
	else
		height = left_height;

	return height;
}

int Node::get_balance() {
	int balance, left_height, right_height;

	if ( left_child != NULL )
		left_height = get_max_height(left_child) + 1;
	else
		left_height = 0;

	if ( right_child != NULL )
		right_height = get_max_height(right_child) + 1;
	else
		right_height = 0;

	balance = right_height - left_height;

	return balance;
}

int Node::max(int x, int y) {
	int max = (x > y) ? x : y;
	return max;
}
