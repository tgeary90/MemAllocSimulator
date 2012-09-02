/*
 * MAL.cpp
 *
 *  Module: Algorithmics
 *  Coursework: 1
 *  Created on: 19 Feb 2011
 *  Modified: 10 Mar 2011
 *  Author: Tom Geary
 *
 *  Spec: Implements a MAL (Memory Allocation List) class.
 *
 *  	The MAL is a double-linked list of all the Blocks of memory that have
 *  	been allocated or deallocated. It is managed by the BlockManager class.
 */

#include "BlockManager.h"
#include "MAL.h"
#include "Block.h"
#include <iostream>

using namespace std ;

MAL::MAL()
{
	head = NULL ;
}

MAL::~MAL()
{
	Block* p = head ;
	for ( ; p != NULL ; p = p->previous )
	{
		delete p ;
	}
}


Block* MAL::initializeMAL( int MEMORY_SIZE )
{
	Block* p = new Block() ;

	head = p ;

	p->memValue = MEMORY_SIZE ;
	p->isFree = 'y' ;

	return p ;
}


Block* MAL::add( const int size, Block* pb, char free, int BID )
{

/*	A new memory block is inserted after the largest free block in the MAL.
 * 	This process is driven by the Block Manager object and implemented
 * 	here, in the MAL...
 */

	Block* p = new Block() ;

	if ( pb->next == NULL  )
	{
		pb->next = p ;
		p->previous = pb ;
	}
	else
	{
		// insert block and hook up...

		p->next = pb->next ;
		p->previous = pb->next->previous ;
		pb->next = p ;
		p->next->previous = p ;

	}

	p->isFree = free ;
	p->memValue = size ;
	p->BID = BID ;

	pb->memValue = pb->memValue - size ;


	return p ;
}


bool MAL::remove( Block* pRemovedBlock )
{
	pRemovedBlock->isFree = 'y' ;
	return true ;
}


void MAL::print()
{
	// walk along MAL creating the memory map...

	Block* p = head ;
	const char TAB = '\t' ;

	cout << endl << "Here is the Memory Map:" << endl << endl ;
	for ( ; p != NULL ; p = p->next )
	{
		cout << "---------------" << endl ;
		cout << "BID: "
			 << p->BID
			 << endl
			 << "free: "
			 << p->isFree
			 << endl ;

		cout << p->memValue
			 << " B"
			 << endl ;

		cout << "---------------"

			 << endl
			 << endl ;
	}
}




































