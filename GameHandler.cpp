#include "GameHandler.h"
#include "Player.h"
#include "Computer.h"
#include "Menu.h"
#include "windows.h"


void GameHandler::getTurnLimit() {
    do {

        int limit;
        std::cout << "\nEnter turn limit: ";
        std::cin >> limit;
        turnLimit = limit;
        if (!((turnLimit <= 50) && (turnLimit >= 5)));
        std::cout << "\nTurn limit must be greater than 5 and lower than 50\n";
    } while (!((turnLimit <= 50) && (turnLimit >= 5)));

}

int GameHandler::getBoardSize() {
    int x;
    do {
        std::cout << "\nEnter size of board: ";
        std::cin >> x;
        std::cout << std::endl;
        boardSize = x;
        if (!((x >= 5) && (x <= 10)))
            std::cout << "Enter size from 5 to 10";
    } while (!((x >= 5) && (x <= 10)));
    setBoardSize(x);
    return boardSize;
}

void GameHandler::setBoardSize(int bs) {
    boardSize = bs;
}

void GameHandler::displayShotResult() {}
void GameHandler::pVp() {
    Player player1(boardSize);
    player1.PlaceShips();
    std::cout << "\n";
    system("cls");
    Player player2(boardSize);
    player2.PlaceShips();
    system("cls");
    std::cout << "LET'S START BATTLE!!!";
    Sleep(2000);
    system("cls");

    while (turnLimit > 0) {
        if (turnLimit % 2 == 0) {
            std::cout << "Turns left: " << turnLimit << "\n";

            player1.printName();
            std::cout << "'s turn\n";
            player1.PrintPlayerInterface();
            player1.TakeAShot(player2);
            //std::cout << "strzela p1 ";
            turnLimit--;

            Sleep(3000);
            system("cls");
        }
        else {
            std::cout << "Turns left: " << turnLimit << "\n";

            player2.printName();
            std::cout << "'s turn\n";
            player2.PrintPlayerInterface();
            player2.TakeAShot(player1);
            //std::cout << "strzela p2";
            turnLimit--;
            Sleep(3000);
            system("cls");
        }
    }
    std::cout << "DRAW";
    Sleep(3000);
    system("cls");
    Menu::printMenu();
}

void GameHandler::pVc()
{
    srand(time(NULL));
    Player player1(boardSize);
    player1.PlaceShips();
    std::cout << "\n";
    system("cls");
    Computer player2(boardSize);
    player2.PlaceShips();
    system("cls");
    std::cout << "LET'S START BATTLE!!!";
    Sleep(2000);
    system("cls");

    while (turnLimit > 0) {
        if (turnLimit % 2 == 0) {
            std::cout << "Turns left: " << turnLimit << "\n";

            player1.printName();
            std::cout << "'s turn\n";
            player1.PrintPlayerInterface();
            player1.TakeAShot(player2);
            turnLimit--;

            Sleep(3000);
            system("cls");
        }
        else {
            std::cout << "Turns left: " << turnLimit << "\n";

            player2.printName();
            std::cout << "'s turn\n";
            player2.PrintPlayerInterface();
            player2.TakeAShot(player1);
            turnLimit--;
            Sleep(3000);
            system("cls");
        }
    }
    std::cout << "DRAW";
    Sleep(3000);
    system("cls");
    Menu::printMenu();
}
