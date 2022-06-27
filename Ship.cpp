#include "Ship.h"


Ship::Ship(int size, int x, int y)
{

	shipSize = size;
	coordinates temp;
	temp.x = x;
	temp.y = y;
	positions.push_back(temp);


}
