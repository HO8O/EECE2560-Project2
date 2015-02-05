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


int wordlist::partition(int left, int right)
{
	std::string p = myWordList[left];
	int i = left;
	int j = (right + 1);
	do {
		do {
			i = i + 1;

		} while (myWordList[i] < p && i < right);
		do{
			j = j - 1;
		} while (myWordList[j] > p);
		swap(myWordList[i], myWordList[j]);
	} while (i < j);
	swap(myWordList[i], myWordList[j]);
	swap(myWordList[left], myWordList[j]);
	return j;
}

void wordlist::quicksort()
{
    quicksortfunc(0, myWordList.size()-1);
}


void wordlist::quicksortfunc(int left, int right)
{
	if (left < right)
	{
		int s = partition(left, right);
		quicksortfunc(left, s - 1);
		quicksortfunc(s + 1, right);
	}
}


void wordlist::insertionsort()
{
    insertionsortfunc(myWordList.size());
}


void wordlist::insertionsortfunc(int length)
{
    int j;
    for (int i=0; i<length-1; i++)
    {
        j=i;
        while (j > 0  &&  myWordList[j-1] > myWordList[j])
        {
            swap(myWordList[j], myWordList[j-1]);
            j = j-1;
        }
    }
}


void wordlist::mergesort()
{
    mergesortfunc(0, myWordList.size()-1);
}


void wordlist::merge(int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    std::vector<std::string> R[n2];
    std::vector<std::string> L[n1];
    for(int i=1; i<=n1; i++)
    {
        L[i]= myWordList[p+i-1];
    }
    for(int i=1; i<=n2; i++)
    {
        R[i]= myWordList[q+i];
    }
    L[n1+1]= "zzzzzz";
    R[n2+1]= "zzzzzz";
    i=1; j=1;
    for(int k=p; p<=r; k++)
    {
        if(L[i] <= R[j])
        {
            myWordList[k] = L[i];
            i= i+1;
        }
        else{
            myWordList[k] = R[j];
            j= j+1;
        }
    }
}


void wordlist::mergesortfunc(int p, int r)
{
    if (p<r)
    {
        int q = (p+r)/2;
        mergesortfunc(p, q);
        mergesortfunc(q+1, r);
        merge(p, q, r);
    }
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
