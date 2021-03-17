#include "PrzeszkodaPr.hh"

#include <memory>

#define OBRYS_POZ 23.6205
#define OBRYS_PION 7.5

/*!
 * \file
 * \brief Definicje metod klasy PrzeszkodaPr.
 *
 * Zawiera definicje metod klasy PrzeszkodaPr
 *
 */


/*!
 *  Implementacja konstruktora z jednym parametrem dla klasy PrzeszkodaPr.
 *  KolejDron punktom przypisywane sa odpowiednie wspolrzedne wraz z odpowiednim przesunieciem podanym
 *  w argumencie konstruktora, jako wektor, w celu poprawnego narysowania
 *  przeszkody prostopadlosciennej przez program GNUPlot.
 */
PrzeszkodaPr::PrzeszkodaPr(Wektor3D przesun)
{
    Wektor3D wek;
    wek[0] = 100 + przesun[0];
    wek[1] = 100 + przesun[1];
    wek[2] = 5 + przesun[2];
    wsp.push_back(wek);

    wek[0] =100 + przesun[0];
    wek[1] =100 + przesun[1];
    wek[2] =-5 + przesun[2];
    wsp.push_back(wek);

    wek[0] = 120 + przesun[0];
    wek[1] = 100 + przesun[1];
    wek[2] = 5 + przesun[2];
    wsp.push_back(wek);

    wek[0] = 120 + przesun[0];
    wek[1] = 100 + przesun[1];
    wek[2] = -5 + przesun[2];
    wsp.push_back(wek);

    wek[0] = 120 + przesun[0];
    wek[1] = 76 + przesun[1];
    wek[2] = 5 + przesun[2];
    wsp.push_back(wek);

    wek[0] = 120 + przesun[0];
    wek[1] = 76 + przesun[1];
    wek[2] = -5 + przesun[2];
    wsp.push_back(wek);

    wek[0] = 100 + przesun[0];
    wek[1] = 76 + przesun[1];
    wek[2] = 5 + przesun[2];
    wsp.push_back(wek);

    wek[0] = 100 + przesun[0];
    wek[1] = 76 + przesun[1];
    wek[2] = -5 + przesun[2];
    wsp.push_back(wek);

    wek[0] = 110 + przesun[0];
    wek[1] = 88 + przesun[1];
    wek[2] = 5 + przesun[2];
    wsp.push_back(wek);

    wek[0] = 110 + przesun[0];
    wek[1] = 88 + przesun[1];
    wek[2] = -5 + przesun[2];
    wsp.push_back(wek);

    obrys_x[0] = wsp[8][0] + OBRYS_POZ + 10;
    obrys_x[1] = wsp[8][0] - OBRYS_POZ - 10;
    obrys_y[0] = wsp[8][1] + OBRYS_POZ + 12;
    obrys_y[1] = wsp[8][1] - OBRYS_POZ - 12;
    obrys_z[0] = wsp[8][2] + OBRYS_PION;
    obrys_z[1] = wsp[8][2] - OBRYS_PION - 10;
}




/*!
 * Metoda ta ma na celu wyrysowanie przeszkody prostopadlosciennej za pomoca programu GNUPlot.
 */
int PrzeszkodaPr::Inicjalizuj(int ind, PzG::LaczeDoGNUPlota  &Lacze)
{
    pliki.push_back("dat/przeszkodaPr"+to_string(ind-1)+".dat");


    Lacze.DodajNazwePliku(&pliki[0][0],PzG::RR_Ciagly,2);


    for(int i=0;i<10;i++)
    {
        wsp[i][2] = wsp[i][2]*(ind-1);

    }

        obrys_z[1] = wsp[8][2] - OBRYS_PION - 10*(ind-1);

    if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[0][0])) return 1;
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

	return 0;
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] Strm - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzeszkodaPr::PrzykladZapisuWspolrzednychDoStrumienia( ostream& Strm)
{
    for(int i=0;i<(int)wsp.size()-2;i+=2)
    {
        Strm << wsp[8] << wsp[i] << wsp[i+1] << wsp[9];
        if(i%2 == 0)
            Strm << endl;
    }

        Strm << wsp[8] << wsp[0] << wsp[1] << wsp[9];


}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzeszkodaPr::PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku)
{
    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);

    if (!StrmPlikowy.is_open())
    {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
             << ":(  nie powiodla sie." << endl;
        return false;
    }

    PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy);

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}



/*!
 * Metoda ta ma na celu wykrywanie kolizji drona z przeszkoda prostopadloscienna.
 * \param[in] Ob - wskaznik na obiekt klasy Dron
 * \retval true - gdy wykryto kolizje
 * \retval false - w przypadku przeciwnym.
 */
bool PrzeszkodaPr::CzyKolizja(const shared_ptr<Dron> Ob) const
{
    Wektor3D wek;
    wek = Ob->get_srodek();

    if(wek[0] > obrys_x[1] && wek[0] < obrys_x[0] && wek[1] > obrys_y[1] && wek[1] < obrys_y[0] )// wek[2] > obrys_z[1] && wek[2] < obrys_z[0])
    {

        cout << "KOLIZJA  Z PRZESZKODA!" << endl;
        cout << "RUCH DRONA ZATRZYMANY" << endl;
        return true;
    }

    return false;
}
