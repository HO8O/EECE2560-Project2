#include "stdafx.h"
#include "grid.h"
#include <string>
#include <vector>

grid::grid()
{
}


grid::~grid()
{
	myGrid.clear();
}


grid::grid(std::string path)
{
	readFromFile(path);
}


void grid::readFromFile(std::string path)
{
}
