#include "Stopnja.h"
#include <time.h>
Stopnja::Stopnja()
{
    //ctor
    srand(time(NULL));
}

void Stopnja::Kalibriraj(int izbrana_stopnja)
{
    if(izbrana_stopnja == 1)
    {
        zacetna_hitrost = 50;
        zacetno_zdravje = 1;
        stevilo_nasprotnikov = 1;
        max_nasprotnikov = 50;
        max_zdravje = 20;
        max_hitrost = 300;
        korak_hitrosti = 5;
        korak_nasprotnikov = 1;
        korak_zdravja = 1;
    }
    else if(izbrana_stopnja == 2)
    {
        zacetna_hitrost = 70;
        zacetno_zdravje = 2;
        stevilo_nasprotnikov = 2;
        max_nasprotnikov = 75;
        max_zdravje = 40;
        max_hitrost = 500;
        korak_hitrosti = 2;
        korak_nasprotnikov = 2;
        korak_zdravja = 1;
    }
    else if(izbrana_stopnja == 3)
    {
        zacetna_hitrost = 100;
        zacetno_zdravje = 5;
        stevilo_nasprotnikov = 4;
        max_nasprotnikov = 100;
        max_zdravje = 60;
        max_hitrost = 700;
        korak_hitrosti = 5;
        korak_nasprotnikov = 4;
        korak_zdravja = 5;
    }
    else if(izbrana_stopnja == 4)
    {
        zacetna_hitrost = 150;
        zacetno_zdravje = 10;
        stevilo_nasprotnikov = 10;
        max_nasprotnikov = 200;
        max_zdravje = 100;
        max_hitrost = 1000;
        korak_hitrosti = 10;
        korak_nasprotnikov = 10;
        korak_zdravja = 10;
    }
}

void Stopnja::Naslednji_level(std::vector<Enemie> &enem,sf::Texture &texGuard,sf::Texture &texOficer, sf::Texture &texSS)
{
    for(int i = 0;i < stevilo_nasprotnikov;i++)
    {
        int stevilo = rand() % 3;
        if(stevilo == 0)
        {
            Enemie enemie1(texGuard,10,zacetno_zdravje,zacetna_hitrost,3,-100 * (i + 1),625.f,300,1);
            enem.push_back(enemie1);
        }
        else if(stevilo == 1)
        {
             Enemie enemie1(texOficer,10,zacetno_zdravje,zacetna_hitrost + 20,3,-100 * (i + 1),625.f,300,2);
            enem.push_back(enemie1);
        }
        else if(stevilo == 2)
        {
             Enemie enemie1(texSS,10,zacetno_zdravje,zacetna_hitrost + 10,3,-100 * (i + 1),625.f,300,3);
            enem.push_back(enemie1);
        }
    }
    if(zacetna_hitrost < max_hitrost)
    {
        zacetna_hitrost += korak_hitrosti;
    }
    if(stevilo_nasprotnikov < max_nasprotnikov)
    {
        stevilo_nasprotnikov += korak_nasprotnikov;
    }
    if(zacetno_zdravje < max_zdravje)
    {
        zacetno_zdravje += korak_zdravja;
    }
}

Stopnja::~Stopnja()
{
    //dtor
}
