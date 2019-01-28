#ifndef MONKEY_H
#define MONKEY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Enemie.h"
#include "Metek.h"
#include <SFML/Audio.hpp>

extern sf::Sound strel2;

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
        void Umetna_inteligenca(std::vector<Enemie> &enemie,std::vector<Metek> &metki,sf::Texture &tex);
    protected:

    private:
        sf::Clock casUI;
        int zdravje;
        int moc;
};

#endif // MONKEY_H
