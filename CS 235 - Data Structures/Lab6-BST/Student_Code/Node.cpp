#include "Node.h"

Node::Node(int data) {
	left_child = NULL;
	right_child = NULL;
	data = data;
}

Node::~Node() {

}

int Node::getData() {
	return data;
}

NodeInterface * Node::getLeftChild() {
	return left_child;
}

NodeInterface * Node::getRightChild() {
	return right_child;
}
