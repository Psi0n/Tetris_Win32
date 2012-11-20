//Grid.cpp
//2D array used for Tetris
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Grid.h"


//constructor
GRID::GRID(void)
{
	for (int x = 0; x < GRID_WIDTH; x++)
	{
		for (int y = 0; y < GRID_HEIGHT; y++)
		{
			m_grid[x][y] = '=';
		}
	}
}

//outputs a single row of the grid
string GRID::rowGet(int rowNum)
{
	string row = "";
	for (int i = 0; i < 10; i++)
	{
		row += m_grid[i][rowNum];
	}
	return row;
}
//clears a given row of the grid,
//then triggers rowShift
void GRID::rowClear (int rowNum, int * score, int * lines, int * level)
{
	for (int i = 0; i < 10; i++)
		{
		m_grid[i][rowNum] = '=';
		}
	rowShift(rowNum);
	*score += 10;
	*lines++;

	int levelTest = *level;
	while(levelTest > 0)
		{levelTest -= 10;}

	if (levelTest == 0)
		{*level += 1;}
}
//moves everything above a certain level
//down a row
void GRID::rowShift (int rowNum)
{
	for (int j = rowNum; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			m_grid[i][j-1] = m_grid[i][j];
			m_grid[i][j] = '=';
		}
	}
}

//scans top row of grid to determine if player has lost
//8 of the '=' character means a clear row
bool GRID::lossCheck(void)
{
	string row21 = rowGet(21);
	if (row21 != "==========")
		{return true;}
	else
		{return false;}
}
//prints the grid array to console.
//not reccommended.
//will probably delete later.
void GRID::printGrid(void)
{
	string rowGot;
	for (int i = 0; i < 23; i++)
	{
		rowGot = rowGet(i);
		cout << rowGot << endl;
	}
}
//supposed to write grid array to a file.
//currently broken
/*void GRID::writeGrid(FILE * pFile)
{
	string rowGot;
	for (int i = 0; i < 23; i++)
	{
		rowGot = rowGet(i);
		pFile << rowGot << "\n";
	}
}*/