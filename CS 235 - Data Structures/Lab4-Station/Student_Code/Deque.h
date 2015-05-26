/*
 *  Deque.h
 *  Andy Mockler
 *	CS 235 Spring 2015 Midterm
 */

#ifndef DEQUE_H_
#define DEQUE_H_
#include <iostream>
#include <stdexcept>

template<class T>
class Deque
{
public:
	Deque() : head(NULL), tail(NULL), length(0) {};
	virtual ~Deque(){ clear(); };

	void insert_left(T data) {
		// Create a new node "in front of" the head
		Node* insert = new Node(data, head, NULL);

		if (head != NULL)
			head->prev = insert;

		head = insert;
		if (tail == NULL)
			tail = insert;

		// Increment length
		length++;
	}

	void insert_right(T data) {
		Node* insert = new Node(data, NULL, tail);

		if (tail != NULL)
			tail->next = insert;

		tail = insert;
		if (head == NULL)
			head = insert;

		length++;
	}

	void remove_left() {
		if (head != NULL) {
			Node* temp = head;
			head = head->next;

			delete temp;
			temp = NULL;

			length--;
		}
	}

	void remove_right() {
		if (tail != NULL) {
			Node* temp = tail;

			tail = tail->prev;
			tail->next = NULL;

			delete temp;
			temp = NULL;

			length--;
		}
	}

	T peek_right() {
		return tail->data;
	}

	T peek_left() {
		return head->data;
	}

	int size() {
		return length;
	}

	bool empty() {
		if ( length == 0 )
			return true;
		else
			return false;
	}

	void clear() {
		Node* cur = head;
		Node* temp;

		while (cur != NULL)
		{
			temp = cur;
			cur = cur->next;
			delete temp;
			temp = NULL;
		}

		// Reset the list head
		head = NULL;
		tail = NULL;
		length = 0;
	}

	bool contains(T data) {
		bool contains = false;
		Node* temp = head;

		while (temp != NULL && contains == false)
		{
			if (temp->data == data)
				contains = true;
			temp = temp->next;
		}

		return contains;
	}

	void print() {
		if (length == 0) {
			std::cout << "There are no cars to display" << std::endl;
		}
		else {
			Node* temp = head;
			while (temp != NULL) {
				std::cout << temp->data << std::endl;
				temp = temp->next;
			}
		}
	}

private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;

		Node(); // Default Constructor
		Node(T data) : data(data), next(NULL), prev(NULL) {};
		Node(T data, Node* next, Node* prev) : data(data), next(next), prev(prev) {};
		virtual ~Node() {};
	};

	Node* head;
	Node* tail;
	int length;
};

#endif /* DEQUE_H_ */
