#include "stdafx.h"
#include "heap.h"
#include <vector>

template<class T>
heap<T>::heap()
{
}

template <class T>
heap<T>::~heap()
{
}


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
void heap<T>::initMaxHeap()
{
}


template <class T>
void heap<T>::initMinHeap()
{
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

	if (r <= myHeap.size() &&  A[r] > A[i])
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
}


template <class T>
void heap<T>::buildMaxHeap()
{
}


template <class T>
void heap<T>::buildMinHeap()
{
}


template <class T>
void heap<T>::heapSort()
{
}
