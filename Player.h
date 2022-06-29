#pragma once
#include <iostream>
#include "Board.h"
#include <vector>
#include "Ship.h"
class Player
{
protected:
	
	Board myBoard;
	Board enemyBoard;
	int size;
	std::vector<Ship> Fleet;
public:
	std::string name;
	int enterCoordinate();
	void TakeAShot(Player &enemy);
	void PlaceShips();
	void PrintPlayerInfo();
	Player(int size);


};
