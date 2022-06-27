#pragma once
#include <iostream>

class Player
{
protected:
	std::string imie;
	int tabliaca;

public:
	void TakeAShot();
	void PlaceShips();
};
