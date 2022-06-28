#include "Player.h"
#include <iostream>
#include "Board.h"


void Player::TakeAShot()
{

	/*ZADANIE:
	-gracz1 podaje koordynaty
	-sprawdzamy czy koordynaty nie przekraczaj� rozmiaru planszy, albo czy czy zamiast cyfry gracz1 nie wpisa� eloelo320
	-jesli koordynaty bledne to prosimy zeby wpisal jeszcze raz
	-jesli koordynaty prawidlowe to w pierwszej kolejnosci sprawdzamy czy gracz ju� nie strzela� w to miejsce, je�li tak, to informujemy go �e miss
	i przerywamy p�tle(tura nast�pnego gracza)
	-jesli koordynaty prawidlowe to sprawdzamy co znajduje si� pod dan� pozycj� w myBoard gracza2
	-Je�li trafimy to na Enemyboard gracza1 oraz myBoard Gracza 2 pod dan� pozycj� piszemy 'H'
	-Je�li nie trafimy, to na Enemyboard gracza1 oraz myBoard Gracza 2 pod dan� pozycj� piszemy 'M'
	-
	
	*/
}

void Player::PlaceShips()
{
	
	
	/*Dla przypadku statku wi�kszego ni� 1 pobieramy 2 koordynaty(pocz�tek statku, koniec statku)
	////ZADANIE:
	. Nale�y zrobi� kilka rzeczy:
	-Sprawdzi� czy aby na pewno mo�emy dany statek stworzy�:
		*Sprawdzi� czy statek nie jest zrobiony po skosie
		*Czy ma odpowiedni� d�ugo��?(size) np. chcemy stworzy� statek 4 masztowy. Kto� wysy�a nam koordynaty start[0,0] end[0,2].
		Taki statek ma d�ugo�� 3 ([0,0][0,1][0,2]) zatem nie mo�e by� bo chcemy statek 4 masztowy. start[0][0] end[0][4] akceptujemy bo ma dlugo�c 4
		Podpowied�: zwr�� uwag�, �e �eby statek by� ustawiony pionowo lub poziomo, to musi mie� albo x albo y takie same np.
		[3][2] [3][4] -Ok bo x takie samo(3)
		[3][5] [6][5] -Ok bo y takie samo(5)
		[3][4]  [5] [6] - Nie ok bo nic takie samo
		a jego d�ugo�� to r�nica nie takich samych koordynat�w + 1

		
		
		*Zadanie z gwiazdk�*:Nie mo�na umie�ci� 2 statk�w w tym samym miejscu
		
		*#*Zadanie z gwiazdk� i hasztagiem*#*: When trying to place two ships next to each other (touching corners are okay), the Ships are
			too close! Error message is displayed and the program asks again for an input


	*/
	
	int xStart, yStart, xEnd, yEnd;
	coordinates temp;
	for (int i = 0; i < Fleet.size(); i++)
	{
		std::cout << "Statek o rozmiarze " << Fleet[i].shipSize << std::endl;
		
		std::cout << "Podaj x start: ";
		std::cin >> xStart;
		std::cout << "Podaj y start: ";
		std::cin >> yStart;

		if (Fleet[i].shipSize > 1)
		{
			std::cout << "Podaj x end: ";
			std::cin >> xEnd;
			std::cout << "Podaj y end: ";
			std::cin >> yEnd;
		}
		
		
		temp.x = xStart;
		temp.y = yStart;
		
		//Tutaj trzeba wypchn�� WSZYSTKIE poprawne koordynaty
		Fleet[i].positions.push_back(temp);
	
		//Tutaj trzeba wypchn�� WSZYSTKIE poprawne koordynaty
		myBoard.setShip(xStart, yStart);
		
		if (Fleet[i].shipSize > 1)
			myBoard.setShip(xEnd, yEnd);

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
