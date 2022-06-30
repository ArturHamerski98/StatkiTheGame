#include "Player.h"
#include <iostream>
#include "Board.h"
#include <string>
#include <windows.h>

int Player::enterCoordinate() {
	std::string number;
	std::cin >> number;

	//checking for negative numbers
	if (number[0] == '-') {
		std::cout << "Invalid input - negative values are not permitted! Try once again!\n";
		enterCoordinate();
	}

	for (int i = 0; number[i] != 0; i++) {
		if (number[i] > '9' || number[i] < '0') {
			std::cout << "Invalid input - detected a sign not being a digit! Try once again!\n";
			enterCoordinate();
		}
	}
	int x = stoi(number);
	if (x > size) {
		std::cout << "Swum overboard! Try once again";
		enterCoordinate();
	}
	return x;

}
void Player::TakeAShot(Player& enemy)
{
	int x, y;
	std::cout << "Specify the X-coordinate of the area you want to shoot: ";
	x = enterCoordinate();

	std::cout << "Specify the Y-coordinate of the area you want to shoot: ";
	y = enterCoordinate();

	if (enemyBoard.getCellValue(x, y) != '0') {
		std::cout << "You've missed!\n";
		return;
	}

	if (enemy.myBoard.getCellValue(x, y) == '0') {
		std::cout << "You've missed!\n";
		enemyBoard.setCellValue(x, y, 'M');
		enemy.myBoard.setCellValue(x, y, 'M');
		return;
	}
	if (enemy.myBoard.getCellValue(x, y) == '1') {
		std::cout << "You've hit!\n";
		enemyBoard.setCellValue(x, y, 'H');
		enemy.myBoard.setCellValue(x, y, 'H');
		for (int i = 0; i < Fleet.size(); i++) {
			for (int j = 0; j < 1; j++) {
				std::cout << Fleet[i].numOfHits;
				if (Fleet[i].positions[j].x == x && Fleet[i].positions[j].y == y) {
					Fleet[i].numOfHits++;
					std::cout << Fleet[i].numOfHits;
					std::cout << std::endl;
					std::cout << i << "   " << j;
				}
			}
		}
		return;
	}




	/*ZADANIE:
	-gracz1 podaje koordynaty
	-sprawdzamy czy koordynaty nie przekraczaj¹ rozmiaru planszy, albo czy czy zamiast cyfry gracz1 nie wpisa³ eloelo320
	-jesli koordynaty bledne to prosimy zeby wpisal jeszcze raz
	-jesli koordynaty prawidlowe to w pierwszej kolejnosci sprawdzamy czy gracz ju¿ nie strzela³ w to miejsce, jeœli tak, to informujemy go ¿e miss
	i przerywamy pêtle(tura nastêpnego gracza)
	-jesli koordynaty prawidlowe to sprawdzamy co znajduje siê pod dan¹ pozycj¹ w myBoard gracza2
	-Jeœli trafimy to na Enemyboard gracza1 oraz myBoard Gracza 2 pod dan¹ pozycj¹ piszemy 'H'
	-Jeœli nie trafimy, to na Enemyboard gracza1 oraz myBoard Gracza 2 pod dan¹ pozycj¹ piszemy 'M'
	

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
		std::cout << "Statek o rozmiarze " << Fleet[i].shipSize << std::endl;

		std::cout << "Podaj x start: ";
		std::cin >> xStart;
		std::cout << "Podaj y start: ";
		std::cin >> yStart;

		if (Fleet[i].shipSize == 1) {
			temp.x = xStart;
			temp.y = yStart;

			takenPositions.push_back(temp);

			Fleet[i].positions.push_back(temp);

			myBoard.setCellValue(xStart, yStart,'1');

			temp.x = xStart + 1;
			temp.y = yStart;

			takenPositions.push_back(temp);
			temp.x = xStart - 1;
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
			std::cout << "Podaj x end: ";
			std::cin >> xEnd;
			std::cout << "Podaj y end: ";
			std::cin >> yEnd;

			//warunki do sprawdzenia przy wielomasztowcach
			if ((xEnd < xStart) || (yEnd < yStart)) {
				std::cout << "Startowe koordynaty musza byc mniejsze" << std::endl;
				std::cout << "Try again!" << std::endl;
				Sleep(2000);
				i--;
				continue;
			}
			//badamy czy nie po skosie!
			else if ((xStart != xEnd) && (yStart != yEnd)) {
				std::cout << "Nie po skosie!" << std::endl;
				std::cout << "Try again!" << std::endl;
				Sleep(2000);
				i--;
				continue;
			}
			//badamy czy odpowiednia długość statku
			else if ((xStart == xEnd) && (modul(yStart - yEnd) + 1 != Fleet[i].shipSize)) {
				std::cout << "Nie ta dlugosc!" << std::endl;
				std::cout << "Try again!" << std::endl;
				Sleep(2000);
				i--;
				continue;
			}
			else if ((yStart == yEnd) && (modul(xStart - xEnd) + 1 != Fleet[i].shipSize)) {
				std::cout << "Nie ta dlugosc!" << std::endl;
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
			temp.y = yStart - 1;
			currentShipVectorExtended.push_back(temp);

			temp.x = xEnd;
			temp.y = yEnd + 1;
			currentShipVectorExtended.push_back(temp);
		}

		bool isTaken = 0;
		for (int i = 0; i < takenPositions.size(); i++) {
			for (int j = 0; j < currentShipVectorExtended.size(); j++) {
				if ((takenPositions[i].x == currentShipVectorExtended[j].x) && (takenPositions[i].y == currentShipVectorExtended[j].y)) {
					isTaken = 1;
				}
			}
		}

		if (isTaken == 1) {
			std::cout << "statki zachodza na siebie" << std::endl;
			Sleep(2000);
			i--;
			continue;
		}
		else {
			for (int j = 0; j < currentShipVector.size(); j++) {
				takenPositions.push_back(currentShipVector[j]);
				Fleet[i].positions.push_back(currentShipVector[j]);
				myBoard.setCellValue(currentShipVector[j].x, currentShipVector[j].y,'1');
			}
		}
		
	}
	system("CLS");
	myBoard.printSea(size);
	Sleep(2000);

}

void Player::PrintPlayerInfo()
{
	std::cout << "    My sea" << std::endl;
	myBoard.printSea(size);
	std::cout << "\n\n    Enemy sea\n";
	enemyBoard.printSea(size);

}
void Player::printName()
{
	std::cout << name;
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
