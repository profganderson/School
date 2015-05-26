/*
 *  Station.cpp
 *  Andy Mockler
 *	CS 235 Spring 2015 Midterm
 */

#include "Station.h"


///////////////////////////
//						 //
//   Station Operations  //
//						 //
///////////////////////////

bool Station::addToStation(int car) {
	cout << "Add to Station (" << car << ")" << endl;
	bool arrived;

	// Make sure there is not a car currently, the ID is greater than
	// one, and that the ID does not exist in any structure.
	if ( current_car == NO_CAR && car >= 0 && is_unique(car) ) {
		current_car = car;
		arrived = true;
	} else {
		arrived = false;
	}

	return arrived;
}

int Station::showCurrentCar() {
	cout << "Show current car" << endl;
	return current_car;
}

bool Station::removeFromStation() {
	cout << "Remove From Station" << endl;
	bool removed;

	if (current_car != NO_CAR) {
		current_car = NO_CAR;
		removed = true;
	}
	else {
		removed = false;
	}

	return removed;
}


////////////////////////////
//						  //
//    Stack Operations    //
//						  //
////////////////////////////
/*
 * Stacks will only use the "_left" operations of the Deque class.
 * 		i.e. goes in left and comes out left
 */

bool Station::addToStack() {
	cout << "Add to stack" << endl;
	bool added;

	if ( stack.size() >= 5 || current_car == NO_CAR ) {
		added = false;
	}
	else {
		stack.insert_left(current_car);
		current_car = NO_CAR;
		added = true;
	}

	return added;
}

bool Station::removeFromStack() {
	cout << "Remove from Stack" << endl;
	bool removed;

	if (stack.size() == 0 || current_car != NO_CAR)
		removed = false;
	else {
		int car = stack.peek_left();
		stack.remove_left();
		current_car = car;
		removed = true;
	}

	return removed;
}

int Station::showTopOfStack() {
	cout << "Show top of stack" << endl;
	int car;

	if (stack.size() == 0)
		car = NO_CAR;
	else
		car = stack.peek_left();

	return car;
}

int Station::showSizeOfStack() {
	cout << "Getting size of stack" << endl;
	return stack.size();
}


////////////////////////////
//						  //
//    Queue Operations    //
//						  //
////////////////////////////
/*
 * Queues use "_left" operations for insert and "_right" operations for remove
 * 		i.e. goes in left and comes out right
 */

bool Station::addToQueue() {
	cout << "Add to queue" << endl;
	bool added;

	if ( queue.size() >= 5 || current_car == NO_CAR )
		added = false;
	else {
		cout << "  Adding " << current_car << endl;
		queue.insert_left(current_car);
		current_car = NO_CAR;
		added = true;
	}

	return added;
}

bool Station::removeFromQueue(){
	cout << "Remove from queue" << endl;
	bool removed;

	if (queue.size() == 0 || current_car != NO_CAR)
		removed = false;
	else {
		int car = queue.peek_right();
		queue.remove_right();
		current_car = car;
		removed = true;
	}

	return removed;
}

int Station::showTopOfQueue(){
	cout << "Show top of queue";
	int car;

	if (queue.size() == 0) {
		car = NO_CAR;
		cout << endl;
	}
	else {
		car = queue.peek_right();
		cout << "(" << queue.peek_right() << ")" << endl;
	}
	return car;
}

int Station::showSizeOfQueue(){
	cout << "Show size of queue" << endl;
	return queue.size();
}


////////////////////////////
//						  //
//    Deque Operations    //
//						  //
////////////////////////////

bool Station::addToDequeLeft(){
	cout << "Add to deque left" << endl;
	bool added;

	if ( deque.size() >= 5 || current_car == NO_CAR )
		added = false;
	else {
		deque.insert_left(current_car);
		current_car = NO_CAR;
		added = true;
	}

	return added;
}

bool Station::addToDequeRight(){
	cout << "Add to deque right" << endl;
	bool added;

	if ( deque.size() >= 5 || current_car == NO_CAR )
		added = false;
	else {
		deque.insert_right(current_car);
		current_car = NO_CAR;
		added = true;
	}

	return added;
}

bool Station::removeFromDequeLeft(){
	cout << "Remove from deque left" << endl;
	bool removed;

	if (deque.size() == 0 || current_car != NO_CAR)
		removed = false;
	else {
		int car = deque.peek_left();
		deque.remove_left();
		current_car = car;
		removed = true;
	}

	return removed;
}

