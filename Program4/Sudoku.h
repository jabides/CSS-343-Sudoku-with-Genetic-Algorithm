/*	File:		Sudoku.h
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of Sudoku.h: This file contains the class definition of the Sudoku class. This class inherits from the puzzle interface
	to use the initialize() method and the display() method. This class also contains its own overloaded operator=() method for
	copying values from other sudoku objects. This class also contains a double int array, sudokuGrid, for holding the values
	of a sudoku puzzle, and a double bool array, fixed, for holding all fixed numbers. These data members are kept public for
	easy access.

*/
#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include "Puzzle.h"

class Sudoku : public Puzzle {
public:
	Sudoku();	//No-arg constructor

	//Overriden methods from Puzzle
	void initialize(std::ifstream&);
	void display() const;

	//Overloaded operator=()
	Sudoku& operator=(const Sudoku& rhs);

	int sudokuGrid[9][9];
	bool fixed[9][9];

};

#endif
