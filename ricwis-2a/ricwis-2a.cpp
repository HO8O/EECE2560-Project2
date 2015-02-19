// ricwis-2a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wordlist.h"
#include "grid.h"
#include "common.h"
#include "heap.h"

#include <string>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	//search(3);
	heap<int> imHeapy;
	std::vector < int > vec = { 5, 15, 3, 2, 10 };
	imHeapy.initMinHeap(vec);

	while (1);
	return 0;
}

