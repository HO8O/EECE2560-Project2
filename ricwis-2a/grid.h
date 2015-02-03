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
private:
	std::vector<std::vector<char>> myGrid;
};

