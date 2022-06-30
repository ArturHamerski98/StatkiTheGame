#include "Player.h"
#include <iostream>
#include "Board.h"
#include <string>
#include <windows.h>



int Player::enterXCoordinate(int numberOfLetters) {
	char x;//metoda pobiera litere kolumny, nie pozwala wyjsc za obszar planszy
	int col;
	numberOfLetters = 'A' + numberOfLetters;
	while (true) {
		std::cin >> x;
		x = toupper(x);
		if ((x < 'A') || (x >= numberOfLetters)) {
			std::cout << "Input a proper letter! ";
			continue;
		}
		col = x - 'A';
		return col;

	}
}

int Player::enterYCoordinate(int rowNumber) {
	int y; //metoda pobiera numer wiersza, nie pozwala wyjsc za obszar planszy
	while (true) {
		if (!(std::cin >> y)) {
			std::cout << "Input a proper number! ";
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		else if ((y > rowNumber - 1) || (y < 0)) {
			std::cout << "Input a proper number! ";
			continue;
		}
		return y;
	}
}
void Player::TakeAShot(Player& enemy)
{	
	int x, y;
	std::cout << "Specify the X-coordinate of the area you want to shoot: ";
	x = enterXCoordinate(size);

	std::cout << "Specify the Y-coordinate of the area you want to shoot: ";
	y = enterYCoordinate(size);

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

			for (int j = 0; j < Fleet[i].shipSize; j++) {
				if (Fleet[i].positions[j].x == x && Fleet[i].positions[j].y == y) {
					Fleet[i].numOfHits++;
					if (Fleet[i].numOfHits == Fleet[i].shipSize) {
						std::cout << "Ship sunk!";
						Fleet[i].status = 1;
						for (int k = 0; k < Fleet[i].shipSize; k++) {
							enemyBoard.setCellValue(Fleet[i].positions[k].x, Fleet[i].positions[k].y, 'S');
							enemy.myBoard.setCellValue(Fleet[i].positions[k].x, Fleet[i].positions[k].y, 'S');
						}
					}

				}
			}
		}
		return;
	}
	
}
double modul(double x)
{
	//funkcja zwraca wartosc bezwzgledna
	//wykorzystanie trójargumentowego operatora
	return x < 0 ? -x : x;
}
void Player::PlaceShips()
{
	//umieszaczanie statkow na mapie
	int xStart, yStart, xEnd = -1, yEnd = -1;
	coordinates temp;
	std::vector<coordinates> takenPositions;


	for (int i = 0; i < Fleet.size(); i++)
	{
		std::vector<coordinates> currentShipVector; //wektor przechowuje koordynaty obecnie umieszczanego statku
		std::vector<coordinates> currentShipVectorExtended; //wektor przechowuje koordynaty obecnie umieszczanego statku oraz pol dookola niego

		system("CLS");
		myBoard.printSea(size);
		std::cout << "Ship size " << Fleet[i].shipSize << std::endl;

		std::cout << "Enter x start coordinate: ";
		xStart = enterXCoordinate(size);
		std::cout << "Enter y start coordinate: ";
		yStart = enterYCoordinate(size);

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

			temp.x = xStart;
			temp.y = yStart - 1;

			takenPositions.push_back(temp);

			continue;
		}

		if (Fleet[i].shipSize > 1)
		{
			std::cout << "Enter x End coordinates: ";
			xEnd = enterXCoordinate(size);
			std::cout << "Enter y End coordinates: ";
			yEnd = enterYCoordinate(size);

			//warunki do sprawdzenia przy wielomasztowcach
			//sprawdzamy czy koordynaty sa podane od lewej do prawej
			if ((xEnd < xStart) || (yEnd < yStart)) {
				std::cout << "The starting coordinates has to be larger!" << std::endl;
				std::cout << "Try again!" << std::endl;
				Sleep(2000);
				i--;
				continue;
			}
			//badamy czy nie po skosie!
			else if ((xStart != xEnd) && (yStart != yEnd)) {
				std::cout << "You can not put ships diagonally!" << std::endl;
				std::cout << "Try again!" << std::endl;
				Sleep(2000);
				i--;
				continue;
			}
			//badamy czy odpowiednia długość statku
			else if ((xStart == xEnd) && (modul(yStart - yEnd) + 1 != Fleet[i].shipSize)) {
				std::cout << "Check the length of the ship!" << std::endl;
				std::cout << "Try again!" << std::endl;
				Sleep(2000);
				i--;
				continue;
			}
			else if ((yStart == yEnd) && (modul(xStart - xEnd) + 1 != Fleet[i].shipSize)) {
				std::cout << "Check the length of the ship!" << std::endl;
				std::cout << "Try again!" << std::endl;
				Sleep(2000);
				i--;
				continue;
			}
		}

		int dif = 0;
		//umieszczanie pozycji w wektorach:
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
		//sprawdzamy czy istnieje mozliwosc umieszczenia statku w tym miejscu
		bool isTaken = 0;
		for (int i = 0; i < takenPositions.size(); i++) {
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
		else {//umieszczenie statku na mapie
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
	//Fleet.push_back(Ship(3));
	//Fleet.push_back(Ship(4));
	



	
}
