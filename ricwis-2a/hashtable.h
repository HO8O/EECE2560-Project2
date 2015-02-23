#pragma once
#include <vector>
#include <functional>

#define HASHTABLE_SIZE 100

template <class T>
class hashtable
{
private:
	std::vector<std::vector<T>> myTable;
	unsigned int size = HASHTABLE_SIZE;
public:
	void initTable()
	{
		myTable.resize(size);
	}

	void addItem(T item)
	{
		myTable[hash(item)].push_back(item);
	}

	void deleteItem(T item)
	{
		for (int i = 0; i < myTable[hash(item)].size(); i++)
		{
			if (myTable[hash(item)][i] == item)
			{
				myTable[hash(item)].remove(i);
				return;
			}
		}
	}

	bool inList(T item)
	{
		for (int i = 0; i < myTable[hash(item)].size(); i++)
		{
			if (myTable[hash(item)][i] == item)
			{
				return true;
			}
		}
		return false;
	}

	int hash(T item)
	{
		std::hash<T> h;
		return h(item) % HASHTABLE_SIZE;
	}
};

