#pragma once
#include <iostream>
#include <vector>


struct coordinates {
	int x;
	int y;
};

class Ship
{

public:
	int shipSize;
	int numOfHits;
	std::vector<coordinates> positions;


	Ship(int size, int x, int y);

};

