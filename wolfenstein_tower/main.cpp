#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Enemie.h"
#include "Fizika.h"
#include <vector>
#include "Monkey.h"
#include "Zeblji.h"
#include "Kontrolni_elementi.h"
#include "Kontrolni_obraz.h"
#include "Skrbnik_dogodkov.h"
#include "Metek.h"
#include "Detekcija_trkov.h"
#include "Stopnja.h"
#include "Irisovalnik.h"
#include "Inicializator.h"
#include "Bralnik_datotek.h"

int zivljenja = 100;
int stanje_igre = 0;
int denar = 600;
int tocke = 0;
int stopnja = 1;

Stopnja upravitelj_stopenj;

    sf::RenderWindow win(sf::VideoMode(1800, 900), "Wolfenstein tower");
    sf::Texture guard;
    sf::Texture ss;
    sf::Texture oficer;
    sf::Texture ozadje;
    sf::Texture obraz;
    sf::Texture opice_in_glave;
    sf::Texture orozja;
    sf::Texture meniji;

    sf::SoundBuffer achtung;
    sf::SoundBuffer aiiii;
    sf::SoundBuffer bolecina;
    sf::SoundBuffer shustafel;
    sf::SoundBuffer main_leben;
    sf::SoundBuffer spion;
    sf::SoundBuffer nain_so_vas;
    sf::SoundBuffer strel;
    sf::Music glasba_meni;
    sf::Music glasba_igra;
    sf::SoundBuffer odpiranje_vrat;
    sf::SoundBuffer explozija;

    sf::Sound achtung2;
    sf::Sound aiiii2;
    sf::Sound bolecina2;
    sf::Sound shustafel2;
    sf::Sound main_leben2;
    sf::Sound spion2;
    sf::Sound nain_so_vas2;
    sf::Sound strel2;
    sf::Sound odpiranje_vrat2;
    sf::Sound explozija2;

    sf::Font font;

    sf::Text text;
    sf::Text text1;
    sf::Text text2;
    sf::Text vpisano_ime;
    sf::Text Highscori[5];

    sf::Sprite ozad;
    sf::Sprite pot1;
    sf::Sprite pot2;
    sf::Sprite pot3;
    sf::Sprite pot4;
    sf::Sprite pot5;
    sf::Sprite nadzorna;
    sf::Sprite obr;
    sf::CircleShape krog(200.f);

    sf::Sprite zacetni_meni;
    sf::Sprite ostali_meniji;
    sf::Sprite zacni_igro;
    sf::Sprite najboljsi_rezultati;
    sf::Sprite najboljsi_rezultati2;
    sf::Sprite izhod;
    sf::Sprite izberi_zahtevnost;
    sf::Sprite tezavnost1;
    sf::Sprite tezavnost2;
    sf::Sprite tezavnost3;
    sf::Sprite tezavnost4;
    sf::Sprite next_level;
    sf::Sprite nazaj;
    sf::Sprite nazaj1;
    sf::Sprite nazaj2;
    sf::Sprite vpisi_svoje_ime;
    sf::Sprite potrdi;

    Bralnik_datotek bralnik;


std::string ime;

std::vector<Monkey> monkeys;
std::vector<Zeblji> vsi_zeblji;
std::vector<Enemie> enemies;
std::vector<Metek> metki_igralec;

std::stringstream ziv;
std::stringstream den;
std::stringstream toc;
sf::Clock casZanke;

