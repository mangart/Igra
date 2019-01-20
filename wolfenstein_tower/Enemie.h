#ifndef ENEMIE_H
#define ENEMIE_H

#include <SFML/Graphics.hpp>

class Enemie
{
    public:
        Enemie(sf::Texture &tekstura,int m,int zdr,int hitr, int sm,float x, float y);
        virtual ~Enemie();
        void preveriAnimacijo();
        int stanje;
        sf::Sprite slika;

    protected:

    private:
        sf::Clock casAnimacije;
        sf::Clock casUstvarjanja;
        int hitrost;
        int zdravje;
        int smer;
        int moc;
        int slicica;
};

#endif // ENEMIE_H
