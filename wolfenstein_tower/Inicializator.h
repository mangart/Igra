#ifndef INICIALIZATOR_H
#define INICIALIZATOR_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include "Monkey.h"
#include "Metek.h"
#include "Enemie.h"
#include "Zeblji.h"


extern    sf::Texture guard;
extern    sf::Texture ss;
extern    sf::Texture oficer;
extern    sf::Texture ozadje;
extern    sf::Texture obraz;
extern    sf::Texture opice_in_glave;
extern    sf::Texture orozja;
extern    sf::Texture meniji;

extern    sf::SoundBuffer achtung;
extern    sf::SoundBuffer aiiii;
extern    sf::SoundBuffer bolecina;
extern    sf::SoundBuffer shustafel;
extern    sf::SoundBuffer main_leben;
extern    sf::SoundBuffer spion;
extern    sf::SoundBuffer nain_so_vas;
extern    sf::SoundBuffer strel;
extern    sf::Music glasba_meni;
extern    sf::Music glasba_igra;
extern    sf::SoundBuffer odpiranje_vrat;
extern    sf::SoundBuffer explozija;

extern    sf::Sound achtung2;
extern    sf::Sound aiiii2;
extern    sf::Sound bolecina2;
extern    sf::Sound shustafel2;
extern    sf::Sound main_leben2;
extern    sf::Sound spion2;
extern    sf::Sound nain_so_vas2;
extern    sf::Sound strel2;
extern    sf::Sound odpiranje_vrat2;
extern    sf::Sound explozija2;

extern    sf::Font font;

extern    sf::Text text;
extern    sf::Text text1;
extern    sf::Text text2;
extern    sf::Text vpisano_ime;
extern    sf::Text Highscori[5];

extern    int denar;
extern    int zivljenja;
extern    int tocke;
extern    std::stringstream ziv;
extern    std::stringstream den;
extern    std::stringstream toc;

extern    sf::Sprite ozad;
extern    sf::Sprite pot1;
extern    sf::Sprite pot2;
extern    sf::Sprite pot3;
extern    sf::Sprite pot4;
extern    sf::Sprite pot5;
extern    sf::Sprite nadzorna;
extern    sf::Sprite obr;

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

extern sf::CircleShape krog;

extern    std::vector<Monkey> monkeys;
extern    std::vector<Zeblji> vsi_zeblji;
extern    std::vector<Enemie> enemies;
extern    std::vector<Metek> metki_igralec;

class Inicializator
{
    public:
        Inicializator();
        virtual ~Inicializator();
        void inicializiraj();
        void postavi_vrednosti_napisom();
        void brisi_nepotrebno();
        void Animiraj();

    protected:

    private:
};

#endif // INICIALIZATOR_H
