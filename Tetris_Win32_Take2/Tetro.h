//Tetro.h
/*
	The Tetro class is the part of the algorithm responsible for most
	of my headaches. It behaves a little bit like a machine making
	its way across the grid class's array, altering the data as it
	goes to indicate its current position. Once it reaches the bottom,
	it makes a final alteration, changes shape, and moves back into
	the queue area to the side of the main playing field.

	I know the way it's implemented looks odd, and the mountain of
	minor calculations aredefinitely a pain to deal with, but it's
	working, and this way I can easily break the tetrominoes apart
	when lines get completed and cleared by the grid.
*/
#ifndef TETRO_H
#define TETRO_H
#include "grid.h"
class TETRO
{
private:
	//four sets of coordinates:
	int m_x1, m_x2, m_x3, m_x4;
	int m_y1, m_y2, m_y3, m_y4;
	//position tetro is rotated in (1-4)
	int m_rot;
	//shape of tetro
	char m_type;
public:
	TETRO(GRID * grid);
	void reset(GRID * grid);
	void dropIn(GRID * grid, TETRO * spare1, TETRO * spare2, TETRO * spare3);	//not currently used
	void dropIn2(GRID * grid);
	void rotateLeft(GRID * grid);
	void rotateRight(GRID * grid);
	void moveDown(GRID * grid, int * score, int * lines, int * level);
	void moveLeft(GRID * grid);
	void moveRight(GRID * grid);
	void slamDown(GRID * grid, int * score, int * lines, int * level);
	void lockIn(GRID * grid, int * score, int * lines, int * level);
	void shiftUp(void);															//not currently used
	void printStats(void);
	//void writeStats(FILE * pFile);
};
#endif