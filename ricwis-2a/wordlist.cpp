#include "stdafx.h"
#include "wordlist.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

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

/*
int partition(std::vector<std::string> list, int left, int right)
{
	std::string p = list[left];
	int i = left;
	int j = (right + 1);
	do {
		do {
			i = i + 1;

		} while (list[i] < p && i < right);
		do{
			j = j - 1;
		} while (list[j] > p);
		swap(list[i], list[j]);
	} while (i < j);
	swap(list[i], list[j]);
	swap(list[left], list[j]);
	return j;
}

void wordlist::quicksort(std::vector<std::string> list)
{
    quicksortfunc(list, 0, list.size()-1);
}


void wordlist::quicksortfunc(std::vector<std::string> list, int left, int right)
{
	if (left < right)
	{
		int s = partition(list, left, right);
		quicksortfunc(list, left, s - 1);
		quicksortfunc(list, s + 1, right);
	}
}
*/

void wordlist::insertionsort(std::vector<std::string> list)
{
    insertionsortfunc(list, list.size());
}


void wordlist::insertionsortfunc(std::vector<std::string> list, int length)
{
    int j;
    for (int i=0; i<length-1; i++)
    {
        j=i;
        while (j > 0  &&  list[j-1] > list[j])
        {
            swap(list[j], list[j-1]);
            j = j-1;
        }
    }
}


void wordlist::mergesort(std::vector<std::string> list)
{
}

/*
void wordlist::merge(std::vector<std::string> list, int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    for(int i=1)
}
*/

void wordlist::mergesortfunc()
{

}


bool wordlist::lookup(std::string word)const
{
	return (std::binary_search(myWordList.begin(), myWordList.end(), word));
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
