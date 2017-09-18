/*	File:		SudokuFactory.h
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of SudokuFactory.h: This file contains the class definition of the SudokuFactory class. This class inherits from the
	PuzzleFactory interface and must override the createPuzzle() method.

*/
#ifndef SUDOKUFACTORY_H
#define SUDOKUFACTORY_H
#include "PuzzleFactory.h"
#include "Puzzle.h"

class SudokuFactory : public PuzzleFactory {
public:
	//Overriden createPuzzle() method
	Puzzle& createPuzzle(const Puzzle&, Puzzle&);

};


#endif