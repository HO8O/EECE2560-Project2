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


int partition(std::vector<std::string> list, int left, int right)
{
	std::string p = list[left];
	int i = left;
	int j = right + 1;
	do {
		do {
			i = i + 1;
			
		} while (list[i] < p && list[i] < right);
		do{
			j = j - 1;
		} while (list[j] > p);
		swap(list[i], list[j]);
	} while (i < j);
	swap(list[i], list[j]);
	swap(list[left], list[j]);
	return j;
}


void wordlist::quicksort(std::vector<std::string> list, int left, int right)
{
	if (left < right)
	{
		int s = partition(list, left, right);
		quicksort(list, left, s - 1);
		quicksort(list, s + 1, right);
	}
}


void wordlist::insertionsort()
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