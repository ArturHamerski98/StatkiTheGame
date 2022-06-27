#pragma once
#include <iostream>
#include "Board.h"
#include <vector>
#include "Ship.h"
class Player
{
protected:
	std::string name;
	Board myBoard;
	Board enemyBoard;
	int size;
	std::vector<Ship> Fleet;
public:
	void TakeAShot();
	void PlaceShips();
	void PrintPlayerInfo();
	Player(int size);


};
