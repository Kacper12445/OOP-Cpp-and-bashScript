#pragma once
#include <iostream>
#include <memory>
#include <list>
#include "Dron.hh"
#include "PrzeszkodaPr.hh"
#include "lacze_do_gnuplota.hh"
using namespace std;


/*!
 * \file
 * \brief Ten plik zawiera definicję klasy Scena.
 *
 */


/*!
 * \brief Definicja klasy Scena.
 *
 *  Klasa ta modeluje pojecie pojecie trojwymiarowej sceny, na ktorej znajduja sie drony oraz przeszkody.
 *  Obiekt tej klasy jest reprezentowany przez dwa szablony listy std::list, ktorej elementami sa wskazniki wspoldzielone std::shared_ptr na 
 *  obiekty klasy ObiektSceny oraz Dron. Klasa zwiera tazke wskaznik wspoldzielony na aktualny obiekt klasy Dron, nad ktorym wykonywane jest 
 *  sterowanie. Odpowiednie metody klasy Scena zostaly szczegolowo opisane w pliku \link Scena.cpp \endlink
 *
 */
class Scena{
	shared_ptr<Dron> akt_dron;
	list<shared_ptr<ObiektSceny>> obiekty;
	list<shared_ptr<Dron>> roboty;
	
	

	public:
/*!
 * \brief Definicja konstruktora bezparametrycznego, ktory wywoluje poszczegolne konstruktory dla obiektow klasy PrzeszkodaPr i Dron, a nastepnie 
 * umieszcza je na odpowiednich listach std::list<>.
 */
		Scena()
		{
			Wektor3D wek;
			wek[0] = 0;
			wek[1] = 0;
			wek[2] = 0;
			shared_ptr<Dron> Dron0 = make_shared<Dron>(wek);
			roboty.push_back(Dron0);
			obiekty.push_back(Dron0);
			
			wek[0] = -70;
			wek[1] = -55;
			wek[2] = 30;
			shared_ptr<Dron> Dron1 = make_shared<Dron>(wek);
			roboty.push_back(Dron1);
			obiekty.push_back(Dron1);

			wek[0] = -50;
			wek[1] = 80;
			wek[2] = -10;
			shared_ptr<Dron> Dron2 = make_shared<Dron>(wek);
			roboty.push_back(Dron2);
			obiekty.push_back(Dron2);
			
			akt_dron = Dron0;
			
			wek[0] = 80;
			wek[1] = 80;
			wek[2] = 0;
			shared_ptr<PrzeszkodaPr> Prz0 = make_shared<PrzeszkodaPr>(wek);
			obiekty.push_back(Prz0);

			wek[0] = 60;
			wek[1] = -60;
			wek[2] = 0;
			shared_ptr<PrzeszkodaPr> Prz1 = make_shared<PrzeszkodaPr>(wek);
			obiekty.push_back(Prz1);

			wek[0] = 0;
			wek[1] = 60;
			wek[2] = 15;
			shared_ptr<PrzeszkodaPr> Prz2 = make_shared<PrzeszkodaPr>(wek);
			obiekty.push_back(Prz2);


			wek[0] = 20;
			wek[1] = 90;
			wek[2] = 35;
			shared_ptr<PrzeszkodaPr> Prz3 = make_shared<PrzeszkodaPr>(wek);
			obiekty.push_back(Prz3);


			wek[0] = 20;
			wek[1] = 50;
			wek[2] = 35;
			shared_ptr<PrzeszkodaPr> Prz4 = make_shared<PrzeszkodaPr>(wek);
			obiekty.push_back(Prz4);

			wek[0] = 20;
			wek[1] = 40;
			wek[2] = 35;
			shared_ptr<PrzeszkodaPr> Prz5 = make_shared<PrzeszkodaPr>(wek);
			obiekty.push_back(Prz5);

			wek[0] = 10;
			wek[1] = 10;
			wek[2] = 35;
			shared_ptr<PrzeszkodaPr> Prz6 = make_shared<PrzeszkodaPr>(wek);
			obiekty.push_back(Prz6);
		}


/*!
 * \brief Definicja destruktora, ktory wywoluje metody "clear" dla obiektow dla poszczegolnych szablonow list zawartch w klasie Scena, a takze 
 * wywoluje destruktor dla wskaznika wspoldzielonego, ktory przetrzymuje adres aktualnego drona, nad ktorym wykonywane jest sterowanie. Ponadto wypisuje
 * na ekran ilosc stworzonych i aktualnie istniejacych wektorow.
 */
		~Scena()
		{    
			obiekty.clear();
			roboty.clear();
			akt_dron.~__shared_ptr();

			cout << " Ilosc stworzonych wektorow: " << Wektor3D::ilosc_istniejacych << endl;
   			cout << " Ilosc aktualnie istniejacych wektorow: " << Wektor3D::ilosc_tymczasowa << endl;
			cout << " Ilosc aktualnie istenijacych obiektow: " << ObiektSceny::ilosc << endl << endl;
			   
		}

		int Inicjalizuj(PzG::LaczeDoGNUPlota  &Lacze);
		int Menu(PzG::LaczeDoGNUPlota &Lacze);
		
};

	
