#include "Computer.h"
#include "Player.h"
#include "Menu.h"
#include <windows.h>

Computer::Computer(int size) {

    name = "Computer";
    this->size = size;

    myBoard = Board(size);
    enemyBoard = Board(size);
    Fleet.push_back(Ship(1));
    Fleet.push_back(Ship(2));
    Fleet.push_back(Ship(3));
    Fleet.push_back(Ship(4));
}

Computer::Computer() {}
void Computer::TakeAShot(Player& enemy) {
    int x, y;

    if (plansOfWar.size() == 0) {
        bool temp = 0;
        do {

            x = rand() % size;
            y = rand() % size;
            temp = 0;

            for (int i = 0; i < shootPositions.size(); i++) {
                if (shootPositions[i].x == x && shootPositions[i].y == y)
                    temp = 1;
            }

        } while (temp == 1);

    }
    else {

        bool temp2;
        do {
            temp2 = 0;
            if (plansOfWar.back().direction == 0) {
                x = plansOfWar.back().hitedShip.x + 1;
                y = plansOfWar.back().hitedShip.y;
                if (x >= size) {
                    temp2 = 1;
                    plansOfWar.back().direction++;
                }
                else {
                    for (int i = 0; i < shootPositions.size(); i++) {
                        if (shootPositions[i].x == x && shootPositions[i].y == y) {
                            temp2 = 1;
                            plansOfWar.back().direction++;
                        }

                    }
                }

            }
            else if (plansOfWar.back().direction == 1) {
                x = plansOfWar.back().hitedShip.x - 1;
                y = plansOfWar.back().hitedShip.y;
                if (x < 0) {
                    temp2 = 1;
                    plansOfWar.back().direction++;
                }
                else {
                    for (int i = 0; i < shootPositions.size(); i++) {
                        if (shootPositions[i].x == x && shootPositions[i].y == y) {
                            temp2 = 1;
                            plansOfWar.back().direction++;
                        }

                    }
                }

            }
            else if (plansOfWar.back().direction == 2) {
                x = plansOfWar.back().hitedShip.x;
                y = plansOfWar.back().hitedShip.y + 1;
                if (y >= size) {
                    temp2 = 1;
                    plansOfWar.back().direction++;
                }
                else {
                    for (int i = 0; i < shootPositions.size(); i++) {
                        if (shootPositions[i].x == x && shootPositions[i].y == y) {
                            temp2 = 1;
                            plansOfWar.back().direction++;
                        }

                    }
                }
            }
            else if (plansOfWar.back().direction == 3) {
                x = plansOfWar.back().hitedShip.x;
                y = plansOfWar.back().hitedShip.y - 1;
                if (y < 0) {
                    temp2 = 1;
                    plansOfWar.back().direction++;
                }
                else {
                    for (int i = 0; i < shootPositions.size(); i++) {
                        if (shootPositions[i].x == x && shootPositions[i].y == y) {
                            temp2 = 1;
                            plansOfWar.back().direction++;
                        }

                    }
                }
            }
            else {

                plansOfWar.push_back(plansOfWar.at(0));

            }

        } while (temp2 == 1);
        plansOfWar.back().direction++;
    }

    shootPositions.push_back(coordinates{
      x,
      y
        });

    if (enemyBoard.getCellValue(x, y) != '0') {
        std::cout << "You've missed!\n";
        system("Color 80");
        Sleep(250);
        system("Color 30");
        Sleep(250);
        system("Color 80");
        Sleep(250);
        system("Color 30");
        if (plansOfWar.size() > 1) {
            plansOfWar.push_back(plansOfWar.at(0));

        }
        return;
    }

    if (enemy.myBoard.getCellValue(x, y) == '0') {
        std::cout << "You've missed!\n";
        enemyBoard.setCellValue(x, y, 'M');
        enemy.myBoard.setCellValue(x, y, 'M');
        system("Color 80");
        Sleep(250);
        system("Color 30");
        Sleep(250);
        system("Color 80");
        Sleep(250);
        system("Color 30");
        if (plansOfWar.size() > 1) {
            plansOfWar.push_back(planOfWar{
              plansOfWar.at(0).hitedShip, plansOfWar.back().direction
                });

        }
        return;
    }
    else {
        std::cout << "You've hit!\n";
        enemyBoard.setCellValue(x, y, 'H');
        enemy.myBoard.setCellValue(x, y, 'H');
        if (plansOfWar.size() == 0)
            plansOfWar.push_back(planOfWar{
              coordinates {
                x,
                y
              }, 0
                });
        else
            plansOfWar.push_back(planOfWar{
              coordinates {
                x,
                y
              }, plansOfWar.back().direction - 1
                });
        for (int i = 0; i < enemy.Fleet.size(); i++) {

            for (int j = 0; j < enemy.Fleet[i].shipSize; j++) {
                if (enemy.Fleet[i].positions[j].x == x && enemy.Fleet[i].positions[j].y == y) {
                    enemy.Fleet[i].numOfHits++;

                    if (enemy.Fleet[i].numOfHits == enemy.Fleet[i].shipSize) {
                        std::cout << "Ship sunk!";
                        plansOfWar.clear();
                        system("Color 07");
                        Sleep(250);
                        system("Color 30");
                        Sleep(250);
                        system("Color 07");
                        Sleep(250);
                        system("Color 30");
                        enemy.Fleet[i].status = 1;
                        for (int k = 0; k < enemy.Fleet[i].shipSize; k++) {
                            enemyBoard.setCellValue(enemy.Fleet[i].positions[k].x, enemy.Fleet[i].positions[k].y, 35);
                            enemy.myBoard.setCellValue(enemy.Fleet[i].positions[k].x, enemy.Fleet[i].positions[k].y, 35);
                        }
                        for (int a = 0; a < enemy.Fleet.size(); a++) { //checking if all of the ships were sunk (wchich indicates a win)
                            if (enemy.Fleet[a].status == 0) {
                                return;
                            }
                        }
                        system("cls");
                        enemyBoard.printSea(size);
                        std::cout << "\nCongratulations! " << name << " wins!";

                        for (int q = 0; q < 10; q++) {
                            system("Color 60");
                            Sleep(250);
                            system("Color 30");
                            Sleep(250);

                        }

                        system("cls");
                        Menu::printMenu();

                    }

                }
            }
        }
        system("Color 40");
        Sleep(250);
        system("Color 30");
        Sleep(250);
        system("Color 40");
        Sleep(250);
        system("Color 30");
        return;
    }

}

