#include "Player.h"
#include <iostream>
#include "Board.h"


void Player::PlaceShips()
{
	for (int i = 0; i < Fleet.size(); i++)
	{
		
		int x, y;
		std::cout << "Podaj x: ";
		std::cin >> x;
		std::cout << "Podaj y: ";
		std::cin >> y;

		
		
		Fleet[i].positions[0].x=x;
		Fleet[i].positions[0].y=y;
		myBoard.setShip(x, y);

	}


}

void Player::PrintPlayerInfo()
{
	std::cout << name<<std::endl;
	myBoard.printSea(size);
	std::cout << "\n\n";
	enemyBoard.printSea(size);

}
Player::Player(int size)
{
	
	std::string name;
	std::cout << "Enter youre name: ";
	std::cin >> name;
	this->name = name;
	this->size = size;


	myBoard = Board(size);
	enemyBoard = Board(size);
	Fleet.push_back(Ship(1,2,3));
	Fleet.push_back(Ship(1, 2, 3));
	Fleet.push_back(Ship(1, 2, 3));



	
}
