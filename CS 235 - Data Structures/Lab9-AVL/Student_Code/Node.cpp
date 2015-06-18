/*
 * Node.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mocklera
 */

#include "Node.h"

Node::Node(int data) {
	height = 0;
	left_child = NULL;
	right_child = NULL;
	this->data = data;
}

int Node::getData() {
	return data;
}

Node* Node::getLeftChild() {
	return left_child;
}

Node* Node::getRightChild() {
	return right_child;
}

int Node::getHeight() {
	int height, left_height, right_height;

	if ( left_child != NULL )
		left_height = get_max_height(left_child);
	else
		left_height = 0;

	if ( right_child != NULL )
		right_height = get_max_height(left_child);
	else
		right_height = 0;

	if ( right_height > left_height )
		height = right_height;
	else
		height = left_height;

	return height;
}

int Node::get_max_height(Node* current) {
	int left_height = 0;
	int right_height = 0;
	int height = 0;

	if ( current->left_child != NULL ) {
		left_height = 1;
		left_height += get_max_height(current->left_child);
	}

	if ( current->right_child != NULL ) {
		right_height = 1;
		right_height += get_max_height(current->right_child);
	}

	if ( right_height > left_height )
		height = right_height;
	else
		height = left_height;

	return height;
}

int Node::get_balance() {
	int balance, left_height, right_height;

	if ( left_child != NULL )
		left_height = get_max_height(left_child);
	else
		left_height = 0;

	if ( right_child != NULL )
		right_height = get_max_height(left_child);
	else
		right_height = 0;

	balance = right_height - left_height;

	return balance;
}









