#include "Monkey.h"

Monkey::Monkey(sf::Texture &textura,int zdr,float x, float y, int izris)
{
    //ctor
    se_izrise = izris;
    zdravje = zdr;
    slika.setTexture(textura);
    slika.setTextureRect(sf::IntRect(0,0, 64, 64));
    // za aèetek nastavi x koordinato na - 75.f
    // x = -30.f y = 625.f
    slika.setPosition(sf::Vector2f(x, y)); // absolute position
    slika.setScale(sf::Vector2f(1.3f, 1.3f));
    slika.setOrigin(sf::Vector2f(32,32));
}

void Monkey::spremeni_pozicijo(float x, float y)
{
    slika.setPosition(sf::Vector2f(x,y));
}

void Monkey::preveri_animacijo()
{
        sf::Time elapsed1 = casAnimacije.getElapsedTime();
    if(elapsed1.asMilliseconds() > 300){
        casAnimacije.restart();
        slika.setTextureRect(sf::IntRect(0,0,64,64));
    }

}

Monkey::~Monkey()
{
    //dtor
}
