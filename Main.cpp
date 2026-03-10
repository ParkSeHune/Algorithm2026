#include <SFML/Graphics.hpp>
#include "Complexity.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
    window.setFramerateLimit(60);
    Complexity visualizer;
    int startN = 100;
    int endN = 15000;
    int step = 100;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::R)
                {
                    visualizer.runAlgorithm(startN, endN, step);
                }
        }

        window.clear();
        visualizer.draw(window);
        window.display();
    }
    return 0;
}