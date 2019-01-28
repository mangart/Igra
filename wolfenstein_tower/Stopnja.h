#ifndef STOPNJA_H
#define STOPNJA_H

#include <iostream>
#include <vector>
#include "Enemie.h"
#include <SFML/Graphics.hpp>

class Stopnja
{
    public:
        Stopnja();
        virtual ~Stopnja();
        int stevilo_nasprotnikov;
        void Kalibriraj(int izbrana_stopnja);
        float zacetna_hitrost;
        int zacetno_zdravje;
        float korak_hitrosti;
        int korak_nasprotnikov;
        int korak_zdravja;
        int max_hitrost;
        int max_zdravje;
        int max_nasprotnikov;
        void Naslednji_level(std::vector<Enemie> &enem,sf::Texture &texGuard,sf::Texture &texOficer, sf::Texture &texSS);

    protected:

    private:
};

#endif // STOPNJA_H
