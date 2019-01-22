#ifndef FIZIKA_H
#define FIZIKA_H

#include "Enemie.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

extern int zivljenja;

class Fizika
{
    public:
        Fizika();
        virtual ~Fizika();
        void premakniNasprotnika(std::vector<Enemie> &vec, float preteceniCas);

    protected:

    private:
};

#endif // FIZIKA_H
