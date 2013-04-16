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
		for (int y = 0; y < 24; y++)
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
void GRID::rowClear (int rowNum, int * score, int * lines, int * level)
{
	cout << "Clearing rows...\n";
	for (int i = 0; i < 10; i++)
		{
		m_grid[i][rowNum] = '=';
		}
	rowShift(rowNum);

	cout << *lines << "lines" << endl;
	system("pause");
	if (*lines % 10 == 0){
		*level += 1;}

	cout << "Rows cleared. score: " << *score << "\n";
}

//moves everything above a certain level
//down a row
void GRID::rowShift (int rowNum)
{
	string row;
	for (int j = rowNum + 1; j < 22; j++)
	{
		row = rowGet(j);
		if (row.compare("==========") == 0){
			cout << "loop broken\n";
			break;}

		printGrid();
		//system("pause");
		for (int i = 0; i < 10; i++)
		{
			m_grid[i][j-1] = m_grid[i][j];
			m_grid[i][j] = '=';
			printGrid();
			//system("pause");
		}
	}
}

//scans top row of grid to determine if player has lost
//8 of the '=' character means a clear row
bool GRID::lossCheck(void)
{
	string row22 = rowGet(22);
	if (row22 != "==========")
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
	for (int i = 24; i >= 0; i -= 1)
	{
		rowGot = rowGet(i);
		cout << rowGot << endl;
	}
}

//write grid array to a file. unused
void GRID::writeGrid(ofstream& outFile)
{
	string rowGot;
	for (int i = 24; i >= 0; i -= 1)
	{
		rowGot = rowGet(i);
		outFile << rowGot << "\n";
	}
}
