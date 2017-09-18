/*	File:		SudokuOffspring.cpp
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of SudokuOffspring.cpp: This file contains the class implementation of the SudokuOffspring class. This class is used
	to make mutations of puzzles through the makeOffspring() method.

*/
#include "SudokuOffspring.h"
#include <stdlib.h>

/* makeOffspring() method: This method take a parent puzzle and dummy puzzle and copies values from the parent puzzle to the
   dummy puzzle. The dummy puzzle is then mutated and acts as the offspring of the parent puzzle. For every index in the array
   that is not a fixed number, there is a 5% chance that the value of that index will change into a random number. The offspring 
   is then returned once the mutation process is completed.
   Precondition: An offspring needs to be made from a puzzle.
   Postcondition: An offspring has been made, which is a mutated puzzle of the parent puzzle.
*/
Puzzle& SudokuOffspring::makeOffspring(const Puzzle& parent, Puzzle& offspring) const {
	(Sudoku&)offspring = (Sudoku&)parent;		//Copying values

	//Looping through each index, with a 5% chance of changing the value to a random number between 1 and 9
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (rand() % 100 <= 5 && ((Sudoku&)offspring).fixed[i][j] == false) {
				((Sudoku&)offspring).sudokuGrid[i][j] = (rand() % 9) + 1;
			}
		}
	}
	return offspring;
}