#include "Player.h"
#include <iostream>
#include "Board.h"
#include <string>

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
void Player::TakeAShot(Player &enemy)
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

	if (enemy.myBoard.getCellValue(x,y) == '0') {
		std::cout << "You've missed!\n";
		enemyBoard.setCellValue(x, y, 'M');
		enemy.myBoard.setCellValue(x, y, 'M');
		return;
	}
	if (enemy.myBoard.getCellValue(x, y) == '1') {
		std::cout << "You've hit!\n";
		enemyBoard.setCellValue(x, y, 'H');
		enemy.myBoard.setCellValue(x, y, 'H');
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

void Player::PlaceShips()
{
	
	
	/*Dla przypadku statku większego niż 1 pobieramy 2 koordynaty(początek statku, koniec statku)
	////ZADANIE:
	. Należy zrobić kilka rzeczy:
	-Sprawdzić czy aby na pewno możemy dany statek stworzyć:
		*Sprawdzić czy statek nie jest zrobiony po skosie
		*Czy ma odpowiednią długość?(size) np. chcemy stworzyć statek 4 masztowy. Ktoś wysyła nam koordynaty start[0,0] end[0,2].
		Taki statek ma długość 3 ([0,0][0,1][0,2]) zatem nie może być bo chcemy statek 4 masztowy. start[0][0] end[0][4] akceptujemy bo ma dlugośc 4
		Podpowiedź: zwróć uwagę, że żeby statek był ustawiony pionowo lub poziomo, to musi mieć albo x albo y takie same np.
		[3][2] [3][4] -Ok bo x takie samo(3)
		[3][5] [6][5] -Ok bo y takie samo(5)
		[3][4]  [5] [6] - Nie ok bo nic takie samo
		a jego długość to różnica nie takich samych koordynatów + 1

		
		
		*Zadanie z gwiazdką*:Nie można umieścić 2 statków w tym samym miejscu
		
		*#*Zadanie z gwiazdką i hasztagiem*#*: When trying to place two ships next to each other (touching corners are okay), the Ships are
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
		
		//Tutaj trzeba wypchnąć WSZYSTKIE poprawne koordynaty
		Fleet[i].positions.push_back(temp);
	
		//Tutaj trzeba wypchnąć WSZYSTKIE poprawne koordynaty
		myBoard.setCellValue(xStart, yStart,'1');
		
		if (Fleet[i].shipSize > 1)
			myBoard.setCellValue(xEnd, yEnd,'1');

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
	//Fleet.push_back(Ship(3));
	//Fleet.push_back(Ship(4));
	



	
}
