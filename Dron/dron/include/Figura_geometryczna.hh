#pragma once

#include <iostream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <vector>
#include <assert.h>

using namespace std;

/*!
 * \file
 * \brief Ten plik zawiera definicję klasy Figura_geometryczna.
 *
 */


/*!
 * \brief Definicja klasy Figura_geometryczna.
 *
 *  Klasa ta modeluje pojecie pojecie prostopadloscianu w przestrzeni trojwymiarowej.
 *  Obiekt tej klasy jest reprezentowany przez tablice dynamiczna instancji szablonu klasy Wektor<>
 *  wykorzystaniem szablonu vector<>, przy czym
 *  nastepuje tutaj pewna konkretyzacja, gdyz uzywa sie obiektow typu Wektor3D .
 *
 */
class Figura_geometryczna{
  protected:
    vector<Wektor3D> wsp;



  public:
/*!
 *  \brief Definicja i implementacja przeciazenia operatora indeksujacego.
 *
 *  param[in] i - zmienna typu int pozwalajaca na poruszanie sie po tablicy wspolrzednych wektora.
 *
 *  Dzieki temu opeartorowi mozliwa jest modyfikacja pol klasy Figura_geometryczna.
 *
 *  \return Zwraca referencje do odpowiedniego pola klasy Figura_geometryczna.
 */
    Wektor3D &operator [] (int i)
    {


        assert(i >= 0 && i <= (int)wsp.size());
        return wsp[i];
    }


/*!
 *  \brief Definicja i implementacja przeciazenia operatora indeksujacego.
 *  param[in] i - zmienna typu int pozwalajaca na poruszanie sie po tablicy wspolrzednych wektora.
 *  Przeciazenie tego operatora nie umozliwia modyfikacji pol instancji szablomu klasy Wektor<>.
 *  \return Zwraca referencje do odpowiedniego pola klasy Figura_geometryczna.
 */
    Wektor3D operator [] (int i) const
    {
        assert(i >= 0 && i <= (int)wsp.size());
        return wsp[i];
    }

    ~Figura_geometryczna()
    {
      wsp.clear();
    }



};



