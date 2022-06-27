#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "Player.h"

int main() {

    Menu menu;
    menu.printMenu();
    std::cout << "\nRozmiar planszy: " << menu.getBoardSize()<<std::endl;
    
    
    Board board(menu.getBoardSize());
    board.printSea(menu.getBoardSize());
    Player player(menu.getBoardSize());
    player.PrintPlayerInfo();
    return 0;
}