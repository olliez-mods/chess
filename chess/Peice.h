#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
class Peice
{
public:
	sf::Texture texture;
	sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(100.0, 100.0));
	int peice;
	bool isBlack;
	bool beenMoved = false;
	void setPos(int x, int y);
	void draw(sf::RenderWindow& window);
	void setTexture();
	Peice(int peice, bool isBlack);

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