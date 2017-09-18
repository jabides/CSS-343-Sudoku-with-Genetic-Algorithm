/*	File:		GeneticAlgorithm.cpp
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of GeneticAlgorithm.cpp: This file is the driver for the program. This genetic algorithm asks for two inputs, the initial
	population size, and the max number of generations. The algorithm will then read from a file that contains 81 numbers for a sudoku
	puzzle, and stores them into a Sudoku object. This Sudoku object is then stored into a constructing SudokuPopulation object, and 
	reproduces a generation based on the given Sudoku object. The algorithm will then iterate the number of times that it was given
	for the max number of generations, and will stop if a perfect solution was found. The program will also output the best fit
	sudoku puzzle and its fitness every generation, for only 10 times. The last generation's best sudoku puzzle is also outputted
	if the user asked for more than 10 generations. During each generation, the algorithm determines if the puzzle with the best
	fitness is 0. If so, the loop will break. If not, the best puzzle is outputted, the population culls the bottom 90% of the puzzles,
	and a new generation is created based off of the best puzzles from the previous generation.

	Assumptions:
	- The user will not input more than 10000 for the population. The population cap is 10000. If inputted more than said amount,
	  the input will only be 10000.

*/
#include "Sudoku.h"
#include "SudokuFactory.h"
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "Fitness.h"
#include "SudokuPopulation.h"
#include "SudokuFitness.h"
#include "Population.h"


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	
	//Asking for a population size and max generation number
	int size, num;
	cout << "Population size: ";
	cin >> size;
	cout << "Max number of generations: ";
	cin >> num;


	//Initializing the sudoku text file into the sudoku object
	Sudoku s;
	ifstream file("default.txt");
	s.initialize(file);

	//Inserting the sudoku object and population size into the newly constructed SudokuPopulation object
	SudokuPopulation population(size, s);
	file.close();
	
	//Initializing random seed
	srand(time(NULL));

	//Looping through each generation until max generation has been met or until a 0-fit sudoku puzzle has been met
	for (int i = 0; i < num; i++) {
		if (population.bestFitness() == 0) break;

		//For all generations below 10, output the best fit sudoku puzzle and its fitness rank
		if (i < 10) {
			cout << "Best fit of generation " << i + 1 << endl;
			population.bestIndividual().display();
			cout << "Fitness rank: " << population.bestFitness() << endl << endl;
		}


		//Cull the population and create a new generation
		population.cull();
		population.newGeneration(size);

	}

	//The best fit of the final generation and its fitness
	cout << "Best fit of final generation: " << endl;
	population.bestIndividual().display();
	cout << "Fitness rank: " << population.bestFitness() << endl;


	return 0;
	
}