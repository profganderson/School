/*
 * AVL.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mocklera
 */

#include "AVL.h"

AVL::AVL() {
	root = NULL;
}

AVL::~AVL() {
	clear(root);
}

Node* AVL::getRootNode() {
	return root;
}

bool AVL::add(int data) {
	bool added;

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
		added = true;
	}
	else {
		if ( data < current->data )
			added = add_recursive(data, current->left_child);
		else
			added = add_recursive(data, current->right_child);
	}
	// Balance the tree
	balance(current);
	return added;
}

bool AVL::remove(int data) {
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
			return true;
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
			return true;
		}
		// Two children
		else if ( current->right_child != NULL && current->left_child != NULL ) {
			// Find the inorder predecessor and put it where the deleted node is.
				// Deleting, swapping, etc. happens within the inorder_predecessor function
			return inorder_predecessor(current, current->left_child);
		}
	}
	else { // Recurse
		if (data > current->data) {
			return remove_recursive(data, current->right_child);
		}
		else {
			return remove_recursive(data, current->left_child);
		}
	}
}

// bool AVL::check_balance(Node*& node) {
// 	bool balanced = true;
// 	if ( (node->right_height - node->left_height) > 1 || (node->right_height - node->left_height) < 1 )
// 		balanced = false;

// 	if (node->right_child != NULL)
// 		check_balance(node->right_child);

// 	if (node->left_child != NULL)
// 		check_balance(node->left_child);
// }

bool AVL::inorder_predecessor(Node*& n1, Node*& n2) {
	// If right == NULL, you have found the inorder predecessor
	if ( n2->right_child == NULL ) {
		n1->data = n2->data;
		Node* temp = n2;
		n2 = n2->left_child;
		delete temp;
		temp = NULL;
		return true;
	} else {
		inorder_predecessor(n1, n2->right_child);
	}
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




Node* AVL::rotate_right(Node* n) {
	Node* temp = n->left_child;
	n->left_child = temp->right_child;
	temp->right_child = n;
	n->set_height();
	temp->set_height();
	return temp;
}

Node* AVL::rotate_left(Node* n) {
	Node* temp = n->right_child;
	n->right_child = temp->left_child;
	temp->left_child = n;
	n->set_height();
	temp->set_height();
	return temp;
}

Node* AVL::balance(Node* n) {
	n->set_height();
	if (n->get_balance() == 2) {
		if ( n->right_child->get_balance() < 0 )
			n->right_child = rotate_right(n->right_child);
		return rotate_left(n);
	}
	
	if (n->get_balance() == -2) {
		if(n->left_child->get_balance() > 0)
			n->left_child = rotate_left(n->left_child);
		return rotate_right(n);
	}
	return n;
}



























