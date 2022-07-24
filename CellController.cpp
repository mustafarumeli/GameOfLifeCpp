#include "CellController.h"

CellController::CellController(p_cellsMatrix cells)
{
    this->cells = cells;
}

CellController::~CellController()
{
}

Cell* CellController::getCell(int x, int y)
{
    auto cell = this->cells[x][y];
    return cell;
}


void CellController::updateCellState(Cell *cell,bool isAlive)
{
    cell->setIsAlive(isAlive);
}
