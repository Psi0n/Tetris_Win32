//Grid.h
#ifndef GRID_H
#define GRID_H
//#include <cstring>
#include <fstream>
#define GRID_WIDTH 18
#define GRID_HEIGHT 22

class GRID
{
public:
	char m_grid[GRID_WIDTH][GRID_HEIGHT];
	GRID(void);
	string rowGet(int rowNum);
	void rowClear (int rowNum, int * score, int * lines, int * level);
	void rowShift (int rowNum);
	bool lossCheck (void);
	void printGrid (void);
	//void writeGrid (FILE * pFile);
};
#endif