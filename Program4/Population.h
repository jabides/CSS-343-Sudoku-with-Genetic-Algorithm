/*	File:		Population.h
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of Population.h: This file contains the class definition of the Population interface. Population and its subclasses are
	used to contain puzzles and operate on them using certain methods, like cull() or newGeneration(). This interface itself does
	not contain any data members for holding the puzzles, so the subclasses are going to have to implement those instead.

*/
#ifndef POPULATION_H
#define POPULATION_H
#include "Fitness.h"
#include "Puzzle.h"
#include <list>

class Population {
public:
	
	//Pure virtual functions for operating on puzzles
	virtual void cull() = 0;
	virtual void newGeneration(int) = 0;
	virtual int bestFitness() const = 0;
	virtual const Puzzle& bestIndividual() = 0;

};


#endif