#include "Kontrolni_obraz.h"

#include <time.h>

Kontrolni_obraz::Kontrolni_obraz(sf::Texture &textura, float x, float y)
{
    //ctor
    srand(time(NULL));
    slika.setTexture(textura);
    slika.setTextureRect(sf::IntRect(0,1,24,31));
    slika.setPosition(x,y);
    slika.setScale(sf::Vector2f(2.5f,2.5f));

}

void Kontrolni_obraz::posodobiAnimacijo()
{
    sf::Time elapsed1 = casAnimacije.getElapsedTime();
    if(elapsed1.asMilliseconds() > 300){
        int slicica;
        if(zivljenja > 86)
        {
            slicica = 0;
        }
        else if(zivljenja > 72)
        {
            slicica = 1;
        }
        else if(zivljenja > 58)
        {
            slicica = 2;
        }
        else if(zivljenja > 44)
        {
            slicica = 3;
        }
        else if(zivljenja > 30)
        {
            slicica = 4;
        }
        else if(zivljenja > 16)
        {
            slicica = 5;
        }
        else
        {
            slicica = 6;
        }
        int stev = rand() % 3;
        casAnimacije.restart();

        slika.setTextureRect(sf::IntRect(24 * stev,64 + 31 * slicica,24,31));
    }
}

Kontrolni_obraz::~Kontrolni_obraz()
{
    //dtor
}
