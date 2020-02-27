#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "Figura_geometryczna.hh"
#include "lacze_do_gnuplota.hh"
#include <unistd.h>
#include <cmath>
#include <ctime>
#include <assert.h>
#include "ObiektSceny.hh"
#include <memory>




/*!
 * \file
 * \brief Ten plik zawiera definicję klasy Dron.
 *
 */


/*!
 * \brief Definicja klasy Dron.
 *
 *  Klasa ta modeluje pojecie pojecie drona w przestrzeni trojwymiarowej.
 *  Obiekt tej klasy jest reprezentowany przez obiekt klasy Prostopadloscian, ktory modeluje pojecie korpusu drona oraz czteroelementowa tablice
 *  obiektow klasy Graniastoslup, ktore modeluja pojecie rotorow drona. Ponadto klasa Dron posiada rowniez zmienna potrzebna do wizualizacji jego ruchu przez program
 *  GNUPlot oraz macierz obrotu korpusu i macierze obrotu dla poszczegolnych rotorow. Klasa Dron posiada takze takie skladowe jak: indeks 
 *  Drona, pliki ze wspolrzednymi wierzcholkow szablonu vector<string>, kat obrotu oraz wektor srodka ciezkosci korpusu Drona.
 *  Odpowiednie metody klasy Dron zostaly szczegolowo opisane w pliku \link Dron.cpp \endlink
 *
 */
class Dron : public ObiektSceny{
    Prostopadloscian Pr;
    Graniastoslup Gr[4];
    Macierz3x3 M_obrotu;
    Macierz3x3 M_obrotu2[2];
    int index;
    vector<string> pliki;
    double kat_obrotu;
    double suma_kat_obrotu;
    Wektor3D wek_ob;
    Wektor3D wek_ciezkosci;

    public:
    Dron(Wektor3D przesun)
    :Pr(przesun)
    {
        this->kat_obrotu = 0;
        this->suma_kat_obrotu = 0;

        wek_ob[0] = 110 + przesun[0];    // srodek ciezkosci prostopadloscianu
        wek_ob[1] = 88 + przesun[1];
        wek_ob[2] = 0 + przesun[2];
        wek_ciezkosci[0] = 110 + przesun[0];   // srodek ciezkosci Drona, pomocny w wykrywaniu kolizji
        wek_ciezkosci[1] = 88 + przesun[1];
        wek_ciezkosci[2] = 2.5 + przesun[2];
        
    }
    
    Wektor3D get_srodek(){ return wek_ciezkosci; }
    void ustaw_index(int ind) { index = ind;}
    int Inicjalizuj(int ind, PzG::LaczeDoGNUPlota  &Lacze);
    int Menu();
    int Translacja(PzG::LaczeDoGNUPlota  &Lacze, double kat_wznoszenia, double droga);
    int Rotacja(PzG::LaczeDoGNUPlota  &Lacze);
    int get_index() { return index; } 
    void set_kat(double kat)
    {
        this->kat_obrotu = kat;
        suma_kat_obrotu+=kat*(-1);
    }

    void PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy, Wektor3D &Przesuniecie, Prostopadloscian &F);
    void PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy, Macierz3x3 M, Wektor3D &Przesuniecie, Prostopadloscian &F);
    bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Wektor3D &Przesuniecie, Prostopadloscian &F);
    bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Macierz3x3 M, Wektor3D &Przesuniecie, Prostopadloscian &F);
    void PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy, Wektor3D &Przesuniecie, Graniastoslup &F);
    void PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy, Macierz3x3 &M, Wektor3D &Przesuniecie, Graniastoslup &F);
    bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Wektor3D &Przesuniecie, Graniastoslup &F);
    bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Macierz3x3 &M, Wektor3D &Przesuniecie, Graniastoslup &F);
    bool CzyKolizja(const shared_ptr<Dron> Ob) const;

};
