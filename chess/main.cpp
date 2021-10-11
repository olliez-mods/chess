#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

bool mouseInBox(sf::RenderWindow &window)
{
    return(sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < window.getSize().x &&
           sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).x < window.getSize().y);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Chess", sf::Style::Titlebar | sf::Style::Close);

    sf::Sprite board_sprite;
    sf::Texture board_texture;
    board_texture.loadFromFile("textures/board.png");
    board_sprite.setTexture(board_texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //testing visual studio git
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseInBox(window))
        {
        }

        window.clear();
        window.draw(board_sprite);
        window.display();
    }

    return 0;
}