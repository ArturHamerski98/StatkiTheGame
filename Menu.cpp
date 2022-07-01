#include "Menu.h"
#include <iostream>
#include "GameHandler.h"

void Menu::printMenu()
{

    std::cout << "................................................." << std::endl;
    std::cout << "................................................." << std::endl;
    std::cout << "...................]]]..,@@[....................." << std::endl;
    std::cout << ".............`[\\]]]@@]`,[@]`..]`................." << std::endl;
    std::cout << "...........\\]]@[[[[\\@\\]`[\\@]`[\\\\`[^....]/\\`......" << std::endl;
    std::cout << "=@@@@O]]]]]]]`...,[[@\\]].,[@]],[\\][\\\\][@][`......" << std::endl;
    std::cout << ".\\@]]]]]]]`.   ..[[[\\@`...,[\\\\]`,[\\],[]/\\\\``....." << std::endl;
    std::cout << "..=@@@@@@@@@@@@@@@@@@@@@\\@@@@@]]`..[[]][`][\\/...." << std::endl;
    std::cout << "...=@@@@@@@@@@@@@@@@@@@@@@@@@@/@]@[@[@@@O]]/[,@.." << std::endl;
    std::cout << ".....,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//..." << std::endl;
    std::cout << "......\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//....." << std::endl;
    std::cout << "" << std::endl;

    std::cout << "Welcome to the Battleship game! Are you up to the dangerous life on the open sea? Let's see if you surivive!\n";
    std::cout << "1 Player-versus-player " << std::endl;
    std::cout << "2 Player-versus-computer" << std::endl;
    std::cout << "3 Quit game\nYour choice: ";
    int choice;
    std::cin >> choice;
    if (choice == 1)
    {
        GameHandler myGame;
        myGame.getBoardSize();
        myGame.getTurnLimit();
        system("cls");
        myGame.pVp();

    }
    else if (choice == 2)
    {
        GameHandler myGame;
        myGame.getBoardSize();
        myGame.getTurnLimit();
        system("cls");
        myGame.pVc();
    }
    else
        exit(0);
}