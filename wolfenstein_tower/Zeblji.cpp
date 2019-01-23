#include "Zeblji.h"

Zeblji::Zeblji(sf::Texture &textura, float x, float y, int st_dotik,int izris)
{
    //ctor
    stevilo_dotikov = st_dotik;
    se_izrise = izris;
    slika.setTexture(textura);
    slika.setTextureRect(sf::IntRect(128,0, 64, 64));
    // za aèetek nastavi x koordinato na - 75.f
    // x = -30.f y = 625.f
    slika.setPosition(sf::Vector2f(x, y)); // absolute position
    slika.setScale(sf::Vector2f(1.3f, 1.3f));
    slika.setOrigin(sf::Vector2f(32,32));
}

void Zeblji::spremeni_pozicijo(float x, float y)
{
    slika.setPosition(sf::Vector2f(x,y));
}

Zeblji::~Zeblji()
{
    //dtor
}
