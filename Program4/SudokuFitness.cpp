/*	File:		SudokuFitness.cpp
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of SudokuFitness.cpp: This file contains the class implementation of the SudokuFitness class.

*/
#include "SudokuFitness.h"
#include <iostream>

/* howFit() method: This method was inherited and overriden by the Fitness interface. This method takes in a puzzle
   object and determines the "fitness" of that puzzle. The method does this by looping through each number and
   checking if it has duplicates in both its row and its column. The fitness count goes up for every duplicate and
   for every empty spot in the sudokuGrid. The method then returns the total number of errors in the sudoku puzzle.
   Precondition: The fitness of a sudoku puzzle needs to be determined.
   Postcondition: The fitness level of a sudoku puzzle has been determined.
*/
int SudokuFitness::howFit(const Puzzle& puzzle) const {

	int retVal = 0;				//Return value
	bool rowCompletion[10];		//bool array for keeping track of numbers in a row
	bool columnCompletion[10];	//bool array for keeping track of numbers in a column

	//Set all values to false
	for (int k = 0; k < 10; k++) {
		rowCompletion[k] = false;
		columnCompletion[k] = false;
	}

	//looping through every index
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			//+1 for every hole, +1 for every duplicate in a row, +1 for every duplicate in column
			if (((Sudoku&)puzzle).sudokuGrid[i][j] != 0) {
				if (rowCompletion[((Sudoku&)puzzle).sudokuGrid[i][j]] == false) {
					rowCompletion[((Sudoku&)puzzle).sudokuGrid[i][j]] = true;
				}
				else {
					retVal++;
				}

				if (columnCompletion[((Sudoku&)puzzle).sudokuGrid[j][i]] == false) {
					columnCompletion[((Sudoku&)puzzle).sudokuGrid[j][i]] = true;
				}
				else {
					retVal++;
				}
			}
			else retVal++;
		}

		//Set all values to false again
		for (int k = 0; k < 10; k++) {
			rowCompletion[k] = false;
			columnCompletion[k] = false;
		}
	}

	return retVal; //Return the fitness rank
}