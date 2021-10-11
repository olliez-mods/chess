#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Peice.h"

void emptyBoard(std::vector<std::vector<Peice>> &board);
void setBoard(std::vector<std::vector<Peice>> &board);
void drawBoard(std::vector<std::vector<Peice>> &board, sf::RenderWindow &window);