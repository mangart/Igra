#include "Bralnik_datotek.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>


Bralnik_datotek::Bralnik_datotek()
{
    //ctor
	for(int i = 0;i < 5;i++)
	{
		Ime_in_tocke primerek;
		osebe[i] = primerek;
	}
}

void Bralnik_datotek::dodaj_zapis(std::string ime,int tocke)
{
	int st_vrstic = 0;
	std::string line;
	std::ifstream poskusna("rezultati.txt");
  	if (poskusna.is_open())
  	{
		poskusna.close();
  	}
  	else
  	{
		std::ofstream file("rezultati.txt");
  	}
 	std::ifstream myfile("rezultati.txt");
  	if (myfile.is_open())
	{
    	while (std::getline(myfile,line))
    	{
			int stevilka;
      		std::cout << line << '\n';
      		std::string delimiter = ":";
			std::string token = line.substr(0, line.find(delimiter));
			line.erase(0, line.find(delimiter) + delimiter.length());
			stevilka = atoi( line.c_str() );
			Ime_in_tocke objekt;
			objekt.ime = token;
			objekt.tocke = stevilka;
			osebe[st_vrstic] = objekt;
      		st_vrstic++;
      		if(st_vrstic == 5)
      		{
				break;
			}
    	}
    	myfile.close();
		for(int i = 0;i < 5;i++)
		{
			for(int j = 0;j < (5- 1);j++)
			{
				if(osebe[i].tocke > osebe[j].tocke)
				{
					Ime_in_tocke zacasna;
					zacasna = osebe[i];
					osebe[i] = osebe[j];
					osebe[j] = zacasna;
				}
			}
		}
		Ime_in_tocke novi_zapis;
		novi_zapis.ime = ime;
		novi_zapis.tocke = tocke;
		osebe[4] = novi_zapis;
		for(int i = 0;i < 5;i++)
		{
			for(int j = 0;j < (5- 1);j++)
			{
				if(osebe[i].tocke > osebe[j].tocke)
				{
					Ime_in_tocke zacasna;
					zacasna = osebe[i];
					osebe[i] = osebe[j];
					osebe[j] = zacasna;
				}
			}
		}
	}
	else
	{
		std::cout << "datoteko se ni dalo odpreti!" << std::endl;
	}


  	std::ofstream myfile1("rezultati.txt");
  	if (myfile1.is_open())
  	{
		for(int i = 0;i < 5;i++)
		{
			std::stringstream ss;
			if(osebe[i].tocke == 0)
			{
				break;
			}
			else
			{
				std::string ime_osebe = osebe[i].ime;
				ss << osebe[i].tocke;
				std::string tocke_osebe = ss.str();
				ime_osebe += ":" + tocke_osebe + "\n";
				myfile1 << ime_osebe;
			}
		}
   		myfile1.close();
  	}
  	else std::cout << "Unable to open file";
}


void Bralnik_datotek::Ponastavi_vrednosti()
{
	for(int i = 0;i < 5;i++)
	{
		Ime_in_tocke objektek;
		objektek.ime = "";
		objektek.tocke = 0;
		osebe[i] = objektek;
	}
}

void Bralnik_datotek::preberi_datoteko()
{
    	int st_vrstic = 0;
	std::string line;
 	std::ifstream myfile("rezultati.txt");
  	if (myfile.is_open())
	{
    	while (std::getline(myfile,line))
    	{
			int stevilka;
      		std::string delimiter = ":";
			std::string token = line.substr(0, line.find(delimiter));
			line.erase(0, line.find(delimiter) + delimiter.length());
			stevilka = atoi( line.c_str() );
			Ime_in_tocke objekt;
			objekt.ime = token;
			objekt.tocke = stevilka;
			osebe[st_vrstic] = objekt;
      		st_vrstic++;
      		if(st_vrstic == 5)
      		{
				break;
			}
    	}
    	myfile.close();
        for(int i = 0;i < 5;i++)
        {
            if(osebe[i].tocke == 0)
            {
                Highscori[i].setString("");
            }
            else
            {
                std::stringstream ss;
                ss << osebe[i].tocke;
                Highscori[i].setString(osebe[i].ime + ": \t\t" + ss.str());
            }
        }
	}
	else
	{
		std::cout << "nekaj je slo narobe!\n";
	}
}

Bralnik_datotek::~Bralnik_datotek()
{
    //dtor
}
