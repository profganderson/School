/*
 * Node.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mocklera
 */

#include "Node.h"

Node::Node(int data) {
	left_height = 0;
	right_height = 0;
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
	if (left_height > right_height)
		return left_height;
	else
		return right_height;
}
