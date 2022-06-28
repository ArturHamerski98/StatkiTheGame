#include "GameHandler.h"
#include "Player.h"
#include "Menu.h"


void GameHandler::pVp()
{
	Player player1(boardSize);
	player1.PlaceShips();
	Player player2(boardSize);
	player2.PlaceShips();
	player1.PrintPlayerInfo();
	player2.PrintPlayerInfo();
}

void GameHandler::getBoardSize()
{
	int size;
	std::cout << "\nRozmiar planszy: " << std::endl;
	std::cin >> size;
	boardSize = size;
}

