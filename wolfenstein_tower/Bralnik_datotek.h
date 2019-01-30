#ifndef BRALNIK_DATOTEK_H
#define BRALNIK_DATOTEK_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Ime_in_tocke.h"

extern sf::Text Highscori[5];

class Bralnik_datotek
{
    public:
        Bralnik_datotek();
        virtual ~Bralnik_datotek();
        Ime_in_tocke osebe[5];
        void dodaj_zapis(std::string ime,int tocke);
		void preberi_datoteko();
		void Ponastavi_vrednosti();

    protected:

    private:
};

#endif // BRALNIK_DATOTEK_H