bool Station::removeFromDequeRight(){
	cout << "Remove from deque right" << endl;
	bool removed;

	if (deque.size() == 0 || current_car != NO_CAR)
		removed = false;
	else {
		int car = deque.peek_right();
		deque.remove_right();
		current_car = car;
		removed = true;
	}

	return removed;
}

int Station::showTopOfDequeLeft(){
	cout << "Show top of deque left" << endl;
	int car;

	if (deque.size() == 0)
		car = NO_CAR;
	else
		car = deque.peek_left();

	return car;
}

int Station::showTopOfDequeRight(){
	cout << "Show top of deque right" << endl;
	int car;

	if (deque.size() == 0)
		car = NO_CAR;
	else
		car = deque.peek_right();

	return car;
}

int Station::showSizeOfDeque(){
	cout << "show size of deque" << endl;
	return deque.size();
}


///////////////////////////
//					     //
//     EC Operations     //
//					     //
///////////////////////////

bool Station::addToIRDequeLeft() {
	cout << "Add to irdeque left" << endl;
	bool added;

	if ( irdeque.size() >= 5 || current_car == NO_CAR )
		added = false;
	else {
		irdeque.insert_left(current_car);
		current_car = NO_CAR;
		added = true;
	}

	return added;
}

bool Station::removeFromIRDequeLeft() {
	cout << "Remove from irdeque left" << endl;
	bool removed;

	if (irdeque.size() == 0 || current_car != NO_CAR)
		removed = false;
	else {
		int car = irdeque.peek_left();
		irdeque.remove_left();
		current_car = car;
		removed = true;
	}

	return removed;
}

bool Station::removeFromIRDequeRight() {
	cout << "Remove from irdeque right" << endl;
	bool removed;

	if (irdeque.size() == 0 || current_car != NO_CAR)
		removed = false;
	else {
		int car = irdeque.peek_right();
		irdeque.remove_right();
		current_car = car;
		removed = true;
	}

	return removed;
}

int Station::showTopOfIRDequeLeft(){
	cout << "Show top of irdeque left" << endl;
	int car;

	if (irdeque.size() == 0)
		car = NO_CAR;
	else
		car = irdeque.peek_left();

	return car;
}

int Station::showTopOfIRDequeRight(){
	cout << "Show top of irdeque right" << endl;
	int car;

	if (irdeque.size() == 0)
		car = NO_CAR;
	else
		car = irdeque.peek_right();

	return car;
}

int Station::showSizeOfIRDeque(){
	cout << "show size of irdeque" << endl;
	return irdeque.size();
}

bool Station::addToORDequeLeft() {
	cout << "Add to ordeque left" << endl;
	bool added;

	if ( ordeque.size() >= 5 || current_car == NO_CAR )
		added = false;
	else {
		ordeque.insert_left(current_car);
		current_car = NO_CAR;
		added = true;
	}

	return added;
}

bool Station::addToORDequeRight() {
	cout << "Add to ordeque right" << endl;
	bool added;

	if ( ordeque.size() >= 5 || current_car == NO_CAR )
		added = false;
	else {
		ordeque.insert_right(current_car);
		current_car = NO_CAR;
		added = true;
	}

	return added;
}

bool Station::removeFromORDequeLeft() {
	cout << "Remove from ordeque left" << endl;
	bool removed;

	if (ordeque.size() == 0 || current_car != NO_CAR)
		removed = false;
	else {
		int car = ordeque.peek_left();
		ordeque.remove_left();
		current_car = car;
		removed = true;
	}

	return removed;
}

int Station::showTopOfORDequeLeft(){
	cout << "Show top of ordeque left" << endl;
	int car;

	if (ordeque.size() == 0)
		car = NO_CAR;
	else
		car = ordeque.peek_left();

	return car;
}

int Station::showSizeOfORDeque(){
	cout << "show size of irdeque" << endl;
	return ordeque.size();
}

///////////////////////////
//						 //
//        Helpers        //
//						 //
///////////////////////////

// Is unique if contains = false
bool Station::is_unique(int id) {
	cout << "is unique" << endl;
	bool unique;

	// Check all three structures
	cout << "  stack contains(size " << stack.size() << ")" << endl;
	unique = !stack.contains(id);

	if (unique) {
		cout << "  queue contains (size " << queue.size() << ")" << endl;
		unique = !queue.contains(id);
	}

	if (unique) {
		cout << "  deque contains" << endl;
		unique = !deque.contains(id);
	}

	if (unique) {
		cout << "  IR deque contains" << endl;
		unique = !irdeque.contains(id);
	}

	if (unique) {
		cout << "  OR deque contains" << endl;
		unique = !ordeque.contains(id);
	}

	cout << "  checked all" << endl;

	return unique;
}
