#pragma once
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
	void initMaxHeap();
	void initMinHeap();
	void maxHeapify();
	void minHeapify();
	void buildMaxHeap();
	void buildMinHeap();
	void heapSort();

private:
    std::vector<T> myHeap;
};

