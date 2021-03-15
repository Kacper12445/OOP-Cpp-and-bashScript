#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <iomanip>
#include <cmath>
#include <assert.h>

using namespace std;

/*!
 * \file
 * \brief Ten plik zawiera definicję szablonu Wektor<>.
 *
 *  Zawiera ponadto implementacje odpowiednich metod i przeciazen opeartorow dzialajacych na obiektach szablonu
 *  klasy Wektor<>.
 */


/*!
 * \brief Definicja szablonu klasy Wektor<>.
 *
 *  Szablon ten modeluje pojecie wektora w przestrzeni o zmiennym rozmiarze.
 *  Wymiar jest okreslany poprzez liczbe calkowita podana jako argument podczas tworzenia instancji tego szablonu.
 *  Wektor jest reprezentowany poprzez tablice liczb typu double.
 *
 */
template <int Wymiar>
class Wektor
{
    double wsp[Wymiar];


public:

    static int ilosc_istniejacych;
    static int ilosc_tymczasowa;
    Wektor<Wymiar> operator + (Wektor<Wymiar> v) const;
    Wektor<Wymiar> operator - (Wektor<Wymiar> v) const;
    double operator * (Wektor<Wymiar> w) const;
    double dlugosc(Wektor<Wymiar> *w) const;

/*!
 *  \brief Definicja i implementacja przeciazenia operatora indeksujacego.
 *
 *  param[in] i - zmienna typu int pozwalajaca na poruszanie sie po tablicy wspolrzednych wektora.
 *
 *  Dzieki temu opeartorowi mozliwa jest modyfikacja pol instancji szablomu klasy Wektor<>.
 *
 *  \return Zwraca referencje do odpowiedniego pola instancji szablomu klasy Wektor<>.
 */
    double &operator [] (int i)
    {
        assert(i >= 0 && i < Wymiar);
        return wsp[i];
    }

/*!
 *  \brief Definicja i implementacja przeciazenia operatora indeksujacego.
 *
 *  param[in] i - zmienna typu int pozwalajaca na poruszanie sie po tablicy wspolrzednych wektora.
 *
 *  Przeciazenie tego operatora nie umozliwia modyfikacji pol instancji szablomu klasy Wektor<>.
 *
 *  \return Zwraca odpowiednia wartosc pola instancji szablomu klasy Wektor<>.
 */
    double operator [] (int i) const
    {
        assert(i >= 0 && i < Wymiar);
        return wsp[i];
    }


/*!
 *  Implementacja konstruktora bezparametrycznego dla klasy Wektor.
 *  Konstruktor ten ma na celu inkrementacje dwoch zmiennych statycznych, ktore sa odpowiedzialne za zliczanie istniejacyh obiektow klasy Wektor.
 *
 */
    Wektor()
    {
        ilosc_istniejacych++;
        ilosc_tymczasowa++;
    }


/*!
 *  Implementacja destruktora bezparametrycznego dla klasy Wektor.
 *  Destruktor ten ma na celu dekrementacje zmiennej statycznej, ktora jest odpowiedzialn za przechwowywanie liczby tymczasowo istniejacych obiektow klasy Wektor.
 *
 */
     ~Wektor()
    {
        ilosc_tymczasowa--;
    }

    Wektor(const Wektor& wek)
    {
        ilosc_tymczasowa++;
        for(int i=0;i<Wymiar;i++)
		    wsp[i] = wek.wsp[i];
    }

    Wektor& operator = (const Wektor& wek)
    {
        for(int i=0;i<Wymiar;i++)
            wsp[i] = wek.wsp[i];

        return *this;
    }

};

template <int Wymiar>
int Wektor<Wymiar>::ilosc_istniejacych = 0;

template <int Wymiar>
int Wektor<Wymiar>::ilosc_tymczasowa = 0;


/*!
 * \brief Przeciążenie dla wejścia także jest szablonem.
 *
 *  Przeciazenie to pozwala wczytac ze standardowego wejscia wektor przesuniecia punktu w przestrzeni 3D.
 *  Wczytywane sa kolejno po sobie wspolrzedne punktu przy pomocy operatora indeksujacego.
 *
 *  \param[in] &Strm - referencja do strumienia wejsciowego
 *  \param[in] &Wek - referencja do instancji szablonu klasy Wektor<>, ktora mozna modyfikowac
 *
 *  \return Zwraca referencje do strumienia wejsciowego.
 *
 */
