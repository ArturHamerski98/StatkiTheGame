#pragma once
class GameHandler
{
	
	int turnLimit;
protected:
	int BoardSize;
	void setBoardSize(int bs);

public:
	void pVp();
	int getBoardSize();
	void displayShotResult();
	void getTurnLimit();
		/*Zadanie: Trzeba stworzyæ klasê GameHandler w która :
	+*Tworzy dwóch graczy
	+* Dwaj gracze Tworz¹ swoje statki
	* Gracze wykonuj¹ ruch na zmianê
	 *- wyœwietla sie informacja, którego gracza jest tura
	* -wyswietlaja sie 2 plansze
	 -prosi gracza o podanie koordynatow(tylko cout nie implementacja)
	 - informujemy czy trafienie czy pudlo(tylko cout nie implementacja)
	+ -czekamy 3sekundy, czyscimy konsole, zmiana tury na gracza numer 2
	+ -zrobiæ Level4
	
	* */
	
};

