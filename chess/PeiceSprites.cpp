#include "PeiceSprites.h"
#include <iostream>
sf::Texture temp_texture;

PeiceSprites::PeiceSprites()
{
	blank_texture.loadFromFile("textures/blank.png");
	blank.setTexture(blank_texture);

	bKing_texture.loadFromFile("textures/kingB.png");
	bKing.setTexture(bKing_texture);

	temp_texture.loadFromFile("textures/queenB.png");
	bQueen.setTexture(temp_texture);

	temp_texture.loadFromFile("textures/rookB.png");
	bRook.setTexture(bRook_texture);

	bRook_texture.loadFromFile("textures/bishopB.png");
	bBishop.setTexture(temp_texture);

	bKnight_texture.loadFromFile("textures/knightB.png");
	bKnight.setTexture(bKnight_texture);

	bPawn_texture.loadFromFile("textures/pawnB.png");
	bPawn.setTexture(bPawn_texture);

	wKing_texture.loadFromFile("textures/kingW.png");
	wKing.setTexture(wKing_texture);

	wQueen_texture.loadFromFile("textures/queenW.png");
	wQueen.setTexture(wQueen_texture);

	wRook_texture.loadFromFile("textures/rookW.png");
	wRook.setTexture(wRook_texture);

	wBishop_texture.loadFromFile("textures/bishopW.png");
	wBishop.setTexture(wBishop_texture);

	wKnight_texture.loadFromFile("textures/knightW.png");
	wKnight.setTexture(wKnight_texture);

	wPawn_texture.loadFromFile("textures/pawnW.png");
	wPawn.setTexture(temp_texture);
}

