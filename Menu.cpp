#include "Menu.h"
#include <iostream>

void Menu::setBoardSize(int bs)
{
    BoardSize = bs;
}

void  Menu::printMenu()
{
    int x;
    std::cout << "Wpradz rozmiar planszy: \n";
    std::cin >> x;
    std::cout << std::endl;
    setBoardSize(x);

}

int Menu::getBoardSize() {

    return BoardSize;
}


Menu::Menu() {
    BoardSize = 5;
}