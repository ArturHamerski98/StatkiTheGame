#include "Board.h"

Board::Board(int size)
{
	for (int j = 0; j < size; j++) {
		std::vector<char> row;
		for (int i = 0; i < size; i++)
			row.push_back('0');
		Sea.push_back(row);
	}
}

Board::Board()
{
	for (int j = 0; j < 5; j++) {
		std::vector<char> row;
		for (int i = 0; i < 5; i++)
			row.push_back('0');
		Sea.push_back(row);
	}
}

void Board::printSea(int size)
{
	std::cout << "   ";
	for (int i = 0; i < size; i++) { // The loop that use to print out the english character row.
		std::cout << (char)('A' + i) << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (i < 10)
			std::cout << i << "  ";
		else
			std::cout << i << " ";

		for (int j = 0; j < size; j++) {
			std::cout << Sea[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

void Board::setShip(int x, int y)
{
	Sea[x][y] = '1';
}

char Board::getCellValue(int x, int y)
{
	return Sea[x][y];
}