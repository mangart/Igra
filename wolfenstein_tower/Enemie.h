#ifndef ENEMIE_H
#define ENEMIE_H

#include <SFML/Graphics.hpp>

class Enemie
{
    public:
        Enemie(sf::Texture &tekstura,int m,int zdr,int hitr, int sm,float x, float y,int ani_ref_tim,int tip_nasp);
        virtual ~Enemie();
        void preveriAnimacijo();
        int stanje;
        sf::Sprite slika;
        int hitrost;
        int smer;
        int na_poti;
        int AnimationRefreshTime;
        int tip_nasprotnika;
        int zdravje;
        int slicica1;

    protected:

    private:
        sf::Clock casAnimacije;
        sf::Clock casUstvarjanja;
        int moc;
        int slicica;
};

#endif // ENEMIE_H
