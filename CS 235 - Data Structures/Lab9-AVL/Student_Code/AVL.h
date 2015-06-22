/*
 * AVL.h
 *
 *  Created on: Jun 18, 2015
 *      Author: mocklera
 */

#ifndef STUDENT_CODE_AVL_H_
#define STUDENT_CODE_AVL_H_

#include "AVLInterface.h"
#include "Node.h"

class AVL: public AVLInterface {
public:
	// Constructor and Destructor
	AVL() : root(NULL) {};
	virtual ~AVL() { clear(root); };

	// Inherited from AVLInterface
	virtual Node* getRootNode() { return root; };
	virtual bool add(int data);
	virtual bool remove(int data);

private:
	Node* root;

	bool add_recursive(int data, Node*& current);
	bool remove_recursive(int data, Node*& current);
	bool inorder_predecessor(Node*& n1, Node*& n2);
	bool find(int data, Node*& current);
	void clear(Node*& node);
	void balance(Node*& n);
	void rotate_right(Node*& n);
	void rotate_left(Node*& n);
};

#endif /* STUDENT_CODE_AVL_H_ */