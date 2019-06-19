## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Compiling](#compiling)
* [Preview](#preview)
* [Author](#author)

## General info
 A multithreaded Sudoku Solution Checker program that accepts a Sudoku solution from the user as input,
 and determines whether the solution is valid or invalid.
 
 This sudoku solution checker is using 9 threads to check each subgrid and 2 threads to check each row and
 column.
 
 The program is also able to determine which row or column has an error and returns number.
	
## Technologies
Project is created with:
* XCode version: 10.2.1

## Compiling

To compile this software you must use a gcc terminal.
1. Open the bash terminal
2. To compile, $ g++ --std=c++11 -o run.out main.cpp
3. To run, ./run.out


## Preview

<img src="https://i.imgur.com/TuRBcve.png">


## Author

* Burak Can Ozter
* burak.ozter@dal.ca
	
