#include "stdafx.h"
#include "wordlist.h"
#include <iostream>
#include <string>

wordlist::wordlist()
{
}


wordlist::~wordlist()
{
	myWordList.clear();
}


void wordlist::ReadFromFile(std::string path)
{
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


std::string wordlist::lookup(std::string word)
{
	return std::string();
}
