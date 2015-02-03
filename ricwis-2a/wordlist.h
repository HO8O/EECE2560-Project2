#pragma once
#include <vector>

class wordlist
{
public:
	wordlist();
	~wordlist();
	void ReadFromFile(std::string path);
	wordlist(std::string path);
	void insertionsort();
	void quicksort();
	void mergesort();
	std::vector<std::string> GetWords()const;
	std::string lookup(std::string word)const;
private:
	std::vector<std::string> myWordList;
};

std::ostream &operator<<(std::ostream &stream, const wordlist &words);
