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
	int shipSize = 4;
	int numOfHits = 3;
	bool status =zayopa;
	std::vector<coordinates> positions;


	Ship(int size, int x, int y);

};

