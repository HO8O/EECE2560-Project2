#include "stdafx.h"
#include "grid.h"

#include <fstream>
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
	ReadFromFile(path);
}


void grid::ReadFromFile(std::string path)
{
	myGrid.clear();
	std::ifstream file(path);
	if (file.is_open())
	{
		char c;

	}
	else
	{
		//std::cout << "Opening wordlist failed!";
	}
}
