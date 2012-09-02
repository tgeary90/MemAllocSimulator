/*
 *  cwk1.cc
 *
 *  Module: Algorithmics
 *  Coursework: 1
 *  Created on: 19 Feb 2011
 *  Modified: 9 March 2011
 *  Author: Tom Geary
 *
 *  Spec: This is the program front end. It provides a menu to access
 *  the functionality of the BlockManager class and MAL class
 *
 */


#include <iostream>
#include <string>
#include <cstdlib>

#include "MAL.h"
#include "BlockManager.h"


using namespace std ;

int main()
{
	int numberValue ;
	char option ;
	const int BUFFER_SIZE = '80' ;
	const char NL = '\n' ;
	const char TAB = '\t' ;

	cout << "----------------------------------------------------------" << endl << endl ;
	cout << "Welcome to the Memory Allocation Simulator, by Tom Geary. " << endl << endl ;
	cout << "----------------------------------------------------------" << endl << endl ;

	BlockManager bm ;

// 	We initialize the BlockManager object with the Memory Block (10000 B)

	if ( ! bm.initializeBlockManager() )
	{
		cout << "Block Manager could not be created, exiting" << endl ;
		exit( 0 ) ;
	}



	while ( option != 'q' )
	{
		cout << "p. " << TAB << "to print" << endl ;
		cout << "a N." << TAB << "to allocate a memory block of size N" << endl ;
		cout << "h." << TAB << "show history" << endl ;
		cout << "r BID." << TAB << "deallocate a memory block " << endl ;
		cout << "q." << TAB << "to quit" << endl << endl ;
		cout << "choice: " << endl ;
		cout << endl ;

		cin >> option ;

		if ( option == 'a' || option == 'r' )
		{
			cin >> numberValue ;
			cin.ignore( BUFFER_SIZE, NL ) ;

		}

		switch ( option )
		{
			case 'p' :
			{
				bm.printBlocks() ;
				break ;
			}

			case 'a' :
			{
				if ( numberValue > MEMORY_SIZE )
					break ;

				bm.allocateBlock( numberValue ) ;
				break ;
			}

			case 'h' :
			{
				bm.showHistory() ;
				break ;
			}

			case 'r' :
			{
				if ( numberValue < 1 )
					break ;

				if ( ! bm.deallocateBlock( numberValue ) )
				{
					cout << "Block could not be deallocated" << endl ;
				}
				break ;
			}
			case 'q' :
			{
			  bm.printBlocks() ;
			  bm.showHistory() ;
			  exit ( 0 ) ;

			}
		}
	}
}


