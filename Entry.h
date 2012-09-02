/*
 * Entry.h
 *
 *  Module: Algorithmics
 *  Coursework: 1
 *  Created on: 19 Feb 2011
 *  Modified: 26 Feb 2011
 *  Author: Tom Geary
 *
 *  Spec: Declares a Entry structure.
 *
 *  	The Entry structure is the basic unit of block management. They are used to record block data.
 */

#pragma once
#include "Block.h"

struct Entry
{
	Entry( int itsBID, int itsSize, bool itsFree, Block* itsPBlock )
	 : BID(itsBID), size(itsSize), pBlock(itsPBlock), free(itsFree) {}

	int BID ;
	bool free ;
	int size ;
	Block* pBlock ;
};
