/*
 * QS.h
 *
 *  Created on: Jun 15, 2015
 *      Author: mocklera
 */

#ifndef STUDENT_CODE_QS_H_
#define STUDENT_CODE_QS_H_

#include "QSInterface.h"

/*
 * TODO: help session
 *
 * 	QUICKSORT
 *
 *		PARTITION
 * 		   Swap pivot and left
 * 		   Make two temporary vars (up and down)
 * 		   	compare the value of up with the pivot index value
 * 		   		while (up < down)
 * 		   			while (arr[up] <= arr[left])
 * 		   				up++
 * 		   			while(arr[down] > arr[left])
 * 		   				down--
 * 		   			swap up and down (unless they have crossed, then you handle outside the loop)
 * 		   		swap L and down (outside the loop)
 * 		   		return down
 * 		   Add extra conditions so you don't go past L and R. (down > L, up < R)
 *
 *		SORTALL
 *			Make a void sortall_recursive(int L, int R)
 *				if (l == r)
 *					return
 *				if (l + 1 == r)
 *					media of three(l, r)
 *					return
 *				if (l + 2 == r)
 *					median of three(l, r)
 *					return
 *				else
 *					int mid = median of three(l, r)
 *					mid = partition(l, r, mid)
 *					sortall_recursive(l, mid - 1)
 *					sortall_recursive(mid + 1, r)
 *
 *		SWAP
 *			you shouldn't use stdlib swap - write a swap function
 *				int old = arr[l];
 *				arr[l] = arr[r];
 *				arr[r] = old;
 *
 *		SORTALL
 *			Start with L = 0 and R = size-1 (NOT capacity)
 *			Then call recursive func
 *
 */

class QS: public QSInterface {
public:
	QS() { arr = NULL; size = 0; capacity = 0; };
	virtual ~QS() { clear(); };

	virtual void sortAll();
	virtual int medianOfThree(int left, int right);
	virtual int partition(int left, int right, int pivotIndex);
	virtual string getArray();
	virtual int getSize();
	virtual void addToArray(int value);
	virtual bool createArray(int capacity);
	virtual void clear();

private:
	void sortAll_recursive(int l, int r);
	void swap(int l, int r);
	int* arr;
	int size;
	int capacity;
};

#endif /* STUDENT_CODE_QS_H_ */
