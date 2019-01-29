#include "Irisovalnik.h"

Irisovalnik::Irisovalnik()
{
    //ctor
}

void Irisovalnik::izrisi_zaslon(sf::RenderWindow &win,Kontrolni_elementi &opic, Kontrolni_elementi &zeb, Kontrolni_obraz &obraz_igralca, Monkey &opica, Zeblji &zebl)
{
    if(stanje_igre == 0)
    {
        izrisi_main_menu(win);
    }
    else if(stanje_igre == 1)
    {
        izrisi_izberi_zahtevnost(win);
    }
    else if(stanje_igre == 2)
    {
        izrisi_igro(win,opic,zeb,obraz_igralca,opica,zebl);
    }
    else if(stanje_igre == 3)
    {
        izrisi_igra_v_pripravi(win,opic,zeb,obraz_igralca,opica,zebl);
    }
    else if(stanje_igre == 5)
    {
        izrisi_vpisi_ime(win);
    }
    else if(stanje_igre == 6)
    {
        izrisi_rezultate(win);
    }
}

void Irisovalnik::izrisi_igra_v_pripravi(sf::RenderWindow &win,Kontrolni_elementi &opic, Kontrolni_elementi &zeb, Kontrolni_obraz &obraz_igralca, Monkey &opica, Zeblji &zebl)
{
    izrisi_igro(win,opic,zeb,obraz_igralca,opica,zebl);
    win.draw(next_level);
    win.draw(nazaj2);
}

void Irisovalnik::izrisi_igro(sf::RenderWindow &win,Kontrolni_elementi &opic, Kontrolni_elementi &zeb, Kontrolni_obraz &obraz_igralca, Monkey &opica, Zeblji &zebl)
{
        win.draw(ozad);
        win.draw(pot1);
        win.draw(pot2);
        win.draw(pot3);
        win.draw(pot4);
        win.draw(pot5);
        //win.draw(sprite);
        if(stanje_igre == 2)
        {
            for(unsigned int i = 0;i < enemies.size();i++)
            {
                win.draw(enemies[i].slika);
            }
        }
        win.draw(nadzorna);
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
}

void Irisovalnik::izrisi_izberi_zahtevnost(sf::RenderWindow &win)
{
    win.draw(ostali_meniji);
    win.draw(izberi_zahtevnost);
    win.draw(tezavnost1);
    win.draw(tezavnost2);
    win.draw(tezavnost3);
    win.draw(tezavnost4);
    win.draw(nazaj1);
}


void Irisovalnik::izrisi_main_menu(sf::RenderWindow &win)
{
        win.draw(zacetni_meni);
        win.draw(zacni_igro);
        win.draw(najboljsi_rezultati);
        win.draw(izhod);
}


void Irisovalnik::izrisi_rezultate(sf::RenderWindow &win)
{
    win.draw(ostali_meniji);
    win.draw(najboljsi_rezultati2);
    win.draw(nazaj1);
}

void Irisovalnik::izrisi_vpisi_ime(sf::RenderWindow &win)
{
    win.draw(ostali_meniji);
    win.draw(vpisi_svoje_ime);
    win.draw(potrdi);
}








Irisovalnik::~Irisovalnik()
{
    //dtor
}
