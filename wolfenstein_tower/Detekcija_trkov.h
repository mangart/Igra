#ifndef DETEKCIJA_TRKOV_H
#define DETEKCIJA_TRKOV_H

#include<iostream>
#include<vector>
#include "Monkey.h"
#include "Enemie.h"
#include "Metek.h"
#include "Zeblji.h"

extern sf::Sound aiiii2;
extern sf::Sound main_leben2;
extern sf::Sound nain_so_vas2;
extern sf::Sound bolecina2;
extern sf::Sound explozija2;
extern int tocke;
extern int denar;
extern int stopnja;


class Detekcija_trkov
{
    public:
        Detekcija_trkov();
        virtual ~Detekcija_trkov();
        void trki_med_metki_in_nasprotniki(std::vector<Metek> &met, std::vector<Enemie> &enem);
        void trki_med_zeblji_in_nasprotniki(std::vector<Zeblji> &zeb, std::vector<Enemie> &enem);
        float vrni_razdaljo(float x1, float y1,float x2, float y2);
    protected:

    private:
        sf::Clock casDetekcije;
};

#endif // DETEKCIJA_TRKOV_H
