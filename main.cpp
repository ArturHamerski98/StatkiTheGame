#include <iostream>
#include "Menu.h"

int main() {

    Menu menu;
    menu.printMenu();
    std::cout << "\nRozmiar planszy:  " << menu.getBoardSize();
    return 0;
}