int main()
{
    ziv << zivljenja;
    den << denar;
    toc << tocke;
    Inicializator inicial;
    inicial.inicializiraj();


win.setFramerateLimit(60);


Monkey opica(opice_in_glave,100,200,200,0);
Zeblji zebl(opice_in_glave,400,400,10,0);

Kontrolni_elementi opic(opice_in_glave,font,1510,200,0,0,100);
Kontrolni_elementi zeb(opice_in_glave,font,1640,200,128,0,25);
Kontrolni_obraz obraz_igralca(opice_in_glave,1510,50);

casZanke.restart();
Fizika fiz;
Skrbnik_dogodkov skrbnik;
Detekcija_trkov detektorTrkov;
//Stopnja upravitelj_stopenj;
upravitelj_stopenj.Kalibriraj(1);
upravitelj_stopenj.Naslednji_level();
Irisovalnik izrisovalnik;


//Glavna zanka igre

    while (win.isOpen())
    {

        if(stanje_igre == 50)
        {
            upravitelj_stopenj.Kalibriraj(1);
            enemies.clear();
            upravitelj_stopenj.Naslednji_level();
            glasba_meni.stop();
            glasba_igra.play();
            stanje_igre = 3;
        }
        else if(stanje_igre == 51)
        {
            upravitelj_stopenj.Kalibriraj(2);
            enemies.clear();
            upravitelj_stopenj.Naslednji_level();
            glasba_meni.stop();
            glasba_igra.play();
            stanje_igre = 3;
        }
        else if(stanje_igre == 52)
        {
            upravitelj_stopenj.Kalibriraj(3);
            enemies.clear();
            upravitelj_stopenj.Naslednji_level();
            glasba_meni.stop();
            glasba_igra.play();
            stanje_igre = 3;
        }
        else if(stanje_igre == 53)
        {
            upravitelj_stopenj.Kalibriraj(4);
            enemies.clear();
            upravitelj_stopenj.Naslednji_level();
            glasba_meni.stop();
            glasba_igra.play();
            stanje_igre = 3;
        }

        if(enemies.size() == 0 && (stanje_igre == 2 || stanje_igre == 3))
        {
            upravitelj_stopenj.Naslednji_level();
            stanje_igre = 3;
        }
        if(stanje_igre == 3)
        {
            if(metki_igralec.size() != 0)
            {
                metki_igralec.clear();
            }
        }
        inicial.postavi_vrednosti_napisom();
        float pretCas = casZanke.restart().asSeconds();

        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }

        skrbnik.obravnavaj_dogodke(monkeys,vsi_zeblji,krog,opica,zebl,win);
        if(stanje_igre == 100)
        {
            vsi_zeblji.clear();
            enemies.clear();
            monkeys.clear();
            metki_igralec.clear();
            denar = 600;
            zivljenja = 100;
            tocke = 0;
            glasba_igra.stop();
            glasba_meni.play();
            stanje_igre = 0;
        }

        if(stanje_igre == 2)
        {
            for(unsigned int i = 0;i < monkeys.size();i++)
            {
                monkeys[i].Umetna_inteligenca(enemies,metki_igralec,orozja);
            }
            fiz.premakniNasprotnika(enemies,pretCas + casZanke.getElapsedTime().asSeconds());
            fiz.premakniMetek(metki_igralec,pretCas + casZanke.getElapsedTime().asSeconds());
            detektorTrkov.trki_med_metki_in_nasprotniki(metki_igralec,enemies);
            detektorTrkov.trki_med_zeblji_in_nasprotniki(vsi_zeblji,enemies);
        }

        win.clear();
        //win.draw(shape);
        izrisovalnik.izrisi_zaslon(win,opic,zeb,obraz_igralca,opica,zebl);

        win.display();

        inicial.Animiraj();
        obraz_igralca.posodobiAnimacijo();
        inicial.brisi_nepotrebno();
        if(zivljenja <= 0)
        {
            zivljenja = 100;
            denar = 600;
            toc.str("");
            toc.clear();
            toc << tocke;
            glasba_igra.stop();
            glasba_meni.play();
            vpisano_ime.setString("Tocke: " + toc.str());
            stanje_igre = 5;
        }
        if(stanje_igre == 250)
        {
            bralnik.dodaj_zapis(ime,tocke);
            stanje_igre = 260;
        }
        if(stanje_igre == 260)
        {
            tocke = 0;
            ime = "";
            bralnik.preberi_datoteko();
            stanje_igre = 6;
        }

    }

    return 0;
}
