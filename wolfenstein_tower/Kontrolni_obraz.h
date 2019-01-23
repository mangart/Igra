#ifndef KONTROLNI_OBRAZ_H
#define KONTROLNI_OBRAZ_H

#include <SFML/Graphics.hpp>

extern int zivljenja;

class Kontrolni_obraz
{
    public:
        Kontrolni_obraz(sf::Texture &textura, float x, float y);
        virtual ~Kontrolni_obraz();
        sf::Sprite slika;
        void posodobiAnimacijo();
        sf::Clock casAnimacije;


    protected:

    private:
};

#endif // KONTROLNI_OBRAZ_H
