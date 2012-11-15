//Tetro.h
#ifndef TETRO_H
#define TETRO_H
#include "grid.h"
class TETRO
{
private:
	int m_x1, m_x2, m_x3, m_x4, m_y1, m_y2, m_y3, m_y4, m_rot;
	char m_type;
public:
	TETRO(GRID * grid);
	void reset(GRID * grid);
	void dropIn(GRID * grid, TETRO * spare1, TETRO * spare2, TETRO * spare3);
	void dropIn2(GRID * grid);
	void rotateLeft(GRID * grid);
	void rotateRight(GRID * grid);
	void moveDown(GRID * grid, int * score, int * lines, int * level);
	void moveLeft(GRID * grid);
	void moveRight(GRID * grid);
	void slamDown(GRID * grid, int * score, int * lines, int * level);
	void lockIn(GRID * grid, int * score, int * lines, int * level);
	void shiftUp(void);
	void printStats(void);
	//void writeStats(FILE * pFile);
};
#endif