/*	File:		SudokuPopulation.cpp
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of SudokuPopulation.cpp: This file contains the class implementation of the SudokuPopulation class. SudokuPopulation is used
	to store a population of Sudoku objects and operate on them using the given methods from the Population interface. This class uses a
	vector for holding the sudoku objects. This class also contains a private helper quickSort method for sorting the vector of Sudoku objects.

	Assumptions: 
	- The size will not exceed more than 10000. If it does, it will be inputted as 10000. This is to prevent the program from running out
	  of memory.

*/
#include "SudokuPopulation.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"

/* SudokuPopulation constructor: This constructor takes a size and a Sudoku object. The populationSize of the SudokuPopulation object is
   updated to the given size and sudokuVector is then populated with offspring from the given Sudoku object. Finally, the sudokuVector
   is quick sorted.
   Precondition: The SudokuPopulation object needs to be populated and a size and Sudoku object are provided
   Postcondition: The sudokuVector has been populated with offspring based off of the given Sudoku object
*/
SudokuPopulation::SudokuPopulation(int size, const Sudoku& s) {
	if (size > 10000) {
		populationSize = 10000;
		size = 10000;
	}
	else populationSize = size;		//Set size
	
	sudokuVector.push_back(s);			//Initially adding the given sudoku object to the vector

	//Looping up to the given size, adding mutations from the given sudoku object, using a SudokuFactory object
	for (int i = 1; i < size; i++) {
		SudokuFactory tempFactory;
		Sudoku temp;
		sudokuVector.push_back((Sudoku&) tempFactory.createPuzzle(s, temp));
	}

	quickSort(0, populationSize - 1);
	
}

//------------------------------------------------------------------------------------------------------------------

/* cull() method: This method eliminates the bottom 90% percent of Sudoku puzzles in the sudokuVector, keeping the
   top 10% most fit sudoku puzzles. The method then pops off the 90% of the puzzles (the sudokuVector is already sorted).
   Precondition: The population needs to be culled.
   Postcondition: The population was culled down to the top 10% most fit (90% was removed).
*/
void SudokuPopulation::cull() {
	
	//If population is less than 10, the new size becomes 1. Otherwise, new size is population / 10
	int newSize = 1;
	if (populationSize / 10 > 0) newSize = populationSize / 10;

	//Removing bottom 90%
	for (int i = populationSize; i > newSize; i--) sudokuVector.pop_back();

	//populationSize is resized
	populationSize = newSize;
}

//------------------------------------------------------------------------------------------------------------------

/* bestFitness() method: This method finds the sudoku object with the best fitness and returns the fitness rank
   of that sudoku object. Because the sudokuVector is already sorted, this method just returns the fitness of the 0th
   sudoku object in the sudokuVector.
   Precondition: The fitness rank of the best sudoku puzzle in the current population needs to be viewed
   Postcondition: The fitness rank of the best sudoku puzzle has been returned
*/
int SudokuPopulation::bestFitness() const {
	if (populationSize == 0) return 0;				//If the population size is zero, return zero
	SudokuFitness tempFit;

	return tempFit.howFit(sudokuVector[0]);
}

//------------------------------------------------------------------------------------------------------------------

/* newGeneration() method: This method takes an integer n and populates a new sudokuVector by mutating each sudoku object
   in the current generation n times. These mutations are then stored into the new sudokuVector. Afterward, the old
   sudokuVector is emptied and is set to the new SudokuVector. Then population size becomes resized to the new amount.
   The population is then sorted to keep order.
   Precondition: A new generation needs to be formed
   Postcondition: A new generation is made
*/
void SudokuPopulation::newGeneration(int n) {
	vector<Sudoku> sudokuVector2;	//Dummy sudokuVector
	SudokuFactory tempFactory;	

	//Looping through each sudoku puzzle, mutating them n times. Each mutation is stored into sudokuVector2
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < populationSize;  j++) {
			//If size meets/breaks cap, break
			if (sudokuVector2.size() >= 10000) break;
			Sudoku temp;
			sudokuVector2.push_back((Sudoku&) tempFactory.createPuzzle(((Sudoku&) sudokuVector[j]), temp));

			
		}
	}

	//Empty old vector, set to new vector, and resize
	sudokuVector.empty();
	sudokuVector = sudokuVector2;
	populationSize = sudokuVector.size();

	quickSort(0, populationSize - 1);
}

//------------------------------------------------------------------------------------------------------------------

/* bestIndividual() method: This method looks for the most fit individual and returns that individual sudoku object.
   This method uses a similar process as the bestFitness() method. Since the sudokuVector is already sorted, this method
   just returns the vector at the 0th index.
   Precondition: The best individual of the current generation needs to be found and returned
   Postcondition: The best individual of the current generation has been found.
*/
const Puzzle& SudokuPopulation::bestIndividual() {

	SudokuFitness tempFit;

	return sudokuVector[0];
}

//------------------------------------------------------------------------------------------------------------------

/* quickSort() method: This method performs a quick sort on the sudokuVector. This method is recursive and uses the
   fitness of the sudoku objects for comparison.
   Precondition: The sudokuVector needs to be sorted.
   Postcondition: The sudokuVector has been sorted to most fit (closest to 0) to least fit
*/
void SudokuPopulation::quickSort(int left, int right) {
	SudokuFitness tempFit;
	int i = left, j = right;
	Sudoku temp;
	int pivot = tempFit.howFit(sudokuVector[(left + right) / 2]);

	while (i <= j) {
		while (tempFit.howFit(sudokuVector[i]) < pivot) i++;
		while (tempFit.howFit(sudokuVector[j]) > pivot) j--;
	
		if (i <= j) {
			temp = sudokuVector[i];
			sudokuVector[i] = sudokuVector[j];
			sudokuVector[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j) quickSort(left, j);
	if (i < right) quickSort(i, right);
}