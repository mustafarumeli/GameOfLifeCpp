#pragma once
#include <windows.h>
#include <wingdi.h>
#include <WinUser.h>



class CellDrawer
{

private:
	HWND  hWnd;
public:
	CellDrawer(HWND hWnd);
	~CellDrawer();
	RECT* DrawCell(int x, int y, int cellSize, COLORREF color, HDC* hdc);
};

