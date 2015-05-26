#pragma once
#include <iostream>
#include <stdexcept>
#include "LinkedListInterface.h"

template<class T>
class LinkedList : public LinkedListInterface<T>
{
public:
	LinkedList() : head(NULL), length(0) {};
	virtual ~LinkedList(){clear();};


	virtual void insertHead(T value)
	{
		cout_helper("Insert Head");
		// If the list is empty, this will just create a node at the head and exit
		if (is_list_empty(value)) return;

		// Check for unique value
		bool unique = is_unique(value);

		// If it is unique, insert a new head
		if (unique) {
			// Create a new node that points to the head (the front of the list)
			Node * insert = new Node(value, head);
			// Set the head to be the new node
			head = insert;
			insert = NULL;
			length++;
		}
	}


	virtual void insertTail(T value)
	{
		cout_helper("Insert Tail");
		// If the list is empty, this will just create a node at the head and exit
		if (is_list_empty(value)) return;

		// Check for unique value
		bool unique = is_unique(value);

		// If unique, proceed
		if (unique) {
			// Find the end of the list
			Node* temp = head;
			Node* insert = new Node(value);
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			// Append a node to the end of the list
			temp->next = insert;
			temp = NULL;
			insert = NULL;
			length++;
		}
	}


	virtual void insertAfter(T value, T insertionNode) 
	{
		cout_helper("Insert After");
		bool unique = is_unique(value);
		bool exists = !is_unique(insertionNode);

		if (unique && exists) {
			Node * temp = head;
			while (temp->data != insertionNode) {
				temp = temp->next;
			}
			Node * insert = new Node(value, temp->next);
			temp->next = insert;
			temp = NULL;
			insert = NULL;
			length++;
		}
	}

	virtual void remove(T value)
	{
		cout_helper("Remove");
		// Use the "uniqueness" function to determine if the value exists. 
		bool exists = !(is_unique(value));

		if (exists) {
			Node * temp = head;
			// Check if we are deleting the head
			if (temp->data == value) {
				head = temp->next;
				delete temp;
			} else {
				// Get to the node before the one we're going to delete
				while (temp->next != NULL && temp->next->data != value) {
					temp = temp->next;
				}
				Node * curr = temp->next;
				if (curr == NULL)
					temp->next = NULL;
				else
					temp->next = curr->next;
				delete curr;
				temp = NULL;
				curr = NULL;
			}
			length--;
		}
	}


	virtual void clear()
	{
		if (head == NULL) return;
		cout_helper("Clear");
		Node * temp = head;
		Node * curr;

		while (temp->next != NULL)
		{
			curr = temp;
			temp = temp->next;
			delete curr;
		}
		delete temp;
		temp = NULL;
		curr = NULL;
		head = NULL;
		length = 0;
	}


	virtual T at(int index)
	{
		cout_helper("At");
		if (index < 0) {
			throw out_of_range("Index cannot be negative number.");
		} else if (index >= length) {
			throw out_of_range("Index is out of bounds.");
		} else if (head == NULL) {
			throw out_of_range("Cannot get index of empty list.");
		} else {
			Node* temp = head;
			for(int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			return temp->data;
		}
	}

	virtual int size()
	{
		cout_helper("Size");
		return this->length;
	}

private:
	struct Node
	{
		T data;
		Node* next;

		// Default constructor
		Node();

		// Constructor with data
		Node(T data) : data(data) { this->next = NULL; };

		// Constructor for full node
		Node(T data, Node* next) : data(data), next(next) {};

		virtual ~Node() {};
	};
	Node * head;
	int length;

	// Search through the linked list for duplicates. Returns true if found, false if not
	bool is_unique(T value)
	{
		cout_helper("Is Unique");
		bool is_unique = true;
		Node * temp = head;
		while (is_unique == true && temp != NULL) {
			if (value == temp->data)
			{
				is_unique = false;
			}
			temp = temp->next;
		}
		temp = NULL;
		return is_unique;
	}


	bool is_list_empty(T value) {
		cout_helper("Is List Empty");
		if (head == NULL) {
			head = new Node(value);
			length++;
			return true;
		} else {
			return false;
		}
	}


	void cout_helper(string func_name)
	{
		bool logging = false;
		if (logging) {
			cout << endl << func_name; // << "::: Current length is " << length;
		}
	}
};
