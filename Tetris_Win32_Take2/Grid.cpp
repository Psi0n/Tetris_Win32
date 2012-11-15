//Grid.cpp
//2D array used for Tetris
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Grid.h"

GRID::GRID(void)
{
	for (int x = 0; x < 17; x++)
	{
		for (int y = 0; y < 22; y++)
		{
			m_grid[x][y] = '=';
		}
	}
}
string GRID::rowGet(int rowNum)
{
	string row = "";
	for (int i = 0; i < 10; i++)
	{
		row += m_grid[i][rowNum];
	}
	return row;
}
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

bool GRID::lossCheck(void)
{
	string row21 = rowGet(21);
	if (row21 != "==========")
		{return true;}
	else
		{return false;}
}

void GRID::printGrid(void)
{
	string rowGot;
	for (int i = 0; i < 23; i++)
	{
		rowGot = rowGet(i);
		cout << rowGot << endl;
	}
}

/*void GRID::writeGrid(FILE * pFile)
{
	string rowGot;
	for (int i = 0; i < 23; i++)
	{
		rowGot = rowGet(i);
		pFile << rowGot << "\n";
	}
}*/