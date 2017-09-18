/*	File:		Sudoku.cpp
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of Sudoku.cpp: This file contains the implementation of the Sudoku class. This class implements the Sudoku constructor,
	initialize() method, display() method, and operator=() method. These methods operate on the sudokuGrid and fixed[][] boolean array.
	Descriptions of each method is explained below.

	Assumptions:
	- All submitted files have a complete set of 81 numbers
*/
#include "Sudoku.h"
#include <fstream>
using namespace std;

/* Sudoku constructor: This constructor initializes the fixed double-boolean array to all false values, and sets all values in the
   sudokuGrid int array to 0.
   Preconditions: None
   Postcondition: A Sudoku object is made with all of its boolean array values set to false and all of its integer array values set to 0
*/
Sudoku::Sudoku() {

	//Two loops for row and column
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			fixed[i][j] = false;
			sudokuGrid[i][j] = 0;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------------

/* initialize() method: This method takes numbers from a file and initializes the sudokuGrid to those values. It is assumed that all
   files have a complete set of 81 numbers to submit into the sudokuGrid. The method first loops through each character until the end
   of the file has been met, or until all the values in the sudokuGrid have been filled. If a value is non-zero, the fixed array is
   updated. This method also checks for boundaries.
   Preconditions: The sudokuGrid needs to be filled and an appropriate file has been provided
   Postconditions: The sudokuGrid has been filled with numbers from the given file
*/
void Sudoku::initialize(ifstream& file) {
	//variables for holding the character and index numbers
	char c;
	int i = 0, j = 0;

	//Loop until end of file
	while (!file.eof()) {

		c = file.get();

		//If the number is in range
		if (c - '0' >= 0 && c -'0' <= 9) {

			//If the number is non-zero
			if (c - '0' != 0) fixed[i][j] = true;

			sudokuGrid[i][j] = c - '0';
			j++;

			if (j == 9) {
				j = 0;
				i++;
			}

			//break if last index has been filled
			if (i == 9) break;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------------

/* display() method: This method displays the sudoku grid to the console screen.
   Preconditions: None
   Postcondition: The sudoku grid has been displayed to the console screen
*/
void Sudoku::display() const {
	
	for (int i = 0; i < 9; i++) {
		if (i == 0 || i == 3 || i == 6) cout << "+-------+-------+-------+" << endl;

		for (int j = 0; j < 9; j++) {
			if (j == 0 || j == 3 || j == 6) cout << "| ";
			if (sudokuGrid[i][j] == 0) cout << "  ";
			else cout << sudokuGrid[i][j] << " ";
			if (j == 8) cout << "|" << endl; //Ending pipe, next line
		}
	}

	cout << "+-------+-------+-------+" << endl;
}

//------------------------------------------------------------------------------------------------------------------------------------

/* Overloaded operator=(): This overloaded operator is used for copying values from one sudoku object to another. This is used a lot
   in the newGeneration() method in the SudokuPopulation class. This method simply takes all of the values in one sudoku's sudokuGrid
   and fixed array, and copies them to the other sudoku's sudokuGrid and fixed array. Once finished, the method returns the object itself.
   Preconditions: A Sudoku object needs to copy values from another Sudoku object.
   Postcondition: A Sudoku object has copied values from another Sudoku object.
*/
Sudoku& Sudoku::operator=(const Sudoku& rhs) {
	if (&rhs != this) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				sudokuGrid[i][j] = rhs.sudokuGrid[i][j];
				fixed[i][j] = rhs.fixed[i][j];
			}
		}
	}
	return *this;
}