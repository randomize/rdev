#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main()
{
    // sf::sleep(sf::seconds(1.f));
    sf::ContextSettings settings;
    settings.depthBits         = 24;
    settings.stencilBits       = 8;
    settings.antialiasingLevel = 2;  // Optional

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Close, settings);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    // running = false;
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
