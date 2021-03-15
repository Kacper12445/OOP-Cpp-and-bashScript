#include <iostream>
#include "Prostopadloscian.hh"

#define DL_BOKU 50

using namespace std;


/*!
 * \file
 * \brief Definicje metod klasy Prostopadloscian.
 *
 * Zawiera definicje metod klasy Prostopadloscian
 *
 */



/*!
 *  Implementacja przeciazenia przesuniecia bitowego w lewo dla klasy Prostopadloscian.
 *  Pelny opis zostal zawarty w pliku naglowkowym \link Prostopadloscian.hh\endlink.
 */
ostream& operator << (ostream &Strm, const Prostopadloscian &Pr)
{
    Wektor3D w1,w2;
    w1[0]=w1[1]=0;
    w1[2]=5;
    w2[0]=w2[1]=0;
    w2[2]=-5;


    for(int i=0;i<(int)Pr.wsp.size()-2;i+=2)
    {
        Strm << Pr[8] << Pr[i] << Pr[i+1] << Pr[9];
        if(i%2 == 0)
            Strm << endl;
    }

        Strm << Pr[8] << Pr[0] << Pr[1] << Pr[9];

    return Strm;
}


/*!
 *  Implementacja konstruktora z jednym parametrem dla klasy Prostopadloscian.
 *
 *  Kolejnym punktom przypisywane sa odpowiednie wspolrzedne w celu poprawnego narysowania
 *  prostopadloscianu prze program GNUPlot.
 */
Prostopadloscian::Prostopadloscian(Wektor3D prz)
{
    Wektor3D wek;
    wek[0] = 100 + prz[0];
    wek[1] = 100 + prz[1];
    wek[2] = 5 + prz[2];
    wsp.push_back(wek);

    wek[0] =100 + prz[0];
    wek[1] =100 + prz[1];
    wek[2] =-5 + prz[2];
    wsp.push_back(wek);

    wek[0] = 120 + prz[0];
    wek[1] = 100 + prz[1];
    wek[2] = 5 + prz[2];
    wsp.push_back(wek);

    wek[0] = 120 + prz[0];
    wek[1] = 100 + prz[1];
    wek[2] = -5 + prz[2];
    wsp.push_back(wek);

    wek[0] = 120 + prz[0];
    wek[1] = 76 + prz[1];
    wek[2] = 5 + prz[2];
    wsp.push_back(wek);

    wek[0] = 120 + prz[0];
    wek[1] = 76 + prz[1];
    wek[2] = -5 + prz[2];
    wsp.push_back(wek);

    wek[0] = 100 + prz[0];
    wek[1] = 76 + prz[1];
    wek[2] = 5 + prz[2];
    wsp.push_back(wek);

    wek[0] = 100 + prz[0];
    wek[1] = 76 + prz[1];
    wek[2] = -5 + prz[2];
    wsp.push_back(wek);

    wek[0] = 110 + prz[0];
    wek[1] = 88 + prz[1];
    wek[2] = 5 + prz[2];
    wsp.push_back(wek);

    wek[0] = 110 + prz[0];
    wek[1] = 88 + prz[1];
    wek[2] = -5 + prz[2];
    wsp.push_back(wek);
}



