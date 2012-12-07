//Tetro.cpp
//Tetrominoes
#include <windows.h>
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <fstream>

using namespace std;

#include "Tetro.h"
//constructor
TETRO::TETRO(GRID * grid)
{
	cout << "constructing tetro\n";
	int typeNum = ((rand() % 7) + 1); //selects random type for new tetro
	switch(typeNum) //generates tetro at bottom of stack in right of screen
	{
		case 1:
			{
			m_type = '|';
			m_y1 = m_y2 = m_y3 = m_y4 = 1;	//1234
			m_x1 = 13;						//====
			m_x2 = 14;
			m_x3 = 15;
			m_x4 = 16;
			break;
			}
		case 2:
			{
			m_type = 'L';
			m_y1 = m_y2 = m_y3 = 1;			//==4=
			m_y4 = 2;						//123=
			m_x1 = 13;
			m_x2 = 14;
			m_x3 = m_x4 = 15;
			break;
			}
		case 3:
			{
			m_type = 'J';
			m_y1 = m_y2 = m_y3 = 1;			//=4==
			m_y4 = 2;						//=321
			m_x3 = m_x4 = 16;
			m_x2 = 15;
			m_x1 = 14;
			break;
			}
		case 4:
			{
			m_type = 'Z';
			m_y1 = m_y2 = 2;				//=12=
			m_y3 = m_y4 = 1;				//==34
			m_x1 = 14;
			m_x2 = m_x3 = 15;
			m_x4 = 16;
			break;
			}
		case 5:
			{
			m_type = 'S';
			m_y1 = m_y2 = 2;				//=21=
			m_y3 = m_y4 = 1;				//43==
			m_x1 = 15;
			m_x2 = m_x3 = 14;
			m_x4 = 13;
			break;
			}
		case 6:
			{
			m_type = 'O';
			m_y1 = m_y2 = 1;				//=34=
			m_y3 = m_y4 = 2;				//=12=
			m_x1 = m_x3 = 14;
			m_x2 = m_x4 = 15;
			break;
			}
		case 7:
			{
			m_type = 'T';
			m_y1 = m_y2 = m_y3 = 2;			//123=
			m_y4 = 1;						//=4==
			m_x1 = 13;
			m_x2 = m_x4 = 14;
			m_x3 = 15;
				break;
			}
		grid->m_grid[m_x1][m_y1] = '1';
		grid->m_grid[m_x2][m_y2] = '1';
		grid->m_grid[m_x3][m_y3] = '1';
		grid->m_grid[m_x4][m_y4] = '1';
	}
	m_rot = 1;
	cout << "construction complete\n";
}
//re-constructs tetro. may be discarded in future updates
void TETRO::reset(ofstream& outFile, GRID * grid)
{
	cout << "begin reset\n";
	int typeNum = ((rand() % 7) + 1);
	switch(typeNum)
	{
		case 1:
			{
			m_type = '|';
			m_y1 = m_y2 = m_y3 = m_y4 = 1;	//1234
			m_x1 = 13;						//====
			m_x2 = 14;
			m_x3 = 15;
			m_x4 = 16;
			break;
			}
		case 2:
			{
			m_type = 'L';
			m_y1 = m_y2 = m_y3 = 1;			//==4=
			m_y4 = 2;						//123=
			m_x1 = 13;
			m_x2 = 14;
			m_x3 = m_x4 = 15;
			break;
			}
		case 3:
			{
			m_type = 'J';
			m_y1 = m_y2 = m_y3 = 1;			//=4==
			m_y4 = 2;						//=321
			m_x3 = m_x4 = 16;
			m_x2 = 15;
			m_x1 = 14;
			break;
			}
		case 4:
			{
			m_type = 'Z';
			m_y1 = m_y2 = 2;				//=12=
			m_y3 = m_y4 = 1;				//==34
			m_x1 = 14;
			m_x2 = m_x3 = 15;
			m_x4 = 16;
			break;
			}
		case 5:
			{
			m_type = 'S';
			m_y1 = m_y2 = 2;				//=21=
			m_y3 = m_y4 = 1;				//43==
			m_x1 = 15;
			m_x2 = m_x3 = 14;
			m_x4 = 13;
			break;
			}
		case 6:
			{
			m_type = 'O';
			m_y1 = m_y2 = 1;				//=34=
			m_y3 = m_y4 = 2;				//=12=
			m_x1 = m_x3 = 14;
			m_x2 = m_x4 = 15;
			break;
			}
		case 7:
			{
			m_type = 'T';
			m_y1 = m_y2 = m_y3 = 2;			//123=
			m_y4 = 1;						//=4==
			m_x1 = 13;
			m_x2 = m_x4 = 14;
			m_x3 = 15;
				break;
			}
		grid->m_grid[m_x1][m_y1] = '1';
		grid->m_grid[m_x2][m_y2] = '1';
		grid->m_grid[m_x3][m_y3] = '1';
		grid->m_grid[m_x4][m_y4] = '1';
	}
	m_rot =1;
	cout << "reset successful\n";
	grid->printGrid();
	system("pause");
	printStats();
	grid->writeGrid(outFile);
}
//leftover from early attempt at keeping
//a rotating 'stack' of predetermined tetros.
//currently unused. needs major revision before implementation.
/*void TETRO::dropIn(GRID * grid, TETRO * spare1, TETRO * spare2, TETRO * spare3)
{
	if (spare1->m_y1 > spare2->m_y1 && spare1->m_y1 > spare3->m_y1)
	{
		m_type = spare1->m_type;
		spare1->reset(outFile, grid);
		spare2->m_y1 +=3;
		spare2->m_y2 +=3;
		spare2->m_y3 +=3;
		spare2->m_y4 +=3;
		spare3->m_y1 +=3;
		spare3->m_y2 +=3;
		spare3->m_y3 +=3;
		spare3->m_y4 +=3;
	}
	if (spare2->m_y1 > spare1->m_y1 && spare2->m_y1 > spare3->m_y1)
	{
		m_type = spare2->m_type;
		spare2->reset(outFile, grid);
		spare1->m_y1 +=3;
		spare1->m_y2 +=3;
		spare1->m_y3 +=3;
		spare1->m_y4 +=3;
		spare3->m_y1 +=3;
		spare3->m_y2 +=3;
		spare3->m_y3 +=3;
		spare3->m_y4 +=3;
	}
	if (spare3->m_y1 > spare1->m_y1 && spare3->m_y1 > spare2->m_y1)
	{
		m_type = spare3->m_type;
		spare3->reset(outFile, grid);
		spare1->m_y1 +=3;
		spare1->m_y2 +=3;
		spare1->m_y3 +=3;
		spare1->m_y4 +=3;
		spare2->m_y1 +=3;
		spare2->m_y2 +=3;
		spare2->m_y3 +=3;
		spare2->m_y4 +=3;
	}
	m_rot = 1;
switch(m_type)
{
	case '|':
		m_y1 = m_y2 = m_y3 = m_y4 = 22;	//1234
		m_x1 = 4;						//====
		m_x2 = 5;
		m_x3 = 6;
		m_x4 = 7;
		break;

	case 'L':
		m_y1 = m_y2 = m_y3 = 21;		//==4=
		m_y4 = 22;						//123=
		m_x1 = 4;
		m_x2 = 5;
		m_x3 = m_x4 = 6;
		break;

	case 'J':
		m_y1 = m_y2 = m_y3 = 21;		//=4==
		m_y4 = 22;						//=321
		m_x1 = m_x4 = 7;
		m_x2 = 6;
		m_x3 = 5;
		break;

	case 'S':
		m_y1 = m_y2 = 22;				//=21=
		m_y3 = m_y4 = 21;				//43==
		m_x1 = 6;
		m_x2 = m_x3 = 5;
		m_x4 = 4;
		break;
	
	case 'Z':
		m_y1 = m_y2 = 22;				//=12=
		m_y3 = m_y4 = 21;				//==34
		m_x1 = 5;
		m_x2 = m_x3 = 6;
		m_x4 = 7;
		break;
	
	case 'O':
		m_y1 = m_y2 = 21;				//=34=
		m_y3 = m_y4 = 22;				//=12=
		m_x1 = m_x3 = 5;
		m_x2 = m_x4 = 6;
		break;
	case 'T':							
		m_y1 = m_y2 = m_y3 = 22;		//123=
		m_y4 = 21;						//=4==
		m_x1 = 4;
		m_x2 = m_x4 = 5;
		m_x3 = 6;
		break;
}
	grid->m_grid[m_x1][m_y1] = '1';
	grid->m_grid[m_x2][m_y2] = '1';
	grid->m_grid[m_x3][m_y3] = '1';
	grid->m_grid[m_x4][m_y4] = '1';
}*/
//current function for placing lone
//tetro in the top rows of the grid.
void TETRO::dropIn2(ofstream& outFile, GRID * grid)
{
	cout << "begin dropIn2\n";
	switch(m_type)
	{
	case '|':
		{
		m_y1 = m_y2 = m_y3 = m_y4 = 21;	//1234
		m_x1 = 4;						//====
		m_x2 = 5;
		m_x3 = 6;
		m_x4 = 7;
		break;
		}

	case 'L':
		{
		m_y1 = m_y2 = m_y3 = 20;		//==4=
		m_y4 = 21;						//123=
		m_x1 = 4;
		m_x2 = 5;
		m_x3 = m_x4 = 6;
		break;
		}

	case 'J':
		{
		m_y1 = m_y2 = m_y3 = 20;		//=4==
		m_y4 = 21;						//=321
		m_x1 = m_x4 = 7;
		m_x2 = 6;
		m_x3 = 5;
		break;
		}

	case 'S':
		{
		m_y1 = m_y2 = 21;				//=21=
		m_y3 = m_y4 = 20;				//43==
		m_x1 = 6;
		m_x2 = m_x3 = 5;
		m_x4 = 4;
		break;
		}
	
	case 'Z':
		{
		m_y1 = m_y2 = 21;				//=12=
		m_y3 = m_y4 = 20;				//==34
		m_x1 = 5;
		m_x2 = m_x3 = 6;
		m_x4 = 7;
		break;
		}
	
	case 'O':
		{
		m_y1 = m_y2 = 20;				//=34=
		m_y3 = m_y4 = 21;				//=12=
		m_x1 = m_x3 = 5;
		m_x2 = m_x4 = 6;
		break;
		}

	case 'T':	
		{
		m_y1 = m_y2 = m_y3 = 21;		//123=
		m_y4 = 20;						//=4==
		m_x1 = 4;
		m_x2 = m_x4 = 5;
		m_x3 = 6;
		break;
		}
	}
	grid->m_grid[m_x1][m_y1] = '1';
	grid->m_grid[m_x2][m_y2] = '1';
	grid->m_grid[m_x3][m_y3] = '1';
	grid->m_grid[m_x4][m_y4] = '1';
	cout << "dropIn2 successful\n";
	grid->printGrid();
	system("pause");
	printStats();
	grid->writeGrid(outFile);
	grid->printGrid();
	system("pause");
}
//should rotate tetro counterclockwise,
//but no guarantees at the moment.
void TETRO::rotateLeft(ofstream& outFile, GRID * grid)
{
	cout << "begin rotateLeft\n";
	grid->m_grid[m_x1][m_y1] = '=';
	grid->m_grid[m_x2][m_y2] = '=';
	grid->m_grid[m_x3][m_y3] = '=';
	grid->m_grid[m_x4][m_y4] = '=';
	switch(m_type){
		case '|':
			{
				switch(m_rot){
					case 1:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 - 2][m_y4 + 2] != '8')){
							m_x1 += 1; m_y1 -= 1;
							m_x3 -= 1; m_y3 += 1;
							m_x4 -= 2; m_y4 += 2;
							m_rot = 4;}
							break;
					}
					case 2:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 + 2][m_y4 + 2] != '8')){
							m_x1 -= 1; m_y1 -= 1;
							m_x3 += 1; m_y3 += 1;
							m_x4 += 2; m_y4 += 2;
							m_rot = 1;}
							break;
					}
					case 3:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 + 2][m_y4 - 2] != '8')){
							m_x1 -= 1; m_y1 += 1;
							m_x3 += 1; m_y3 -= 1;
							m_x4 += 2; m_y4 -= 2;
							m_rot = 2;}
						break;
					}
					case 4:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 - 2][m_y4 - 2] != '8')){
							m_x1 +=1 ; m_y1 += 1;
							m_x3 -=1 ; m_y3 -= 1;
							m_x4 -=2 ; m_y4 -= 2;
							m_rot = 3;}
							break;
					}
				}
				break;}
		case 'L':
			{
				switch(m_rot){
					case 1:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 - 2][m_y4] != '8')){
							m_x1 += 1; m_y1 -= 1;
							m_x3 -= 1; m_y3 += 1;
							m_x4 -= 2;
							m_rot = 4;}
							break;
					}
					case 2:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4][m_y4 + 2] != '8')){
							m_x1 -= 1; m_y1 -= 1;
							m_x3 += 1; m_y3 += 1;
							m_y4 += 2;
							m_rot = 1;}
							break;
						}
					case 3:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 + 2][m_y4] != '8')){
							m_x1 -= 1; m_y1 += 1;
							m_x3 += 1; m_y3 -= 1;
							m_x4 += 2;
							m_rot = 2;}
							break;
					}
					case 4:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4][m_y4 - 2] != '8')){
							m_x1 += 1; m_y1 += 1;
							m_x3 -= 1; m_y3 -= 1;
							m_y4 -= 2;
							m_rot = 3;}
							break;
					}
				}
				break;}
		case 'J':
			{
				switch(m_rot){
					case 1:
					{
					    if((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						&& (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						&& (grid->m_grid[m_x4][m_y4 - 2] != '8')){
						   m_x1 -= 1; m_y1 += 1;
					       m_x3 += 1; m_y3 -= 1;
						   m_x4 -= 2;
						   m_rot = 4;}
						   break;
					}
					case 2:
					{
						if((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						&& (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						&& (grid->m_grid[m_x4 + 2][m_y4] != '8')){
							m_x1 += 1; m_y1 += 1;
							m_x3 -= 1; m_y3 -= 1;
       						m_y4 += 2;
       						m_rot = 1;}
      						break;
     				}
     				case 3:
     				{
      					if((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
      					&& (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8')
      					&& (grid->m_grid[m_x4][m_y4 + 2] != '8')){
       						m_x1 += 1; m_y1 -= 1;
       						m_x3 -= 1; m_y3 += 1;
       						m_x4 += 2;
       						m_rot = 2;}
      						break;
     				}
     				case 4:
					{
						if((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						&& (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						&& (grid->m_grid[m_x4][m_y4 - 2] != '8')){
							m_x1 -= 1; m_y1 -= 1;
       						m_x3 += 1; m_y3 += 1;
       						m_y4 -= 2;
      						m_rot = 3;}
      						break;
     				}
				}
				break;}
		case 'Z':
			{
				switch(m_rot){
					case 1:
					{
						if((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						&& (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						&& (grid->m_grid[m_x4][m_y4 + 2] != '8')){
							m_x1 += 1; m_y1 -= 1;
							m_x3 += 1; m_y3 += 1;
							m_y4 += 2;
							m_rot = 4;}
						break;
					}
					case 2:
					{
						if((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						&& (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						&& (grid->m_grid[m_x4 + 2][m_y4] != '8')){
							m_x1 -= 1; m_y1 -= 1;
							m_x3 += 1; m_y3 -= 1;
							m_x4 += 2;
							m_rot = 1;}
						break;
						}
					case 3:
					{
						if((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						&& (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						&& (grid->m_grid[m_x4][m_y4 - 2] != '8')){
							m_x1 -= 1; m_y1 += 1;
							m_x3 -= 1; m_y3 -= 1;
							m_y4 -= 2;
							m_rot = 2;}
						break;
						}
					case 4:
					{
						if((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						&& (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8')
						&& (grid->m_grid[m_x4 - 2][m_y4] != '8')){
							m_x1 += 1; m_y1 += 1;
							m_x3 -= 1; m_y3 += 1;
							m_x4 -= 2;
							m_rot = 3;}
						break;
						}
				}
				break;}
		case 'S':
			{
				switch(m_rot){
					case 1:
					{
						if((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						&& (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						&& (grid->m_grid[m_x4 + 2][m_y4] != '8')){
							m_x1 -= 1; m_y1 += 1;
							m_x3 += 1; m_y3 += 1;
							m_x4 += 2;
							m_rot = 4;}
						break;
						}
					case 2:
					{
						if((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						&& (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8')
						&& (grid->m_grid[m_x4][m_y4 + 2] != '8')){
							m_x1 += 1; m_y1 += 1;
							m_x3 += 1; m_y3 -= 1;
							m_y4 -= 2;
							m_rot = 1;}
						break;
					}
					case 3:
					{
						if((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						&& (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						&& (grid->m_grid[m_x4 - 2][m_y4] != '8')){
							m_x1 += 1; m_y1 -= 1;
							m_x3 -= 1; m_y3 -= 1;
							m_x4 -= 2;
							m_rot = 2;}
						break;
					}
					case 4:
					{
						if((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						&& (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						&& (grid->m_grid[m_x4][m_y4 - 2] != '8')){
							m_x1 -= 1; m_y1 -= 1;
							m_x3 -= 1; m_y3 += 1;
							m_y4 += 2;
							m_rot = 3;}
						break;
					}
				}
				break;}
		case 'O':
			{//This tetro remains in the same position regardless of rotation.
				break;}
		case 'T':
			{
				switch(m_rot){
					case 1:
					{
						if((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						&& (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						&& (grid->m_grid[m_x4 - 1][m_x4 + 1] != '8')){
							m_x1 += 1; m_y1 -= 1;
							m_x3 -= 1; m_y3 += 1;
							m_x4 += 1; m_y4 += 1;
							m_rot = 4;}
						break;
					}
					case 2:
					{
						if((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8') 
						&& (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8') 
						&& (grid->m_grid[m_x4 + 1][m_x4 + 1] != '8')){
							m_x1 -= 1; m_y1 -= 1;
							m_x3 += 1; m_y3 += 1;
							m_x4 += 1; m_y4 -= 1;
							m_rot = 1;}
						break;
					}
					case 3:
					{
						if((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						&& (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						&& (grid->m_grid[m_x4 + 1][m_x4 - 1] != '8')){
							m_x1 -= 1; m_y1 += 1;
							m_x3 += 1; m_y3 -= 1;
							m_x4 -= 1; m_y4 -= 1;
							m_rot = 2;}
						break;
					}
					case 4:
					{
						if((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						&& (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						&& (grid->m_grid[m_x4 - 1][m_x4 - 1] != '8')){
							m_x1 += 1; m_y1 += 1;
							m_x3 -= 1; m_y3 -= 1;
							m_x4 -= 1; m_y4 += 1;
							m_rot = 3;}
						break;
					}
				}
				break;}
}
	grid->m_grid[m_x1][m_y1] = '1';
	grid->m_grid[m_x2][m_y2] = '1';
	grid->m_grid[m_x3][m_y3] = '1';
	grid->m_grid[m_x4][m_y4] = '1';
	cout << "rotateLeft successful\n";
	printStats();
	grid->writeGrid(outFile);
}
//similar to above.
//should rotate clockwise.
//nothing guaranteed at the moment.
void TETRO::rotateRight(ofstream& outFile, GRID * grid)	
{
	cout << "begin rotateRight\n";
	grid->m_grid[m_x1][m_y1] = '=';
	grid->m_grid[m_x2][m_y2] = '=';
	grid->m_grid[m_x3][m_y3] = '=';
	grid->m_grid[m_x4][m_y4] = '=';
	switch(m_type){
		case '|':
			{
				switch(m_rot){
					case 1:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 - 2][m_y4 - 2] != '8')){
						   m_x1 += 1; m_y1 += 1;
						   m_x3 -= 1; m_y3 -= 1;
						   m_x4 -= 2; m_y4 -= 2;
                  		   m_rot = 2;}
						break;
					}
					case 2:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 - 2][m_y4 + 2] != '8')){
						   m_x1 += 1; m_y1 -= 1;
						   m_x3 -= 1; m_y3 += 1;
						   m_x4 -= 2; m_y4 += 2;
				           m_rot = 3;}
						break;
					}
					case 3:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 + 2][m_y4 - 2] != '8')){
						   m_x1 -= 1; m_y1 -= 1;
						   m_x3 += 1; m_y3 += 1;
						   m_x4 += 2; m_y4 += 2;
              			   m_rot = 4;}
						break;
					}
					case 4:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 + 2][m_y4 - 2] != '8')){
						   m_x1 -= 1; m_y1 += 1;
						   m_x3 += 1; m_y3 -= 1;
						   m_x4 += 2; m_y4 -= 2;
				           m_rot = 1;}
						break;
					}
				}
				break;}
		case 'L':
			{
				switch(m_rot){
					case 1:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4][m_y4 - 2] != '8')){
						   m_x1 += 1; m_y1 += 1;
						   m_x3 -= 1; m_y3 -= 1;
						   m_y4 -= 2;
                           m_rot = 2;}
						break;
					}
					case 2:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 - 2][m_y4] != '8')){
						   m_x1 += 1; m_y1 -= 1;
						   m_x3 -= 1; m_y3 += 1;
						   m_x4 -= 2;
                           m_rot = 3;}
						break;
					}
					case 3:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4][m_y4 + 2] != '8')){
						   m_x1 -= 1; m_y1 -= 1;
						   m_x3 += 1; m_y3 += 1;
						   m_y4 += 2;
                           m_rot = 4;}
						break;
					}
					case 4:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 + 2][m_y4] != '8')){
						   m_x1 -= 1; m_y1 += 1;
						   m_x3 += 1; m_y3 -= 1;
						   m_x4 += 2;
                           m_rot = 1;}
						break;
					}
				}
				break;}

		case 'J':
			{
				switch(m_rot){
					case 1:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 + 2][m_y4] != '8')){
						   m_x1 -= 1; m_y1 -= 1;
						   m_x3 += 1; m_y3 += 1;
						   m_y4 -= 2;
                           m_rot = 2;}
						break;
					}
					case 2:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4][m_y4 - 2] != '8')){
						   m_x1 -= 1; m_y1 += 1;
						   m_x3 += 1; m_y3 -= 1;
						   m_x4 -= 2;
                           m_rot = 3;}
						break;
					}
					case 3:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 - 2][m_y4] != '8')){
						   m_x1 += 1; m_y1 += 1;
						   m_x3 -= 1; m_y3 -= 1;
						   m_y4 += 2;
                           m_rot = 4;}
						break;
					}
					case 4:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4][m_y4 + 2] != '8')){
						   m_x1 += 1; m_y1 -= 1;
						   m_x3 -= 1; m_y3 += 1;
						   m_x4 += 2;
                           m_rot = 1;}
						break;
					}
				}
				break;}
		case 'Z':
			{
				switch(m_rot){
					case 1:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 - 2][m_y4] != '8')){
						   m_x1 += 1; m_y1 += 1;
						   m_x3 -= 1; m_y3 += 1;
						   m_x4 -= 2;
                           m_rot = 2;}
						break;
					}
					case 2:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4][m_y4 + 2] != '8')){
						   m_x1 += 1; m_y1 -= 1;
						   m_x3 += 1; m_y3 += 1;
						   m_y4 += 2;
                           m_rot = 3;}
						break;
					}
					case 3:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 + 2][m_y4] != '8')){
						   m_x1 -= 1; m_y1 -= 1;
						   m_x3 += 1; m_y3 -= 1;
						   m_x4 += 2;
                           m_rot = 4;}
						break;
					}
					case 4:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4][m_y4 - 2] != '8')){
						   m_x1 -= 1; m_y1 += 1;
						   m_x3 -= 1; m_y3 -= 1;
						   m_y4 -= 2;
                           m_rot = 1;}
						break;
					}
				}
				break;}
		case 'S':
			{
				switch(m_rot){
					case 1:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4][m_y4 + 2] != '8')){
						   m_x1 -= 1; m_y1 -= 1;
						   m_x3 -= 1; m_y3 += 1;
						   m_y4 += 2;
                           m_rot = 2;}
						break;
					}
					case 2:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 + 2][m_y4] != '8')){
						   m_x1 -= 1; m_y1 += 1;
						   m_x3 += 1; m_y3 += 1;
						   m_x4 += 2;
                           m_rot = 3;}
						break;
					}
					case 3:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4][m_y4 - 2] != '8')){
						   m_x1 += 1; m_y1 += 1;
						   m_x3 += 1; m_y3 -= 1;
						   m_y4 -= 2;
                           m_rot = 4;}
						break;
					}
					case 4:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 - 2][m_y4] != '8')){
						   m_x1 += 1; m_y1 -= 1;
						   m_x3 -= 1; m_y3 -= 1;
						   m_x4 -= 2;
                           m_rot = 1;}
						break;
					}
				}
				break;}
		case 'O':
			{//This tetro remains in the same position regardless of rotation.
				break;}
		case 'T':
			{
				switch(m_rot){
					case 1:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 - 1][m_y4 + 1] != '8')){
						   m_x1 += 1; m_y1 += 1;
						   m_x3 -= 1; m_y3 -= 1;
						   m_x4 -= 1; m_y4 += 1;
                           m_rot = 2;}
						break;
					}
					case 2:
					{
						if ((grid->m_grid[m_x1 + 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 - 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 + 1][m_y4 + 1] != '8')){
						   m_x1 += 1; m_y1 -= 1;
						   m_x3 -= 1; m_y3 += 1;
						   m_x4 += 1; m_y4 += 1;
                           m_rot = 3;}
						break;
					}
					case 3:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 - 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 + 1] != '8')
						 && (grid->m_grid[m_x4 + 1][m_y4 - 1] != '8')){
						   m_x1 -= 1; m_y1 -= 1;
						   m_x3 += 1; m_y3 += 1;
						   m_x4 += 1; m_y4 -= 1;
                           m_rot = 4;}
						break;
					}
					case 4:
					{
						if ((grid->m_grid[m_x1 - 1][m_y1 + 1] != '8')
						 && (grid->m_grid[m_x3 + 1][m_y3 - 1] != '8')
						 && (grid->m_grid[m_x4 - 1][m_y4 - 1] != '8')){
						   m_x1 -= 1; m_y1 += 1;
						   m_x3 += 1; m_y3 -= 1;
						   m_x4 -= 1; m_y4 -= 1;
                           m_rot = 1;}
						break;
					}
				}
				break;}
}
	grid->m_grid[m_x1][m_y1] = '1';
	grid->m_grid[m_x2][m_y2] = '1';
	grid->m_grid[m_x3][m_y3] = '1';
	grid->m_grid[m_x4][m_y4] = '1';
	cout << "rotateRight successful\n";
	writeStats(outFile);
	grid->writeGrid(outFile);
}
//shifts tetro down one row in the grid.
//if movement down is impossible, triggers lockIn.
void TETRO::moveDown(ofstream& outFile, GRID * grid, int * score, int * lines, int * level)		//Moves tetro down one row
{
	cout << "begin moveDown\n";
	grid->m_grid[m_x1][m_y1] = '=';
	grid->m_grid[m_x2][m_y2] = '=';
	grid->m_grid[m_x3][m_y3] = '=';
	grid->m_grid[m_x4][m_y4] = '=';
	if    ((grid->m_grid[m_x1][m_y1 - 1] != '8')
		&& (grid->m_grid[m_x2][m_y2 - 1] != '8')
		&& (grid->m_grid[m_x3][m_y3 - 1] != '8')
		&& (grid->m_grid[m_x4][m_y4 - 1] != '8')
		&& (m_y1 !=0) && (m_y2 !=0) && (m_y3 !=0) && (m_y4 !=0))
	
	{
		m_y1 -= 1;
		m_y2 -= 1;
		m_y3 -= 1;
		m_y4 -= 1;
		grid->m_grid[m_x1][m_y1] = '1';
		grid->m_grid[m_x2][m_y2] = '1';
		grid->m_grid[m_x3][m_y3] = '1';
		grid->m_grid[m_x4][m_y4] = '1';
	}
	else
	{
		//cout << "moveDown successful";
		lockIn(outFile, grid, score, lines, level);
		reset(outFile, grid);
		dropIn2(outFile, grid);
	}
	cout << "moveDown successful\n";
	writeStats(outFile);
	grid->writeGrid(outFile);
}
//shifts tetro one column left in the grid, if possible.
//checks for collisions with old blocks and 
//edge of playing field.
void TETRO::moveLeft(ofstream& outFile, GRID * grid)		//Moves tetro left one column
{
	cout << "begin moveLeft\n";
	grid->m_grid[m_x1][m_y1] = '=';
	grid->m_grid[m_x2][m_y2] = '=';
	grid->m_grid[m_x3][m_y3] = '=';
	grid->m_grid[m_x4][m_y4] = '=';
	if    ((grid->m_grid[m_x1 - 1][m_y1] != '8')
		&& (grid->m_grid[m_x2 - 1][m_y2] != '8')
		&& (grid->m_grid[m_x3 - 1][m_y3] != '8')
		&& (grid->m_grid[m_x4 - 1][m_y4] != '8')
		&& (m_x1 != 0) && (m_x2 != 0) && (m_x3 != 0) && (m_x4 != 0))
	
	{
		m_x1 -= 1;
		m_x2 -= 1;
		m_x3 -= 1;
		m_x4 -= 1;
	}
	grid->m_grid[m_x1][m_y1] = '1';
	grid->m_grid[m_x2][m_y2] = '1';
	grid->m_grid[m_x3][m_y3] = '1';
	grid->m_grid[m_x4][m_y4] = '1';
	cout << "moveLeft successful\n";
	writeStats(outFile);
	grid->writeGrid(outFile);
}
//shifts tetro one column right in the grid.
//checks for collisions with old blocks and 
//edge of playing field.
void TETRO::moveRight(ofstream& outFile, GRID * grid)		//Moves tetro right one column
{
	cout << "begin moveRight\n";
	grid->m_grid[m_x1][m_y1] = '=';
	grid->m_grid[m_x2][m_y2] = '=';
	grid->m_grid[m_x3][m_y3] = '=';
	grid->m_grid[m_x4][m_y4] = '=';
	if    ((grid->m_grid[m_x1 + 1][m_y1] != '8')
		&& (grid->m_grid[m_x2 + 1][m_y2] != '8')
		&& (grid->m_grid[m_x3 + 1][m_y3] != '8')
		&& (grid->m_grid[m_x4 + 1][m_y4] != '8')
		&& (m_x1 != 9) && (m_x2 != 9) && (m_x3 != 9) && (m_x4 != 9))
	
	{
		m_x1 += 1;
		m_x2 += 1;
		m_x3 += 1;
		m_x4 += 1;
	}
	grid->m_grid[m_x1][m_y1] = '1';
	grid->m_grid[m_x2][m_y2] = '1';
	grid->m_grid[m_x3][m_y3] = '1';
	grid->m_grid[m_x4][m_y4] = '1';
	cout << "moveRight successful\n";
	writeStats(outFile);
	grid->writeGrid(outFile);
}
//drops tetro down in the grid until it hits something.
//activates lockIn function.
void TETRO::slamDown(ofstream& outFile, GRID * grid, int * score, int * lines, int * level)
{
	cout << "begin slamDown\n";
	grid->m_grid[m_x1][m_y1] = '=';
	grid->m_grid[m_x2][m_y2] = '=';
	grid->m_grid[m_x3][m_y3] = '=';
	grid->m_grid[m_x4][m_y4] = '=';
	while ((grid->m_grid[m_x1][m_y1 - 1] != '8')
		&& (grid->m_grid[m_x2][m_y2 - 1] != '8')
		&& (grid->m_grid[m_x3][m_y3 - 1] != '8')
		&& (grid->m_grid[m_x4][m_y4 - 1] != '8')
		&& (m_y1 != 0) && (m_y2 != 0) && (m_y3 != 0) && (m_y4 != 0))
	
	{
		m_y1 -= 1;
		m_y2 -= 1;
		m_y3 -= 1;
		m_y4 -= 1;
	}
	
	cout << "slamDown successful\n";

	//string bottomRow = grid->rowGet(1);

	writeStats(outFile);
	grid->writeGrid(outFile);
	lockIn(outFile, grid, score, lines, level);
	reset(outFile, grid);
	dropIn2(outFile, grid);
	/*for (int i = 0; i <9; i++){
		grid->m_grid[i][1] = bottomRow.at(i);
	}*/
}
//changes grid array at tetro's currentr position(s).
//these spots will be treated like the edge
//of the playing field
void TETRO::lockIn(ofstream& outFile, GRID * grid, int * score, int * lines, int * level)			//Locks the tetro in place when it can't move any further down.
{
	cout << "begin lockIn\n";
	grid->m_grid[m_x1][m_y1] = '8';
	grid->m_grid[m_x2][m_y2] = '8';
	grid->m_grid[m_x3][m_y3] = '8';
	grid->m_grid[m_x4][m_y4] = '8';

	int numCleared = 0;
	for (int y = 0; y < 21; y++)
	{
		if (grid->rowGet(y) == "8888888888")
		{
			numCleared +=1;
			grid->rowClear(y, score, lines, level);
			switch(numCleared)
			{
			case 1:
				*score += ((*level + 1) * 40);
				break;
			case 2:
				*score += ((*level + 1) * 100);
				break;
			case 3:
				*score += ((*level + 1) * 300);
				break;
			case 4:
				*score += ((*level + 1) * 1200);
				break;
	}
			grid->rowShift(y);
		}
	}
	cout << "lockIn successful\n";
	printStats();
	grid->printGrid();
	system("pause");
	grid->writeGrid(outFile);
}
//leftover function, meant to be used by dropIn.
/*void TETRO::shiftUp(void)
{
	cout << "begin shiftUp\n";
	m_y1 +=3;
	m_y2 +=3;
	m_y3 +=3;
	m_y4 +=3;
	cout << "shiftUp successful\n";
}*/
//outputs current coordinates of tetro to console.
void TETRO::printStats(void)
{
	cout << "Current Position:\n";
	cout << "Block 1: " << m_x1 << ", " << m_y1 <<"\n";
	cout << "Block 2: " << m_x2 << ", " << m_y2 <<"\n";
	cout << "Block 3: " << m_x3 << ", " << m_y3 <<"\n";
	cout << "Block 4: " << m_x4 << ", " << m_y4 <<"\n";
}
//supposed to write current coordinates to a file.
void TETRO::writeStats(ofstream& outFile)
{
	cout << "Current Position:\n";
	cout << "Block 1: " << m_x1 << ", " << m_y1 <<"\n";
	cout << "Block 2: " << m_x2 << ", " << m_y2 <<"\n";
	cout << "Block 3: " << m_x3 << ", " << m_y3 <<"\n";
	cout << "Block 4: " << m_x4 << ", " << m_y4 <<"\n";
}
