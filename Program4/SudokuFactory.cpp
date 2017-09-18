/*	File:		SudokuFactory.cpp
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of SudokuFactory.cpp: This file contains the implementation of the SudokuFactory class.
*/

#include "SudokuFactory.h"
#include "SudokuOffspring.h"

/* createPuzzle() method: This method takes two puzzles and submits them into the makeOffspring() method from the
   SudokuOffspring class. This class then returns a mutation of the first sudoku puzzle, which is the 2nd sudoku puzzle
   that was inputted.
   Precondition: A puzzle needs to be created from another puzzle.
   Postcondition: The 2nd puzzle argument becomes a mutation of the first puzzle argument and is returned.
*/
Puzzle& SudokuFactory::createPuzzle(const Puzzle& sudoku, Puzzle& copy) {
	SudokuOffspring temp;
	return temp.makeOffspring((Sudoku&) sudoku, (Sudoku&) copy);
}