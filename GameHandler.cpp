#include "GameHandler.h"
#include "Player.h"
#include "Menu.h"
#include "windows.h"



void GameHandler::getTurnLimit()
{
	do {

		int limit;
		std::cout << "\nLimit tur: ";
		std::cin >> limit;
		turnLimit = limit;
		if ((turnLimit <= 50) && (turnLimit >= 5));
		std::cout << "\nLimit tur musi byc wiekszy od 5 i mniejszy od 50\n";
	} while (!((turnLimit <= 50) && (turnLimit >= 5)));

}

int GameHandler::getBoardSize()
{
	int x;
	do {
		std::cout << "\nWpradz rozmiar planszy: ";
		std::cin >> x;
		std::cout << std::endl;
		BoardSize = x;
		if (!((x >= 5) && (x <= 10)))
			std::cout << "Wprowadz rormiar od 5 do 10";
	} while (!((x >= 5) && (x <= 10)));
	setBoardSize(x);
	return BoardSize;
}

void GameHandler::setBoardSize(int bs)
{
	BoardSize = bs;
}


void GameHandler::displayShotResult()
{
}
void GameHandler::pVp()
{
	Player player1(BoardSize);
	player1.PlaceShips();
	std::cout << "\n";
	Sleep(2000);
	system("cls");
	Player player2(BoardSize);
	player2.PlaceShips();
	Sleep(2000);
	system("cls");
	player1.PrintPlayerInfo();
	Sleep(2000);
	system("cls");
	player2.PrintPlayerInfo();
	Sleep(2000);
	system("cls");


	while (turnLimit > 0) {
		if (turnLimit % 2 == 0)
		{
			std::cout << "Zostalo tur: " << turnLimit << "\n";
			std::cout << "Podaj x miejsca strzalu: \n";

			std::cout << "Podaj y miejsca strzalu: \n";

			player1.TakeAShot(player2);
			//std::cout << "strzela p1 ";
			turnLimit--;

			Sleep(3000);
			system("cls");
		}
		else
		{
			std::cout << "Zostalo tur: " << turnLimit << "\n";
			std::cout << "Podaj x miejsca strzalu: \n";

			std::cout << "Podaj y miejsca strzalu: \n";

			player2.TakeAShot(player2);
			//std::cout << "strzela p2";
			turnLimit--;
			Sleep(3000);
			system("cls");
		}
	}
	std::cout << "Koniec gry";
}

