#ifndef METEK_H
#define METEK_H

#include <SFML/Graphics.hpp>

class Metek
{
    public:
        Metek(sf::Texture &tekstura,int hitro,int smerniX,int smerniY,float rotacija,float x, float y,float ciljX,float ciljY);
        virtual ~Metek();
        int stanje;
        sf::Sprite slika;
        int hitrost;
        int smerX;
        int smerY;
        float normirana_smerX;
        float normirana_smerY;
        float razdalja;
        float ciljniX;
        float ciljniY;
        sf::Clock casAnimacije;


    protected:

    private:
};

#endif // METEK_H
