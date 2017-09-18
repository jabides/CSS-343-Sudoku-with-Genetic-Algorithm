/*	File:		PuzzleFactory.h
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of PuzzleFactory.h: This file contains the class definition of the PuzzleFactory interface. This interface is used for the
	creation of concrete factories and is also used to help model the abstract factory design. For this project, the SudokuFactory is
	the only factory that uses the PuzzleFactory interface. This interface contains one method for the creation of puzzles.

*/
#ifndef PUZZLEFACTORY_H
#define PUZZLEFACTORY_H
#include "Puzzle.h"
#include "Reproduction.h"

class PuzzleFactory {
public:
	//Pure virtual function for the creation of puzzles
	virtual Puzzle& createPuzzle(const Puzzle&, Puzzle&) = 0;
};

#endif
