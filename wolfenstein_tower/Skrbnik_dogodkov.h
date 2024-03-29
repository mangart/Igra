#ifndef SKRBNIK_DOGODKOV_H
#define SKRBNIK_DOGODKOV_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Monkey.h"
#include "Zeblji.h"

extern int stanje_igre;
extern int denar;
extern sf::Text vpisano_ime;
extern std::string ime;
extern sf::Sound odpiranje_vrat2;

class Skrbnik_dogodkov
{
    public:
        Skrbnik_dogodkov();
        virtual ~Skrbnik_dogodkov();
        void obravnavaj_dogodke(std::vector<Monkey> &mon, std::vector<Zeblji> &zeb, sf::CircleShape &krog,Monkey &opica,Zeblji &zebl, sf::RenderWindow &win);
        void obravnavaj_dogodke_v_stanju_dva(std::vector<Monkey> &mon, std::vector<Zeblji> &zeb, sf::CircleShape &krog,Monkey &opica,Zeblji &zebl, sf::RenderWindow &win);
        void dogodki_v_zacetnem_meniju(sf::RenderWindow &win);
        void dogodki_v_izbiranju_zahtevnosti(sf::RenderWindow &win);
        void priprava_na_igro_dogodki(std::vector<Monkey> &mon, std::vector<Zeblji> &zeb, sf::CircleShape &krog,Monkey &opica,Zeblji &zebl, sf::RenderWindow &win);
        void najboljsi_rezultati_dogodki(sf::RenderWindow &win);
        void vpisi_ime_dogodki(sf::RenderWindow &win);

    protected:

    private:
        int stvar_pritisnjena;
        int na_pravem_mestu;
        bool preveri_pot(int x, int y);
        bool preveri_opice(std::vector<Monkey> &mon, int x, int y);
        bool preveri_pot_zebli(int x, int y);

};

#endif // SKRBNIK_DOGODKOV_H
