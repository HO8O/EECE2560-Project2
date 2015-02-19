#pragma once
template <class T>
class hasttable
{
public:
	hasttable();
	~hasttable();
	void addItem(T item);
	void deleteItem(T item);
	bool inList(T item);
	int hash(T item);
};

