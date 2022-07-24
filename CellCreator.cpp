#include "CellCreator.h"

CellCreator::CellCreator(int width, int height, CellDrawer* drawer, COLORREF aliveColor, COLORREF deadColor)
{
	this->aliveColor = aliveColor;
	this->deadColor = deadColor;
	this->width = width;
	this->height = height;
	this->drawer = drawer;
}

CellCreator::~CellCreator()
{
	this->cells.clear();
	delete &this->aliveColor;
	delete &this->deadColor ;
	
}

Cell* CellCreator::createCell(int x, int y, int cellSize, bool isAlive, HDC* hdc)
{
	auto color = isAlive ? aliveColor : deadColor;
	drawer->DrawCell(x,y,cellSize, color,hdc);

	auto cell = new Cell(x, y, isAlive);

	return cell;
}

p_cellsMatrix CellCreator::initializeCells(int cellSize, HDC* hdc)
{
	
	for (int x = 0; x < width; x += cellSize)
	{
		std::vector<Cell*> row = std::vector<Cell*>();
		for (int y = 0; y < height; y += cellSize) {
			auto cell = createCell(x, y, cellSize, true, hdc);
			row.push_back(cell);
		}
		cells.push_back(row);
	}
	
	return cells;
}

p_cellsMatrix CellCreator::iterateLife(p_cellsMatrix cells, int cellSize, HDC* hdc)
{
	for (int x = 0; x < cells.size(); x += 1) // cellsize = width = height of single cell
	{
		for (int y = 0; y < cells[x].size(); y += 1) {
			auto cell = cells[x][y];
			auto isAlive = cell->getIsAlive();
			 createCell(cell->x, cell->y, cellSize, isAlive, hdc);
		}
	}

	return cells;
}