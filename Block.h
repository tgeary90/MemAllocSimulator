/*
 *  Block.h
 *
 *  Module: Algorithmics
 *  Coursework: 1
 *  Created on: 19 Feb 2011
 *  Modified: 9 March 2011
 *  Author: Tom Geary
 *
 *  Spec: Declares a Block class.
 *
 *  	  A Block of memory. Forms a unit in the MAL a double-linked
 *        of all memory assigned. Blocks may be allocated or deallocated.
 */

#pragma once
using namespace std ;

class Block
{

public:

	Block();
	~Block();

private:

	Block* next ;
	Block* previous ;
	int memValue ;
	char isFree ;
	int BID ;

	friend class MAL ;
};


