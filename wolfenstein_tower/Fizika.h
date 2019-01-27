#ifndef FIZIKA_H
#define FIZIKA_H

#include "Enemie.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Metek.h"

extern int zivljenja;

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
