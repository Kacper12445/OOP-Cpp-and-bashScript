#pragma once

#include <iostream>
#include "Figura_geometryczna.hh"

using namespace std;

/*!
 * \file
 * \brief Ten plik zawiera definicję klasy Graniastoslup, ktora dziedziczy po klasie
 * Figura_geometryczna
 *
 */
class Graniastoslup : public Figura_geometryczna{
  public:
/*!
 * \brief Definicja konstruktora z jednym parametrem.
 *
 */
    void ustaw(Wektor3D w);
    friend ostream& operator << (ostream &Strm, const Graniastoslup &Gr);

    ~Graniastoslup()
    {
      wsp.clear();
    }

};


/*!
 * \brief Definicja przeciazenia przesuniecia bitowego w lewo dla klasy Graniastoslup.
 *
 *  Przeciazenie to pozwala wypisac na standardowe wyjscie wspolrzedne wierzcholkow
 *  Graniastoslup, ktore zrealizowane jest dzieki przeciazeniu operatora przesuniecia bitowego w lewo
 *  dla szablonu klasy Wektor<>.
 *
 *  \param[in] &Strm - referencja do strumienia wyjsciowego
 *  \param[in] &Gr - referencja do obiektu klasy Graniastoslup, ktorej nie mozna modyfikowac
 *
 *  \return Zwraca referencje do strumienia wyjsciowego.
 *
 */
ostream& operator << (ostream &Strm, const Graniastoslup &Gr);
