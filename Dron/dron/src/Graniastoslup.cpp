#include "Graniastoslup.hh"
#include <cmath>

#define DL_PRZEKATNEJ 8

/*!
 * \file
 * \brief Definicje metod klasy Graniastoslup.
 *
 * Zawiera definicje metod klasy Graniastoslup
 *
 */



/*!
 *  Implementacja przeciazenia przesuniecia bitowego w lewo dla klasy Graniastoslup.
 *  Pelny opis zostal zawarty w pliku naglowkowym \link Graniastoslup.hh\endlink.
 */
ostream& operator << (ostream &Strm, const Graniastoslup &Gr)
{
    for(int i=0;i<(int)Gr.wsp.size()-2;i+=2)
    {
        Strm << Gr[12] << Gr[i] << Gr[i+1] << Gr[13];
        if(i%2 == 0)
            Strm << endl;
    }

	Strm << Gr[12] << Gr[0] << Gr[1] << Gr[13];

    return Strm;
}

/*!
 *  Implementacja konstruktora z jednym parametrem dla klasy Graniastoslup.
 *
 *  param[in] w - wektor poczatkowy opisujacy polozenie pierwszego punktu
 *                   prostopadloscianu. Kolejne punkty sa rysowane w oparciu o podany wektor.
 *
 *  Kolejnym punktom przypisywane sa odpowiednie wspolrzedne w celu poprawnego narysowania
 *  graniastoslupu prze program GNUPlot.
 */

void Graniastoslup::ustaw(Wektor3D w)
{
	Wektor3D wek;

	for(int i=0;i>=-300;i-=60)
	{
		wek[0] = w[0] + DL_PRZEKATNEJ*cos(i*M_PI/180);
		wek[1] = w[1] + DL_PRZEKATNEJ*sin(i*M_PI/180);
		wek[2] = w[2] + 5;
		wsp.push_back(wek);

		wek[0] = w[0] + DL_PRZEKATNEJ*cos(i*M_PI/180);
		wek[1] = w[1] + DL_PRZEKATNEJ*sin(i*M_PI/180);
		wek[2] = w[2];
		wsp.push_back(wek);
	}

	wek[0] = w[0];
	wek[1] = w[1];
	wek[2] = w[2] + 5;
	wsp.push_back(wek);

	wek[0] = w[0];
	wek[1] = w[1];
	wek[2] = w[2];
	wsp.push_back(wek);
}