template <int Wymiar>
inline
std::istream& operator >> (std::istream &Strm, Wektor<Wymiar> &Wek)
{
    for(int i=0; i<Wymiar; i++)
        Strm >> Wek[i];

    return Strm;
}




/*!
 * \brief Przeciążenie dla wyjścia także jest szablonem.
 *
 *  Przeciazenie to pozwala wypisac na standardowe wyjscie (lub zapisac do pliku) wektor
 *  przesuniecia punktu w przestrzeni 3D.
 *  Wypisywane sa kolejno po sobie wspolrzedne punktu przy pomocy operatora indeksujacego.
 *
 *  \param[in] &Strm - referencja do strumienia wyjsciowego
 *  \param[in] &Wek - referencja do instancji szablonu klasy Wektor<>, ktorej nie mozna modyfikowac
 *
 *  \return Zwraca referencje do strumienia wyjsciowego.
 *
 */
template <int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Wektor<Wymiar> &Wek)
{
    for(int i=0; i<Wymiar; i++)
        Strm << Wek[i] << " ";
    Strm << std::endl;

    return Strm;
}




/*!
 * Przeciazenie operatora dodawania dwoch wektorow.
 *
 * \param[in] v - instancja szablonu klasy Wektor<>.
 *
 *  \return Zwraca wektor bedacy suma wektorow: wektora podanego w argumencie wywolania metody oraz
 *  wektora, na ktorym zostala wywolana ta metoda.
 */
template<int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator + (Wektor<Wymiar>  v) const
{
    Wektor<Wymiar> v1;
    for(int i=0; i<Wymiar; i++)
        v1[i] = wsp[i] + v[i];
    return v1;
}


/*!
 * Przeciazenie operatora odejmowania dwoch wektorow.
 *
 * \param[in] v - instancja szablonu klasy Wektor<>.
 *
 *  \return Zwraca wektor bedacy roznica wektorow: wektora podanego w argumencie wywolania metody oraz
 *  wektora, na ktorym zostala wywolana ta metoda.
 */
template<int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator - (Wektor<Wymiar> v) const
{
    Wektor<Wymiar> v1;
    for(int i=0; i<Wymiar; i++)
        v1[i] = wsp[i] - v[i];
    return v1;
}



/*!
 * Przeciazenie operatora mnozenia skalarnego dwoch wektorow.
 *
 * \param[in] w - instancja szablonu klasy Wektor<>.
 *
 *  \return Zwraca liczbe typu double bedaca iloczynem wektorow: wektora podanego w argumencie wywolania metody
 *  oraz wektora, na ktorym zostala wywolana ta metoda.
 *
 */
template<int Wymiar>
double Wektor<Wymiar>::operator * (Wektor<Wymiar> w) const
{
    double a = 0;
    for(int i=0; i<Wymiar; i++)
        a += wsp[i]*w[i];

    return a;
}



/*!
 * Oblicza dlugosc wektora
 *
 *  \param[in] *w - wskaznik na instancje szablonu klasy Wektor<>.
 *
 *  Wskaznik zostal uzyty w celu lepszego poruszania sie po tablcy wektorow, ktora wchodzi w sklad
 *  klasy Prostopadloscian, co jest juz pewna konkretyzacja tej metody.
 *
 *  \return Zwraca liczbe typu double bedaca pierwiastkiem kwadratowym z sumy roznic poszczegolnych
 *  wspolrzednych dwoch wektorow: wektora podanego w argumencie wywolania metody jako wskaznik na niego
 *  oraz wektora, na ktorym zostala wywolana ta metoda.
 *
 */
template<int Wymiar>
double Wektor<Wymiar>::dlugosc(Wektor<Wymiar> *w) const
{
    double tab[Wymiar];
    double a = 0;

    for(int i=0; i<Wymiar; i++)
        tab[i] = wsp[i] - w->wsp[i];

    for(int i=0; i<Wymiar; i++)
        a += pow(tab[i],2);
    return sqrt(a);
}


#endif
