#pragma once
#include <iostream>
#include "Board.h"
class Player
{
protected:
	std::string name;
	Board myBoard;
	Board enemyBoard;
	int size;
public:
	void TakeAShot();
	void PlaceShips();
	void PrintPlayerInfo();
	Player(int size);


};
