#include "stdafx.h"
#include "grid.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>


/*
*	Function : grid()
*	Summary : Constructs the Grid object
*	Params : N/A
*	Returns : void
*/
grid::grid()
{
}


/*
*	Function : ~grid()
*	Summary : Deconstructs the Grid object
*	Params : N/A
*	Returns : void
*/
grid::~grid()
{
	myGrid.clear();
}


/*
*	Function : grid()
*	Summary : Constructs the grid object and immediately calls ReadFromFile
*	Params : String with a path to a file
*	Returns : void
*/
grid::grid(std::string path)
{
	ReadFromFile(path);
}


/*
*	Function : parseOutSpace()
*	Summary : Parses out the spaces of a string
*	Params : String
*	Returns : String with spaces sparsed out
*/
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


/*
*	Function : ReadFromFile()
*	Summary : Reads and populates the grid from a file
*	Params : String with a path to a file
*	Returns : void
*/
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
		for (int j = 0; j < height; j++)
		{
			std::getline(file, str);
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


/*
*	Function : getGrid()
*	Summary : Returns myGrid
*	Params : N/A
*	Returns : Vector of char vectors
*/
std::vector < std::vector<char> > grid::GetGrid()const
{
	return myGrid;
}


/*
*	Function : &operator<<()
*	Summary : Overloads the << operator to output the grid
*	Params : N/A
*	Returns : ostream
*/
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


/*
*	Function : getHeight()
*	Summary : Returns the grid height
*	Params : N/A
*	Returns : Int height
*/
int grid::GetHeight()const
{
	return height;
}


/*
*	Function : GetWidth()
*	Summary : Returns the grid width
*	Params : N/A
*	Returns : Int width
*/
int grid::GetWidth()const
{
	return width;
}