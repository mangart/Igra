#ifndef MONKEY_H
#define MONKEY_H

#include <SFML/Graphics.hpp>

class Monkey
{
    public:
        Monkey(sf::Texture &textura,int zdr, float x, float y, int izris);
        virtual ~Monkey();
        void preveri_animacijo();
        int stanje;
        int se_izrise;
        sf::Sprite slika;
        sf::Clock casAnimacije;
        void spremeni_pozicijo(float x,float y);
    protected:

    private:
        int zdravje;
        int moc;
};

#endif // MONKEY_H
