/*	File:		SudokuOffspring.h
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of SudokuOffspring.h: This file contains the class definition of the SudokuOffspring class. This class inherits from the
	Reproduction interface and overrides the makeOffspring() method. This class is used to make mutated sudoku puzzles (offspring) based
	on their parent puzzle.

*/
#ifndef SUDOKUOFFSPRING_H
#define SUDOKUOFFSPRING_H

#include "Reproduction.h"
#include "Sudoku.h"

class SudokuOffspring :public Reproduction {
public:
	//pure virtual makeOffspring() method from the Reproduction interface
	Puzzle& makeOffspring(const Puzzle&, Puzzle&) const;

};
#endif
