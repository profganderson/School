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

/*
 * TODO: [[help session]]
 *
 ** DATA STRUCTURES------------------------------------------------
 * 		map<unsigned long long int,StudentInterface*>
 * 			set of pairs (pair<key,value>)
 * 			for this, it will be <ID, StudentInterface*>
 * 		set<StudentInterface*,Comparator>
 * 			^^^^^value^^^^^^ ,^^^order^^^
 * 		struct Comparator (just sorts alphabetically by name)
 ** ---------------------------------------------------------------
 *
 ** FOR EACH LOOPS-------------------------------------------------
 * 	 	[[ Sets ]]
 * 		for(StudentInterface* student : mySet) {
 * 			if( si->getID() == cool_id )
 * 				return true;
 * 		}
 *
 * 		OR
 *
 * 		[[ maps ]]
 * 		for (pair<unsigned long long int; SI*> p : myMap) {
 * 			if(p.second->getID() == cool_id)
 * 				return true
 * 		}
 ** ---------------------------------------------------------------
 *
 ** IMPORT STUDENTS------------------------------------------------
 *		You will have a set and a map in your GPA.h
 *		Students have name, address, phone, ID, GPA (better to do total_GPA and total_classes)
 *
 *		File format:
 *			ID #
 *			Name
 *			Address
 *			Phone #
 *		GPA and total classes should always start at 0
 *
 *		CHECKING FOR INVALID FILES
 *			They give 2 arguments: a set filename and a map filename
 *			Make sure you check the set AND the map before adding anything anywhere
 *				Just do it by checking the number of lines in the file - if something is missing, then there wont be the right number of lines.
 *					fstream fs;
 *					fs.open(mapfile);
 *					string temp;
 *					int lines;
 *					while (getline(fs, temp))
 *						lines++;
 *					if (numlines % 4 == 0)
 *
 *		INSERTING
 *			set.insert(new Student(...));
 *			mymap[ID] = new Student(...);
 *
 *		!!!MAKE SURE YOU CLOSE THE FILE BETWEEN!!!
 *
 ** ---------------------------------------------------------------
 *
 ** IMPORT GRADES--------------------------------------------------
 *
 *		File format:
 *			Student ID				123654789
 *			Class					REL A 327
 *			Grade					B-
 *
 *		First, locate the student with that ID in the map OR the set
 *			Best way to search is using a for each loop
 *
 *		ROUNDING
 *			Student has a double total_gpa data member. The total sum of all of the grades they have.
 *			Have another called total_classes (just an int - don't need to store the class info)
 *			Then, to calculate the GPA (getGPA()), do total_gpa / total_classes.
 *			Then, to spit it out with just 2 decimal places...
 *				stringstream ss;
 *				ss << fixed << setprecision(2) << average_gpa;
 *				return ss.str();
 *
 *		So, if you find the student, add the GPA, increment total classes.
 *
 *		FOR EACH LOOP!
 *		ulli ID = 5234905823045;
 *		for(pair<unsigned long long int, StudentInterface*> p : myMap)	{					// also, for(auto a : myMap) works!
 *			if (p.first == ID) {
 *				p.second->addGPA(grade);
 *			}
 *		}
 ** ---------------------------------------------------------------
 *
 ** QUERYSET/QUERYMAP----------------------------------------------
 *
 *		Just go through the string and the map and see if you find the student. If you do, call toString();
 *		Don't have to check for valid files or anything here
 *
 ** ---------------------------------------------------------------
 *
 ** CLEAR----------------------------------------------------------
 *
 *		You just have to delete students.
 *			Use a for each loop...
 *				for ( auto a : mySet ) {
 *					delete a;
 *				}
 *		then just do mymap.clear() and myset.clear()
 *
 *		Make sure you put clear() in your destructor.
 *
 ** ---------------------------------------------------------------
 */

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
	map<unsigned long long int, StudentInterface*> student_map;
	set<StudentInterface*, Comparator> student_set;
	bool check_file_length(string file_name, int input_length);
	double convert_grade(string grade);
	unsigned long long int string_to_ulli(string str);
};

#endif /* STUDENT_CODE_GPA_H_ */
