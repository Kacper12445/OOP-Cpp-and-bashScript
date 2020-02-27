#pragma once

#include <iostream>
#include "Figura_geometryczna.hh"


using namespace std;

/*!
 * \file
 * \brief Ten plik zawiera definicję klasy Prostopadloscian, ktora dziedziczy z klasy Figura_geometryczna.
 *
 */


/*!
 * \brief Definicja klasy Prostopadloscian.
 *
 *  Klasa ta modeluje pojecie pojecie prostopadloscianu w przestrzeni trojwymiarowej.
 *  Obiekt tej klasy jest reprezentowany przez tablice instancji szablonu klasy Wektor<>, przy czym
 *  nastepuje tutaj pewna konkretyzacja, gdyz uzywa sie obiektow typu Wektor3D.
 *
 */
class Prostopadloscian : public Figura_geometryczna{


  public:
/*!
 * \brief Definicja konstruktora z jednym parametrem, ktory jest obiektem klasy Wektor3D i odpowiada za przesuniecie 
 * prostopadloscianu o zadany wektor od polozenia poczatkowego. Destruktor tej klasy czysci dynamiczna tablice szablonu vector<>. 
 *
 */
    Prostopadloscian(Wektor3D prz);
    friend ostream& operator << (ostream &Strm, const Prostopadloscian &Pr);

    ~Prostopadloscian()
    {
      wsp.clear();
    }

};


/*!
 * \brief Definicja przeciazenia przesuniecia bitowego w lewo dla klasy Prostopadloscian.
 *
 *  Przeciazenie to pozwala wypisac na standardowe wyjscie wspolrzedne wierzcholkow
 *  prostopadloscianu, ktore zrealizowane jest dzieki przeciazeniu operatora przesuniecia bitowego w lewo dla
 *  szablonu klasy Wektor<>.
 *
 *  \param[in] &Strm - referencja do strumienia wyjsciowego
 *  \param[in] &Pr - referencja do obiektu klasy Prostopadloscian, ktorej nie mozna modyfikowac
 *
 *  \return Zwraca referencje do strumienia wyjsciowego.
 *
 */
ostream& operator << (ostream &Strm, const Prostopadloscian &Pr);
