// ricwis-2a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wordlist.h"
#include "grid.h"

#include <string>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	std::string path;
	std::cin >> path;

	//wordlist words = wordlist(path);
	grid mygrid = grid(path);
	std::cout << mygrid;
	while (1);
	return 0;
}

