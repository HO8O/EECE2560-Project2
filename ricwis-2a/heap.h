#pragma once
#include <vector>

template <class T>
class heap
{
public:
	heap();
	~heap();
	int left(int node);
	int parent(int node);
	int right(int node);
	T getItem(int index);
	void initMaxHeap(std::vector<T>);
	void initMinHeap(std::vector<T>);
	void maxHeapify(int i);
	void minHeapify(int i);
	void buildMaxHeap();
	void buildMinHeap();
	void heapSort();

private:
    std::vector<T> myHeap;
};

