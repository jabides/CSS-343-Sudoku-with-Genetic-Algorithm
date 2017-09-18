/*	File:		SudokuPopulation.h
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of SudokuPopulation.h: This file contains the class definition of the SudokuPopulation class. SudokuPopulation is used
	to store a population of Sudoku objects and operate on them using the given methods from the Population interface. This class uses a
	vector for holding the sudoku objects. This class also contains a private helper quickSort method for sorting the vector of Sudoku objects.

	Assumptions:
	- The size will not exceed more than 10000. If it does, it will be inputted as 10000. This is to prevent the program from running out
	of memory.

*/
#ifndef SUDOKUPOPULATION_H
#define SUDOKUPOPULATION_H

#include "Population.h"
#include "Sudoku.h"
#include <vector>
using namespace std;

class SudokuPopulation : public Population {
public:
	SudokuPopulation(int, const Sudoku&);

	//Pure virtual methods overriden from the Population interface
	void cull();
	int bestFitness() const;
	void newGeneration(int);
	const Puzzle& bestIndividual();
	
	
private:
	void quickSort(int, int);		//Private quick sort method

	//Private data members
	int populationSize = 0;
	vector<Sudoku> sudokuVector;
};
#endif