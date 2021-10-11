#include "Functions.h"

void emptyBoard(std::vector<std::vector<Peice>> &board)
{
	board = std::vector<std::vector<Peice>>();
	for (int x = 0; x < 8; x++)
	{
		board.push_back(std::vector<Peice>());
		for (int y = 0; y < 8; y++)
		{
			board[x].push_back(Peice(0, true));
			board[x][y].setTexture();
			board[x][y].setPos(x * 100, y * 100);
		}
	}
}

void setBoard(std::vector<std::vector<Peice>> &board)
{
	
	board[0][0] = Peice(3, true);
	board[1][0] = Peice(5, true);
	board[2][0] = Peice(4, true);
	board[3][0] = Peice(2, true);
	board[4][0] = Peice(1, true);
	board[5][0] = Peice(4, true);
	board[6][0] = Peice(5, true);
	board[7][0] = Peice(3, true);
	
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			board[x][y].setPos(x * 100, y * 100);
		}
	}
	
}

void drawBoard(std::vector<std::vector<Peice>> &board, sf::RenderWindow &window)
{
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			window.draw(board[x][y].rect);
		}
	}
}
