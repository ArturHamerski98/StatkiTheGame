#pragma once
#include <iostream>
#include <vector>

class Board
{
private:
	std::vector<std::vector<char>>Sea;
	
public:
	Board(int size);
	Board();
	void printSea(int size);

};