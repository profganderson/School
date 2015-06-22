/*
 * QS.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: mocklera
 */

#include <sstream>
#include <iostream>
#include "QS.h"

void QS::sortAll() {
	sortAll_recursive(0, size - 1);
}

void QS::sortAll_recursive(int l, int r) {
	// If they are the same, no sorting to be done.
	if (l == r)
		return;
	// If it is within 3, then it will be sorted by the median of three bubble sort
	else if (l + 1 == r || l + 2 == r) {
		medianOfThree(l, r);
		return;
	}
	// Else, find the median, partition, and sort recursively.
	else {
		int mid = medianOfThree(l, r);
		mid = partition(l, r, mid);
		sortAll_recursive(l, mid - 1);
		sortAll_recursive(mid + 1, r);
	}
}

int QS::medianOfThree(int l, int r) {
	int mid;

	// Check for invalid inputs / cases
	if( arr == NULL ||
			l < 0 ||
			r > capacity - 1 ||
			l >= r) {
		mid = -1;
	}
	else {
		// 1. Calculate the middle index by averaging the given left and right indices
		mid = (l + r) / 2;

		// 2. Bubble-sorts the left, right, and middle
		while ( arr[l] > arr[mid] || arr[mid] > arr[r] || arr[l] > arr[r] ) {
			if ( arr[l] > arr[mid] ) {
				swap(l, mid);
			}
			else if ( arr[mid] > arr[r] ) {
				swap( mid, r );
			}
			else if ( arr[l] > arr[r] ) {
				swap( l, r );
			}
		}
	}

	return mid;
}

int QS::partition(int l, int r, int pivotIndex) {
	int up, down;

	// Check for invalid input / cases
	if (arr == NULL ||
			l < 0 ||
			r > size - 1 ||
			pivotIndex < l ||
			pivotIndex > r ||
			l >= r) {
		down = -1;
	}
	else {
		up = l + 1;
		down = r - 1;

		swap(pivotIndex, l);
		// walk through the array
		while(up < down) {
			while (arr[up] <= arr[l] && up <= r) {
				up++;
			}
			while (arr[down] > arr[l] && down >= l) {
				down--;
			}
			// Swap them as long as they haven't crossed
			if( down > up ) {
				swap(up, down);
			}
		}
		swap(l, down); // Do the last swap (after up and down have crossed)
	}

	// Down is the new middle
	return down;
}

string QS::getArray() {
	stringstream arr_string;
	if(arr == NULL) {
		arr_string << "";
	}
	else {
		// < size - 1 so the last value doesn't get a comma after it
		for (int i = 0; i < size - 1; i++) {
			arr_string << arr[i] << ",";
		}
		arr_string << arr[size - 1]; // Add the final element
	}

	return arr_string.str();
}

int QS::getSize() {
	return size;
}

void QS::addToArray(int value) {
	if (arr != NULL && size < capacity) {
		arr[size] = value;
		size++;
	}
}

bool QS::createArray(int capacity) {
	bool created;
	if (capacity < 0) {
		created = false;
	} else {
		if ( arr != NULL ) {
			clear();
		}
		arr = new int[capacity];
		this->capacity = capacity;
		created = true;
	}
	return created;
}

void QS::clear() {
	if (arr != NULL) {
		delete[] arr;
		arr = NULL;
		size = 0;
		capacity = 0;
	}
}

void QS::swap(int l, int r) {
	int old = arr[l];
	arr[l] = arr[r];
	arr[r] = old;
}