#include "stdafx.h"
#include "heap.h"


heap::heap()
{
}


heap::~heap()
{
}


int heap::left(int node)
{
	return (2*(node+1))-1;
}


int heap::parent(int node)
{
	return ((node+1)/2)-1;
}


int heap::right(int node)
{
	return ((node+1)/2)-1;
}

Template<class T>
T heap::getItem(int index)
{
	return myHeap[index];
}


void heap::initMaxHeap()
{
}


void heap::initMinHeap()
{
}


void heap::maxHeapify()
{
}


void heap::minHeapify()
{
}


void heap::buildMaxHeap()
{
}


void heap::buildMinHeap()
{
}


void heap::heapSort()
{
}
