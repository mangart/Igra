#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Enemie.h"

int zivljenja = 100;
int stanje_igre = 2;
int denar = 600;
    sf::RenderWindow win(sf::VideoMode(1800, 900), "Wolfenstein tower");
    sf::Texture guard;
    sf::Texture ss;
    sf::Texture ozadje;
    sf::Texture obraz;
std::stringstream ziv;
std::stringstream den;

int main()
{
    ziv << zivljenja;
    den << denar;

if (!guard.loadFromFile("sprites/guard_sprite_sheet.png"))
{
    // error...
    std::cout << "Neki je narobe!";

}
if(!ss.loadFromFile("sprites/SS_sprite_sheet2.png")){
    std::cout << "Neki je narobe!";
}
if(!ozadje.loadFromFile("sprites/PC Computer - Wolfenstein 3D - Walls.png")){
    std::cout << "Neki je narobe!";
}

if(!obraz.loadFromFile("sprites/PC Computer - Wolfenstein 3D - BJ Blazkowicz.png")){
    std::cout << "Neki je narobe!";
}

sf::Font font;
if (!font.loadFromFile("Arcon-Regular.otf"))
{
    // error...
}

sf::Text text;
text.setFont(font); // font is a sf::Font
text.setString("Zivljenja: " + ziv.str());
text.setCharacterSize(24); // in pixels, not points!
text.setFillColor(sf::Color::Red);
text.setPosition(sf::Vector2f(1600.f, 50.f));

sf::Text text1;
text1.setFont(font); // font is a sf::Font
text1.setString("Denar: " + den.str());
text1.setCharacterSize(24); // in pixels, not points!
text1.setFillColor(sf::Color::Red);
text1.setPosition(sf::Vector2f(1600.f, 100.f));

sf::Sprite sprite;
sprite.setTexture(guard);
sprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
sprite.setPosition(sf::Vector2f(10.f, 625.f)); // absolute position
sprite.setScale(sf::Vector2f(2.5f, 2.5f));

sf::Sprite sprite1;
sprite1.setTexture(ss);
sprite1.setTextureRect(sf::IntRect(64, 128, 64, 64));
sprite1.setPosition(sf::Vector2f(448.f, 400.f)); // absolute position
sprite1.setScale(sf::Vector2f(2.5f, 2.5f));

sf::Sprite ozad;
ozad.setTexture(ozadje);
ozad.setTextureRect(sf::IntRect(0, 0, 64, 64));
ozad.setPosition(sf::Vector2f(0.f, 0.f)); // absolute position
ozad.setScale(sf::Vector2f(28.125f, 14.0625f));

sf::Sprite pot1;
pot1.setTexture(ozadje);
pot1.setTextureRect(sf::IntRect(128,320,64,64));
pot1.setPosition(0.f,650.f);
pot1.setScale(sf::Vector2f(7.f, 2.4f));

sf::Sprite pot2;
pot2.setTexture(ozadje);
pot2.setTextureRect(sf::IntRect(128,320,64,64));
pot2.setPosition(448.f,200.f);
pot2.setScale(sf::Vector2f(2.4f, 9.43125f));

sf::Sprite pot3;
pot3.setTexture(ozadje);
pot3.setTextureRect(sf::IntRect(128,320,64,64));
pot3.setPosition(601.6f,200.f);
pot3.setScale(sf::Vector2f(5.f, 2.4f));

sf::Sprite pot4;
pot4.setTexture(ozadje);
pot4.setTextureRect(sf::IntRect(128,320,64,64));
pot4.setPosition(921.6f,200.f);
pot4.setScale(sf::Vector2f(2.4f, 9.43125f));

sf::Sprite pot5;
pot5.setTexture(ozadje);
pot5.setTextureRect(sf::IntRect(128,320,64,64));
pot5.setPosition(1075.2f,650.f);
pot5.setScale(sf::Vector2f(6.6375f, 2.4f));

sf::Sprite nadzorna;
nadzorna.setTexture(ozadje);
nadzorna.setTextureRect(sf::IntRect(0,448,64,64));
nadzorna.setPosition(1500.f,0.f);
nadzorna.setScale(sf::Vector2f(4.6875f,14.0625f));

sf::Sprite obr;
obr.setTexture(obraz);
obr.setTextureRect(sf::IntRect(0,1,24,31));
obr.setPosition(1510.f,50.f);
obr.setScale(sf::Vector2f(2.5f,2.5f));
win.setFramerateLimit(60);

Enemie enemie(guard,10,10,10,3,-30.f,625.f);
Enemie enemie1(ss,10,10,10,2,448.f, 400.f);

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
        win.draw(ozad);
        win.draw(pot1);
        win.draw(pot2);
        win.draw(pot3);
        win.draw(pot4);
        win.draw(pot5);
        win.draw(nadzorna);
        //win.draw(sprite);
        win.draw(enemie.slika);
        win.draw(enemie1.slika);
        //win.draw(sprite1);
        win.draw(text);
        win.draw(text1);
        win.draw(obr);
        win.display();
        enemie.preveriAnimacijo();
        enemie1.preveriAnimacijo();
    }

    return 0;
}
