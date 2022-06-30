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
        if (!((turnLimit <= 50) && (turnLimit >= 5)));
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
            std::cout << "Wprowadz rozmiar od 5 do 10";
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
    system("cls");
    Player player2(BoardSize);
    player2.PlaceShips();
    system("cls");
    std::cout << "LET'S START BATTLE!!!";
    Sleep(2000);
    system("cls");
   


    while (turnLimit > 0) {
        if (turnLimit % 2 == 0)
        {
            std::cout << "Zostalo tur: " << turnLimit << "\n";
            std::cout << "Teraz gra:"; player1.printName(); std::cout << "\n";
            player1.PrintPlayerInfo();
            player1.TakeAShot(player2);
           
            turnLimit--;
            Sleep(3000);
            system("cls");
        }
        else
        {
            std::cout << "Zostalo tur: " << turnLimit << "\n";
            std::cout << "Teraz gra:"; player2.printName(); std::cout << "\n";
            player2.PrintPlayerInfo();
            player2.TakeAShot(player1);
            
            turnLimit--;
            Sleep(3000);
            system("cls");
        }
    }
    std::cout << "Koniec gry";
}