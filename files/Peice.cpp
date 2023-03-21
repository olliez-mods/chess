#include "Peice.h"
#include <vector>

void Peice::setPos(sf::Vector2i pos)
{
	if (pos.x >= 0 && pos.x <= 7 && pos.y >= 0 && pos.y <= 7)
	{
		this->pos = pos;
		rect.setPosition(sf::Vector2f(pos.x*100, pos.y*100));
	}
}

void Peice::setPos(int x, int y)
{
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
	{
		this->pos = sf::Vector2i(x, y);
		rect.setPosition(sf::Vector2f(x * 100, y * 100));
	}
}

sf::Vector2i Peice::getPos()
{
	return pos;
}


sf::RectangleShape Peice::getRect()
{
	return rect;
}

sf::Texture &Peice::getTexture()
{
	return texture;
}

void Peice::setTexture(std::string texturePath)
{
	texture.loadFromFile(texturePath);
}

Peice::Peice(int peice, bool isBlack, sf::Vector2i pos)
{
	this->peice = peice;
	this->isBlack = isBlack;

	rect = sf::RectangleShape(sf::Vector2f(100.0, 100.0));

	std::string clr = "W";
	if (isBlack) { clr = "B"; }

	std::string toLoad;

	switch (peice)
	{
	case 1:
		toLoad = "resources/king" + clr + ".png";
		break;
	case 2:
		toLoad = "resources/queen" + clr + ".png";
		break;
	case 3:
		toLoad = "resources/rook" + clr + ".png";
		break;
	case 4:
		toLoad = "resources/bishop" + clr + ".png";
		break;
	case 5:
		toLoad = "resources/knight" + clr + ".png";
		break;
	case 6:
		toLoad = "resources/pawn" + clr + ".png";
		break;
	default:
		toLoad = "resources/blank.png";
	}
	texture.loadFromFile(toLoad);
	rect.setTexture(&texture);
	setPos(pos);
}


int Peice::getPeiceAt(sf::Vector2i pos, std::vector<Peice> &peices)
{
	for (int i = 0; i < peices.size(); i++)
	{
		if (peices[i].getPos() == pos)
		{
			if (!peices[i].disabled)
			{
				return i;
			}
		}
	}
	return -1;
}

