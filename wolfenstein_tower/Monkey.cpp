#include "Monkey.h"
#include <math.h>


Monkey::Monkey(sf::Texture &textura,int zdr,float x, float y, int izris)
{
    //ctor
    se_izrise = izris;
    zdravje = zdr;
    slika.setTexture(textura);
    slika.setTextureRect(sf::IntRect(0,0, 64, 64));
    // za aèetek nastavi x koordinato na - 75.f
    // x = -30.f y = 625.f
    slika.setPosition(sf::Vector2f(x, y)); // absolute position
    slika.setScale(sf::Vector2f(1.3f, 1.3f));
    slika.setOrigin(sf::Vector2f(32,32));
    stanje = 1;
}

void Monkey::spremeni_pozicijo(float x, float y)
{
    slika.setPosition(sf::Vector2f(x,y));
}

void Monkey::Umetna_inteligenca(std::vector<Enemie> &enemie, std::vector<Metek> &metki, sf::Texture &tex)
{
    if(stanje == 1)
    {
        int  preteceniCas = casUI.getElapsedTime().asMilliseconds();
        if(preteceniCas > 500)
        {
            int x = slika.getPosition().x;
            int y = slika.getPosition().y;
            int najblizji_enemieX;
            int najblizji_enemieY;
            float razdalja = 100000000;
            int index_najblizjega = -1;
            for(unsigned int i = 0; i < enemie.size();i++)
            {
                int enemieX = enemie[i].slika.getPosition().x + 120;
                int enemieY = enemie[i].slika.getPosition().y + 80;
                float nova_razdalja = (x - enemieX) * (x - enemieX) + (y - enemieY) * (y - enemieY);
                nova_razdalja = sqrt(nova_razdalja);
                if(nova_razdalja < razdalja)
                {
                    razdalja = nova_razdalja;
                    index_najblizjega = i;
                    najblizji_enemieX = enemieX;
                    najblizji_enemieY = enemieY;
                }
            }
            if(index_najblizjega != -1)
            {
                if(razdalja < 400)
                {
                    int vector_x = najblizji_enemieX - x;
                    int vector_y = najblizji_enemieY - y;
                    int drugi_vektor_x = 0;
                    int drugi_vektor_y = 200;
                    float zgor_del_ulomka = ((vector_x * drugi_vektor_x) + (vector_y * drugi_vektor_y));
                    float spod_del_ulomka = sqrt((vector_x * vector_x) + (vector_y * vector_y)) * sqrt((drugi_vektor_x * drugi_vektor_x) + (drugi_vektor_y * drugi_vektor_y));
                    float kosinus_kota = (zgor_del_ulomka / spod_del_ulomka);
                    float kot = (acos(kosinus_kota) * 180.0) / 3.14159265;
                    if(x < najblizji_enemieX)
                    {
                        kot = kot * (-1);
                    }
                    slika.setRotation(kot);
                    if(razdalja < 200)
                    {
                        slika.setTextureRect(sf::IntRect(64,0,64,64));
                        Metek met(tex,200,vector_x,vector_y,kot,slika.getPosition().x,slika.getPosition().y,najblizji_enemieX,najblizji_enemieY);
                        metki.push_back(met);
                    }
                }
            }
            casUI.restart();
        }
        else if(preteceniCas > 200)
        {
            slika.setTextureRect(sf::IntRect(0,0,64,64));
        }
    }
}




void Monkey::preveri_animacijo()
{
        sf::Time elapsed1 = casAnimacije.getElapsedTime();
    if(elapsed1.asMilliseconds() > 300){
        casAnimacije.restart();
        slika.setTextureRect(sf::IntRect(0,0,64,64));
    }

}

Monkey::~Monkey()
{
    //dtor
}
