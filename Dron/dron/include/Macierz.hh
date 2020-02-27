#ifndef MACIERZ_HH
#define MACIERZ_HH
#include "Wektor3D.hh"
#include <cmath>
#include <iostream>
#include <assert.h>

using namespace std;


/*!
 * \file
 * \brief Ten plik zawiera definicję szablonu Macierz<>.
 *
 *  Zawiera ponadto implementacje odpowiednich metod i przeciazen opeartorow dzialajacych na obiektach szablonu
 *  klasy Macierz<>.
 */


/*!
 * \brief Definicja szablonu klasy Macierz<>.
 *
 *  Szablon ten modeluje pojecie macierzy obrotu o zmiennym rozmiarze.
 *  Wymiar jest okreslany poprzez liczbe calkowita podana jako argument podczas tworzenia instancji tego szablonu.
 *  Macierz jest reprezentowana poprzez tablice instancji szablonu klasy Wektor<> oraz pole "rad" typu
 *  double, ktore przechowuje kat obrotu wyrazony w radianach.
 *
 */
template <int Wymiar>
class Macierz
{
    Wektor<Wymiar> w[Wymiar];
    double rad;


public:
    Wektor<Wymiar> operator * (Wektor<Wymiar> w) const;

/*!
 *  \brief Definicja i implementacja przeciazenia operatora indeksujacego.
 *
 *  param[in] i - zmienna typu int pozwalajaca na poruszanie sie po tablicy wspolrzednych wektora.
 *
 *  Dzieki temu opeartorowi mozliwa jest modyfikacja pol instancji szablomu klasy Macierz<>.
 *
 *  \return Zwraca referencje do odpowiedniego pola instancji szablomu klasy Wektor<>, wchodzacego w sklad
 *  szablonu klasy Macierz<>.
 *
 */
    Wektor<Wymiar> &operator [] (int i)
    {
        assert(i >= 0 && i < Wymiar);
        return w[i];
    }

/*!
 *  \brief Definicja i implementacja przeciazenia operatora indeksujacego.
 *
 *  param[in] i - zmienna typu int pozwalajaca na poruszanie sie po tablicy wspolrzednych wektora.
 *
 *  Przeciazenie tego operatora nie umozliwia modyfikacji pol instancji szablomu klasy Macierz<>.
 *
 *  \return Zwraca odpowiednia wartosc pola instancji szablomu klasy Macierz<>.
 */
    Wektor<Wymiar> operator [] (int i) const
    {
        assert(i >= 0 && i < Wymiar);
        return w[i];
    }

    void przelicz();
    void set_rad(double r);
    Macierz<Wymiar> operator * (Macierz<Wymiar> M1) const;
};



/*!
 * \brief Przeciążenie dla wyjścia także jest szablonem.
 *
 *  Przeciazenie to pozwala wypisac na standardowe wyjscie macierzy obrotu, ktore
 *  zrealizowane jest dzieki przeciazeniu operatora przesuniecia bitowego w lewo dla
 *  szablonu klasy Wektor<>.
 *
 *  \param[in] &Strm - referencja do strumienia wyjsciowego
 *  \param[in] &Wek - referencja do instancji szablonu klasy Wektor<>, ktorej nie mozna modyfikowac
 *
 *  \return Zwraca referencje do strumienia wyjsciowego.
 *
 */
template <int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Macierz<Wymiar> &Wek)
{
    for(int i=0; i<Wymiar; i++)
        Strm << Wek[i] << endl;
    return Strm;
}




/*!
 * Przeciazenie operatora mnozenia macierzy przez wektor.
 *
 * \param[in] wek - instancja szablonu klasy Wektor<>.
 *
 *  \return Zwraca wektor bedacy iloczynem macierzy i wektora: wektora podanego
 *  w argumencie wywolania metody oraz
 *  macierzy, na ktorej zostala wywolana ta metoda.
 */
template<int Wymiar>
Wektor<Wymiar> Macierz<Wymiar>::operator * (Wektor<Wymiar> wek) const
{
    Wektor<Wymiar> w1;
    for(int i=0; i<Wymiar; i++)
        w1[i] = w[i]*wek;

    return w1;
}


/*!
 *  Metoda "set_rad" przelicza stopnie na radiany i zapisuje je w polu prywatnym macierzy "rad".
 *
 * \param[in] r - wartosc kata w stopniach.
 *
 *  \return Metoda ta jest typu void.
 */
template<int Wymiar>
void Macierz<Wymiar>::set_rad (double r)
{
    rad = (r*M_PI)/180;
}



/*!
 *  Metoda "przelicz" wylicza odpowiednie wartosci funkcji trygonometrycznych sinus i cosinus oraz zapisuje je
 *  w odpowiednich polach macierzy obrotu. Metoda ta zostala zaimplementowana dla macierzy obrotu w trzech
 *  wymiarach ( dla osi x, y, z).
 *
 * \param[in] q - zmienna typu char reprezentujaca obrot wokol konkretnej osi (x, y, z). .
 *
 *  \return Metoda ta jest typu void.
 */
template<int Wymiar>
void Macierz<Wymiar>::przelicz()
{
        w[0][0] = cos(rad);
        w[0][1] = -sin(rad);
        w[0][2] = w[1][2] = w[2][0] = w[2][1] = 0;
        w[1][0] = sin(rad);
        w[1][1] = cos(rad);
        w[2][2] = 1;
}



/*!
 * Przeciazenie operatora mnozenia macierzy przez macierz.
 *
 * \param[in] M1 - instancja szablonu klasy Macierz<>.
 *
 *  Mnozenie macierzy jest wykorzystywane przy skladaniu obrotow w czasie pracy programu.
 *
 *  \return Zwraca macierz bedaca iloczynem dwoch macierzy: macierzy podanej w argumencie wywolania metody oraz
 *  macierzy, na ktorej zostala wywolana ta metoda.
 */
template<int Wymiar>
Macierz<Wymiar> Macierz<Wymiar>::operator * (Macierz<Wymiar> M1) const
{
    Macierz<Wymiar> M;
    double s;

    for(int i=0; i<Wymiar; i++)
    {
        for(int j=0; j<Wymiar; j++)
        {
            s = 0;
            for(int k=0; k<Wymiar; k++)
                s = s + w[i][k] * M1[k][j];
            M[i][j] = s;
        }
    }

    return M;
}

#endif
