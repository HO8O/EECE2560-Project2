#include "stdafx.h"
#include "wordlist.h"
#include <iostream>
#include <string>
#include <fstream>

wordlist::wordlist()
{
}


wordlist::~wordlist()
{
}


void wordlist::ReadFromFile(std::string path)
{
	myWordList.clear();
	std::ifstream file(path);
	if (file.is_open())
	{
		std::string str;
		while (std::getline(file, str))
		{
			myWordList.push_back(str);
		}
	}
	else
	{
		std::cout << "Opening wordlist failed!";
	}
}


wordlist::wordlist(std::string path)
{
	ReadFromFile(path);
}


void wordlist::insertionsort()
{
}


void wordlist::quicksort()
{
}


void wordlist::mergesort()
{
}


std::string wordlist::lookup(std::string word)const
{
	return std::string();
}

std::vector<std::string> wordlist::GetWords()const
{
	return myWordList;
}

std::ostream &operator<<(std::ostream &stream, const wordlist &words)
{
	for each(std::string str in words.GetWords())
	{
		stream << str << "\n";
	}
	return stream;
}