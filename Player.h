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
	int enterXCoordinate(int NumberOfLetters);
	int enterYCoordinate(int rowNumber);
	void TakeAShot(Player &enemy);
	void PlaceShips();
	void PrintPlayerInfo();
	void printName();
	Player(int size);
};
