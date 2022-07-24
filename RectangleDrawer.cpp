#include "RectangleDrawer.h"


CellDrawer::CellDrawer(HWND hWnd)
{
	this->hWnd = hWnd;
}

CellDrawer::~CellDrawer()
{
	this->hWnd = nullptr;

}

RECT* CellDrawer::DrawCell(int x, int y, int cellSize, COLORREF color, HDC* hdc)
{
	HBRUSH hBrush = CreateSolidBrush(color);
	tagRECT rect = { x + 1, y + 1, cellSize + x, cellSize + y };
	FillRect(*hdc, &rect, hBrush);
	DeleteObject(hBrush);
	
	return &rect;
}
