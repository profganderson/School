# Lab 7 - Maps and Sets

## Purpose
To learn how to use the map and set data structures. Students will also learn how to overload a set's comparison operator.

## Background
A map data structure is a set of pairs. Each pair is composed of a key and a (mapped) value. Keys within a map must be unique (no duplicates). The( mapped) values may be duplicates.
A set often is stored as an ordered array. All elements in a set must be unique. To order elements in the representation of a set, the comparison operator must be overloaded. This is demonstrated in this lab in the "StudentInterface.h".

## Requirements
##### Part 1 - Import Students (9 points)
* Extend GPAInterface.h and StudentInterface.h, and pass the Import Students tests.
* Correctly read in a file and correctly store student information.

##### Part 2 - Import Grades (9 points)
* Extend GPAInterface.h and StudentInterface.h, and pass the Import Grades tests.
* Correctly read in a file and update the grades of students in the set.

##### Part 3 - Query (5 points)
* Extend GPAInterface.h and StudentInterface.h, and pass the Query tests.
* Correctly read in the query file and return the correct query response.

##### Part 4 - Pass Valgrind (5 points)
* Must pass all of the tests in order to receive credit for Part 4.

##### UML Design Document (2 points)

## Requirement Notes
* Use the predefined <set> and <map> classes in the C++ std library.
* Do NOT modify any of the files found in the "Files" folder.
* The best way to round your GPA is to use stringstream's precision() function. Look on cplusplus.com for more information and examples.
* You are required to write a separate '.h' and '.cpp' for every class you implement.
