#pragma once
#include"Player.h"
class GameHandler
{
private:
	int turnLimit;
	int boardSize;
	void setBoardSize(int bs);

public:
	void pVp();
	void pVc();
	int getBoardSize();
	void displayShotResult();
	void getTurnLimit();

};
