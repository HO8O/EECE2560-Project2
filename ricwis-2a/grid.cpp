#include "stdafx.h"
#include "grid.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

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

std::string parseOutSpace(const std::string &string)
{
	std::string output;
	for (size_t i = 0; i < string.size(); ++i)
	{
		if (string[i] != ' ')
		{
			output += string[i];
		}
	}
	
	return output;
}

void grid::ReadFromFile(std::string path)
{
	myGrid.clear();
	std::ifstream file(path);
	if (file.is_open())
	{
		std::string str;
		//read dimensions
		std::getline(file, str, ' ');
		width = std::stoi(str, nullptr);
		std::getline(file, str);
		height = std::stoi(str, nullptr);

		std::cout << "Grid is " << width << " x " << height << '\n';

		//read each row
		while (std::getline(file, str))
		{
			std::vector<char> row;
			std::string rowbuffer = parseOutSpace(str);
			for (int i = 0; i < width; i++)
			{
				row.push_back(rowbuffer[i]);
			}
			myGrid.push_back(row);
		}


	}
	else
	{
		std::cout << "Opening grid failed!";
	}
}

std::vector < std::vector<char> > grid::GetGrid()const
{
	return myGrid;
}

std::ostream &operator<<(std::ostream &stream, const grid &mygrid)
{
	for each(std::vector<char> row in mygrid.GetGrid())
	{
		for each(char c in row)
		{
			stream << c << ' ';
		}
		stream << "\n";
	}
	return stream;
}