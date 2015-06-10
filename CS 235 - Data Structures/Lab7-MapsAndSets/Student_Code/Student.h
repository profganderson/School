/*
 * Student.h
 *
 *  Created on: Jun 10, 2015
 *      Author: mocklera
 */

#ifndef STUDENT_CODE_STUDENT_H_
#define STUDENT_CODE_STUDENT_H_

#include "StudentInterface.h"

class Student: public StudentInterface {
public:
	Student(unsigned long long int id, string name, string address, string tel) : id(id), name(name), address(address), tel(tel) {
		total_gpa = 0.0;
		num_classes = 0.0;
	};
	virtual ~Student() {};

	virtual unsigned long long int getID();
	virtual string getName();
	virtual string getGPA();
	virtual void addGPA(double classGrade);
	virtual string toString();

private:
	unsigned long long int id;
	string name;
	string address;
	string tel;
	double total_gpa;
	double num_classes;
};

#endif /* STUDENT_CODE_STUDENT_H_ */
