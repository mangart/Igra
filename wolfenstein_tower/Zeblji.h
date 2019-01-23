#ifndef ZEBLJI_H
#define ZEBLJI_H

#include <SFML/Graphics.hpp>

class Zeblji
{
    public:
        Zeblji(sf::Texture &textura, float x,float y,int st_dotik, int izris);
        virtual ~Zeblji();
        int stevilo_dotikov;
        int se_izrise;
        int stanje;
        sf::Sprite slika;
        void spremeni_pozicijo(float x, float y);


    protected:

    private:
};

#endif // ZEBLJI_H
