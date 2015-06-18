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
	int data;
	int height;
	Node* left_child;
	Node* right_child;

	Node(int data);
	virtual ~Node() {};
	virtual int getData();
	virtual Node* getLeftChild();
	virtual Node* getRightChild();
	virtual int getHeight();

	int get_max_height(Node* current);
	int get_balance();
};

#endif /* STUDENT_CODE_NODE_H_ */
