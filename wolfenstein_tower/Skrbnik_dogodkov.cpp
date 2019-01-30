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
    else if(stanje_igre == 5)
    {
        vpisi_ime_dogodki(win);
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
                stanje_igre = 260;
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

void Skrbnik_dogodkov::vpisi_ime_dogodki(sf::RenderWindow &win)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        stvar_pritisnjena = 100;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        stvar_pritisnjena = 101;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        stvar_pritisnjena = 102;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        stvar_pritisnjena = 103;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        stvar_pritisnjena = 104;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        stvar_pritisnjena = 105;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        stvar_pritisnjena = 106;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        stvar_pritisnjena = 107;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        stvar_pritisnjena = 108;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    {
        stvar_pritisnjena = 109;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        stvar_pritisnjena = 110;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        stvar_pritisnjena = 111;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
    {
        stvar_pritisnjena = 112;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        stvar_pritisnjena = 113;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        stvar_pritisnjena = 114;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        stvar_pritisnjena = 115;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        stvar_pritisnjena = 116;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        stvar_pritisnjena = 117;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        stvar_pritisnjena = 118;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        stvar_pritisnjena = 119;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::U))
    {
        stvar_pritisnjena = 120;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        stvar_pritisnjena = 121;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        stvar_pritisnjena = 122;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        stvar_pritisnjena = 123;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        stvar_pritisnjena = 124;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        stvar_pritisnjena = 125;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
    {
        stvar_pritisnjena = 126;
    }
    else
    {
        if(stvar_pritisnjena == 100)
        {
            ime += "A";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 101)
        {
            ime += "B";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 102)
        {
            ime += "C";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 103)
        {
            ime += "D";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 104)
        {
            ime += "E";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 105)
        {
            ime += "F";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 106)
        {
            ime += "G";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 107)
        {
            ime += "H";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 108)
        {
            ime += "I";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 109)
        {
            ime += "j";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 110)
        {
            ime += "K";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 111)
        {
            ime += "L";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 112)
        {
            ime += "M";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 113)
        {
            ime += "N";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 114)
        {
            ime += "O";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 115)
        {
            ime += "P";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 116)
        {
            ime += "Q";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 117)
        {
            ime += "R";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 118)
        {
            ime += "S";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 119)
        {
            ime += "T";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 120)
        {
            ime += "U";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 121)
        {
            ime += "X";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 122)
        {
            ime += "Y";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 123)
        {
            ime += "W";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 124)
        {
            ime += "V";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 125)
        {
            ime += "Z";
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }
        else if(stvar_pritisnjena == 126)
        {
            ime = ime.substr(0, ime.size()-1);
            vpisano_ime.setString(ime);
            stvar_pritisnjena = 0;
        }

    }

    if((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(win);
        if(stvar_pritisnjena == 0)
        {
            if((localPosition.x >= 760 && localPosition.x <= 1016) && (localPosition.y >= 700 && localPosition.y <= 764))
            {
                stvar_pritisnjena = 220;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
        else if(stvar_pritisnjena == 220)
        {
            if((localPosition.x >= 760 && localPosition.x <= 1016) && (localPosition.y >= 700 && localPosition.y <= 764))
            {
                stvar_pritisnjena = 220;
            }
            else
            {
                stvar_pritisnjena = 0;
            }
        }
    }
    else
    {
            if(stvar_pritisnjena == 220)
            {
                stvar_pritisnjena = 0;
                stanje_igre = 250;
            }
    }

}


Skrbnik_dogodkov::~Skrbnik_dogodkov()
{
    //dtor
}
