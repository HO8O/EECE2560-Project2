#pragma once
#include <vector>

template <class T>
class heap
{
public:

	unsigned int left(int node)const
	{
		return 2 * (node + 1);
	}

	unsigned int parent(int node)const
	{
		return ((node + ) / 2);
	}

	unsigned int right(int node)const
	{
		return (2 * (node + 1)) + 1;
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

		if (l <= myHeap.size() && myHeap[l] > myHeap[i])
		{
			largest = l;
		}
		else
		{
			largest = i;
		}

		if (r <= myHeap.size() && myHeap[r] > myHeap[i])
		{
			largest = r;
		}

		//Swap A[i] with largest child
		if (largest != i)
		{
			std::swap(myHeap[i], myHeap[largest]);
			//maxHeapify(myHeap, largest);
		}
	}

	void minHeapify(int i)
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
			//minHeapify(myHeap, smallest);
		}
	}

	void buildMaxHeap()
	{
		for (int i = (int)floor((float)myHeap.size() / (float)2); i >= 0; i--)
		{
			maxHeapify(i);
		}
	}

	void buildMinHeap()
	{
		for (int i = (int)floor((float)myHeap.size() / (float)2); i >= 0; i--)
		{
			minHeapify(i);
		}
	}

	void heapSort()
	{

	}

private:
    std::vector<T> myHeap;
};

