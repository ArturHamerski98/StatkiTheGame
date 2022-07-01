#pragma once
#include <iostream>
#include "Board.h"
#include <vector>
#include "Ship.h"

class Player {
protected:
    std::string name;
    Board enemyBoard;
    int size;
    int enterXCoordinate(int NumberOfLetters);
    int enterYCoordinate(int rowNumber);
  

public:
    void TakeAShot(Player& enemy);
    void PlaceShips();
    void PrintPlayerInterface();
    void printName();
    Board myBoard;
    std::vector < Ship > Fleet;
    Player();
    Player(int size);
};