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
	AVL();
	virtual ~AVL();
	virtual Node* getRootNode();
	virtual bool add(int data);
	virtual bool remove(int data);

private:
	Node* root;

	bool add_recursive(int data, Node*& current);
	bool remove_recursive(int data, Node*& current);
	// bool check_balance(Node*& node);
	bool inorder_predecessor(Node*& n1, Node*& n2);
	bool find(int data, Node*& current);
	void clear(Node*& node);

	// asdfasdf
	Node* rotate_right(Node* n);
	Node* rotate_left(Node* n);
	Node* balance(Node* n);
};

#endif /* STUDENT_CODE_AVL_H_ */
