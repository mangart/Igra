#include "Metek.h"
#include <math.h>


Metek::Metek(sf::Texture &tekstura,int hitro,int smerniX,int smerniY,float rotacija,float x, float y,float ciljX,float ciljY)
{
    //ctor
    slika.setTexture(tekstura);
    slika.setTextureRect(sf::IntRect(0, 128, 64, 64));
    slika.setOrigin(32,32);
    // za aèetek nastavi x koordinato na - 75.f
    // x = -30.f y = 625.f
    slika.setPosition(sf::Vector2f(x, y)); // absolute position
    slika.setRotation(rotacija);
    slika.setScale(sf::Vector2f(2.5f, 2.5f));
    hitrost = hitro;
    smerX = smerniX;
    smerY = smerniY;
    ciljniX = ciljX;
    ciljniY = ciljY;
    float dolzina = (smerX * smerX) + (smerY * smerY);
    dolzina = sqrt(dolzina);
    normirana_smerX = smerX / dolzina;
    normirana_smerY = smerY / dolzina;
    razdalja = (x - ciljX) * (x - ciljX) + (y - ciljY) * (y - ciljY);
    razdalja = sqrt(razdalja);
    stanje = 1;

}

Metek::~Metek()
{
    //dtor
}
