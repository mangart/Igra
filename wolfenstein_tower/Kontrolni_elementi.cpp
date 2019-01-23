#include "Kontrolni_elementi.h"
#include <iostream>
#include <string>
#include <sstream>


Kontrolni_elementi::Kontrolni_elementi(sf::Texture &textura,sf::Font &font, float x, float y, int xTexture, int yTexture, int cena)
{
    //ctor
    std::stringstream cen;
    cen << cena;
    slika.setTexture(textura);
    tekst.setFont(font);
    slika.setTextureRect(sf::IntRect(xTexture,yTexture, 64, 64));
    slika.setPosition(sf::Vector2f(x, y));
    kvadrat.setSize(sf::Vector2f(64.f, 64.f));
    kvadrat.setPosition(sf::Vector2f(x,y));
    kvadrat.setFillColor(sf::Color(255, 255, 255));
    tekst.setString("Cena: " + cen.str());
    tekst.setCharacterSize(24); // in pixels, not points!
    tekst.setFillColor(sf::Color::Red);
    tekst.setPosition(sf::Vector2f(x , y + 70));
}

Kontrolni_elementi::~Kontrolni_elementi()
{
    //dtor
}
