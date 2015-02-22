#include "stdafx.h"
#include "wordlist.h"
#include "heap.h"
#include "hashtable.h"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


/*
*	Function : wordlist()
*	Summary : Constructs the Wordlist object
*	Params : N/A
*	Returns : void
*/
wordlist::wordlist()
{
}


/*
*	Function : ~wordlist()
*	Summary : Deconstructs the Wordlist object
*	Params : N/A
*	Returns : void
*/
wordlist::~wordlist()
{
}



/*
*	Function : ReadFromFile()
*	Summary : Reads the list of words from a file and enters it into myWordList
*	Params : String containing the path of the file
*	Returns : void
*/
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
			myTable.addItem(str);
		}
	}
	else
	{
		std::cout << "Opening wordlist failed!";
	}
}



/*
*	Function : wordlist()
*	Summary : Constructs the Wordlist object and immediately calls ReadFromFile()
*	Params : String containing the path of a file
*	Returns : void
*/
wordlist::wordlist(std::string path)
{
	ReadFromFile(path);
}



/*
*	Function : partition()
*	Summary : Takes the first index and moves all the words that come before it alphabetically in front of it and vice versa
*	Params : Two int indecies that contain the words to be partitioned
*	Returns : Int containing the index where the partition ended
*/
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


/*
*	Function : quicksort()
*	Summary : Calls the quick sort function
*	Params : N/A
*	Returns : void
*/
void wordlist::quicksort()
{
    quicksortfunc(0, myWordList.size()-1);
}


/*
*	Function : quicksortfunc()
*	Summary : Runs a quick sort on myWordList
*	Params : Two int indicies that contain the words to be quick sorted
*	Returns : void
*/
void wordlist::quicksortfunc(int left, int right)
{
	if (left < right)
	{
		int s = partition(left, right);
		quicksortfunc(left, s - 1);
		quicksortfunc(s + 1, right);
	}
}


/*
*	Function : insertionsort()
*	Summary : Calls the insertion sort function
*	Params : N/A
*	Returns : void
*/
void wordlist::insertionsort()
{
    insertionsortfunc(myWordList.size());
}



/*
*	Function : insertionsortfunc()
*	Summary : Runs an insertion sort on myWordList
*	Params : Int with the length of the list to be sorted
*	Returns : void
*/
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


/*
*	Function : mergesort()
*	Summary : Calls the merge sort function
*	Params : N/A
*	Returns : void
*/
void wordlist::mergesort()
{
    mergesortfunc(0, myWordList.size()-1);
}


/*
*	Function : merge()
*	Summary : Merges two word lists into one sorted one
*	Params : Start index, middle index, end index respectively
*	Returns : void
*/
void wordlist::merge(int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    std::vector<std::string> R;
	R.resize(n2);
    std::vector<std::string> L;
	L.resize(n1);
    for(int i = 0; i < n1; i++)
    {
        L[i]= myWordList[p+i-1];
    }
    for(int i = 0; i < n2; i++)
    {
        R[i]= myWordList[q+i];
    }
    L[n1+1]= "zzzzzz";
    R[n2+1]= "zzzzzz";
    int i=0; int j=0;
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


/*
*	Function : mergesortfunc()
*	Summary : Runs a merge sort on myWordList
*	Params : Start index and end index of the words to be sorted
*	Returns : void
*/
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


/*
*	Function : lookup()
*	Summary : Runs a binary search on myWordList to see if the word is there
*	Params : Word to be looked up
*	Returns : A bool on whether the word is contained in myWordList
*/
bool wordlist::lookup(std::string word)const
{
	return (std::binary_search(myWordList.begin(), myWordList.end(), word));
}


/*
*	Function : GetWords()
*	Summary : Returns myWordList
*	Params : N/A
*	Returns : String vector myWordlist
*/
std::vector<std::string> wordlist::GetWords()const
{
	return myWordList;
}

void wordlist::heapSort()
{
	heap<std::string> tempHeap;
	tempHeap.initMaxHeap(myWordList);
	myWordList = tempHeap.GetHeap();
}

/*
*	Function : &operator<<()
*	Summary : Overloads the << operator to print out myWordList
*	Params : N/A
*	Returns : ostream
*/
std::ostream &operator<<(std::ostream &stream, const wordlist &words)
{
	for each(std::string str in words.GetWords())
	{
		stream << str << "\n";
	}
	return stream;
}
