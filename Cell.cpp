#include "Cell.h"

Cell::Cell(int x, int y, bool isAlive)
{
	this->x = x;
	this->y = y;
	this->isAlive = isAlive;
}

bool Cell::WasAlive()
{
	if (this->prev == nullptr)
		return false;
	else
		return this->prev->isAlive;
}

Cell* Cell::GetPrev()
{
	return this->prev;
}

void Cell::setIsAlive(bool isAlive)
{
	this->prev = new Cell(this->x, this->y, isAlive);
	this->isAlive = isAlive;
}

bool Cell::getIsAlive()
{
	return this->isAlive;
}

RECT* Cell::GetRect()
{
	return this->rect;
}
