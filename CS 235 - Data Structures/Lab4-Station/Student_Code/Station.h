/*
 *  Station.h
 *  Andy Mockler
 *	CS 235 Spring 2015 Midterm
 */

#ifndef STATION_H_
#define STATION_H_

#include "StationInterface.h"
#include "StationInterfaceExtra.h"
#include "Deque.h"

class Station : public StationInterfaceExtra
{
public:
	Station() : current_car(NO_CAR) {};
	virtual ~Station(){};
	virtual bool addToStation(int car);
	virtual int showCurrentCar();
	virtual bool removeFromStation();
	virtual bool addToStack();
	virtual bool removeFromStack();
	virtual int showTopOfStack();
	virtual int showSizeOfStack();
	virtual bool addToQueue();
	virtual bool removeFromQueue();
	virtual int showTopOfQueue();
	virtual int showSizeOfQueue();
	virtual bool addToDequeLeft();
	virtual bool addToDequeRight();
	virtual bool removeFromDequeLeft();
	virtual bool removeFromDequeRight();
	virtual int showTopOfDequeLeft();
	virtual int showTopOfDequeRight();
	virtual int showSizeOfDeque();

	// Extra Credit
	virtual bool addToIRDequeLeft();
	virtual bool removeFromIRDequeLeft();
	virtual bool removeFromIRDequeRight();
	virtual int showTopOfIRDequeLeft();
	virtual int showTopOfIRDequeRight();
	virtual int showSizeOfIRDeque();
	virtual bool addToORDequeLeft();
	virtual bool addToORDequeRight();
	virtual bool removeFromORDequeLeft();
	virtual int showTopOfORDequeLeft();
	virtual int showSizeOfORDeque();

private:
	Deque<int> stack;
	Deque<int> queue;
	Deque<int> deque;
	Deque<int> irdeque;
	Deque<int> ordeque;
	const int NO_CAR = -1;
	int current_car;

	bool is_unique(int id);
};

#endif /* STATION_H_ */
