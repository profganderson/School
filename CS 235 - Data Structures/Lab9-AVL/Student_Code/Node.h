/*
 * Node.h
 *
 *  Created on: Jun 18, 2015
 *      Author: mocklera
 */

#ifndef STUDENT_CODE_NODE_H_
#define STUDENT_CODE_NODE_H_

#include "NodeInterface.h"

class Node: public NodeInterface {
public:
	// Constructor and Destructor
	Node(int data) : data(data), left_child(NULL), right_child(NULL) {};
	virtual ~Node() {};

	// Inherited from NodeInterface
	virtual int getData() { return data; };
	virtual Node* getLeftChild() { return left_child; };
	virtual Node* getRightChild() { return right_child; };
	virtual int getHeight();

	// Utility Functions
	int get_max_height(Node* current);
	int get_balance();
	int max(int x, int y);

	// Data Members
	int data;
	Node* left_child;
	Node* right_child;
};

#endif /* STUDENT_CODE_NODE_H_ */
