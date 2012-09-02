/*
 * MAL.h
 *
 *  Module: Algorithmics
 *  Coursework: 1
 *  Created on: 19 Feb 2011
 *  Modified: 10 Mar 2011
 *  Author: Tom Geary
 *
 *  Spec: Declares a MAL (Memory Allocation List) class.
 *
 *  	The MAL is a double-linked list of all the Blocks of memory that have
 *  	been allocated or deallocated. It is managed by the BlockManager class.
 */

#pragma once
#include "Block.h"

class MAL
{

public:

	MAL();
	~MAL();

	Block* add( const int value, Block* afterBlock, char free, int BID ) ;
	Block* initializeMAL( int MEMORY_SIZE ) ;
	bool remove( Block* pRemovedBlock ) ;
	void print() ;

private:

	Block* head ;		// :)

friend class BlockManager ;

};

