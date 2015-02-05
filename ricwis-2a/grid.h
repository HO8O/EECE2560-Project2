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
	std::vector < std::vector<char> > GetGrid()const;
	int grid::GetWidth()const;
	int grid::GetHeight()const;
private:
	std::vector<std::vector<char>> myGrid;
	int height;
	int width;
};

std::ostream &operator<<(std::ostream &stream, const grid &mygrid);

