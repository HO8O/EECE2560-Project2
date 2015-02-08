#include "stdafx.h"
#include "common.h"
#include "grid.h"
#include "wordlist.h"

#include <string>
#include <iostream>


/*
*	Function : checkWordsRight()
*	Summary : Loops to the right of the given coordinate to see if there is a word contained in the word list
*	Params : myWordList, grid, x coordinate, y coordinate
*	Returns : void
*/
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


/*
*	Function : checkWordsLeft()
*	Summary : Loops to the left of the given coordinate to see if there is a word contained in the word list
*	Params : myWordList, grid, x coordinate, y coordinate
*	Returns : void
*/
void checkWordsLeft(const wordlist &mylist, const grid &g, const unsigned int x, const unsigned int y)
{
	std::string myWord;
	myWord.push_back(g.GetGrid()[x][y]);

	//so we start with 5 letters to save the lookups
	for (unsigned int j = 1; j < 4; j++)
	{
		unsigned int newX;
		if (x - j >= g.GetWidth())
		{
			newX = g.GetWidth() - 1;
		}
		else
		{
			newX = x - j;
		}
		myWord.push_back(g.GetGrid()[newX][y]);
	}

	for (unsigned int i = 5; i <= 22; i++)
	{
		if (mylist.lookup(myWord))
		{
			std::cout << myWord << "\n";
			return;
		}

		unsigned int newX;
		if (x - i >= g.GetWidth())
		{
			newX = g.GetWidth() - 1;
		}
		else
		{
			newX = x - i;
		}

		myWord.push_back(g.GetGrid()[newX][y]);
	}
}


/*
*	Function : checkWordsUp()
*	Summary : Loops above the given coordinate to see if there is a word contained in the word list
*	Params : myWordList, grid, x coordinate, y coordinate
*	Returns : void
*/
void checkWordsUp(const wordlist &mylist, const grid &g, const unsigned int x, const unsigned int y)
{
	std::string myWord;
	myWord.push_back(g.GetGrid()[x][y]);

	//so we start with 5 letters to save the lookups
	for (unsigned int j = 1; j < 4; j++)
	{
		unsigned int newY;
		if (y - j >= g.GetHeight())
		{
			newY = g.GetWidth() - 1;
		}
		else
		{
			newY = y - j;
		}
		myWord.push_back(g.GetGrid()[x][newY]);
	}

	for (unsigned int i = 5; i <= 22; i++)
	{
		if (mylist.lookup(myWord))
		{
			std::cout << myWord << "\n";
			return;
		}

		unsigned int newY;
		if (y - i >= g.GetHeight())
		{
			newY = g.GetHeight() - 1;
		}
		else
		{
			newY = y - i;
		}

		myWord.push_back(g.GetGrid()[x][newY]);
	}
}


/*
*	Function : checkWordsDown()
*	Summary : Loops below the given coordinate to see if there is a word contained in the word list
*	Params : myWordList, grid, x coordinate, y coordinate
*	Returns : void
*/
void checkWordsDown(const wordlist &mylist, const grid &g, const unsigned int x, const unsigned int y)
{
	std::string myWord;
	myWord.push_back(g.GetGrid()[x][y]);

	//so we start with 5 letters to save the lookups
	for (int j = 1; j < 4; j++)
	{
		unsigned int newY = (y + j) % g.GetHeight();
		myWord.push_back(g.GetGrid()[x][newY]);
	}

	for (int i = 5; i <= 22; i++)
	{
		if (mylist.lookup(myWord))
		{
			std::cout << myWord << "\n";
			return;
		}

		unsigned int newY = (y + i) % g.GetHeight();
		myWord.push_back(g.GetGrid()[x][newY]);
	}
}


/*
*	Function : checkWordsUpRight()
*	Summary : Loops up and to the right of the given coordinate to see if there is a word contained in the word list
*	Params : myWordList, grid, x coordinate, y coordinate
*	Returns : void
*/
void checkWordsUpRight(const wordlist &mylist, const grid &g, const unsigned int x, const unsigned int y)
{
	std::string myWord;
	myWord.push_back(g.GetGrid()[x][y]);

	//so we start with 5 letters to save the lookups
	for (int j = 1; j < 4; j++)
	{
		unsigned int newX = (x + j) % g.GetWidth();
		unsigned int newY;
		if (y - j >= g.GetHeight())
		{
			newY = g.GetHeight() - 1;
		}
		else
		{
			newY = y - j;
		}
		myWord.push_back(g.GetGrid()[newX][newY]);
	}

	for (int i = 5; i <= 22; i++)
	{
		if (mylist.lookup(myWord))
		{
			std::cout << myWord << "\n";
			return;
		}

		unsigned int newX = (x + i) % g.GetWidth();
		unsigned int newY;
		if (y - i >= g.GetHeight())
		{
			newY = g.GetHeight() - 1;
		}
		else
		{
			newY = y - i;
		}
		myWord.push_back(g.GetGrid()[newX][newY]);
	}
}


