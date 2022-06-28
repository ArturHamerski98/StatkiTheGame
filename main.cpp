#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "GameHandler.h"

int main() {

   // Menu menu;
    //menu.printMenu();
    GameHandler myGame;
    myGame.getBoardSize();
    myGame.getTurnLimit();
    system("cls");
    myGame.pVp();
   





    return 0;
}