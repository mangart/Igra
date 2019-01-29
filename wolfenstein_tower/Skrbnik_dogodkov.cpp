#include "Skrbnik_dogodkov.h"
#include <iostream>

Skrbnik_dogodkov::Skrbnik_dogodkov()
{
    //ctor
    stvar_pritisnjena = 0;
    na_pravem_mestu = 0;
}

void Skrbnik_dogodkov::obravnavaj_dogodke(std::vector<Monkey> &mon, std::vector<Zeblji> &zeb, sf::CircleShape &krog,Monkey &opica,Zeblji &zebl, sf::RenderWindow &win)
{
    if(stanje_igre == 0)
    {
        dogodki_v_zacetnem_meniju(win);
    }
    else if(stanje_igre == 1)
    {
        dogodki_v_izbiranju_zahtevnosti(win);
    }
    else if(stanje_igre == 2)
    {
        obravnavaj_dogodke_v_stanju_dva(mon,zeb,krog,opica,zebl,win);
    }
    else if(stanje_igre == 3)
    {
        priprava_na_igro_dogodki(mon,zeb,krog,opica,zebl,win);
    }
    else if(stanje_igre == 6)
    {
        najboljsi_rezultati_dogodki(win);
    }

}

void Skrbnik_dogodkov::obravnavaj_dogodke_v_stanju_dva(std::vector<Monkey> &mon, std::vector<Zeblji> &zeb, sf::CircleShape &krog,Monkey &opica,Zeblji &zebl, sf::RenderWindow &win)
{
    if((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(win);
        if(stvar_pritisnjena == 0)
        {
            if((localPosition.x >= 1510 && localPosition.x <= 1574) && (localPosition.y >= 200 && localPosition.y <= 264))
            {
                if(denar >= 100)
                {
                    stvar_pritisnjena = 1;
                }
            }
            if((localPosition.x >= 1640 && localPosition.x <= 1704) && (localPosition.y >= 200 && localPosition.y <= 264))
            {
                if(denar >= 25)
                {
                    stvar_pritisnjena = 2;
                }
            }
        }
        if(stvar_pritisnjena == 1)
        {
            opica.se_izrise = 1;
            opica.spremeni_pozicijo(localPosition.x,localPosition.y);
            krog.setPosition(sf::Vector2f(localPosition.x,localPosition.y));
            if(preveri_pot(localPosition.x,localPosition.y) || preveri_opice(mon,localPosition.x,localPosition.y))
            {
                krog.setFillColor(sf::Color(255,0,0,128));
                na_pravem_mestu = 0;
            }
            else
            {
                krog.setFillColor(sf::Color(100, 250, 50,128));
                na_pravem_mestu = 1;
            }

        }
        if(stvar_pritisnjena == 2)
        {
            zebl.se_izrise = 1;
            zebl.spremeni_pozicijo(localPosition.x,localPosition.y);
            krog.setPosition(sf::Vector2f(localPosition.x,localPosition.y));
            if(!preveri_pot_zebli(localPosition.x,localPosition.y))
            {
                krog.setFillColor(sf::Color(255,0,0,128));
                na_pravem_mestu = 0;
            }
            else
            {
                krog.setFillColor(sf::Color(100, 250, 50,128));
                na_pravem_mestu = 1;
            }

        }
    }
    else
    {
        if(stvar_pritisnjena == 1)
        {
            if(na_pravem_mestu == 1)
            {
                mon.push_back(opica);
                denar = denar - 100;
            }
            opica.se_izrise = 0;
            stvar_pritisnjena = 0;
        }
        if(stvar_pritisnjena == 2)
        {
            if(na_pravem_mestu == 1)
            {
                zeb.push_back(zebl);
                denar = denar - 25;
            }
            zebl.se_izrise = 0;
            stvar_pritisnjena = 0;
        }
        stvar_pritisnjena = 0;
    }
}

bool Skrbnik_dogodkov::preveri_pot(int x, int y)
{
    if(((x + 41.6) >= 0 && (x - 41.6) <= 601.6) && ((y + 41.6) >= 650 && (y - 41.6) <= 803.6))
    {
        return true;
    }
    if(((x + 41.6) >= 448 && (x - 41.6) <= 601.6) && ((y + 41.6) >= 200 && (y - 41.6) <= 803.6))
    {
        return true;
    }
    if(((x + 41.6) >= 448 && (x - 41.6) <= 1075.2) && ((y + 41.6) >= 200 && (y - 41.6) <= 353.6))
    {
        return true;
    }
    if(((x + 41.6) >= 921.6 && (x - 41.6) <= 1075.2) && ((y + 41.6) >= 200 && (y - 41.6) <= 803.6))
    {
        return true;
    }
    if(((x + 41.6) >= 1075.2 && (x - 41.6) <= 1500) && ((y + 41.6) >= 650 && (y - 41.6) <= 803.6))
    {
        return true;
    }
    if((x + 41.6) > 1500)
    {
        return true;
    }


    return false;
}

bool Skrbnik_dogodkov::preveri_opice(std::vector<Monkey> &mon, int x, int y)
{
    for(unsigned int i = 0; i < mon.size();i++)
    {
        if((x + 41.6) >= (mon[i].slika.getPosition().x - 41.6) && (x - 41.6) <= (mon[i].slika.getPosition().x + 41.6) && (y + 41.6) >= (mon[i].slika.getPosition().y - 41.6) && (y - 41.6) <= (mon[i].slika.getPosition().y + 41.6) )
            {
                return true;
            }
    }
    return false;
}

bool Skrbnik_dogodkov::preveri_pot_zebli(int x, int y)
{
    if(((x - 41.6) >= 0 && (x + 41.6) <= 601.6) && ((y - 41.6) >= 650 && (y + 41.6) <= 803.6))
    {
        return true;
    }
    if(((x - 41.6) >= 448 && (x + 41.6) <= 601.6) && ((y - 41.6) >= 200 && (y + 41.6) <= 803.6))
    {
        return true;
    }
    if(((x - 41.6) >= 448 && (x + 41.6) <= 1075.2) && ((y - 41.6) >= 200 && (y + 41.6) <= 353.6))
    {
        return true;
    }
    if(((x - 41.6) >= 921.6 && (x + 41.6) <= 1075.2) && ((y - 41.6) >= 200 && (y + 41.6) <= 803.6))
    {
        return true;
    }
    if(((x - 41.6) >= 921.6 && (x + 41.6) <= 1500) && ((y - 41.6) >= 650 && (y + 41.6) <= 803.6))
    {
        return true;
    }
    if((x - 41.6) > 1500)
    {
        return false;
    }


    return false;
}

void Skrbnik_dogodkov::dogodki_v_zacetnem_meniju(sf::RenderWindow &win)
{
    if((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(win);
        if(stvar_pritisnjena == 0)
        {
            if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 400 && localPosition.y <= 464))
            {
                stvar_pritisnjena = 11;
            }
            else if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 500 && localPosition.y <= 564))
            {
                stvar_pritisnjena = 12;
            }
            else if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 600 && localPosition.y <= 664))
            {
                stvar_pritisnjena = 13;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 11)
        {
            if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 400 && localPosition.y <= 464))
            {
                stvar_pritisnjena = 11;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 12)
        {
             if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 500 && localPosition.y <= 564))
            {
                stvar_pritisnjena = 12;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 13)
        {
             if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 600 && localPosition.y <= 664))
            {
                stvar_pritisnjena = 13;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
    }
    else
        {
            if(stvar_pritisnjena == 11)
            {
                stvar_pritisnjena = 0;
                stanje_igre = 1;
            }
            else if(stvar_pritisnjena == 12)
            {
                stvar_pritisnjena = 0;
                stanje_igre = 6;
            }
            else if(stvar_pritisnjena == 13)
            {
                exit(0);
            }
        }

}

