#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
class Peice
{

	sf::Vector2i pos;
	sf::Texture texture;
	sf::RectangleShape rect;
public:
	int peice;
	bool isBlack;
	bool firstMove = true;
	bool disabled = false;
	void setPos(sf::Vector2i pos);
	void setPos(int x, int y);
	sf::Vector2i getPos();
	sf::RectangleShape getRect();
	sf::Texture& getTexture();
	void setTexture(std::string texturePath);
	Peice(int peice, bool isBlack, sf::Vector2i pos = sf::Vector2i(0, 0));

	static int getPeiceAt(sf::Vector2i pos, std::vector<Peice> &peices);
	static std::vector<sf::Vector2i> getValidMoves(Peice peice, std::vector<Peice>& peices);
	static bool inValidSpace(sf::Vector2i pos, std::vector<sf::Vector2i> validMoves);
};
 
/*
0 blank

1 King
2 Queen
3 Rook
4 Bishop
5 Knight
6 Pawn

*/