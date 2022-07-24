#pragma once
#include <windows.h>

struct Cell
{
	friend class CellCreator;

private:
	int x;
	int y;
	bool isAlive;
	RECT* rect;
	Cell* prev;
public:
	Cell(int x, int y, bool isAlive);
	bool WasAlive();
	Cell* GetPrev();
	void setIsAlive(bool isAlive);
	bool getIsAlive();
	RECT* GetRect();
};

