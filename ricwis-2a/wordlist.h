#pragma once
#include <vector>

class wordlist
{
public:
	wordlist();
	~wordlist();
	void ReadFromFile(std::string path);
	wordlist(std::string path);
	int partition(std::vector<std::string> list, int left, int right);
	void insertionsort();
	void wordlist::quicksort(std::vector<std::string> list, int left, int right);
	void mergesort();
	std::vector<std::string> GetWords()const;
	bool lookup(std::string word)const;
private:
	std::vector<std::string> myWordList;
};

std::ostream &operator<<(std::ostream &stream, const wordlist &words);
