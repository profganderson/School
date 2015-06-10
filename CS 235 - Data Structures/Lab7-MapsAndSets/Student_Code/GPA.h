/*
 * GPA.h
 *
 *  Created on: Jun 10, 2015
 *      Author: mocklera
 */

#ifndef STUDENT_CODE_GPA_H_
#define STUDENT_CODE_GPA_H_

#include "GPAInterface.h"
#include "Student.h"

class GPA: public GPAInterface {
public:
	GPA(){};
	virtual ~GPA(){clear();};

	virtual map<unsigned long long int,StudentInterface*> getMap() { return student_map; };
	virtual set<StudentInterface*,Comparator> getSet() { return student_set; };
	virtual bool importStudents(string mapFileName, string setFileName);
	virtual bool importGrades(string fileName);
	virtual string querySet(string fileName);
	virtual string queryMap(string fileName);
	virtual void clear();

private:
	bool check_file_length(string file_name, int input_length);
	double convert_grade(string grade);
	unsigned long long int string_to_ulli(string str);

	map<unsigned long long int, StudentInterface*> student_map;
	set<StudentInterface*, Comparator> student_set;
};

#endif /* STUDENT_CODE_GPA_H_ */
