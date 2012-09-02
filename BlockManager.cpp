/*
 * BlockManager.cpp
 *
 *  Module: Algorithmics
 *  Coursework: 1
 *  Created on: 19 Feb 2011
 *  Modified: 10 March 2011
 *  Author: Tom Geary
 *
 *  Spec: Implements a BlockManager class.
 *
 *  	Like a book provides an index the block manager provides a table of Block Entries
 *  	to manage the allocation and deallocation of memory blocks.
 */

#include <iostream>
#include <sstream>

#include "Block.h"
#include "BlockManager.h"
#include "MAL.h"
#include "Entry.h"



using namespace std ;

BlockManager::BlockManager()
{
	BID = 0 ;
}


BlockManager::~BlockManager()
{
}


bool BlockManager::initializeBlockManager()
{

//  We create an Entry of 10000 B to initialize the Block Table...

	Entry e0( BID, MEMORY_SIZE , true, m.initializeMAL( MEMORY_SIZE )) ;

	blockTable.push_back( e0 ) ;

	historyList.push_back( "Block Manager initialised with first Entry" ) ;

	return true ;
}


int BlockManager::allocateBlock( int requestSize )
{
	Block* pNewBlock ;
	Block* pBiggestBlock ;

	int biggestBlockSize = 0 ;
	int idxBiggestBlock ;
	stringstream out ;

/*
	The first thing you do when you allocate a new Block is increment the
	Block identifier. This allows us to marry up blockTable entries with
	Memory Allocation list Blocks later in this function. They both reference this
	variable...
*/

	BID++ ;

/*
 *  look at block table and get the index of and pointer to the biggest block
 *	available.
 */

	for ( int i = 0 ; i < blockTable.size() ; i++ )
	{
		if ( blockTable.at( i ).free == true )
		{
			int entrySize ;
			entrySize = blockTable.at( i ).size ;

			if ( entrySize > biggestBlockSize )
			{
				biggestBlockSize = entrySize ;
				idxBiggestBlock = i ;
				pBiggestBlock = blockTable.at( i ).pBlock ;
			}
		}
	}

//	resize the biggest block ie. Implement the worst fit

	if ( biggestBlockSize > requestSize )
	{
		blockTable.at( idxBiggestBlock ).size = biggestBlockSize - requestSize ;
	}

	else
	{
		if ( biggestBlockSize == requestSize )
		{
			blockTable.at( idxBiggestBlock ).free = false ;
		}

		else
		{
			return 0 ;
		}
	}

// 	create a new block on the Memory Allocation double-linked list

	pNewBlock = m.add( requestSize, pBiggestBlock, 'n', BID ) ;

// 	Add new entry for block to the Block Table

	Entry newEntry( BID, requestSize, false, pNewBlock ) ;
	blockTable.push_back( newEntry ) ;

// log this success to our history vector

	out << BID ;
	out << " " ;
	out << requestSize ;
	out << " Bytes" ;
	outputString = out.str() + "..Block allocated" ;

	historyList.push_back( outputString ) ;

	return BID ;
}


bool BlockManager::deallocateBlock( int rBID )
{

/*	To deallocate a block we iterate through the Block Table
 *	and look for our BID, we set its accompanying Entry's free
 *	attribute to yes...
 */

	stringstream out ;

	out << rBID ;
	outputString = out.str() + "..Block deallocated" ;

	for ( int i = 0 ; i < blockTable.size() ; i++ )
	{
		if ( blockTable.at( i ).BID == rBID )
		{

			blockTable.at( i ).free = true ;

			if ( m.remove( blockTable.at( i ).pBlock ))
				{
					historyList.push_back( outputString ) ;
					return true ;
				}

		}
	}

	return false ;

}

void BlockManager::printBlocks()
{
	cout << "----------------------------------------------------------" << endl << endl ;
	m.print() ;
	cout << "----------------------------------------------------------" << endl << endl ;
}


void BlockManager::showHistory()
{
	cout << endl << "-----------------------history----------------------------"
	<< endl << endl ;

	for ( int i = 0 ; i < historyList.size() ; i++ )
	{
		cout << historyList.at( i ) << endl ;
	}

	cout << "----------------------------------------------------------"
	<< endl << endl ;
}























