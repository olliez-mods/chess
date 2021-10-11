#include "Peice.h"

Peice::Peice(int peice, bool isBlack)
{
	this->isBlack = isBlack;
	this->peice = peice;
}

void Peice::setTexture()
{
	std::string type = "W";
	if (isBlack) { type = "B"; }
	switch (peice)
	{
	case 0:
		texture.loadFromFile("textures/blank.png");
		break;
	case 1:
		texture.loadFromFile("textures/king" + type + ".png");
		break;
	case 2:
		texture.loadFromFile("textures/queen" + type + ".png");
		break;
	case 3:
		texture.loadFromFile("textures/rook" + type + ".png");
		break;
	case 4:
		texture.loadFromFile("textures/bishop" + type + ".png");
		break;
	case 5:
		texture.loadFromFile("textures/knight" + type + ".png");
		break;
	case 6:
		texture.loadFromFile("textures/pawn" + type + ".png");
		break;
	}

	rect.setTexture(&texture);
}

void Peice::setPos(int x, int y)
{
	rect.setPosition(x, y);
}

void Peice::draw(sf::RenderWindow& window)
{
	window.draw(rect);
}
