#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "Player.h"

int main() {

    Menu menu;
    menu.printMenu();
    //std::cout << "\nRozmiar planszy: " << menu.getBoardSize()<<std::endl;
    
    
  //  Board board(menu.getBoardSize());
  //  board.printSea(menu.getBoardSize());
    Player player1(menu.getBoardSize());
    player1.PlaceShips();
    Player player2(menu.getBoardSize());
    player2.PlaceShips();
    player1.PrintPlayerInfo();
    player2.PrintPlayerInfo();
    player1.TakeAShot(player2);
    player2.TakeAShot(player1);
    player1.TakeAShot(player2);
    player2.TakeAShot(player1);
    player1.PrintPlayerInfo();
    player2.PrintPlayerInfo();
    return 0;
}