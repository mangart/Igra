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


int zivljenja = 100;
int stanje_igre = 2;
int denar = 600;
int tocke = 0;
int stopnja = 1;
    sf::RenderWindow win(sf::VideoMode(1800, 900), "Wolfenstein tower");
    sf::Texture guard;
    sf::Texture ss;
    sf::Texture oficer;
    sf::Texture ozadje;
    sf::Texture obraz;
    sf::Texture opice_in_glave;
    sf::Texture orozja;

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


std::stringstream ziv;
std::stringstream den;
std::stringstream toc;
sf::Clock casZanke;

int main()
{
    ziv << zivljenja;
    den << denar;
    toc << tocke;

if (!achtung.loadFromFile("sounds/ACHTUNG.wav"))
{
    std::cout << "Neki je narobe!";
}

if (!aiiii.loadFromFile("sounds/KRIK.wav"))
{
    std::cout << "Neki je narobe!";
}

if (!bolecina.loadFromFile("sounds/BOLECINA.wav"))
{
    std::cout << "Neki je narobe!";
}

if (!shustafel.loadFromFile("sounds/SHUTSTAFEL.wav"))
{
    std::cout << "Neki je narobe!";
}

if (!main_leben.loadFromFile("sounds/MAIN_LEBEN.wav"))
{
    std::cout << "Neki je narobe!";
}

if (!spion.loadFromFile("sounds/SPION.wav"))
{
    std::cout << "Neki je narobe!";
}

if (!nain_so_vas.loadFromFile("sounds/NEIN_SO_VAS.wav"))
{
    std::cout << "Neki je narobe!";
}

if (!strel.loadFromFile("sounds/STREL.wav"))
{
    std::cout << "Neki je narobe!";
}

if (!odpiranje_vrat.loadFromFile("sounds/Odpiranje_vrat.wav"))
{
    std::cout << "Neki je narobe!";
}

if (!explozija.loadFromFile("sounds/Explosion3.wav"))
{
    std::cout << "Neki je narobe!";
}

if (!glasba_igra.openFromFile("sounds/Glasba_igra.ogg"))
{
    std::cout << "Neki je narobe!";
}

if (!glasba_meni.openFromFile("sounds/Glasba_meni1.ogg"))
{
    std::cout << "Neki je narobe!";
}




 achtung2.setBuffer(achtung);
 achtung2.setVolume(50);


 aiiii2.setBuffer(aiiii);
 aiiii2.setVolume(50);


 bolecina2.setBuffer(bolecina);
 bolecina2.setVolume(50);


 shustafel2.setBuffer(shustafel);
 shustafel2.setVolume(50);


 main_leben2.setBuffer(main_leben);
 main_leben2.setVolume(50);


 spion2.setBuffer(spion);
 spion2.setVolume(50);


 nain_so_vas2.setBuffer(nain_so_vas);
 nain_so_vas2.setVolume(50);


 strel2.setBuffer(strel);
 strel2.setVolume(50);


 odpiranje_vrat2.setBuffer(odpiranje_vrat);
 odpiranje_vrat2.setVolume(50);


 explozija2.setBuffer(explozija);
 explozija2.setVolume(20);

glasba_meni.setVolume(10);
glasba_meni.setLoop(true);


glasba_igra.setVolume(50);
glasba_igra.setLoop(true);
glasba_igra.play();

//Nalaganje tekstur
if (!guard.loadFromFile("sprites/guard_sprite_sheet.png"))
{
    // error...
    std::cout << "Neki je narobe!";

}
if(!ss.loadFromFile("sprites/SS_sprite_sheet2.png")){
    std::cout << "Neki je narobe!";
}
if(!ozadje.loadFromFile("sprites/PC Computer - Wolfenstein 3D - Walls.png")){
    std::cout << "Neki je narobe!";
}

if(!obraz.loadFromFile("sprites/PC Computer - Wolfenstein 3D - BJ Blazkowicz.png")){
    std::cout << "Neki je narobe!";
}

if(!oficer.loadFromFile("sprites/oficer_sprite_sheet.png")){
    std::cout << "Neki je narobe!";
}

if(!opice_in_glave.loadFromFile("sprites/glave_in_obrambne_sile.png")){
    std::cout << "Neki je narobe!";
}

if(!orozja.loadFromFile("sprites/wapons1.png")){
    std::cout << "Neki je narobe!";
}

sf::Font font;
if (!font.loadFromFile("Arcon-Regular.otf"))
{
    // error...
}

sf::Text text;
text.setFont(font); // font is a sf::Font
text.setString("Zivljenja: " + ziv.str());
text.setCharacterSize(24); // in pixels, not points!
text.setFillColor(sf::Color::Red);
text.setPosition(sf::Vector2f(1600.f, 70.f));

sf::Text text1;
text1.setFont(font); // font is a sf::Font
text1.setString("Denar: " + den.str());
text1.setCharacterSize(24); // in pixels, not points!
text1.setFillColor(sf::Color::Red);
text1.setPosition(sf::Vector2f(1600.f, 100.f));

sf::Text text2;
text2.setFont(font); // font is a sf::Font
text2.setString("Tocke: " + toc.str());
text2.setCharacterSize(24); // in pixels, not points!
text2.setFillColor(sf::Color::Red);
text2.setPosition(sf::Vector2f(1600.f, 40.f));

sf::Sprite sprite;
sprite.setTexture(guard);
sprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
sprite.setPosition(sf::Vector2f(10.f, 625.f)); // absolute position
sprite.setScale(sf::Vector2f(2.5f, 2.5f));

sf::Sprite sprite1;
sprite1.setTexture(ss);
sprite1.setTextureRect(sf::IntRect(64, 128, 64, 64));
sprite1.setPosition(sf::Vector2f(448.f, 400.f)); // absolute position
sprite1.setScale(sf::Vector2f(2.5f, 2.5f));

sf::Sprite ozad;
ozad.setTexture(ozadje);
ozad.setTextureRect(sf::IntRect(0, 0, 64, 64));
ozad.setPosition(sf::Vector2f(0.f, 0.f)); // absolute position
ozad.setScale(sf::Vector2f(28.125f, 14.0625f));

sf::Sprite pot1;
pot1.setTexture(ozadje);
pot1.setTextureRect(sf::IntRect(128,320,64,64));
pot1.setPosition(0.f,650.f);
pot1.setScale(sf::Vector2f(7.f, 2.4f));

sf::Sprite pot2;
pot2.setTexture(ozadje);
pot2.setTextureRect(sf::IntRect(128,320,64,64));
pot2.setPosition(448.f,200.f);
pot2.setScale(sf::Vector2f(2.4f, 9.43125f));

sf::Sprite pot3;
pot3.setTexture(ozadje);
pot3.setTextureRect(sf::IntRect(128,320,64,64));
pot3.setPosition(601.6f,200.f);
pot3.setScale(sf::Vector2f(5.f, 2.4f));

sf::Sprite pot4;
pot4.setTexture(ozadje);
pot4.setTextureRect(sf::IntRect(128,320,64,64));
pot4.setPosition(921.6f,200.f);
pot4.setScale(sf::Vector2f(2.4f, 9.43125f));

sf::Sprite pot5;
pot5.setTexture(ozadje);
pot5.setTextureRect(sf::IntRect(128,320,64,64));
pot5.setPosition(1075.2f,650.f);
pot5.setScale(sf::Vector2f(6.6375f, 2.4f));

sf::Sprite nadzorna;
nadzorna.setTexture(ozadje);
nadzorna.setTextureRect(sf::IntRect(0,448,64,64));
nadzorna.setPosition(1500.f,0.f);
nadzorna.setScale(sf::Vector2f(4.6875f,14.0625f));

sf::Sprite obr;
obr.setTexture(obraz);
obr.setTextureRect(sf::IntRect(0,1,24,31));
obr.setPosition(1510.f,50.f);
obr.setScale(sf::Vector2f(2.5f,2.5f));


win.setFramerateLimit(60);

//Enemie enemie(guard,10,1,50,3,-60.f,625.f,300,1);
//Enemie enemie1(ss,10,5,100,3,-200.f, 625.f,300,3);

std::vector<Monkey> monkeys;
std::vector<Zeblji> vsi_zeblji;
std::vector<Enemie> enemies;
std::vector<Metek> metki_igralec;
//enemies.push_back(enemie);
//enemies.push_back(enemie1);
Monkey opica(opice_in_glave,100,200,200,0);
Zeblji zebl(opice_in_glave,400,400,10,0);

Kontrolni_elementi opic(opice_in_glave,font,1510,200,0,0,100);
Kontrolni_elementi zeb(opice_in_glave,font,1640,200,128,0,25);
Kontrolni_obraz obraz_igralca(opice_in_glave,1510,50);

sf::CircleShape krog(200.f);
krog.setOrigin(sf::Vector2f(200.f,200.f));
krog.setFillColor(sf::Color(100, 250, 50,128));
krog.setPosition(sf::Vector2f(200.f,200.f));


casZanke.restart();
Fizika fiz;
Skrbnik_dogodkov skrbnik;
Detekcija_trkov detektorTrkov;
Stopnja upravitelj_stopenj;
upravitelj_stopenj.Kalibriraj(1);
upravitelj_stopenj.Naslednji_level(enemies,guard,oficer,ss);
/*
sf::Sprite orozje1;
orozje1.setTexture(orozja);
orozje1.setTextureRect(sf::IntRect(0,128,64,64));
orozje1.setPosition(50.f,50.f);
orozje1.setScale(sf::Vector2f(2.5f,2.5f));
*/

//Glavna zanka igre

    while (win.isOpen())
    {

        if(enemies.size() == 0)
        {
            upravitelj_stopenj.Naslednji_level(enemies,guard,oficer,ss);
        }
        ziv.str("");
        ziv.clear();
        ziv << zivljenja;
        den.str("");
        den.clear();
        den << denar;
        toc.str("");
        toc.clear();
        toc << tocke;
        text.setString("Zivljenja: " + ziv.str());
        text1.setString("Denar: " + den.str());
        text2.setString("Tocke: " + toc.str());
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

        for(unsigned int i = 0;i < monkeys.size();i++)
        {
            monkeys[i].Umetna_inteligenca(enemies,metki_igralec,orozja);
        }

        fiz.premakniNasprotnika(enemies,pretCas + casZanke.getElapsedTime().asSeconds());
        fiz.premakniMetek(metki_igralec,pretCas + casZanke.getElapsedTime().asSeconds());
        detektorTrkov.trki_med_metki_in_nasprotniki(metki_igralec,enemies);
        detektorTrkov.trki_med_zeblji_in_nasprotniki(vsi_zeblji,enemies);
        win.clear();
        //win.draw(shape);
        win.draw(ozad);
        win.draw(pot1);
        win.draw(pot2);
        win.draw(pot3);
        win.draw(pot4);
        win.draw(pot5);
        //win.draw(sprite);
        win.draw(nadzorna);
        for(unsigned int i = 0;i < enemies.size();i++)
        {
            win.draw(enemies[i].slika);
        }
        //win.draw(sprite1);

        win.draw(text);
        win.draw(text1);
        win.draw(text2);
        win.draw(obraz_igralca.slika);
        //win.draw(obr);

        if(opica.se_izrise == 1)
        {
            win.draw(krog);
            win.draw(opica.slika);
        }
        if(zebl.se_izrise == 1)
        {
            win.draw(krog);
            win.draw((zebl.slika));

        }
        win.draw(opic.kvadrat);
        win.draw(opic.slika);
        win.draw(opic.tekst);
        win.draw(zeb.kvadrat);
        win.draw(zeb.slika);
        win.draw(zeb.tekst);
        for(unsigned int i = 0; i < monkeys.size();i++)
        {
            win.draw(monkeys[i].slika);
        }
        for(unsigned int i = 0; i < vsi_zeblji.size();i++)
        {
            win.draw(vsi_zeblji[i].slika);
        }

        for(unsigned int i = 0;i < metki_igralec.size();i++)
        {
            win.draw(metki_igralec[i].slika);
        }
        win.display();
        for(unsigned int i = 0;i < enemies.size();i++)
        {
            enemies[i].preveriAnimacijo();
        }
        for(unsigned int i = 0;i < metki_igralec.size();i++)
        {
            metki_igralec[i].preveriAnimacijo();
        }
        obraz_igralca.posodobiAnimacijo();

        for(unsigned int i = 0;i < metki_igralec.size();i++)
        {
            if(metki_igralec[i].stanje != 1 && metki_igralec[i].stanje != 3)
            {
                metki_igralec.erase(metki_igralec.begin() + i);
                i--;
            }
        }

        for(unsigned int i = 0;i < enemies.size();i++)
        {
            if(enemies[i].stanje == 4 || enemies[i].stanje == 2)
            {
                enemies.erase(enemies.begin() + i);
                i--;
            }
        }
        for(unsigned int i = 0;i < vsi_zeblji.size();i++)
        {
            if(vsi_zeblji[i].stanje != 1)
            {
                vsi_zeblji.erase(vsi_zeblji.begin() + i);
                i--;
            }
        }
        /*
        enemie.preveriAnimacijo();
        enemie1.preveriAnimacijo();
        */
    }

    return 0;
}
