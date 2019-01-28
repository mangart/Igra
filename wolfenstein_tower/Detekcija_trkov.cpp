#include "Detekcija_trkov.h"
#include <math.h>

Detekcija_trkov::Detekcija_trkov()
{
    //ctor
}

void Detekcija_trkov::trki_med_metki_in_nasprotniki(std::vector<Metek> &met, std::vector<Enemie> &enem)
{
    for(unsigned int i = 0;i < met.size();i++)
    {
        if(met[i].stanje == 1)
        {
            for(unsigned int j = 0;j < enem.size();j++)
            {
                if(enem[j].stanje == 1)
                {
                    if(vrni_razdaljo(met[i].slika.getPosition().x,met[i].slika.getPosition().y,enem[j].slika.getPosition().x + 80, enem[j].slika.getPosition().y + 80) < 67.5)
                    {
                        explozija2.play();
                        met[i].stanje = 3;
                        enem[j].zdravje--;
                        if(enem[j].zdravje == 0)
                        {
                            enem[j].stanje = 3;
                            if(enem[j].tip_nasprotnika == 3)
                            {
                                main_leben2.play();
                                tocke += 500;
                                denar += 50 * stopnja;
                            }
                            else if(enem[j].tip_nasprotnika == 2)
                            {
                                nain_so_vas2.play();
                                tocke += 200;
                                denar += 20 * stopnja;
                            }
                            else
                            {
                                aiiii2.play();
                                tocke += 100;
                                denar += 10 * stopnja;
                            }
                        }
                        else
                        {
                            enem[j].slika.setTextureRect(sf::IntRect(0,64 * 5,64,64));
                            bolecina2.play();
                        }
                        break;
                    }
                }
            }
        }
    }
}


void Detekcija_trkov::trki_med_zeblji_in_nasprotniki(std::vector<Zeblji> &zeb,std::vector<Enemie> &enem)
{
    float preteceniCas = casDetekcije.getElapsedTime().asMicroseconds();
    if(preteceniCas > 50000)
    {
        casDetekcije.restart();
        for(unsigned int i = 0;i < zeb.size();i++)
        {
            if(zeb[i].stanje == 1)
            {
                for(unsigned int j = 0;j < enem.size();j++)
                {
                    if(enem[j].stanje == 1)
                    {
                        if(vrni_razdaljo(zeb[i].slika.getPosition().x,zeb[i].slika.getPosition().y,enem[j].slika.getPosition().x + 80, enem[j].slika.getPosition().y + 80) < 60.6)
                        {
                            zeb[i].stevilo_dotikov--;
                            if(zeb[i].stevilo_dotikov == 0)
                            {
                                zeb[i].stanje = 2;
                            }
                            enem[j].zdravje--;
                            if(enem[j].zdravje == 0)
                            {
                                enem[j].stanje = 3;
                                if(enem[j].tip_nasprotnika == 3)
                                {
                                    main_leben2.play();
                                    tocke += 500;
                                    denar += 50 * stopnja;
                                }
                                else if(enem[j].tip_nasprotnika == 2)
                                {
                                    nain_so_vas2.play();
                                    tocke += 200;
                                    denar += 20 * stopnja;
                                }
                                else
                                {
                                    aiiii2.play();
                                    tocke += 100;
                                    denar += 10 * stopnja;
                                }
                            }
                            else
                            {
                                enem[j].slika.setTextureRect(sf::IntRect(0,64 * 5,64,64));
                                bolecina2.play();
                            }
                        }
                    }
                }
            }
        }
    }
}

float Detekcija_trkov::vrni_razdaljo(float x1, float y1, float x2, float y2)
{
    float razdalja = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    return sqrt(razdalja);
}

Detekcija_trkov::~Detekcija_trkov()
{
    //dtor
}
