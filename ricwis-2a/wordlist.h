#pragma once
#include <vector>

class wordlist
{
public:
	wordlist();
	~wordlist();
	std::vector<std::string> myWordList;
	void ReadFromFile(std::string path);
	wordlist(std::string path);
	void insertionsort();
	void quicksort();
	void mergesort();
	std::string lookup(std::string word);
};

