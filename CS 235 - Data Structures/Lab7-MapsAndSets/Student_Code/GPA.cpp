/*
 * GPA.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: mocklera
 */

#include <sstream>
#include <fstream>
#include "GPA.h"

bool GPA::importStudents(string mapFileName, string setFileName) {
	bool imported = true; // Will be set to false if there is an error

	// Open the set and map files
	fstream set_file;
	fstream map_file;
	set_file.open(setFileName.c_str());
	map_file.open(mapFileName.c_str());

	// Check for invalid filenames
	if (set_file.fail() || map_file.fail()) {
		imported = false;
	}
	// Make sure both files are the right length
	else if (check_file_length(mapFileName, 4) && check_file_length(setFileName, 4)) {
		string id, name, address, phone;
		unsigned long long int id_as_ulli;

		// Import the map file
		while (getline(map_file, id) &&
				getline(map_file, name) &&
				getline(map_file, address) &&
				getline(map_file, phone) ) {
			id_as_ulli = string_to_ulli(id);
			student_map[id_as_ulli] = new Student(id_as_ulli, name, address, phone);
		}

		// Import the set file
		while (getline(set_file, id) &&
				getline(set_file, name) &&
				getline(set_file, address) &&
				getline(set_file, phone) ) {
			id_as_ulli = string_to_ulli(id);
			student_set.insert( new Student(id_as_ulli, name, address, phone) );
		}

	}
	else {
		imported = false;
	}

	set_file.close();
	map_file.close();
	return imported;
}

bool GPA::importGrades(string fileName) {
	bool imported = false;

	fstream grade_file;
	grade_file.open(fileName.c_str());

	// if the file exists
	if( !grade_file.fail() ) {
		// Check the file length
		if (check_file_length(fileName, 3)) {

			// Read in 1 grade/id/class
			string id, class_name, grade;
			while( getline(grade_file, id) &&
					getline(grade_file, class_name) &&
					getline(grade_file, grade)) {

				// Convert the grade and id
				double grade_as_double = convert_grade(grade);
				unsigned long long int id_as_ulli = string_to_ulli(id);

				// Check for the student in the map
				for ( pair<unsigned long long int,StudentInterface*> student : student_map ) {
					if (student.first == id_as_ulli) {
						student.second->addGPA(grade_as_double);
						imported = true;
					}
				}

				// Check for the student in the set
				for ( StudentInterface* student : student_set ) {
					if (student->getID() == id_as_ulli ) {
						student->addGPA(grade_as_double);
						imported = true;
					}
				}
			}
		}
	}

	return imported;
}

string GPA::querySet(string fileName) {
	stringstream output;
	fstream file;
	file.open(fileName.c_str());

	// Check if file exists
	if(!file.fail()) {
		string id;
		while( getline(file, id) ) {
			unsigned long long int ulli_id = string_to_ulli(id);
			// Check the set
			for ( StudentInterface* student : student_set ) {
				if ( ulli_id == student->getID() ) {
					output << ulli_id << " " << student->getGPA() << " " << student->getName() << "\n";
				}
			}
		}
	}

	return output.str();
}

string GPA::queryMap(string fileName) {
	stringstream output;
	fstream file;
	file.open(fileName.c_str());

	if(!file.fail()) {
		string id;
		while( getline(file, id) ) {
			unsigned long long int ulli_id = string_to_ulli(id);
			// Check the map
			for ( pair<unsigned long long int,StudentInterface*> student: student_map ) {
				if ( ulli_id == student.first ) {
					output << ulli_id << " " << student.second->getGPA() << " " << student.second->getName() << "\n";
				}
			}
		}
	}

	return output.str();
}

void GPA::clear() {
	for ( StudentInterface* student : student_set ) {
		delete student;
	}
	student_set.clear();

	for ( pair<unsigned long long int, StudentInterface*> student : student_map ) {
		delete student.second;
	}
	student_map.clear();
}

bool GPA::check_file_length(string file_name, int input_length) {
	fstream fs;
	fs.open(file_name.c_str());
	int length = 0;
	string temp;

	while( getline(fs, temp) ) {
		length++;
	}

	fs.close();
	return (length % input_length == 0);
}

unsigned long long int GPA::string_to_ulli(string str) {
	unsigned long long int ulli;
	stringstream convert( str );
	convert >> ulli;
	return ulli;
}

double GPA::convert_grade(string grade) {
	double g;

	if ( grade == "A" )
		g = 4.0;
	else if ( grade == "A-" )
		g = 3.7;
	else if ( grade == "B+" )
		g = 3.4;
	else if ( grade == "B" )
		g = 3.0;
	else if ( grade == "B-" )
		g = 2.7;
	else if ( grade == "C+" )
		g = 2.4;
	else if ( grade == "C" )
		g = 2.0;
	else if ( grade == "C-" )
		g = 1.7;
	else if ( grade == "D+" )
		g = 1.4;
	else if ( grade == "D" )
		g = 1.0;
	else if ( grade == "D-" )
		g = 0.7;
	else
		g = 0.0;

	return g;
}
