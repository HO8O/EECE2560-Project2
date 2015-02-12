#pragma once
class hasttable
{
public:
	hasttable();
	~hasttable();
	void addItem(int item);
	void deleteItem(int item);
	bool inList(int item);
	int hash(int item);
};