void Skrbnik_dogodkov::dogodki_v_izbiranju_zahtevnosti(sf::RenderWindow &win)
{
    if((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(win);
        if(stvar_pritisnjena == 0)
        {
            if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 300 && localPosition.y <= 364))
            {
                stvar_pritisnjena = 21;
            }
            else if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 400 && localPosition.y <= 464))
            {
                stvar_pritisnjena = 22;
            }
            else if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 500 && localPosition.y <= 564))
            {
                stvar_pritisnjena = 23;
            }
            else if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 600 && localPosition.y <= 664))
            {
                stvar_pritisnjena = 24;
            }
            else if((localPosition.x >= 0 && localPosition.x <= 256) && (localPosition.y >= 800 && localPosition.y <= 864))
            {
                stvar_pritisnjena = 25;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 21)
        {
            if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 300 && localPosition.y <= 364))
            {
                stvar_pritisnjena = 21;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 22)
        {
             if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 400 && localPosition.y <= 464))
            {
                stvar_pritisnjena = 22;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 23)
        {
             if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 500 && localPosition.y <= 564))
            {
                stvar_pritisnjena = 23;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 24)
        {
              if((localPosition.x >= 772 && localPosition.x <= 1028) && (localPosition.y >= 600 && localPosition.y <= 664))
            {
                stvar_pritisnjena = 24;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 25)
        {
              if((localPosition.x >= 0 && localPosition.x <= 256) && (localPosition.y >= 800 && localPosition.y <= 864))
            {
                stvar_pritisnjena = 25;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
    }
    else
        {
            if(stvar_pritisnjena == 21)
            {
                stvar_pritisnjena = 0;
                stanje_igre = 50;
            }
            else if(stvar_pritisnjena == 22)
            {
                stvar_pritisnjena = 0;
                stanje_igre = 51;
            }
            else if(stvar_pritisnjena == 23)
            {
                stvar_pritisnjena = 0;
                stanje_igre = 52;
            }
            else if(stvar_pritisnjena == 24)
            {
                stvar_pritisnjena = 0;
                stanje_igre = 53;
            }
            else if(stvar_pritisnjena == 25)
            {
                stvar_pritisnjena = 0;
                stanje_igre = 0;
            }
        }
}

void Skrbnik_dogodkov::priprava_na_igro_dogodki(std::vector<Monkey> &mon, std::vector<Zeblji> &zeb, sf::CircleShape &krog,Monkey &opica,Zeblji &zebl, sf::RenderWindow &win)
{
    if((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(win);
        if(stvar_pritisnjena == 0)
        {
            if((localPosition.x >= 1510 && localPosition.x <= 1574) && (localPosition.y >= 200 && localPosition.y <= 264))
            {
                if(denar >= 100)
                {
                    stvar_pritisnjena = 1;
                }
            }
            else if((localPosition.x >= 1640 && localPosition.x <= 1704) && (localPosition.y >= 200 && localPosition.y <= 264))
            {
                if(denar >= 25)
                {
                    stvar_pritisnjena = 2;
                }
            }
            else if((localPosition.x >= 1520 && localPosition.x <= 1776) && (localPosition.y >= 600 && localPosition.y <= 664))
            {
                stvar_pritisnjena = 3;
            }
            else if((localPosition.x >= 1520 && localPosition.x <= 1776) && (localPosition.y >= 700 && localPosition.y <= 764))
            {
                stvar_pritisnjena = 4;
            }
        }
        else if(stvar_pritisnjena == 1)
        {
            opica.se_izrise = 1;
            opica.spremeni_pozicijo(localPosition.x,localPosition.y);
            krog.setPosition(sf::Vector2f(localPosition.x,localPosition.y));
            if(preveri_pot(localPosition.x,localPosition.y) || preveri_opice(mon,localPosition.x,localPosition.y))
            {
                krog.setFillColor(sf::Color(255,0,0,128));
                na_pravem_mestu = 0;
            }
            else
            {
                krog.setFillColor(sf::Color(100, 250, 50,128));
                na_pravem_mestu = 1;
            }

        }
        else if(stvar_pritisnjena == 2)
        {
            zebl.se_izrise = 1;
            zebl.spremeni_pozicijo(localPosition.x,localPosition.y);
            krog.setPosition(sf::Vector2f(localPosition.x,localPosition.y));
            if(!preveri_pot_zebli(localPosition.x,localPosition.y))
            {
                krog.setFillColor(sf::Color(255,0,0,128));
                na_pravem_mestu = 0;
            }
            else
            {
                krog.setFillColor(sf::Color(100, 250, 50,128));
                na_pravem_mestu = 1;
            }

        }
        else if(stvar_pritisnjena == 3)
        {
            if((localPosition.x >= 1520 && localPosition.x <= 1776) && (localPosition.y >= 600 && localPosition.y <= 664))
            {
                stvar_pritisnjena = 3;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 4)
        {
             if((localPosition.x >= 1520 && localPosition.x <= 1776) && (localPosition.y >= 700 && localPosition.y <= 764))
            {
                stvar_pritisnjena = 4;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
    }
    else
    {
        if(stvar_pritisnjena == 1)
        {
            if(na_pravem_mestu == 1)
            {
                mon.push_back(opica);
                denar = denar - 100;
            }
            opica.se_izrise = 0;
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 2)
        {
            if(na_pravem_mestu == 1)
            {
                zeb.push_back(zebl);
                denar = denar - 25;
            }
            zebl.se_izrise = 0;
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 3)
        {
            stanje_igre = 2;
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 4)
        {
            stanje_igre = 100;
            stvar_pritisnjena = 0;
        }

        stvar_pritisnjena = 0;
    }
}


void Skrbnik_dogodkov::najboljsi_rezultati_dogodki(sf::RenderWindow &win)
{
    if((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(win);
        if(stvar_pritisnjena == 0)
        {
            if((localPosition.x >= 0 && localPosition.x <= 256) && (localPosition.y >= 800 && localPosition.y <= 864))
            {
                stvar_pritisnjena = 31;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 31)
        {
            if((localPosition.x >= 0 && localPosition.x <= 256) && (localPosition.y >= 800 && localPosition.y <= 864))
            {
                stvar_pritisnjena = 31;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
    }
    else
        {
            if(stvar_pritisnjena == 31)
            {
                stvar_pritisnjena = 0;
                stanje_igre = 0;
            }
        }
}

Skrbnik_dogodkov::~Skrbnik_dogodkov()
{
    //dtor
}
