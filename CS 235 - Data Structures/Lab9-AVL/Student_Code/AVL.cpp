/*
 * AVL.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mocklera
 */

#include <iostream>
#include "AVL.h"

AVL::AVL() {
	cout << "===AVL Constructor" << endl;
	root = NULL;
}

AVL::~AVL() {
	cout << "===AVL Destructor" << endl;
	clear(root);
}

Node* AVL::getRootNode() {
	cout << "===AVL Get Root Node";

	if (root)
		cout << "(" << root->data << ")";

	cout << endl;
	return root;
}

bool AVL::add(int data) {
	cout << "===AVL Add " << data << endl;
	bool added = false;

	if( root == NULL ) {
		root = new Node(data);
		added = true;
	}
	else if ( !find(data, root) ) {
		add_recursive(data, root);
		added = true;
	}

	return added;
}

bool AVL::add_recursive(int data, Node*& current) {
	bool added;
	if (current == NULL) {
		current = new Node(data);
		height_changed = true;
		added = true;
	}
	else {
		if ( data < current->data ) {
			added = add_recursive(data, current->left_child);
            balance(current);
		}
		else {
			added = add_recursive(data, current->right_child);
            balance(current);
		}
	}
	return added;
}

bool AVL::remove(int data) {
	cout << "===AVL Remove " << data << endl;
	bool removed;

	if ( find(data, root) ) {
		removed = remove_recursive(data, root);
	}
	else {
		removed = false;
	}

	return removed;
}

bool AVL::remove_recursive(int data, Node*& current) {
	bool removed;
	// Once you've arrived to the correct node, delete the node
	if ( data == current->data ) {
		// No children
		if ( current->right_child == NULL && current->left_child == NULL ) {
			delete current;
			current = NULL;
			removed = true;
		}
		// One child
		else if ( (current->right_child == NULL && current->left_child != NULL)
			   || (current->left_child == NULL && current->right_child != NULL)) {
			Node * temp = current;

			// Move up the existing child node
			if (current->left_child == NULL)
				current = current->right_child;
			else
				current = current->left_child;

			delete temp;
			temp = NULL;
			removed = true;
		}
		// Two children
		else if ( current->right_child != NULL && current->left_child != NULL ) {
			// Find the inorder predecessor and put it where the deleted node is.
				// Deleting, swapping, etc. happens within the inorder_predecessor function
			removed = inorder_predecessor(current, current->left_child);
		}
	}
	else { // Recurse
		if (data > current->data) {
			removed = remove_recursive(data, current->right_child);
			//balance(current);
		}
		else {
			removed = remove_recursive(data, current->left_child);
			//balance(current);
		}
	}

	if (current)
		balance(current);

	return removed;
}

bool AVL::inorder_predecessor(Node*& n1, Node*& n2) {
	// If right == NULL, you have found the inorder predecessor
	//cout << "Inorder predecessor" << endl;
	bool removed;
	if ( n2->right_child == NULL ) {
		cout << "     n1->data = " << n1->data << "; n2->data = " << n2->data << endl;
		n1->data = n2->data;
		Node* temp = n2;
		n2 = n2->left_child;
		delete temp;
		temp = NULL;
		cout << "   Removed the inorder predecessor" << endl;
		removed = true;
	} else {
		cout << "          Moving right...." << endl;
		removed = inorder_predecessor(n1, n2->right_child);
		balance(n2);
	}
	return removed;
}

bool AVL::find(int data, Node*& current) {
	bool found;

	if (current == NULL) {
		found = false;
	}
	else if (current->data == data) {
		found = true;
	}
	else {
		if ( data > current->data ) {
			found = find(data, current->right_child);
		}
		else {
			found = find(data, current->left_child);
		}
	}

	return found;
}

void AVL::clear(Node*& node) {
	if ( root != NULL ) {
		if ( node->left_child != NULL )
			clear(node->left_child);

		if ( node->right_child != NULL )
			clear(node->right_child);

		delete node;
		node = NULL;
	}
}

void AVL::balance(Node*& n) {
	cout << "         Balancing node " << n->data << "..." << endl;
	int balance = n->get_balance();
	cout << "            " << balance << endl;
	if (balance == 2) {
		cout << "         Balance == 2" << endl;
		if(n->right_child->get_balance() < 0) {
			rotate_right(n->right_child);
		}
		rotate_left(n);
	}

	if (balance == -2) {
		cout << "         Balance == -2" << endl;
		if(n->left_child->get_balance() > 0)
			rotate_left(n->left_child);
		rotate_right(n);
	}
}

void AVL::rotate_right(Node*& n) {
	cout << "      Rotate Right" << endl;
	Node* temp = n->left_child;
	n->left_child = temp->right_child;
	temp->right_child = n;
	n = temp;
}

void AVL::rotate_left(Node*& n) {
	cout << "      Rotate Left" << endl;
	Node* temp = n->right_child;
	n->right_child = temp->left_child;
	temp->left_child = n;
	n = temp;
}



























