/*	File:		Puzzle.h
	Name:		JJ Abides
	Date:		March 13, 2017
	Professor:	Erika Parsons
	Course:		CSS 343
	Assignment: Program 4: O-O Techniques

	Purpose of Puzzle.h: This file contains the class definition for the Puzzle interface. This interface is used as a base for other puzzle
	classes and to allow them to initialize their puzzle using a file, and to be able to display their puzzle with a display function.

*/
#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>


class Puzzle {
public:
	//Pure virtual methods for I/O operations
	virtual void initialize(std::ifstream&) = 0;
	virtual void display() const = 0;
};
#endif
