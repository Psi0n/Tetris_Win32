//Grid.h
/*
	The Grid class is the simpler part of my alogrithm. It's built
	around a single character array, which the Tetro class alters.
	The classes's functions deal with entire rows of the grid at
	once, checking for completed rows and clearing them (or
	declaring game over) as needed.

	The grid also serves as a guide for the main file's onPaint
	function, with (0,0) in the bottom left corner.
	
	Ex:
	4|
	3|
	2|
	1|
	0|_ _ _ _ _
	  0 1 2 3 4
*/

#ifndef GRID_H
#define GRID_H
#include <cstring>
#include <fstream>

class GRID
{
public:
	char m_grid[18][22];
	GRID(void);
	string rowGet(int rowNum);
	void rowClear (int rowNum, int * score, int * lines, int * level, char * pTempGrid);
	void rowShift (int rowNum, char * pTempGrid);
	bool lossCheck (void);
	void printGrid (void);
	void writeGrid (ofstream& outFile); //unused
};
#endif
