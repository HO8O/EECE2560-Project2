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
	void insertionsort(std::vector<std::string> list);
	void insertionsortfunc(std::vector<std::string> list, int length);
	void quicksort(std::vector<std::string> list);
	void quicksortfunc(std::vector<std::string> list, int left, int right);
	void mergesort(std::vector<std::string> list);
	void merge(std::vector<std::string> list, int p, int q, int r);
	void mergesortfunc();
	std::vector<std::string> GetWords()const;
	bool lookup(std::string word)const;
private:
	std::vector<std::string> myWordList;
};

std::ostream &operator<<(std::ostream &stream, const wordlist &words);
