#pragma once
#include <iostream>
#include "Wektor.hh"
#include "Wektor3D.hh"
#include "lacze_do_gnuplota.hh"
#include <memory>

class Dron;

/*!
 * \file
 * \brief Ten plik zawiera definicję klasy ObiektSceny.
 *
 */


/*!
 * \brief Definicja klasy ObiektSceny.
 *
 *  Klasa ta modeluje pojecie pojecie obiektu sceny w przestrzeni trojwymiarowej. Klasa ta zostala stworzona w celu zastosowania 
 *  polimorfizmu w celu wykrywania kolizji miedzy obiektami. Metodami czysto wirtualnymi sa CzyKolizja() oraz Inicjalizuj().
 * Metoda wirtualna jest metoda get_srodek(), ktora zwraca srodek ciezkosci obiektu sceny.
 *
 */
class ObiektSceny {
    

    public:
    static int ilosc;
    ObiektSceny()
    {
        ilosc++;
    }

    virtual Wektor3D get_srodek() 
    {
        Wektor3D wektor;
        return wektor;
    } 

    virtual bool CzyKolizja(const shared_ptr<Dron> Ob) const = 0;

    virtual ~ObiektSceny()
    {
        ilosc--;   
    }

    virtual int Inicjalizuj(int ind, PzG::LaczeDoGNUPlota &Lacze) = 0;  
};


