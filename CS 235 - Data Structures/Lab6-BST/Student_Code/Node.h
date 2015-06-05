#pragma once

#include "NodeInterface.h"

class Node : public NodeInterface
{
public:
	Node (int data);
	virtual ~Node ();
	virtual int getData();
	virtual NodeInterface * getLeftChild();
	virtual NodeInterface * getRightChild();
private:
	Node * left_child;
	Node * right_child;
	int data;
};
