# Lab 5 - 3D Maze

## Purpose
This lab will help you gain experience with recursion so that you are more comfortable using this powerful tool.

## Background
Two SCUBA diving buddies have encountered a large, box-shaped storage facility inside the hull of the Heian Maru, a 512' submarine tender lying on the bottom of Truk Lagoon at 108'. The storage facility is composed of 10' x 10' x 10' cells, some of which can be entered and some which cannot. The only exterior walls that are missing are on the front of the storage facility in the upper left corner, and on the rear of the storage facility in the lower right corner. The divers wish to determine a path through the storage facility.

## Requirements

##### Part 1 - Make Your Maze (5 points)
* Generate a 3D maze (the storage facility) that measures 50' x 50' x 50' (5 levels with 25 cells on each level, a total of 125 cells) and write it to a string in the format described below.
* To indicate whether one cell can be accessed from an adjacent cell, randomly place roughly equiprobable 1s and 0s in each cell of the maze, except for the cell in the bottom level, first row, and first column which contains a 1 (entry point), and the cell in the highest level, last row, and last column which also contains a 1 (exit point).

##### Part 2 - Import Mazes (5 points)
* Accept a file name from the test driver and read a maze from that file in the indicated format.
* Invalid mazes (e.g. bad tokens, not enough 1's and 0's) in the files should be rejected.

##### Part 3 - Solve Yours (9) and Ours (9) (18 points)
* Have your program attempt to recursively traverse the current maze to find a valid path.
* A valid path is one which starts at the entrance (0, 0, 0) and ends at the exit (4, 4, 4) and does not contain any cycles. When moving between cells, the divers can only move up, down, left, right, forward, and backwards one cell at a time. No diagonals are allowed.

##### UML design document. (2 points)

## Requirement Notes
* You are required to write a seperate '.h' and '.cpp' for every class you implement.
* Strictly follow the formats explained in the interface provided. If not, your generated mazes and paths will not work with the test program we will use and your program will not work with the mazes we will use for Part 3. If there are problems with your lab due to format, you will not be able to pass off until the problems are resolved.
* There will be a 5 point deduction from your overall score if there are any debugging statements left in the code when the TA passes you off.
* A common but flawed approach with this assignment can cause the test driver to run for upwards of 20 minutes.  Since neither you nor the TAs have time to wait this long, you will need to resolve this issue if it arises.  Please refer to this powerpoint to understand the issue and possible solutions
* For the createRandomMaze() to correctly generate random numbers, #include <cstdlib> and use rand().
* The format of the Maze Files are as follows: each colomn and row of the first 2D layer correspond to the x and y dimensions, respectively. The layers of 2D arrays correspond to the z dimension.
