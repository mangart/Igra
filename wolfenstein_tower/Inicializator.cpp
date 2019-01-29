#include "Inicializator.h"
#include <iostream>
Inicializator::Inicializator()
{
    //ctor
}

void Inicializator::inicializiraj()
{
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
glasba_meni.play();

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

if(!meniji.loadFromFile("sprites/meniji1.png")){
    std::cout << "Neki je narobe!";
}


if (!font.loadFromFile("Arcon-Regular.otf"))
{
    // error...
}


text.setFont(font); // font is a sf::Font
text.setString("Zivljenja: " + ziv.str());
text.setCharacterSize(24); // in pixels, not points!
text.setFillColor(sf::Color::Red);
text.setPosition(sf::Vector2f(1600.f, 70.f));


text1.setFont(font); // font is a sf::Font
text1.setString("Denar: " + den.str());
text1.setCharacterSize(24); // in pixels, not points!
text1.setFillColor(sf::Color::Red);
text1.setPosition(sf::Vector2f(1600.f, 100.f));


text2.setFont(font); // font is a sf::Font
text2.setString("Tocke: " + toc.str());
text2.setCharacterSize(24); // in pixels, not points!
text2.setFillColor(sf::Color::Red);
text2.setPosition(sf::Vector2f(1600.f, 40.f));

ozad.setTexture(ozadje);
ozad.setTextureRect(sf::IntRect(0, 0, 64, 64));
ozad.setPosition(sf::Vector2f(0.f, 0.f)); // absolute position
ozad.setScale(sf::Vector2f(28.125f, 14.0625f));


pot1.setTexture(ozadje);
pot1.setTextureRect(sf::IntRect(128,320,64,64));
pot1.setPosition(0.f,650.f);
pot1.setScale(sf::Vector2f(7.f, 2.4f));


pot2.setTexture(ozadje);
pot2.setTextureRect(sf::IntRect(128,320,64,64));
pot2.setPosition(448.f,200.f);
pot2.setScale(sf::Vector2f(2.4f, 9.43125f));


pot3.setTexture(ozadje);
pot3.setTextureRect(sf::IntRect(128,320,64,64));
pot3.setPosition(601.6f,200.f);
pot3.setScale(sf::Vector2f(5.f, 2.4f));


pot4.setTexture(ozadje);
pot4.setTextureRect(sf::IntRect(128,320,64,64));
pot4.setPosition(921.6f,200.f);
pot4.setScale(sf::Vector2f(2.4f, 9.43125f));


pot5.setTexture(ozadje);
pot5.setTextureRect(sf::IntRect(128,320,64,64));
pot5.setPosition(1075.2f,650.f);
pot5.setScale(sf::Vector2f(6.6375f, 2.4f));


nadzorna.setTexture(ozadje);
nadzorna.setTextureRect(sf::IntRect(0,448,64,64));
nadzorna.setPosition(1500.f,0.f);
nadzorna.setScale(sf::Vector2f(4.6875f,14.0625f));


obr.setTexture(obraz);
obr.setTextureRect(sf::IntRect(0,1,24,31));
obr.setPosition(1510.f,50.f);
obr.setScale(sf::Vector2f(2.5f,2.5f));

krog.setOrigin(sf::Vector2f(200.f,200.f));
krog.setFillColor(sf::Color(100, 250, 50,128));
krog.setPosition(sf::Vector2f(200.f,200.f));


// Za zaèetni meni
zacetni_meni.setTexture(meniji);
zacetni_meni.setTextureRect(sf::IntRect(0, 868, 320, 200));
zacetni_meni.setPosition(sf::Vector2f(0.f, 0.f)); // absolute position
zacetni_meni.setScale(sf::Vector2f(5.625f, 4.5f));

zacni_igro.setTexture(meniji);
zacni_igro.setTextureRect(sf::IntRect(0, 0, 256, 64));
zacni_igro.setPosition(sf::Vector2f(772.f, 400.f)); // absolute position
zacni_igro.setScale(sf::Vector2f(1.f, 1.f));

najboljsi_rezultati.setTexture(meniji);
najboljsi_rezultati.setTextureRect(sf::IntRect(0, 64, 256, 64));
najboljsi_rezultati.setPosition(sf::Vector2f(772.f, 500.f)); // absolute position
najboljsi_rezultati.setScale(sf::Vector2f(1.f, 1.f));

izhod.setTexture(meniji);
izhod.setTextureRect(sf::IntRect(0, 128, 256, 64));
izhod.setPosition(sf::Vector2f(772.f, 600.f)); // absolute position
izhod.setScale(sf::Vector2f(1.f, 1.f));

ostali_meniji.setTexture(meniji);
ostali_meniji.setTextureRect(sf::IntRect(0, 768, 175, 100));
ostali_meniji.setPosition(sf::Vector2f(0.f, 0.f)); // absolute position
ostali_meniji.setScale(sf::Vector2f(10.28571428f, 9.f));

izberi_zahtevnost.setTexture(meniji);
izberi_zahtevnost.setTextureRect(sf::IntRect(0,192,256,64));
izberi_zahtevnost.setPosition(sf::Vector2f(650.f,0.f));
izberi_zahtevnost.setScale(sf::Vector2f(2.f,2.f));

tezavnost1.setTexture(meniji);
tezavnost1.setTextureRect(sf::IntRect(0, 256, 256, 64));
tezavnost1.setPosition(sf::Vector2f(772.f, 300.f)); // absolute position
tezavnost1.setScale(sf::Vector2f(1.f, 1.f));

tezavnost2.setTexture(meniji);
tezavnost2.setTextureRect(sf::IntRect(0, 320, 256, 64));
tezavnost2.setPosition(sf::Vector2f(772.f, 400.f)); // absolute position
tezavnost2.setScale(sf::Vector2f(1.f, 1.f));

tezavnost3.setTexture(meniji);
tezavnost3.setTextureRect(sf::IntRect(0, 384, 256, 64));
tezavnost3.setPosition(sf::Vector2f(772.f, 500.f)); // absolute position
tezavnost3.setScale(sf::Vector2f(1.f, 1.f));

tezavnost4.setTexture(meniji);
tezavnost4.setTextureRect(sf::IntRect(0, 448, 256, 64));
tezavnost4.setPosition(sf::Vector2f(772.f, 600.f)); // absolute position
tezavnost4.setScale(sf::Vector2f(1.f, 1.f));

nazaj1.setTexture(meniji);
nazaj1.setTextureRect(sf::IntRect(0,576,256,64));
nazaj1.setPosition(sf::Vector2f(0.f,800.f));
nazaj1.setScale(sf::Vector2f(1.f,1.f));

next_level.setTexture(meniji);
next_level.setTextureRect(sf::IntRect(0,8 * 64,256,64));
next_level.setPosition(sf::Vector2f(1520.f,600.f));
next_level.setScale(sf::Vector2f(1.f,1.f));

nazaj2.setTexture(meniji);
nazaj2.setTextureRect(sf::IntRect(0,576,256,64));
nazaj2.setPosition(sf::Vector2f(1520.f,700.f));
nazaj2.setScale(sf::Vector2f(1.f,1.f));

najboljsi_rezultati2.setTexture(meniji);
najboljsi_rezultati2.setTextureRect(sf::IntRect(0, 64, 256, 64));
najboljsi_rezultati2.setPosition(sf::Vector2f(650.f,0.f)); // absolute position
najboljsi_rezultati2.setScale(sf::Vector2f(2.f,2.f));

vpisi_svoje_ime.setTexture(meniji);
vpisi_svoje_ime.setTextureRect(sf::IntRect(0,640,256,64));
vpisi_svoje_ime.setPosition(sf::Vector2f(630.f,0.f));
vpisi_svoje_ime.setScale(sf::Vector2f(2.f,2.f));

potrdi.setTexture(meniji);
potrdi.setTextureRect(sf::IntRect(0,704,256,64));
potrdi.setPosition(sf::Vector2f(760.f,700.f));
potrdi.setScale(sf::Vector2f(1.f,1.f));

}

void Inicializator::postavi_vrednosti_napisom()
{
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
}

void Inicializator::Animiraj()
{
    for(unsigned int i = 0;i < enemies.size();i++)
    {
        enemies[i].preveriAnimacijo();
    }
    for(unsigned int i = 0;i < metki_igralec.size();i++)
    {
        metki_igralec[i].preveriAnimacijo();
    }
}

void Inicializator::brisi_nepotrebno()
{
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
}


Inicializator::~Inicializator()
{
    //dtor
}
