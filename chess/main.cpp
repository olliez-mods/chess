#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include "Peice.h"

void resetBoard(std::vector<Peice> &peices)
{
    peices = std::vector<Peice>();

    peices.push_back(Peice(3, true, sf::Vector2i(0, 0)));
    peices.push_back(Peice(5, true, sf::Vector2i(1, 0)));
    peices.push_back(Peice(4, true, sf::Vector2i(2, 0)));
    peices.push_back(Peice(1, true, sf::Vector2i(3, 0)));
    peices.push_back(Peice(2, true, sf::Vector2i(4, 0)));
    peices.push_back(Peice(4, true, sf::Vector2i(5, 0)));
    peices.push_back(Peice(5, true, sf::Vector2i(6, 0)));
    peices.push_back(Peice(3, true, sf::Vector2i(7, 0)));

    peices.push_back(Peice(6, true, sf::Vector2i(0, 1)));
    peices.push_back(Peice(6, true, sf::Vector2i(1, 1)));
    peices.push_back(Peice(6, true, sf::Vector2i(2, 1)));
    peices.push_back(Peice(6, true, sf::Vector2i(3, 1)));
    peices.push_back(Peice(6, true, sf::Vector2i(4, 1)));
    peices.push_back(Peice(6, true, sf::Vector2i(5, 1)));
    peices.push_back(Peice(6, true, sf::Vector2i(6, 1)));
    peices.push_back(Peice(6, true, sf::Vector2i(7, 1)));


    peices.push_back(Peice(3, false, sf::Vector2i(0, 7)));
    peices.push_back(Peice(5, false, sf::Vector2i(1, 7)));
    peices.push_back(Peice(4, false, sf::Vector2i(2, 7)));
    peices.push_back(Peice(1, false, sf::Vector2i(3, 7)));
    peices.push_back(Peice(2, false, sf::Vector2i(4, 7)));
    peices.push_back(Peice(4, false, sf::Vector2i(5, 7)));
    peices.push_back(Peice(5, false, sf::Vector2i(6, 7)));
    peices.push_back(Peice(3, false, sf::Vector2i(7, 7)));

    peices.push_back(Peice(6, false, sf::Vector2i(0, 6)));
    peices.push_back(Peice(6, false, sf::Vector2i(1, 6)));
    peices.push_back(Peice(6, false, sf::Vector2i(2, 6)));
    peices.push_back(Peice(6, false, sf::Vector2i(3, 6)));
    peices.push_back(Peice(6, false, sf::Vector2i(4, 6)));
    peices.push_back(Peice(6, false, sf::Vector2i(5, 6)));
    peices.push_back(Peice(6, false, sf::Vector2i(6, 6)));
    peices.push_back(Peice(6, false, sf::Vector2i(7, 6)));
}


bool mouseInBox(sf::RenderWindow &window)
{
    return(sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < window.getSize().x &&
           sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).x < window.getSize().y);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setTitle("Turn: White");
    
    sf::Image icon;
    icon.loadFromFile("resources/icon.png"); // File/Image/Pixel
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::SoundBuffer buffer;
    buffer.loadFromFile("resources/moveSound.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
  

    sf::Sprite board_sprite;
    sf::Texture board_texture;
    board_texture.loadFromFile("resources/board.png");
    board_sprite.setTexture(board_texture);

    sf::RectangleShape validMoveBox = sf::RectangleShape(sf::Vector2f(100.0, 100.0));
    validMoveBox.setFillColor(sf::Color(0, 255, 0, 150));

    std::vector<sf::Vector2i> validMoves = std::vector<sf::Vector2i>();

    std::vector<Peice> peices = std::vector<Peice>();
    resetBoard(peices);
    

    bool holdingPeice = false;
    int holdingPeiceIndex = 0;

    bool overLayKeyDown = false;
    bool overlay = true;

    bool isBlackTurn = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        sf::Vector2i mosPos = sf::Mouse::getPosition(window);
        sf::Vector2i square = mosPos / 100;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && mouseInBox(window))
        {
            if (!overLayKeyDown)
            {
                if (overlay)
                {
                    overlay = false;
                    validMoveBox.setFillColor(sf::Color(0, 255, 0, 0));
                }
                else
                {
                    overlay = true;
                    validMoveBox.setFillColor(sf::Color(0, 255, 0, 150));
                }
                overLayKeyDown = true;
            }
        }
        else
        {
            overLayKeyDown = false;
        }

        if (mouseInBox(window) && sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            resetBoard(peices);
            holdingPeice = false;
            holdingPeiceIndex = 0;

            overLayKeyDown = false;
            overlay = true;

            isBlackTurn = false;
            window.setTitle("Turn: White");
        }

        if (mouseInBox(window))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (!holdingPeice)
                {
                    int i = Peice::getPeiceAt(square, peices);
                    if (i != -1)
                    {
                        if (peices[i].isBlack == isBlackTurn)
                        {
                            holdingPeice = true;
                            holdingPeiceIndex = i;
                            peices[i].disabled = true;
                            validMoves = Peice::getValidMoves(peices[i], peices);
                        }
                    }
                }
            }
            else if (holdingPeice)
            {
                int index = Peice::getPeiceAt(square, peices);
                bool inValidSpace = Peice::inValidSpace(square, validMoves);

                if (inValidSpace)
                {
                    if (index != -1)
                    {
                        peices[index].disabled = true;
                    }
                    if (square != peices[holdingPeiceIndex].getPos()) { peices[holdingPeiceIndex].firstMove = false; }
                    peices[holdingPeiceIndex].setPos(square);
                    sound.play();
                    isBlackTurn = !isBlackTurn;

                    if (peices[holdingPeiceIndex].isBlack && peices[holdingPeiceIndex].peice == 6)
                    {
                        if (square.y == 7)
                        {
                            peices[holdingPeiceIndex].peice = 2;
                            peices[holdingPeiceIndex].setTexture("resources/queenB.png");
                        }
                    }
                    else {
                        if (square.y == 0 && peices[holdingPeiceIndex].peice == 6)
                        {
                            peices[holdingPeiceIndex].peice = 2;
                            peices[holdingPeiceIndex].setTexture("resources/queenW.png");
                        }
                    }

                    window.setTitle("Turn: White");
                    if (isBlackTurn) {
                        window.setTitle("Turn: Black");
                    }
                }
                holdingPeice = false;
                peices[holdingPeiceIndex].disabled = false;
                validMoves = std::vector<sf::Vector2i>();
            }
        }

        window.clear();
        window.draw(board_sprite);
        for (int i = 0; i < validMoves.size(); i++)
        {
            validMoveBox.setPosition(validMoves[i].x*100, validMoves[i].y * 100);
            window.draw(validMoveBox);
        }
        for (int i = 0; i < peices.size(); i++)
        {
            if (!peices[i].disabled)
            {
                sf::Texture text = peices[i].getTexture();
                sf::RectangleShape rect = peices[i].getRect();
                rect.setTexture(&text);
                window.draw(rect);
            }
        }

        if (holdingPeice)
        {
            sf::Texture texture = peices[holdingPeiceIndex].getTexture();
            sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(100.0, 100.0));
            rect.setTexture(&texture);
            rect.setPosition(mosPos.x - 50, mosPos.y - 50);
            window.draw(rect);
        }
        window.display();
    }

    return 0;
}