/*
*	Function : checkWordsDownRight()
*	Summary : Loops down and to the right of the given coordinate to see if there is a word contained in the word list
*	Params : myWordList, grid, x coordinate, y coordinate
*	Returns : void
*/
void checkWordsDownRight(const wordlist &mylist, const grid &g, const unsigned int x, const unsigned int y)
{
	std::string myWord;
	myWord.push_back(g.GetGrid()[x][y]);

	//so we start with 5 letters to save the lookups
	for (int j = 1; j < 4; j++)
	{
		unsigned int newX = (x + j) % g.GetWidth();
		unsigned int newY = (y + j) % g.GetHeight();
		myWord.push_back(g.GetGrid()[newX][newY]);
	}

	for (int i = 5; i <= 22; i++)
	{
		if (mylist.lookup(myWord))
		{
			std::cout << myWord << "\n";
			return;
		}

		unsigned int newX = (x + i) % g.GetWidth();
		unsigned int newY = (y + i) % g.GetHeight();
		myWord.push_back(g.GetGrid()[newX][newY]);
	}
}


/*
*	Function : checkWordsUpLeft()
*	Summary : Loops up and to the left of the given coordinate to see if there is a word contained in the word list
*	Params : myWordList, grid, x coordinate, y coordinate
*	Returns : void
*/
void checkWordsUpLeft(const wordlist &mylist, const grid &g, const unsigned int x, const unsigned int y)
{
	std::string myWord;
	myWord.push_back(g.GetGrid()[x][y]);

	//so we start with 5 letters to save the lookups
	for (unsigned int j = 1; j < 4; j++)
	{
		unsigned int newX;
		if (x - j >= g.GetWidth())
		{
			newX = g.GetWidth() - 1;
		}
		else
		{
			newX = x - j;
		}
		unsigned int newY;
		if (y - j >= g.GetHeight())
		{
			newY = g.GetHeight() - 1;
		}
		else
		{
			newY = y - j;
		}
		myWord.push_back(g.GetGrid()[newX][newY]);
	}

	for (unsigned int i = 5; i <= 22; i++)
	{
		if (mylist.lookup(myWord))
		{
			std::cout << myWord << "\n";
			return;
		}

		unsigned int newX;
		if (x - i >= g.GetWidth())
		{
			newX = g.GetWidth() - 1;
		}
		else
		{
			newX = x - i;
		}
		unsigned int newY;
		if (y - i >= g.GetHeight())
		{
			newY = g.GetHeight() - 1;
		}
		else
		{
			newY = y - i;
		}
		myWord.push_back(g.GetGrid()[newX][newY]);
	}
}


/*
*	Function : checkWordsDownLeft()
*	Summary : Loops down to the left of the given coordinate to see if there is a word contained in the word list
*	Params : myWordList, grid, x coordinate, y coordinate
*	Returns : void
*/
void checkWordsDownLeft(const wordlist &mylist, const grid &g, const unsigned int x, const unsigned int y)
{
	std::string myWord;
	myWord.push_back(g.GetGrid()[x][y]);

	//so we start with 5 letters to save the lookups
	for (unsigned int j = 1; j < 4; j++)
	{
		unsigned int newX;
		if (x - j >= g.GetWidth())
		{
			newX = g.GetWidth() - 1;
		}
		else
		{
			newX = x - j;
		}
		unsigned int newY = (y + j) % g.GetHeight();
		myWord.push_back(g.GetGrid()[newX][newY]);
	}

	for (unsigned int i = 5; i <= 22; i++)
	{
		if (mylist.lookup(myWord))
		{
			std::cout << myWord << "\n";
			return;
		}

		unsigned int newX;
		if (x - i >= g.GetWidth())
		{
			newX = g.GetWidth() - 1;
		}
		else
		{
			newX = x - i;
		}
		unsigned int newY = (y + i) % g.GetHeight();
		myWord.push_back(g.GetGrid()[newX][newY]);
	}
}


/*
*	Function : findMatches()
*	Summary : Loops through each grid coordinate and runs all eight check word functions
*	Params : myWordList, grid, x coordinate, y coordinate
*	Returns : void
*/
// Shortest word is 5
// Longest word is 22
void findMatches(const wordlist &wl, const grid &g)
{
	for (int x = 0; x < g.GetWidth(); x++)
	{
		for (int y = 0; y < g.GetHeight(); y++)
		{
			checkWordsLeft(wl, g, x, y);
			checkWordsRight(wl, g, x, y);
			checkWordsUp(wl, g, x, y);
			checkWordsDown(wl, g, x, y);

			checkWordsUpRight(wl, g, x, y);
			checkWordsDownRight(wl, g, x, y);
			checkWordsUpLeft(wl, g, x, y);
			checkWordsDownLeft(wl, g, x, y);
		}
	}
}


/*
*	Function : search()
*	Summary : Loads the wordlist and grid then runs the selected sort
*	Params : int alg which runs the respective sort
*	Returns : void
*/
void search(int alg)
{
	//load wordlist
	std::string wordListPath;
	std::cout << "Please enter path to wordlist : ";
	std::cin >> wordListPath;
	std::cout << "Loading word list....\n";
	wordlist myList = wordlist(wordListPath);

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
		myList.insertionsort();
		break;
	case 2:
		myList.mergesort();
		break;
	case 3:
		myList.quicksort();
		break;
	default:
		std::cout << "Invalid alg";
		break;
	}

	findMatches(myList, myGrid);
}