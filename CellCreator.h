#pragma once
#include "Cell.h"
#include <vector>
#include "RectangleDrawer.h"
#include "GameOfLifeGlobals.h"
class CellCreator
{
private:
	int width;
	int height;
	COLORREF aliveColor;
	COLORREF deadColor;
	p_cellsMatrix cells;
	CellDrawer* drawer;

public:
	CellCreator(int width, int height, CellDrawer* drawer,COLORREF aliveColor,COLORREF deadColor);
	~CellCreator();
	Cell* createCell(int x, int y, int cellSize, bool isAlive, HDC* hdc);
	p_cellsMatrix initializeCells(int cellSize, HDC* hdc);
	p_cellsMatrix iterateLife(p_cellsMatrix cells, int cellSize, HDC* hdc);
};

