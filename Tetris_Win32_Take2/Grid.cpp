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
	for (int x = 0; x < 18; x++)
	{
		for (int y = 0; y < 22; y++)
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
//then triggers rowShift.
//should also check lines cleared
//and increment level by 1 for every 10.
void GRID::rowClear (int rowNum, int * score, int * lines, int * level, char * pTempGrid)
{
	cout << "Clearing rows...\n";
	for (int i = 0; i < 10; i++)
		{
		m_grid[i][rowNum] = '=';
		}
	rowShift(rowNum, pTempGrid);

	*lines++;

	int levelTest = *lines;
	while(levelTest > 0)
		{levelTest -= 10;}

	if (levelTest == 0)
		{*level += 1;}
	cout << "Rows cleared. score: " << *score << "\n";
}

//moves everything above a certain level
//down a row
void GRID::rowShift (int rowNum, char * pTempGrid)
{
	string row;
	for (int j = rowNum + 1; j < 21; j++)
	{
		row = rowGet(j);
		if (row.compare("==========") == 0){
			cout << "loop broken\n";
			*pTempGrid = m_grid;
			break;}

		printGrid();
		system("pause");
		for (int i = 0; i < 10; i++)
		{
			m_grid[i][j-1] = m_grid[i][j];
			m_grid[i][j] = '=';
			printGrid();
			system("pause");
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
//not recommended for use.
//will probably delete later.
void GRID::printGrid(void)
{
	string rowGot;
	for (int i = 23; i >= 0; i -= 1)
	{
		rowGot = rowGet(i);
		cout << rowGot << endl;
	}
}

//write grid array to a file. unused
void GRID::writeGrid(ofstream& outFile)
{
	string rowGot;
	for (int i = 23; i >= 0; i -= 1)
	{
		rowGot = rowGet(i);
		outFile << rowGot << "\n";
	}
}
