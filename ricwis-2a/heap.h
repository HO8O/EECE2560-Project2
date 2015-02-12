#pragma once
class heap
{
public:
	heap();
	~heap();
	int left(int node);
	int parent(int node);
	int right(int node);
	int getItem(int index);
	void initMaxHeap();
	void initMinHeap();
	void maxHeapify();
	void minHeapify();
	void buildMaxHeap();
	void buildMinHeap();
	void heapSort();
};

