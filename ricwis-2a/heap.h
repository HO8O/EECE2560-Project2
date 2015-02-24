#pragma once
#include <vector>

template <class T>
class heap
{
public:

	unsigned int left(int node)const
	{
		return (2 * (node + 1)) - 1;
	}

	unsigned int parent(int node)const
	{
		return ((node + 1) / 2) - 1;
	}

	unsigned int right(int node)const
	{
		return (2 * (node + 1));
	}

	T getItem(int index)
	{
		return myHeap[index];
	}

	void initMaxHeap(std::vector<T> vec)
	{
		myHeap.resize(vec.size());
		myHeap = vec;
		buildMaxHeap();
	}

	void initMinHeap(std::vector<T> vec)
	{
		myHeap.resize(vec.size());
		myHeap = vec;
		buildMinHeap();
	}

	void maxHeapify(int i)
	{
		unsigned int largest;
		unsigned int l = left(i);
		unsigned int r = right(i);

		if (l < maxHeapSize && myHeap[l] > myHeap[i])
		{
			largest = l;
		}
		else
		{
			largest = i;
		}

		if (r < maxHeapSize && myHeap[r] > myHeap[largest])
		{
			largest = r;
		}

		//Swap A[i] with largest child
		if (largest != i)
		{
			std::swap(myHeap[i], myHeap[largest]);
			maxHeapify(largest);
		}
	}

	void minHeapify(int i)
	{
		unsigned int smallest;
		unsigned int l = left(i);
		unsigned int r = right(i);

		if (l < myHeap.size() && myHeap[l] < myHeap[i])
		{
			smallest = l;
		}
		else
		{
			smallest = i;
		}

		if (r < myHeap.size() && myHeap[r] < myHeap[smallest])
		{
			smallest = r;
		}

		//Swap A[i] with largest child
		if (smallest != i)
		{
			std::swap(myHeap[i], myHeap[smallest]);
			minHeapify(smallest);
		}
	}

	void buildMaxHeap()
	{
		maxHeapSize = myHeap.size() - 1;
		for (int i = myHeap.size() / 2; i >= 0; i--)
		{
			maxHeapify(i);
		}
	}

	void buildMinHeap()
	{
		for (int i = myHeap.size() / 2; i >= 0; i--)
		{
			minHeapify(i);
		}
	}

	void heapSort()
	{
		buildMaxHeap();
		for(int i = maxHeapSize; i > 2; i--)
		{
			swap(myHeap[0], myHeap[i]);
			maxHeapSize--;
			maxHeapify(i);
		}
		maxHeapSize = myHeap.size() - 1;
	}

	std::vector<T> GetHeap()
	{
		return myHeap;
	}

private:
    std::vector<T> myHeap;
	int maxHeapSize;
};

