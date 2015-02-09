#pragma once
#include <string>
#include <vector>
class grid
{
public:
	grid();
	~grid();
	grid(std::string path);
	void ReadFromFile(std::string path);
	std::vector < std::vector<char> > GetGrid();
	unsigned int grid::GetWidth()const;
	unsigned int grid::GetHeight()const;
	std::vector<std::vector<char>> myGrid;
private:
	unsigned int height;
	unsigned int width;
};

std::ostream &operator<<(std::ostream &stream, const grid &mygrid);

