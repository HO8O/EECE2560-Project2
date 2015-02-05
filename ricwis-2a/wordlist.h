#pragma once
#include <vector>

class wordlist
{
public:
	wordlist();
	~wordlist();
	void ReadFromFile(std::string path);
	wordlist(std::string path);
	int partition(int left, int right);
	void insertionsort();
	void insertionsortfunc(int length);
	void quicksort()
	void quicksortfunc(int left, int right);
	void mergesort();
	void merge(int p, int q, int r);
	void mergesortfunc(int p, int r);
	std::vector<std::string> GetWords()const;
	bool lookup(std::string word)const;
private:
	std::vector<std::string> myWordList;
};

std::ostream &operator<<(std::ostream &stream, const wordlist &words);
