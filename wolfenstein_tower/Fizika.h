#ifndef FIZIKA_H
#define FIZIKA_H

#include "Enemie.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Metek.h"

extern int zivljenja;
extern sf::Sound achtung2;
extern sf::Sound spion2;
extern sf::Sound shustafel2;
class Fizika
{
    public:
        Fizika();
        virtual ~Fizika();
        void premakniNasprotnika(std::vector<Enemie> &vec, float preteceniCas);
        void premakniMetek(std::vector<Metek> &met,float preteceniCas);

    protected:

    private:
};

#endif // FIZIKA_H
