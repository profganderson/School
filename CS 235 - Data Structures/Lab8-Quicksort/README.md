# Lab 8 - Quicksort

## Purpose
The purpose of this lab is to implement quicksort.

## Background
Quicksort is a sorting algorithm developed by Tony Hoare that, on average, makes O(n log n) comparisons to sort n items. It is also known as partition-exchange sort. In the worst case, it makes O(n^2) comparisons, though this behavior is rare. Quicksort is typically faster in practice than other O(n log n) algorithms. Additionally, quicksort's sequential and localized memory references work well with a cache. Quicksort can be implemented as an in-place partitioning algorithm,

## Requirements

##### Part 1 - Quick Sort Step by Step (20 points)
* The Test Driver will test your implementation of the QSInterface.h. To get credit for this part you must pass the first 5 tests. It will not test your implementation of the sortAll() function.

##### Part 2 - Your Quick Sort (18 points)
* This is the very last test of the test driver. It will test whether or not you are able to create your own recursive function using the medianOfThree() and partition() functions you already coded for the previous tests.

##### UML design document. (2 points)

## Notes
* No predefined data structures may be used for this lab; you must use an array.
* You are required to write a separate '.h' and '.cpp' for every class you implement.
