#include "Player.h"
#include <iostream>
#include "Board.h"
#include <windows.h>


void Player::TakeAShot()
{

	/*ZADANIE:
	-gracz1 podaje koordynaty
	-sprawdzamy czy koordynaty nie przekraczaj¹ rozmiaru planszy, albo czy czy zamiast cyfry gracz1 nie wpisa³ eloelo320
	-jesli koordynaty bledne to prosimy zeby wpisal jeszcze raz
	-jesli koordynaty prawidlowe to w pierwszej kolejnosci sprawdzamy czy gracz ju¿ nie strzela³ w to miejsce, jeœli tak, to informujemy go ¿e miss
	i przerywamy pêtle(tura nastêpnego gracza)
	-jesli koordynaty prawidlowe to sprawdzamy co znajduje siê pod dan¹ pozycj¹ w myBoard gracza2
	-Jeœli trafimy to na Enemyboard gracza1 oraz myBoard Gracza 2 pod dan¹ pozycj¹ piszemy 'H'
	-Jeœli nie trafimy, to na Enemyboard gracza1 oraz myBoard Gracza 2 pod dan¹ pozycj¹ piszemy 'M'
	-
	
	*/
}
double modul(double x)
{
	//wykorzystanie trójargumentowego operatora
	return x < 0 ? -x : x;
}

void Player::PlaceShips()
{
	
	int xStart, yStart, xEnd = -1, yEnd = -1;
	coordinates temp;
	std::vector<coordinates> takenPositions;
	

	for (int i = 0; i < Fleet.size(); i++)
	{
		std::vector<coordinates> currentShipVector;
		std::vector<coordinates> currentShipVectorExtended;

		system("CLS");
		myBoard.printSea(size);
		std::cout << "Ship size: " << Fleet[i].shipSize << std::endl;
		
		std::cout << "Input x start coordinate: ";
		std::cin >> xStart;
		std::cout << "Input y start coordinate: ";
		std::cin >> yStart;
		
		if (Fleet[i].shipSize == 1) {
			temp.x = xStart;
			temp.y = yStart;

			takenPositions.push_back(temp);

			Fleet[i].positions.push_back(temp);

			myBoard.setShip(xStart, yStart);

			temp.x = xStart +1;
			temp.y = yStart;

			takenPositions.push_back(temp);
			temp.x = xStart -1;
			temp.y = yStart;

			takenPositions.push_back(temp);
			temp.x = xStart;
			temp.y = yStart + 1;

			takenPositions.push_back(temp);

			takenPositions.push_back(temp);
			temp.x = xStart;
			temp.y = yStart - 1;

			takenPositions.push_back(temp);

			continue;
		}

		if (Fleet[i].shipSize > 1)
		{
			std::cout << "Input x end coordinate: ";
			std::cin >> xEnd;
			std::cout << "Input y end coordinate: ";
			std::cin >> yEnd;
		
			//warunki do sprawdzenia przy wielomasztowcach
			if ((xEnd < xStart) || (yEnd < yStart)) {
				std::cout << "The starting coordinates has to be larger!" << std::endl;
				std::cout << "Try again!" << std::endl;
				Sleep(2000);
				i--;
				continue;
			}
			//badamy czy nie po skosie!
			else if ((xStart != xEnd) && (yStart != yEnd)) {
				std::cout << "You can not put the ship diagonally!" << std::endl;
				std::cout << "Try again!" << std::endl;
				Sleep(2000);
				i--;
				continue;
			}
			//badamy czy odpowiednia długość statku
			else if ((xStart == xEnd) && (modul(yStart-yEnd)+1 != Fleet[i].shipSize)) {
				std::cout << "Check the length!" << std::endl;
				std::cout << "Try again!" << std::endl; 
				Sleep(2000);
				i--;
				continue;
			}
			else if ((yStart == yEnd) && (modul(xStart - xEnd) + 1 != Fleet[i].shipSize)) {
				std::cout << "Check the length!" << std::endl;
				std::cout << "Try again!" << std::endl;
				Sleep(2000);
				i--;
				continue;
			}
		}
		
		int dif = 0;
		
		//poziome statki
		if (yStart == yEnd) {
			dif = modul(xStart - xEnd) + 1;
			for (int i = 0; i < dif; i++) {
				temp.x = xStart + i;
				temp.y = yStart;

				currentShipVector.push_back(temp);

				currentShipVectorExtended.push_back(temp);

				temp.y += 1;
				currentShipVectorExtended.push_back(temp);
				temp.y -= 2;
				currentShipVectorExtended.push_back(temp);
			}
			temp.x = xStart - 1;
			temp.y = yStart;
			currentShipVectorExtended.push_back(temp);

			temp.x = xEnd + 1;
			temp.y = yStart;
			currentShipVectorExtended.push_back(temp);
		}
		//pionowe statki
		else if (xStart == xEnd) {
			dif = modul(yStart - yEnd) + 1;
			for (int i = 0; i < dif; i++) {
				temp.x = xStart;
				temp.y = yStart + i;
				currentShipVector.push_back(temp);
				currentShipVectorExtended.push_back(temp);

				temp.x += 1;
				currentShipVectorExtended.push_back(temp);
				temp.x -= 2;
				currentShipVectorExtended.push_back(temp);

			}
			temp.x = xStart;
			temp.y = yStart-1;
			currentShipVectorExtended.push_back(temp);

			temp.x = xEnd;
			temp.y = yEnd+1;
			currentShipVectorExtended.push_back(temp);
		}

		bool isTaken = 0;
		for (int i = 0; i<takenPositions.size(); i++) {
			for (int j = 0; j < currentShipVectorExtended.size(); j++) {
				if ((takenPositions[i].x == currentShipVectorExtended[j].x) && (takenPositions[i].y == currentShipVectorExtended[j].y)) {
					isTaken = 1;
				}
			}
		}

		if (isTaken == 1) {
			std::cout << "The ships are too close!" << std::endl;
			Sleep(2000);
			i--;
			continue;
		}
		else {
			for (int j = 0; j < currentShipVector.size(); j++) {
				takenPositions.push_back(currentShipVector[j]);
				Fleet[i].positions.push_back(currentShipVector[j]);
				myBoard.setShip(currentShipVector[j].x, currentShipVector[j].y);
			}
		}
		
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
	Fleet.push_back(Ship(1));
	Fleet.push_back(Ship(2));
	Fleet.push_back(Ship(3));
	Fleet.push_back(Ship(4));
	
}
