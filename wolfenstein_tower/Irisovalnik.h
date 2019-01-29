#ifndef IRISOVALNIK_H
#define IRISOVALNIK_H

#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Metek.h"
#include "Monkey.h"
#include "Enemie.h"
#include "Zeblji.h"
#include "Kontrolni_elementi.h"
#include "Kontrolni_obraz.h"

extern int stanje_igre;
extern    sf::Text text;
extern    sf::Text text1;
extern    sf::Text text2;

extern    sf::Sprite ozad;
extern    sf::Sprite pot1;
extern    sf::Sprite pot2;
extern    sf::Sprite pot3;
extern    sf::Sprite pot4;
extern    sf::Sprite pot5;
extern    sf::Sprite nadzorna;
extern    sf::Sprite obr;
extern    sf::CircleShape krog;

extern    sf::Sprite zacetni_meni;
extern    sf::Sprite ostali_meniji;
extern    sf::Sprite zacni_igro;
extern    sf::Sprite najboljsi_rezultati;
extern    sf::Sprite najboljsi_rezultati2;
extern    sf::Sprite izhod;
extern    sf::Sprite izberi_zahtevnost;
extern    sf::Sprite tezavnost1;
extern    sf::Sprite tezavnost2;
extern    sf::Sprite tezavnost3;
extern    sf::Sprite tezavnost4;
extern    sf::Sprite next_level;
extern    sf::Sprite nazaj;
extern    sf::Sprite nazaj1;
extern    sf::Sprite nazaj2;
extern    sf::Sprite vpisi_svoje_ime;
extern    sf::Sprite potrdi;

extern    std::vector<Monkey> monkeys;
extern    std::vector<Zeblji> vsi_zeblji;
extern    std::vector<Enemie> enemies;
extern    std::vector<Metek> metki_igralec;



class Irisovalnik
{
    public:
        Irisovalnik();
        virtual ~Irisovalnik();
        void izrisi_zaslon(sf::RenderWindow &win,Kontrolni_elementi &opic, Kontrolni_elementi &zeb, Kontrolni_obraz &obraz_igralca, Monkey &opica, Zeblji &zebl);
        void izrisi_main_menu(sf::RenderWindow &win);
        void izrisi_izberi_zahtevnost(sf::RenderWindow &win);
        void izrisi_igro(sf::RenderWindow &win,Kontrolni_elementi &opic, Kontrolni_elementi &zeb, Kontrolni_obraz &obraz_igralca, Monkey &opica, Zeblji &zebl);
        void izrisi_igra_v_pripravi(sf::RenderWindow &win,Kontrolni_elementi &opic, Kontrolni_elementi &zeb, Kontrolni_obraz &obraz_igralca, Monkey &opica, Zeblji &zebl);
        void izrisi_vpisi_ime(sf::RenderWindow &win);
        void izrisi_rezultate(sf::RenderWindow &win);

    protected:

    private:
};

#endif // IRISOVALNIK_H
