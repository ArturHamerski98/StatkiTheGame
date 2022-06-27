#pragma once
class Menu
{
protected:
	int BoardSize;
	void setBoardSize(int bs);

public:
	void printMenu();
	int getBoardSize();
	
	Menu();

};

