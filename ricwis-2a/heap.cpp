/*

#include "stdafx.h"
#include "heap.h"
#include <vector>

template <class T>
int heap<T>::left(int node)
{
	return 2*(node+1);
}


template <class T>
int heap<T>::parent(int node)
{
	return ((node+)/2);
}


template <class T>
int heap<T>::right(int node)
{
	return (2*(node+1))+1;
}

template<class T>
T heap<T>::getItem(int index)
{
	return myHeap[index];
}


template <class T>
void heap<T>::initMaxHeap(std::vector<T> vector)
{
	myHeap = vector;
	buildMaxHeap();
}


template <class T>
void heap<T>::initMinHeap(std::vector<T> vector)
{
	myHeap = vector;
	buildMinHeap();
}


template <class T>
void heap<T>::maxHeapify(int i)
{
	int largest;
	int l = left(i);
	int r = right(i);

	if (l <=  myHeap.size() &&  myHeap[l] > myHeap[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}

	if (r <= myHeap.size() &&  myHeap[r] > myHeap[i])
	{
		largest = r;
	}

	//Swap A[i] with largest child
	if (largest != i)
	{
		std::swap(myHeap[i], myHeap[largest]);
		maxHeapify(myHeap, largest);
	}
}


template <class T>
void heap<T>::minHeapify(int i)
{
	int smallest;
	int l = left(i);
	int r = right(i);

	if (l >= myHeap.size() && myHeap[l] < myHeap[i])
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}

	if (r >= myHeap.size() && myHeap[r] > myHeap[i])
	{
		smallest = r;
	}

	//Swap A[i] with largest child
	if (smallest != i)
	{
		std::swap(myHeap[i], myHeap[smallest]);
		minHeapify(myHeap, smallest);
	}
}


template <class T>
void heap<T>::buildMaxHeap()
{
	for (int i = (int)floor((float)myHeap.size() / (float)2); i >= 0; i--)
	{
		maxHeapify(i);
	}
}


template <class T>
void heap<T>::buildMinHeap()
{
	for (int i = (int)floor((float)myHeap.size() / (float)2); i >= 0; i--)
	{
		minHeapify(i);
	}
}


template <class T>
void heap<T>::heapSort()
{
}
*/
