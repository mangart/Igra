#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 800), "SFML Test");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture texture;
if (!texture.loadFromFile("sprites/guard_sprite_sheet.png"))
{
    // error...

}
sf::Sprite sprite;
sprite.setTexture(texture);
sprite.setTextureRect(sf::IntRect(64, 0, 64, 64));
sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position
sprite.setScale(sf::Vector2f(4.f, 4.f));
    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }

        win.clear();
        //win.draw(shape);
        win.draw(sprite);
        win.display();
    }

    return 0;
}
