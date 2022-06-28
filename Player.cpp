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

void Player::PlaceShips()
{
	
	
	/*Dla przypadku statku wiêkszego ni¿ 1 pobieramy 2 koordynaty(pocz¹tek statku, koniec statku)
	////ZADANIE:
	. Nale¿y zrobiæ kilka rzeczy:
	-Sprawdziæ czy aby na pewno mo¿emy dany statek stworzyæ:
		*Sprawdziæ czy statek nie jest zrobiony po skosie
		*Czy ma odpowiedni¹ d³ugoœæ?(size) np. chcemy stworzyæ statek 4 masztowy. Ktoœ wysy³a nam koordynaty start[0,0] end[0,2].
		Taki statek ma d³ugoœæ 3 ([0,0][0,1][0,2]) zatem nie mo¿e byæ bo chcemy statek 4 masztowy. start[0][0] end[0][4] akceptujemy bo ma dlugoœc 4
		PodpowiedŸ: zwróæ uwagê, ¿e ¿eby statek by³ ustawiony pionowo lub poziomo, to musi mieæ albo x albo y takie same np.
		[3][2] [3][4] -Ok bo x takie samo(3)
		[3][5] [6][5] -Ok bo y takie samo(5)
		[3][4]  [5] [6] - Nie ok bo nic takie samo
		a jego d³ugoœæ to ró¿nica nie takich samych koordynatów + 1

		
		
		*Zadanie z gwiazdk¹*:Nie mo¿na umieœciæ 2 statków w tym samym miejscu
		
		*#*Zadanie z gwiazdk¹ i hasztagiem*#*: When trying to place two ships next to each other (touching corners are okay), the Ships are
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
		
		//Tutaj trzeba wypchn¹æ WSZYSTKIE poprawne koordynaty
		Fleet[i].positions.push_back(temp);
	
		//Tutaj trzeba wypchn¹æ WSZYSTKIE poprawne koordynaty
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
