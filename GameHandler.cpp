#include "GameHandler.h"
#include "Player.h"
#include "Menu.h"
#include "windows.h"

void GameHandler::getTurnLimit()
{
	int limit;
	std::cout << "\nLimit tur: ";
	std::cin >> limit;
	turnLimit = limit;
}

void GameHandler::getBoardSize()
{
	int size;
	std::cout << "\nRozmiar planszy: ";
	std::cin >> size;
	boardSize = size;
}

void GameHandler::pVp()
{
	Player player1(boardSize);
	player1.PlaceShips();
	std::cout << "\n";
	Sleep(2000);
	system("cls");
	Player player2(boardSize);
	player2.PlaceShips();
	Sleep(2000);
	system("cls");
	player1.PrintPlayerInfo();
	Sleep(2000);
	system("cls");
	player2.PrintPlayerInfo();
	Sleep(2000);
	system("cls");


	while (turnLimit>0) {
		if (turnLimit%2==0)
		{
		std::cout << "Zostalo tur: \n" << turnLimit;
		player1.TakeAShot();
		//std::cout << "strzela p1 ";
		turnLimit--;
		Sleep(3000);
		system("cls");
		}
		else
		{
			std::cout << "Zostalo tur: \n" << turnLimit;
			player2.TakeAShot();
			//std::cout << "strzela p2";
			turnLimit--;
			Sleep(3000);
			system("cls");
		}
	}
}