void Computer::PlaceShips() {
    //umieszaczanie statkow na mapie
    int xStart, yStart, xEnd = -1, yEnd = -1;
    coordinates temp;
    std::vector < coordinates > takenPositions;

    for (int i = 0; i < Fleet.size(); i++) {
        std::vector < coordinates > currentShipVector; //wektor przechowuje koordynaty obecnie umieszczanego statku
        std::vector < coordinates > currentShipVectorExtended; //wektor przechowuje koordynaty obecnie umieszczanego statku oraz pol dookola niego

        system("CLS");
        
        xStart = rand() % size;
        yStart = rand() % size;

        if (Fleet[i].shipSize == 1) {
            temp.x = xStart;
            temp.y = yStart;

            takenPositions.push_back(temp);

            Fleet[i].positions.push_back(temp);

            myBoard.setCellValue(xStart, yStart, 178);

            continue;
        }

        if (Fleet[i].shipSize > 1) {

            if (rand() % 2 == 0) {
                xEnd = xStart;
                yEnd = yStart + Fleet[i].shipSize - 1;

                if (yEnd >= size) {
                    i--;
                    continue;

                }

            }
            else {
                xEnd = xStart + Fleet[i].shipSize - 1;
                yEnd = yStart;

                if (xEnd >= size) {
                    i--;
                    continue;
                }

            }

            //warunki do sprawdzenia przy wielomasztowcach
            //sprawdzamy czy koordynaty sa podane od lewej do prawej, jeœli nie - zamieniamy je miejscami
            if (xStart + yStart > xEnd + yEnd) {
                int tempXStart = xStart;
                int tempYStart = yStart;
                xStart = xEnd;
                yStart = yEnd;
                xEnd = tempXStart;
                yEnd = tempYStart;

            }

            //badamy czy nie po skosie!
            else if ((xStart != xEnd) && (yStart != yEnd)) {

                i--;
                continue;
            }
            //badamy czy odpowiednia d³ugoœæ statku
            else if ((xStart == xEnd) && (-(yStart - yEnd) + 1 != Fleet[i].shipSize)) {

                i--;
                continue;
            }
            else if ((yStart == yEnd) && (-(xStart - xEnd) + 1 != Fleet[i].shipSize)) {

                i--;
                continue;
            }
        }

        int dif = 0;
        //umieszczanie pozycji w wektorach:
        //poziome statki
        if (yStart == yEnd) {
            dif = -(xStart - xEnd) + 1;
            for (int i = 0; i < dif; i++) {
                temp.x = xStart + i;
                temp.y = yStart;

                currentShipVector.push_back(temp);

                currentShipVectorExtended.push_back(temp);

                temp.y += 1;
                currentShipVectorExtended.push_back(temp);
                temp.y -= 2;
                currentShipVectorExtended.push_back(temp);
            }
            temp.x = xStart - 1;
            temp.y = yStart;
            currentShipVectorExtended.push_back(temp);

            temp.x = xEnd + 1;
            temp.y = yStart;
            currentShipVectorExtended.push_back(temp);
        }
        //pionowe statki
        else if (xStart == xEnd) {
            dif = -(yStart - yEnd) + 1;
            for (int i = 0; i < dif; i++) {
                temp.x = xStart;
                temp.y = yStart + i;
                currentShipVector.push_back(temp);
                currentShipVectorExtended.push_back(temp);

                temp.x += 1;
                currentShipVectorExtended.push_back(temp);
                temp.x -= 2;
                currentShipVectorExtended.push_back(temp);

            }
            temp.x = xStart;
            temp.y = yStart - 1;
            currentShipVectorExtended.push_back(temp);

            temp.x = xEnd;
            temp.y = yEnd + 1;
            currentShipVectorExtended.push_back(temp);
        }
        //sprawdzamy czy istnieje mozliwosc umieszczenia statku w tym miejscu
        bool isTaken = 0;
        for (int i = 0; i < takenPositions.size(); i++) {
            for (int j = 0; j < currentShipVectorExtended.size(); j++) {
                if ((takenPositions[i].x == currentShipVectorExtended[j].x) && (takenPositions[i].y == currentShipVectorExtended[j].y)) {
                    isTaken = 1;
                }
            }
        }

        if (isTaken == 1) {

            i--;
            continue;
        }
        else { //umieszczenie statku na mapie
            for (int j = 0; j < currentShipVector.size(); j++) {
                takenPositions.push_back(currentShipVector[j]);
                Fleet[i].positions.push_back(currentShipVector[j]);
                myBoard.setCellValue(currentShipVector[j].x, currentShipVector[j].y, 178);
            }
        }

    }
    system("CLS");
    std::cout << name << "'s fleet\n";
    myBoard.printSea(size);
    Sleep(5000);

}