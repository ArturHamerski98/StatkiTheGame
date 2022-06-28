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
	bool status;
	std::vector<coordinates> positions;


	Ship(int size);


};

