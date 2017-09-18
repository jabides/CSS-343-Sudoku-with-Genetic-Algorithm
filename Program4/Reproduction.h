/*	File:		Reproduction.h
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of Reproduction.h: This file contains the class definition for the Reproduction interface. This interface contains a single
	pure virtual method for making offspring. These offspring contain mutations that make them slightly different than their predecessors.
	The SudokuOffspring class uses this interface to make sudoku offspring.

*/
#ifndef REPRODUCTION_H
#define	REPRODUCTION_H

#include "Puzzle.h"

class Reproduction {
public:
	//pure virtual function for making offspring
	virtual Puzzle& makeOffspring(const Puzzle&, Puzzle&) const = 0;
};
#endif