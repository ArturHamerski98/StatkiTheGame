#include "Player.h"
#include <iostream>
#include "Board.h"
void Player::PrintPlayerInfo()
{
	std::cout << name;
	myBoard.printSea(size);
	enemyBoard.printSea(size);
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

}
