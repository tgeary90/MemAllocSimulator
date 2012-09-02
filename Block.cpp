/*
 * Block.cpp
 *
 *  Module: Algorithmics
 *  Coursework: 1
 *  Created on: 19 Feb 2011
 *  Modified: 23 Feb 2011
 *  Author: Tom Geary
 *
 *  Spec: Implements a Block class.
 *
 *  	  A Block of memory. Forms a unit in the MAL a double-linked
 *        of all memory assigned. Blocks may be allocated or deallocated.
 */

#include "Block.h"
#include <cstdlib>

Block::Block()
{
	previous = NULL ;
	next = NULL ;
}

Block::~Block()
{

}
