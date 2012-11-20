//Tetris
//Created by the seat of Charles McChesney's pants,
//over the course of more than a year.
//Not guaranteed to work properly.

#include <windows.h>
#include <stdlib.h>
#include <string>
#include <tchar.h>
#include <gdiplus.h>
//#include <objidl.h>
#include <ctime>
#include <string>
//#include <cstdlib>
//#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>

using namespace Gdiplus;
using namespace std;

#pragma comment (lib,"Gdiplus.lib")
using namespace std;

#include "Grid.h"
#include "Tetro.h"
#include "Resource.h"

void OnPaint(HWND hWnd, HDC hdc);

//Main window class name
static TCHAR szWindowClass[] = _T("tetrisknockoff");


//window title bar
static TCHAR szTitle[] = _T("Tetris Knockoff by Charles McChesney");

HINSTANCE hInst;
HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
COLORREF clrGray = RGB(200, 200, 200);
COLORREF clrBlack = RGB(0, 0, 0);
UINT timer_id = 0;
BOOL bQuit = FALSE;

//ofstream outFile;
//outFile.open("testData.txt", ios::app);
//FILE * pFile = &outFile;

int scoreNum, linesNum, levelNum = 0;
int * pScore = &scoreNum;
int * pLines = &linesNum;
int * pLevel = &linesNum;

GRID grid;
GRID * pGrid = &grid;

TETRO tetro(pGrid);

TETRO * pTetro = &tetro;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine, int nCmdShow)
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	hBrush = CreateSolidBrush(clrBlack);

	WNDCLASSEX wcex;

	wcex.cbSize =  sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TETRIS));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
	wcex.lpszMenuName = NULL;
	wcex.hInstance = hInstance;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_TETRISMINI));

	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("RegisterClassEX failed."), _T("Tetris Knockoff"), NULL);
		return 1;
	}
	hInst = hInstance;

	HWND hWnd = CreateWindow(szWindowClass,
		szTitle,
		WS_POPUPWINDOW | WS_MINIMIZEBOX | WS_CAPTION,
		CW_USEDEFAULT, CW_USEDEFAULT, 705, 737, NULL, NULL,
		hInstance, NULL);

	if(!hWnd) {
		MessageBox(NULL, _T("CreateWindow failed."), _T("Tetris Knockoff"), NULL);
		return 1;
	}

	AllocConsole();

    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;
	
	time_t now;
	time(&now);
	srand(now);
	
	timer_id = SetTimer( hWnd, 101, 1 *2000, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	tetro.dropIn2(pGrid);
	
	while (!bQuit)
	{
		while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}

	GdiplusShutdown(gdiplusToken);
	//outFile.close();
	return 0;
}

void OnPaint(HWND hWnd, HDC hdc){

	cout << "begin paint\n";
	tetro.printStats();
	//grid.printGrid();

	RECT rect1;
	GetClientRect(hWnd, &rect1);
	FillRect(hdc, &rect1, hBrush);
	
	Graphics graphics(hdc);
	
	Image bGround(L"Back.bmp");
	Image lockedBlock(L"LockedBlock.bmp");
	Image tetroBlock(L"TetroBlock.bmp");
	
	RECT rect2;
	
	TCHAR scoreText[] = _T("SCORE");
	TCHAR levelText[] = _T("LEVEL");
	TCHAR linesText[] = _T("LINES");
	
	HFONT font;
	HDC MemDC;

	//get window dimensions
	GetClientRect(hWnd, &rect2);
	//create screen-sized bmp
	MemDC = CreateCompatibleDC(hdc);
	HBITMAP Membmp = CreateCompatibleBitmap(hdc, rect2.right, rect2.bottom);
	//create a temp graphics obj
	SelectObject(MemDC, Membmp);
	Graphics graph(MemDC);
	SolidBrush blackbrush(Color(0, 0, 0));
	
	graph.FillRectangle(&blackbrush, rect2.left, rect2.top, rect2.right, rect2.bottom);
	graph.DrawImage(&bGround, 0, 0, 704, 704);
	
	for (int xCoord = 0; xCoord < 17; xCoord++)
	{
		for (int yCoord = 0; yCoord < 21; yCoord++)
		{
			if (pGrid->m_grid[xCoord][yCoord] == '8')
			{graph.DrawImage(&lockedBlock, ((xCoord * 32 + 64)), ((608 - (32 * yCoord))), 32, 32);}
			else if (pGrid->m_grid[xCoord][yCoord] == '1')
			{graph.DrawImage(&tetroBlock, ((xCoord * 32 + 64)), ((608 - (32 * yCoord))), 32, 32);}
		}
	}
	
	font = CreateFont(32, 32, 0, 0, FW_MEDIUM, FALSE, FALSE, FALSE,  ANSI_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_MODERN, _T("OCR A Extended"));
		SelectObject(MemDC, font);

		SetTextColor(MemDC, clrGray);
		SetBkColor(MemDC, clrBlack);

		TextOut(MemDC, 448,  32, scoreText, _tcslen(scoreText));
		TextOut(MemDC, 448, 128, levelText, _tcslen(levelText));
		TextOut(MemDC, 448, 224, linesText, _tcslen(linesText));

		//copy bits
		BitBlt(hdc, 0, 0, 704, 704, MemDC, 0, 0, SRCCOPY);

		//restore old
		DeleteDC(MemDC);
		DeleteObject(Membmp);

		cout << "painting done\n";
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch(message)
	{
	case WM_TIMER:
		tetro.moveDown(pGrid, pScore, pLines, pLevel);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_NUMPAD1:
			//timer_id = SetTimer( hWnd, 101, 1 *2000, NULL);
			tetro.moveLeft(pGrid);
			break;
		case VK_NUMPAD2:
			//timer_id = SetTimer( hWnd, 101, 1 *2000, NULL);
			tetro.moveDown(pGrid, pScore, pLines, pLevel);
			break;
		case VK_NUMPAD3:
			//timer_id = SetTimer( hWnd, 101, 1 *2000, NULL);
			tetro.moveRight(pGrid);
			break;
		case VK_NUMPAD4:
			//timer_id = SetTimer( hWnd, 101, 1 *2000, NULL);
			tetro.rotateLeft(pGrid);
			break;
		case VK_NUMPAD5:
			//timer_id = SetTimer( hWnd, 101, 1 *2000, NULL);
			tetro.slamDown(pGrid, pScore, pLines, pLevel);
			break;
		case VK_NUMPAD6:
			//timer_id = SetTimer( hWnd, 101, 1 *2000, NULL);
			tetro.rotateRight(pGrid);
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc=BeginPaint(hWnd, &ps);
		OnPaint(hWnd, hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_ERASEBKGND:
		return true;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}