#pragma once


#include "GameOfLifeGlobals.h"

class CellController
{
private:
	p_cellsMatrix cells;
public:
	CellController(p_cellsMatrix cells);
	~CellController();
	Cell* getCell(int x, int y);
	void updateCellState(Cell* cell, bool isAlive);
	
};
	

