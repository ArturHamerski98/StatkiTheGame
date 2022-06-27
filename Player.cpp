#include "Player.h"
#include <iostream>
#include "Board.h"


void Player::PrintPlayerInfo()
{
	std::cout << name<<std::endl;
	myBoard.printSea(size);
	enemyBoard.printSea(size);
	std::cout << "\nMOJA FLOAT\n";
	std::cout << "x: " << Fleet[0].positions[0].x << "y: " << Fleet[0].positions[0].y;
}
Player::Player(int size)
{
	
	std::string name;
	std::cout << "Enter youre name";
	std::cin >> name;
	this->name = name;
	this->size = size;


	myBoard = Board(size);
	enemyBoard = Board(size);
	Ship ship(1, 2, 3);

	std::cout << "dasdasda";
	Fleet.push_back(ship);



	
}
