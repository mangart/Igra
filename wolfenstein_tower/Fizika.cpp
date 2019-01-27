#include "Fizika.h"
#include <math.h>

Fizika::Fizika()
{
    //ctor
}

void Fizika::premakniNasprotnika(std::vector<Enemie> &vec,float preteceniCas)
{
    int neki = 160;
    for(unsigned int i = 0;i < vec.size();i++)
    {
        if(vec[i].stanje == 1)
        {


            float x = vec[i].slika.getPosition().x;
            float y = vec[i].slika.getPosition().y;
            if(vec[i].na_poti == 1)
            {
                float x1 = x + vec[i].hitrost * preteceniCas;
                if(x1 > (601.6 - neki))
                {
                    vec[i].slika.setPosition((601.6 - neki), y);
                    vec[i].smer = 2;
                    vec[i].na_poti = 2;
                }
                else{
                    vec[i].slika.setPosition(x1,y);
                }
            }

            else if(vec[i].na_poti == 2)
            {
                float y1 = y - vec[i].hitrost * preteceniCas;
                if(y1 < (20 + neki))
                {
                    vec[i].slika.setPosition(x,(20  + neki));
                    vec[i].smer = 3;
                    vec[i].na_poti = 3;
                }
                else
                {
                    vec[i].slika.setPosition(x,y1);
                }
            }

            else if(vec[i].na_poti == 3)
            {
                float x1 = x + vec[i].hitrost * preteceniCas;
                if(x1 > (1075.2 - neki))
                {
                    vec[i].slika.setPosition((1075.2 - neki),y);
                    vec[i].smer = 0;
                    vec[i].na_poti = 4;
                }
                else
                {
                    vec[i].slika.setPosition(x1,y);
                }
            }

            else if(vec[i].na_poti == 4)
            {
                float y1 = y + vec[i].hitrost * preteceniCas;
                if(y1 > (803.6 - neki - 20))
                {
                    vec[i].slika.setPosition(x,(803.6 - neki - 20));
                    vec[i].smer = 3;
                    vec[i].na_poti = 5;
                }
                else
                {
                    vec[i].slika.setPosition(x,y1);
                }
            }

            else if(vec[i].na_poti == 5)
            {
                float x1 = x + vec[i].hitrost * preteceniCas;
                if(x1 > (1500 - neki / 4))
                {
                    vec[i].slika.setPosition((1500 - neki / 4),y);
                    vec[i].stanje = 3;
                    zivljenja--;
                }
                else
                {
                    vec[i].slika.setPosition(x1,y);
                }
            }
        }
    }

}


void Fizika::premakniMetek(std::vector<Metek> &met, float preteceniCas)
{
    for(unsigned int i = 0;i < met.size();i++)
    {
        if(met[i].stanje == 1)
        {
            float x = met[i].slika.getPosition().x;
            float y = met[i].slika.getPosition().y;
            float x1 = x + met[i].normirana_smerX * met[i].hitrost * preteceniCas;
            float y1 = y + met[i].normirana_smerY * met[i].hitrost * preteceniCas;
            float nova_razdalja = (x1 - met[i].ciljniX) * (x1 - met[i].ciljniX) + (y - met[i].ciljniY) * (y -met[i].ciljniY);
            nova_razdalja = sqrt(nova_razdalja);
            if(nova_razdalja < met[i].razdalja)
            {
                met[i].slika.setPosition(x1,y1);
                met[i].razdalja = nova_razdalja;
            }
            else if(nova_razdalja < met[i].razdalja + 80)
            {
                met[i].slika.setPosition(x1,y1);
            }
            else
            {
                met[i].stanje = 2;
            }
        }
    }
}

Fizika::~Fizika()
{
    //dtor
}
