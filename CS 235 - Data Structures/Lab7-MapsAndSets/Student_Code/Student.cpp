/*
 * Student.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: mocklera
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Student.h"

unsigned long long int Student::getID() {
	return id;
}

string Student::getName() {
	return name;
}

string Student::getGPA() {
	stringstream ss;
	double average_gpa;

	if ( num_classes == 0.0 )
		average_gpa = 0.0;
	else
		average_gpa = total_gpa / num_classes;

	ss << fixed << setprecision(2) << average_gpa;
	return ss.str();
}

void Student::addGPA(double classGrade) {
	total_gpa += classGrade;
	num_classes += 1;
}

string Student::toString() {
	stringstream stud;
	stud << this->id << "\n"
			<< this->name << "\n"
			<< this->address << "\n"
			<< this->tel << "\n"
			<< this->getGPA();

	return stud.str();
}