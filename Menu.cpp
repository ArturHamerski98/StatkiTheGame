#include "Menu.h"
#include <iostream>

void Menu::printMenu()
{
}

=======

void  Menu::printMenu()
{
    int x;
    std::cout << "Wpraowaaaaaaaaaaadz rozmiar planszy: \n";
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