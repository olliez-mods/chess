#pragma once
#include <SFML/Graphics.hpp>
class PeiceSprites
{
public:
    sf::Texture blank_texture;
	sf::Texture bKing_texture;
	sf::Texture bQueen_texture;
	sf::Texture bRook_texture;
	sf::Texture bBishop_texture;
	sf::Texture bKnight_texture;
	sf::Texture bPawn_texture;
	sf::Texture wKing_texture;
	sf::Texture wQueen_texture;
	sf::Texture wRook_texture;
	sf::Texture wBishop_texture;
	sf::Texture wKnight_texture;
	sf::Texture wPawn_texture;

    sf::Sprite blank;
    sf::Sprite bKing;
    sf::Sprite bQueen;
    sf::Sprite bRook;
    sf::Sprite bBishop;
    sf::Sprite bKnight;
    sf::Sprite bPawn;
    sf::Sprite wKing;
    sf::Sprite wQueen;
    sf::Sprite wRook;
    sf::Sprite wBishop;
    sf::Sprite wKnight;
    sf::Sprite wPawn;

    PeiceSprites();
};

