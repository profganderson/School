#pragma once

#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface
{
public:
	BST();
	virtual ~BST();
	virtual NodeInterface * getRootNode();
	virtual bool add(int data);
	virtual bool remove(int data);
	virtual void clear();
private:
	Node * root;
};