#pragma once
#include "Player.h"

struct planOfWar {
	coordinates hitedShip;
	int direction;
};

class Computer: public Player
{
private:
	std::vector<planOfWar> plansOfWar;
	std::vector<coordinates> shootPositions;

public:
	
	Computer(int size);
	Computer();
	void TakeAShot(Player& enemy);
	void PlaceShips();
}; 

