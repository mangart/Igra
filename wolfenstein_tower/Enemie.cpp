#include "Enemie.h"

Enemie::Enemie(sf::Texture &tekstura,int m, int zdr, int hitr, int sm, float x, float y)
{
    //ctor
    moc = m;
    zdravje = zdr;
    hitrost = hitr;
    slicica = 0;
    smer = sm;
    slika.setTexture(tekstura);
    slika.setTextureRect(sf::IntRect(0, 64 * smer, 64, 64));
    // za aèetek nastavi x koordinato na - 75.f
    // x = -30.f y = 625.f
    slika.setPosition(sf::Vector2f(x, y)); // absolute position
    slika.setScale(sf::Vector2f(2.5f, 2.5f));

}

void Enemie::preveriAnimacijo()
{
    sf::Time elapsed1 = casAnimacije.getElapsedTime();
    if(elapsed1.asMilliseconds() > 300){
        casAnimacije.restart();
        if(slicica == 3){
            slicica = 0;
        }
        else{
            slicica++;
        }
        slika.setTextureRect(sf::IntRect(64 * slicica,64 * smer,64,64));
    }
}

Enemie::~Enemie()
{
    //dtor
}
