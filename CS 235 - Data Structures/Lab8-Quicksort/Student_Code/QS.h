/*
 * QS.h
 *
 *  Created on: Jun 15, 2015
 *      Author: mocklera
 */

#ifndef STUDENT_CODE_QS_H_
#define STUDENT_CODE_QS_H_

#include "QSInterface.h"

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
