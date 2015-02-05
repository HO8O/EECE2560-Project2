#include "stdafx.h"
#include "common.h"
#include "grid.h"
#include "wordlist.h"

#include <string>
#include <iostream>

void checkWordsRight(const wordlist &mylist, const grid &g, const unsigned int x, const unsigned int y)
{
	std::string myWord;
	myWord.push_back(g.GetGrid()[x][y]);

	//so we start with 5 letters to save the lookups
	for (int j = 1; j < 4; j++)
	{
		unsigned int newX = (x + j) % g.GetWidth();
		myWord.push_back(g.GetGrid()[newX][y]);
	}

	for (int i = 5; i <= 22; i++)
	{
		if (mylist.lookup(myWord))
		{
			std::cout << myWord << "\n";
			return;
		}

		unsigned int newX = (x + i) % g.GetWidth();
		myWord.push_back(g.GetGrid()[newX][y]);
	}
}

// Shortest word is 5
// Longest word is 22
void findMatches(const wordlist &wl, const grid &g)
{
	for (int x = 0; x < g.GetWidth(); x++)
	{
		for (int y = 0; y < g.GetHeight(); y++)
		{
			
		}
	}
}

void search(int alg)
{
	//load wordlist
	std::string wordListPath;
	std::cout << "Please enter path to wordlist : ";
	std::cin >> wordListPath;
	std::cout << "Loading word list....\n";
	wordlist list = wordlist(wordListPath);

	//load grid
	std::string gridPath;
	std::cout << "Please enter path to grid : ";
	std::cin >> gridPath;
	std::cout << "Loading grid....\n";
	grid myGrid = grid(gridPath);

	//sort switch
	switch (alg)
	{
	case 1:
		//myList.insertionsort();
		break;
	case 2:
		//myList.mergesort();
		break;
	case 3:
		//myList.quicksort();
		break;
	default:
		std::cout << "Invalid alg";
		break;
	}

	findMatches(list, myGrid);
}