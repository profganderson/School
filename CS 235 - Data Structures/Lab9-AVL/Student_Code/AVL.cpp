/*
 * AVL.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mocklera
 */

#include "AVL.h"

bool AVL::add(int data) {
	bool added = false;

	// Create a new root if there isn't one
	if( root == NULL ) {
		root = new Node(data);
		added = true;
	}
	// Recursively add unless it is a duplicate
	else if ( !find(data, root) ) {
		add_recursive(data, root);
		added = true;
	}

	return added;
}

bool AVL::add_recursive(int data, Node*& current) {
	bool added;

	// If you are on NULL, insert there
	if (current == NULL) {
		current = new Node(data);
		added = true;
	}
	// Otherwise, traverse the tree until you find the correct NULL pointer
	else {
		if ( data < current->data ) {
			added = add_recursive(data, current->left_child);
		}
		else {
			added = add_recursive(data, current->right_child);
		}
		// Balance the tree as you come out of the recursion (start from leaves, move to root)
		balance(current);
	}
	return added;
}

bool AVL::remove(int data) {
	bool removed;

	// If the value exists, remove it recursively.
	// Otherwise, return false for a non-existent value
	removed = find(data, root) ? remove_recursive(data, root) : false;

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
		}
		else {
			removed = remove_recursive(data, current->left_child);
		}
	}

	// Balance the Nodes as you come out of the recursion
	// Wrapped in an if statement in case you are still on the node that was just deleted.
	if (current)
		balance(current);

	return removed;
}

bool AVL::inorder_predecessor(Node*& n1, Node*& n2) {
	bool removed;

	// If right == NULL, you have found the inorder predecessor; delete accordingly
	if ( n2->right_child == NULL ) {
		n1->data = n2->data;
		Node* temp = n2;
		n2 = n2->left_child;
		delete temp;
		temp = NULL;
		removed = true;
	}
	// If right != NULL, keep traversing until you find it
	else {
		removed = inorder_predecessor(n1, n2->right_child);
	}

	// Balance the tree as you come out of the recursion. Wrapped in if in case the node was just deleted.
	if (n2)
		balance(n2);

	return removed;
}

bool AVL::find(int data, Node*& current) {
	bool found;

	// If you've reached the end of the tree and not found it, it doesn't exist
	if (current == NULL) {
		found = false;
	}
	// Return true if found
	else if (current->data == data) {
		found = true;
	}
	// Otherwise, continue through the tree recursively
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
	// Delete from the bottom up
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
	int balance = n->get_balance();

	// Right unbalanced
	if (balance == 2) {
		// Check for Right-Left
		if(n->right_child->get_balance() < 0)
			rotate_right(n->right_child);
		rotate_left(n);
	}

	// Left unbalanced
	if (balance == -2) {
		//  Check for Left-Right
		if(n->left_child->get_balance() > 0)
			rotate_left(n->left_child);
		rotate_right(n);
	}
}

void AVL::rotate_right(Node*& n) {
	Node* temp = n->left_child;
	n->left_child = temp->right_child;
	temp->right_child = n;
	n = temp;
}

void AVL::rotate_left(Node*& n) {
	Node* temp = n->right_child;
	n->right_child = temp->left_child;
	temp->left_child = n;
	n = temp;
}



























