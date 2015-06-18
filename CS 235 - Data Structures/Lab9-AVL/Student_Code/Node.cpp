/*
 * Node.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mocklera
 */

#include "Node.h"

Node::Node(int data) {
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
	return height;
}

int Node::get_balance() {
	return right_child->getHeight() - left_child->getHeight();
}

void Node::set_height() {
	int height_left = left_child->getHeight();
	int height_right = right_child->getHeight();

	if (height_left > height_right)
		height = height_left;
	else
		height = height_right;

	height++; // Account for 1 more level
}


























































