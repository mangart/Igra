#ifndef STOPNJA_H
#define STOPNJA_H

#include <iostream>
#include <vector>
#include "Enemie.h"
#include <SFML/Graphics.hpp>


extern    std::vector<Enemie> enemies;
extern    sf::Texture guard;
extern    sf::Texture ss;
extern    sf::Texture oficer;

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
        void Naslednji_level();

    protected:

    private:
};

#endif // STOPNJA_H
