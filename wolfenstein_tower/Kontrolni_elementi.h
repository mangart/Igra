#ifndef KONTROLNI_ELEMENTI_H
#define KONTROLNI_ELEMENTI_H

#include <SFML/Graphics.hpp>

class Kontrolni_elementi
{
    public:
        Kontrolni_elementi(sf::Texture &textura, sf::Font &font, float x, float y, int xTexture, int yTexture, int cena);
        virtual ~Kontrolni_elementi();
        sf::Sprite slika;
        sf::Text tekst;
        sf::RectangleShape kvadrat;

    protected:

    private:
};

#endif // KONTROLNI_ELEMENTI_H
