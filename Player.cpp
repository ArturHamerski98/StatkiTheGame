#include "Player.h"
#include <iostream>
#include "Board.h"


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
	
	
	/*Dla przypadku statku wiêkszego ni¿ 1 pobieramy 2 koordynaty(pocz¹tek statku, koniec statku)
	////ZADANIE:
	. Nale¿y zrobiæ kilka rzeczy:
	-Sprawdziæ czy aby na pewno mo¿emy dany statek stworzyæ:
		*Sprawdziæ czy statek nie jest zrobiony po skosie ZROBIONE!
		*Czy ma odpowiedni¹ d³ugoœæ?(size) np. chcemy stworzyæ statek 4 masztowy. Ktoœ wysy³a nam koordynaty start[0,0] end[0,2].
		Taki statek ma d³ugoœæ 3 ([0,0][0,1][0,2]) zatem nie mo¿e byæ bo chcemy statek 4 masztowy. start[0][0] end[0][4] akceptujemy bo ma dlugoœc 4
		PodpowiedŸ: zwróæ uwagê, ¿e ¿eby statek by³ ustawiony pionowo lub poziomo, to musi mieæ albo x albo y takie same np.
		[3][2] [3][4] -Ok bo x takie samo(3)
		[3][5] [6][5] -Ok bo y takie samo(5)
		[3][4]  [5] [6] - Nie ok bo nic takie samo
		a jego d³ugoœæ to ró¿nica nie takich samych koordynatów + 1
		ZROBIONE!
		
		
		*Zadanie z gwiazdk¹*:Nie mo¿na umieœciæ 2 statków w tym samym miejscu
		
		*#*Zadanie z gwiazdk¹ i hasztagiem*#*: When trying to place two ships next to each other (touching corners are okay), the Ships are
			too close! Error message is displayed and the program asks again for an input

	*/
	
	int xStart, yStart, xEnd = -1, yEnd = -1;
	coordinates temp, exact;
	std::vector<coordinates> takenPositions;
	

	for (int i = 0; i < Fleet.size(); i++)
	{
		std::vector<coordinates> currentShipVector;
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

			myBoard.setShip(xStart, yStart);
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
				i--;
				continue;
			}
			//badamy czy nie po skosie!
			else if ((xStart != xEnd) && (yStart != yEnd)) {
				std::cout << "Nie po skosie!" << std::endl;
				std::cout << "Try again!" << std::endl;
				i--;
				continue;
			}
			//badamy czy odpowiednia długość statku
			else if ((xStart == xEnd) && (modul(yStart-yEnd)+1 != Fleet[i].shipSize)) {
				std::cout << "Nie ta dlugosc!" << std::endl;
				std::cout << "Try again!" << std::endl;
				i--;
				continue;
			}
			else if ((yStart == yEnd) && (modul(xStart - xEnd) + 1 != Fleet[i].shipSize)) {
				std::cout << "Nie ta dlugosc!" << std::endl;
				std::cout << "Try again!" << std::endl;
				i--;
				continue;
			}
		}


		//umieszczamy wszystkie koordynaty
		
		int dif = 0;
		
		
		if (yStart == yEnd) {
			dif = modul(xStart - xEnd) + 1;
			for (int i = 0; i < dif; i++) {
				temp.x = xStart + i;
				temp.y = yStart;
				currentShipVector.push_back(temp);

				/*Fleet[i].positions.push_back(temp);
				myBoard.setShip(temp.x, temp.y);*/
			}
		}
		else if (xStart == xEnd) {
			dif = modul(yStart - yEnd) + 1;
			for (int i = 0; i < dif; i++) {
				temp.x = xStart;
				temp.y = yStart + i;
				currentShipVector.push_back(temp);

				/*Fleet[i].positions.push_back(temp);
				myBoard.setShip(temp.x, temp.y);*/
			}
		}

		bool isTaken = 0;
		for (int i = 0; i<takenPositions.size(); i++) {
			for (int j = 0; j < currentShipVector.size(); j++) {
				if ((takenPositions[i].x == currentShipVector[j].x) && (takenPositions[i].y == currentShipVector[j].y)) {
					isTaken = 1;
				}
			}
		}

		if (isTaken == 1) {
			std::cout << "statki zachodza na siebie" << std::endl;
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
