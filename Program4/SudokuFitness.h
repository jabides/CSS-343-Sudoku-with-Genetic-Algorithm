/*	File:		SudokuFitness.h
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of SudokuFitness.h: This file contains the class definition of the SudokuFitness class. This class inherits from the Fitness
	interface and overrides the howFit() method. This class is used to check the fitness rank of Sudoku objects.

*/
#ifndef SUDOKUFITNESS_H
#define SUDOKUFTINESS_H

#include "Fitness.h"
#include "Sudoku.h"

class SudokuFitness : public Fitness {
public: 

	//pure virtual howFit() method from Fitness interface
	int howFit(const Puzzle&) const;

};

#endif