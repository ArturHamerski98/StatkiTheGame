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
	/*Zadanie: Trzeba stworzy� klas� GameHandler w kt�ra :
+*Tworzy dw�ch graczy
+* Dwaj gracze Tworz� swoje statki
* Gracze wykonuj� ruch na zmian�
 *- wy�wietla sie informacja, kt�rego gracza jest tura
* -wyswietlaja sie 2 plansze
 -prosi gracza o podanie koordynatow(tylko cout nie implementacja)
 - informujemy czy trafienie czy pudlo(tylko cout nie implementacja)
+ -czekamy 3sekundy, czyscimy konsole, zmiana tury na gracza numer 2
+ -zrobi� Level4

* */

};
