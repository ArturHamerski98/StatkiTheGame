#include "Menu.h"
#include <iostream>

void Menu::setBoardSize(int bs)
{
    BoardSize = bs;
}

void  Menu::printMenu()
{
    int x;
    std::cout << "Wpraowadz rozmiar planszy";
    std::cin >> x;
    setBoardSize(x);

}

int Menu::getBoardSize() {

    return BoardSize;
}


Menu::Menu() {
    BoardSize = 5;
}