std::vector<sf::Vector2i> Peice::getValidMoves(Peice peice, std::vector<Peice>& peices)
{
	std::vector<sf::Vector2i> validMoves = std::vector<sf::Vector2i>();
	switch (peice.peice)
	{
	case 1:
		validMoves.push_back(peice.getPos() + sf::Vector2i(-1, -1));
		validMoves.push_back(peice.getPos() + sf::Vector2i(0, -1));
		validMoves.push_back(peice.getPos() + sf::Vector2i(1, -1));
		validMoves.push_back(peice.getPos() + sf::Vector2i(-1, 0));
		validMoves.push_back(peice.getPos() + sf::Vector2i(1, 0));
		validMoves.push_back(peice.getPos() + sf::Vector2i(-1, 1));
		validMoves.push_back(peice.getPos() + sf::Vector2i(0, 1));
		validMoves.push_back(peice.getPos() + sf::Vector2i(1, 1));
		break;
	case 2:
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(i, i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(i, i), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(-i, i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(-i, i), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(i, -i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(i, -i), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(-i, -i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(-i, -i), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(i, 0));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(i, 0), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(-i, 0));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(-i, 0), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(0, -i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(0, -i), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(0, i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(0, i), peices) != -1) { break; }
		}
		break;
	case 3:
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(i, 0));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(i, 0), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(-i, 0));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(-i, 0), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(0, -i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(0, -i), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(0, i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(0, i), peices) != -1) { break; }
		}
		break;
	case 4:
		for (int i = 1; i < 8; i++)
		{
			 validMoves.push_back(peice.getPos() + sf::Vector2i(i, i));
			 if (getPeiceAt(peice.getPos() + sf::Vector2i(i, i), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(-i, i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(-i, i), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(i, -i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(i, -i), peices) != -1) { break; }
		}
		for (int i = 1; i < 8; i++)
		{
			validMoves.push_back(peice.getPos() + sf::Vector2i(-i, -i));
			if (getPeiceAt(peice.getPos() + sf::Vector2i(-i, -i), peices) != -1) { break; }
		}
		break;
	case 5:
		validMoves.push_back(peice.getPos() + sf::Vector2i(-1, 2));
		validMoves.push_back(peice.getPos() + sf::Vector2i(1, 2));

		validMoves.push_back(peice.getPos() + sf::Vector2i(-2, 1));
		validMoves.push_back(peice.getPos() + sf::Vector2i(-2, -1));

		validMoves.push_back(peice.getPos() + sf::Vector2i(1, -2));
		validMoves.push_back(peice.getPos() + sf::Vector2i(-1, -2));

		validMoves.push_back(peice.getPos() + sf::Vector2i(2, -1));
		validMoves.push_back(peice.getPos() + sf::Vector2i(2, 1));
		break;
	case 6:
		if (peice.isBlack)
		{
			if (peice.firstMove && Peice::getPeiceAt(peice.getPos() + sf::Vector2i(0, 1), peices) == -1 && Peice::getPeiceAt(peice.getPos() + sf::Vector2i(0, 2), peices) == -1)
			{
				validMoves.push_back(peice.getPos() + sf::Vector2i(0, 2));
			}
			if (Peice::getPeiceAt(peice.getPos() + sf::Vector2i(0, 1), peices) == -1) { validMoves.push_back(peice.getPos() + sf::Vector2i(0, 1)); }
			if(Peice::getPeiceAt(peice.getPos() + sf::Vector2i(1, 1), peices) != -1){ validMoves.push_back(peice.getPos() + sf::Vector2i(1, 1)); }
			if (Peice::getPeiceAt(peice.getPos() + sf::Vector2i(-1, 1), peices) != -1) { validMoves.push_back(peice.getPos() + sf::Vector2i(-1, 1)); }
		}
		else
		{
			if (peice.firstMove && Peice::getPeiceAt(peice.getPos() + sf::Vector2i(0, -1), peices) == -1 && Peice::getPeiceAt(peice.getPos() + sf::Vector2i(0, -2), peices) == -1)
			{
				validMoves.push_back(peice.getPos() + sf::Vector2i(0, -2));
			}
			if (Peice::getPeiceAt(peice.getPos() + sf::Vector2i(0, -1), peices) == -1) { validMoves.push_back(peice.getPos() + sf::Vector2i(0, -1)); }
			if (Peice::getPeiceAt(peice.getPos() + sf::Vector2i(1, -1), peices) != -1) { validMoves.push_back(peice.getPos() + sf::Vector2i(1, -1)); }
			if (Peice::getPeiceAt(peice.getPos() + sf::Vector2i(-1, -1), peices) != -1) { validMoves.push_back(peice.getPos() + sf::Vector2i(-1, -1)); }
		}
		break;
	}

	for (int i = 0; i < validMoves.size(); i++)
	{
		int index = Peice::getPeiceAt(validMoves[i], peices);
		if (index != -1)
		{
			if (peices[index].isBlack == peice.isBlack || peices[index].getPos() == peice.getPos())
			{
				validMoves.erase(validMoves.begin() + i);
				i--;
			}
		}
	}
	
	for (int i = 0; i < validMoves.size(); i++)
	{
		if (
			validMoves[i].x > 7 || 
			validMoves[i].x < 0||
			validMoves[i].y > 7 ||
			validMoves[i].y < 0)
		{
			validMoves[i] = sf::Vector2i(-1, -1);
		}
	}


	
	return validMoves;
}

bool Peice::inValidSpace(sf::Vector2i pos, std::vector<sf::Vector2i> validMoves)
{
	for (int i = 0; i < validMoves.size(); i++)
	{
		if (validMoves[i] == pos)
		{
			return true;
		}
	}
	return false;
}
