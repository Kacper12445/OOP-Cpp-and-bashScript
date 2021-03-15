#pragma once 
#include <iostream>
#include "ObiektSceny.hh"
#include "Wektor.hh"
#include "Przeszkoda.hh"
#include "Wektor3D.hh"
#include <Prostopadloscian.hh>
#include <lacze_do_gnuplota.hh>
#include <vector>
#include <string>
#include <fstream>
#include "Dron.hh"



/*!
 * \file
 * \brief Ten plik zawiera definicję klasy PrzeszkodaPr, ktora dziedziczy z klasy Przeszkoda.
 *
 */


/*!
 * \brief Definicja klasy PrzeszkodaPr.
 *
 *  Klasa ta modeluje pojecie pojecie przeszkody prostopadlosciennej w przestrzeni trojwymiarowej.
 *  Skladowymi tej klasy sa trzy tablice statyczne typu double, ktore reprezentuja obrys przeszkody niezbedny do wykrywania kolizji.
 *  Dynamiczna tablica szablonu std::vector<> zawiera pliki wraz ze wspolrzednymi przeszkody prostopadlosciennej. 
 *  Odpowiednie metody klasy PrzeszkodaPr zostaly szczegolowo opisane w pliku \link PrzeszkodaPr.cpp \endlink
 *
 */
class PrzeszkodaPr : public Przeszkoda, public ObiektSceny
{
	double obrys_x[2];
	double obrys_y[2];
	double obrys_z[2];
	vector<string> pliki;

	public:
		PrzeszkodaPr(Wektor3D przesun);
		PrzeszkodaPr(){}
	  	int Inicjalizuj(int ind, PzG::LaczeDoGNUPlota  &Lacze);
		void PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy);
    	bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku);
		bool CzyKolizja(const shared_ptr<Dron> Ob) const;

		~PrzeszkodaPr()
		{
			pliki.clear();
			wsp.clear();
		}
    	
};

