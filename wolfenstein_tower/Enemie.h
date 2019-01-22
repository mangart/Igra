#ifndef ENEMIE_H
#define ENEMIE_H

#include <SFML/Graphics.hpp>

class Enemie
{
    public:
        Enemie(sf::Texture &tekstura,int m,int zdr,int hitr, int sm,float x, float y,int ani_ref_tim);
        virtual ~Enemie();
        void preveriAnimacijo();
        int stanje;
        sf::Sprite slika;
        int hitrost;
        int smer;
        int na_poti;
        int AnimationRefreshTime;

    protected:

    private:
        sf::Clock casAnimacije;
        sf::Clock casUstvarjanja;
        int zdravje;
        int moc;
        int slicica;
};

#endif // ENEMIE_H
