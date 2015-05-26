/*
 *  Andy Mockler
 *	CS 235 Spring 2015 Midterm
 */

#pragma once

#include "Station.h"
#include <iostream>
#include <sstream>
#include <fstream>

int get_valid_int(int lower, int upper, string error_msg) {
	int num;
	cin >> num;

	while (cin.fail() || num < lower || num > upper) {
		cin.clear();
		cin.ignore(999999, '\n');
		cout << error_msg;
		cin >> num;
	}

	return num;
}

int menu() {
	cout << endl << "Please select and operation to perform:" << endl;
	cout << "  1. Import a train from a file" << endl;
	cout << "  2. Display the current train" << endl;
	cout << "  3. Store the first car of the train in the station" << endl;
	cout << "  4. Display the cars currently accessible in the station" << endl;
	cout << "  5. Add a car from the station to the current train" << endl;
	cout << "  6. Quit" << endl;
	cout << "Enter one of the choices above: ";

	int choice = get_valid_int(1, 6, "Please enter a number between 1 and 6: ");

	cout << endl;

	return choice;
}

int main() {
	Station* st = new Station();
	Station station = *st;
	Deque<int> train; // insert_right, remove_left
	int menu_choice = menu();

	while (menu_choice != 6) {
		if (menu_choice == 1) {
			// Import a train from a file
			cout << "Please enter a filename to read from: ";
			string filename;
			cin >> filename;

			ifstream input;
			input.open(filename.c_str());

			if(input.fail()) {
				input.clear();
				cout << "Bad filename." << endl;
			}
			else {
				int num_cars = 0;
				cout << "..." << endl;
				while(!input.eof()) {
					string line;
					getline(input, line);

					stringstream in;
					in << line;
					int num;
					in >> num;

					train.insert_right(num);
					num_cars++;
				}
				cout << "Imported " << num_cars << " cars." << endl;
			}
		}
		else if (menu_choice == 2) {
			// display the current train
			train.print();
		}
		else if (menu_choice == 3) {
			// store the first car of the train in the station
			cout << "Where would you like to store car " << train.peek_left() << "?" << endl;
			cout << "  1. Stack" << endl;
			cout << "  2. Queue" << endl;
			cout << "  3. Deque (Left)" << endl;
			cout << "  4. Deque (Right)" << endl;
			cout << "Enter your choice: ";
			int choice = get_valid_int(1, 4, "Please enter a number between 1 and 4: ");

			if (train.size() == 0) {
				cout << "No car to add" << endl;
			}
			else if ( choice == 1 ) {
				// Store in the stack
				if ( station.showSizeOfStack() >= 5 ) {
					cout << "The stack is already full." << endl;
				}
				else {
					if (station.addToStation(train.peek_left())) {
						if(station.addToStack()) {
							cout << "Success!" << endl;
							train.remove_left();
						}
						else {
							cout << "Failed to add the car to the stack" << endl;
							station.removeFromStation();
						}
					}
					else {
						cout << "Failed to add the car to the station." << endl;
					}
				}

			}
			else if (choice == 2) {
				// store in the queue
				if (station.showSizeOfQueue() >= 5) {
					cout << "The queue is already full." << endl;
				}
				else {
					if (station.addToStation(train.peek_left())) {
						if (station.addToQueue()) {
							cout << "Success!" << endl;
							train.remove_left();
						}
						else {
							cout << "Failed to add the car to the queue" << endl;
							station.removeFromStation();
						}
					}
					else {
						cout << "Failed to add the car to the station." << endl;
					}
				}
			}
			else if (choice == 3) {
				// store in deque left
				if (station.showSizeOfDeque() >= 5) {
					cout << "The deque is already full." << endl;
				}
				else {
					if (station.addToStation(train.peek_left())) {
						if (station.addToDequeLeft()) {
							cout << "Success!" << endl;
							train.remove_left();
						}
						else {
							cout << "Failed to add the car to the deque" << endl;
							station.removeFromStation();
						}
					}
					else {
						cout << "Failed to add the car to the station." << endl;
					}
				}
			}
			else if (choice == 4) {
				// store in deque right
				if (station.showSizeOfDeque() >= 5) {
					cout << "The deque is already full." << endl;
				}
				else {
					if (station.addToStation(train.peek_left())) {
						if (station.addToDequeRight()) {
							cout << "Success!" << endl;
							train.remove_left();
						}
						else {
							cout << "Failed to add the car to the deque" << endl;
							station.removeFromStation();
						}
					}
					else {
						cout << "Failed to add the car to the station." << endl;
					}
				}
			}
		}
		else if (menu_choice == 4) {
			// display the cars currently accessible in the station
			if (station.showSizeOfStack() == 0
					&& station.showSizeOfQueue() == 0
					&& station.showSizeOfDeque() == 0) {
				cout << "No cars in the stack, queue, or deque" << endl;
			}
			else {
				cout << "Accessible cars: " << endl;
				if ( station.showSizeOfStack() > 0 )
					cout << "  Car " << station.showTopOfStack() << " is at the top of the stack." << endl;
				if ( station.showSizeOfQueue() > 0 )
					cout << "  Car " << station.showTopOfQueue() << " is at the top of the queue." << endl;
				if ( station.showSizeOfDeque() == 1 )
					cout << "  Car " << station.showTopOfDequeLeft() << " is available at the right or left of the deque." << endl;
				if ( station.showSizeOfDeque() > 1 ) {
					cout << "  Car " << station.showTopOfDequeLeft() << " is available at the left of the deque." << endl;
					cout << "  Car " << station.showTopOfDequeRight() << " is available at the right of the deque." << endl;
				}
			}
		}
		else if (menu_choice == 5) {
			// add a car from the station to the current train
			cout << "Please enter the ID of a car to add to the current train: ";

			int id;
			cin >> id;
			if (cin.fail() || id < 0) {
				cin.clear();
				cin.ignore(999999, '\n');
				cout << "Invalid input." << endl;
			}
			else if ( station.showTopOfStack() == id ) {
				station.removeFromStack();
				station.removeFromStation();
				train.insert_left(id);
			}
			else if (station.showTopOfQueue() == id) {
				station.removeFromQueue();
				station.removeFromStation();
				train.insert_left(id);
			}
			else if (station.showTopOfDequeLeft() == id) {
				station.removeFromDequeLeft();
				station.removeFromStation();
				train.insert_left(id);
			}
			else if (station.showTopOfDequeRight() == id) {
				station.removeFromDequeRight();
				station.removeFromStation();
				train.insert_left(id);
			}
			else {
				cout << "The car is unreachable or does not exist." << endl;
			}
		}
		menu_choice = menu();
	}

	cout << "Choo Choo caio!" << endl << endl;

	return 0;
}
