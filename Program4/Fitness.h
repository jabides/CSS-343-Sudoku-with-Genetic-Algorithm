/*	File:		Fitness.h
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of Fitness.h: This file contains the class definition of the Fitness interface. The Fitness interface is used for determining
	the fitenss of a puzzle, with 0 being the most fit. SudokuFitness is a subclass of the Fitness interface. This interface is used by
	the population interface for determining the most-fit puzzle.

*/
#ifndef FITNESS_H
#define FITNESS_H 
#include "Puzzle.h"

class Fitness {
public:
	virtual int howFit(const Puzzle&) const = 0;	//pure virtual function howFit(), returns the fitness number
};

#endif