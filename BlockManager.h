/*
 * BlockManager.h
 *
 *  Module: Algorithmics
 *  Coursework: 1
 *  Created on: 19 Feb 2011
 *  Modified: 10 Mar 2011
 *  Author: Tom Geary
 *
 *  Spec: Declares a BlockManager class.
 *
 *  	The block manager allocates and deallocates memory in the MAL.
 */

#pragma once

#include <vector>
#include <string>

#include "Block.h"
#include "MAL.h"
#include "Entry.h"



using namespace std ;

const int MEMORY_SIZE = 10000 ;
const int TABLE_SIZE = 20 ;

class BlockManager
{

public:

	BlockManager() ;
	~BlockManager() ;

	int allocateBlock( int blockSize ) ;
	bool deallocateBlock( int rBID ) ;
	void printBlocks() ;
	void showHistory() ;
	bool initializeBlockManager() ;

private:

	MAL m ;
	int BID ;
	string outputString ;

	vector <Entry> blockTable ;
	vector <string> historyList ;


};








