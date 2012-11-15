//Grid.h
#ifndef GRID_H
#define GRID_H
//#include <cstring>
#include <fstream>
class GRID
{
public:
	char m_grid[17][22];
	GRID(void);
	string rowGet(int rowNum);
	void rowClear (int rowNum, int * score, int * lines, int * level);
	void rowShift (int rowNum);
	bool lossCheck (void);
	void printGrid (void);
	//void writeGrid (FILE * pFile);
};
#endif