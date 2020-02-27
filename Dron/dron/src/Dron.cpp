#include "Dron.hh"
#include <vector>
#include <string>
#include <cmath>

#define ODL_Z 15
#define ODL_XY 47.241

/*!
 * \file
 * \brief Definicje metod klasy Dron.
 *
 * Zawiera definicje metod klasy Dron
 *
 */


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - instancja szablonu klasy Wektor<>
 * \param[in] &F - referencja do obiektu klasy Prostopadloscian
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void Dron::PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy, Wektor3D &Przesuniecie, Prostopadloscian &F)
{
    for(int i=0; i<10; i++)
        F[i] = F[i] + Przesuniecie;

    StrmWy << F << endl;
}


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] M - instancja szablonu klasy Macierz<>
 * \param[in] &F - referencja do obiektu klasy Prostopadloscian
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void Dron::PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy, Macierz3x3 M, Wektor3D &Przesuniecie, Prostopadloscian &F)
{
    for(int i=0; i<10; i++)
        F[i] = F[i] - Przesuniecie;

    for(int i=0; i<10; i++)
        F[i] = M*F[i];

    for(int i=0; i<10; i++)
        F[i] = F[i] + Przesuniecie;

    StrmWy << F << endl;
}


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - instancja szablonu klasy Wektor<>
 * \param[in] &F - referencja do obiektu klasy Prostopadloscian
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Dron::PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Wektor3D &Przesuniecie, Prostopadloscian &F)
{
    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
             << ":(  nie powiodla sie." << endl;
        return false;
    }

    PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,Przesuniecie,F);

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] M - instancja szablonu klasy Macierz<>
 * \param[in] &F - referencja do obiektu klasy Prostopadloscian
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Dron::PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Macierz3x3 M, Wektor3D &Przesuniecie, Prostopadloscian &F)
{
    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
             << ":(  nie powiodla sie." << endl;
        return false;
    }

    PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,M,Przesuniecie,F);

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}





/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - instancja szablonu klasy Wektor<>
 * \param[in] &F - referencja do obiektu klasy Graniastoslup
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void Dron::PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy, Wektor3D &Przesuniecie, Graniastoslup &F)
{
    for(int i=0; i<14; i++)
        F[i] = F[i] + Przesuniecie;

    StrmWy << F << endl;
}


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] M - instancja szablonu klasy Macierz<>
 * \param[in] &F - referencja do obiektu klasy Graniastoslup
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void Dron::PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy, Macierz3x3 &M, Wektor3D &Przesuniecie, Graniastoslup &F)
{
    for(int i=0; i<14; i++)
        F[i] = F[i] - Przesuniecie;

    for(int i=0; i<14; i++)
        F[i] = M*F[i];

    for(int i=0; i<14; i++)
        F[i] = F[i] + Przesuniecie;

    StrmWy << F << endl;
}


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - instancja szablonu klasy Wektor<>
 * \param[in] &F - referencja do obiektu klasy Graniastoslup
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Dron::PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Wektor3D &Przesuniecie, Graniastoslup &F)
{
    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
             << ":(  nie powiodla sie." << endl;
        return false;
    }

    PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,Przesuniecie,F);

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] M - instancja szablonu klasy Macierz<>
 * \param[in] &F - referencja do obiektu klasy Graniastoslup
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Dron::PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Macierz3x3 &M, Wektor3D &Przesuniecie, Graniastoslup &F)
{
    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
             << ":(  nie powiodla sie." << endl;
        return false;
    }

    PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,M,Przesuniecie,F);

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}




/*!
 * Metoda ta ma na celu wyrysowanie drona za pomoca programu GNUPlot.
 */
int Dron::Inicjalizuj(int ind, PzG::LaczeDoGNUPlota  &Lacze)
{

    ustaw_index(ind);
    pliki.push_back("dat/prostopadloscian0"+to_string(index)+".dat");
    pliki.push_back("dat/graniastoslup0"+to_string(index)+".dat");
    pliki.push_back("dat/graniastoslup1"+to_string(index)+".dat");
    pliki.push_back("dat/graniastoslup2"+to_string(index)+".dat");
    pliki.push_back("dat/graniastoslup3"+to_string(index)+".dat");


    for(int i=0;i<(int)pliki.size();i++)
    Lacze.DodajNazwePliku(&pliki[i][0],PzG::RR_Ciagly,2);


    Wektor3D w1;
    w1[0] = 0;
    w1[1] = 0;
    w1[2] = 0;


    int k=0;
    for(int i=0; i<4; i++)
    {
        Gr[i].ustaw(Pr[k]);
        k+=2;
    }

    //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
    //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
    //  na dwa sposoby:
    //   1. Rysowane jako linia ciagl o grubosci 2 piksel
    //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
    //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
    //  jako wspolrzedne punktow podajemy x,y,z.

    if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[0][0],w1,Pr)) return 1;  // rysowanie korpusu Drona


    for(int i=1; i<5; i++)
    {
       
        if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[i][0],w1,Gr[i-1])) return 1;
        
    }
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

    return 0;

}


/*!
 * Metoda ta ma na celu translacje Drona o zadany wektor przemieszczenia.
 * \param[in] &Lacze - referencja do lacza przestrzeni nazw PzG::LaczeDoGNUPlota
 */
int Dron::Translacja(PzG::LaczeDoGNUPlota  &Lacze, double kat_wznoszenia, double droga)
{
    double x,y,z;
    double kat_ob;
    double kat_wzn;

    Wektor3D w1;
    w1[0] = 0;
    w1[1] = 0;
    w1[2] = 0;
    Wektor3D w2;
    Wektor3D wp[4];
            

            M_obrotu2[0].set_rad(3);
            M_obrotu2[0].przelicz();
            M_obrotu2[1].set_rad(-3);
            M_obrotu2[1].przelicz();

            kat_wzn = kat_wznoszenia*M_PI/180;
            kat_ob = suma_kat_obrotu*M_PI/180;
            x = droga*sin(fabs(kat_ob))*cos(fabs(kat_wzn));
            y = droga*cos(fabs(kat_ob))*cos(fabs(kat_wzn));
            z = droga*sin(fabs(kat_wzn));

           
           for(int i=0; i<4; i++)
    {
        wp[i][0] = Gr[i][13][0];    // obliczanie srodka ciezkosci kazdego rotora Drona
        wp[i][1] = Gr[i][13][1];
        wp[i][2] = Gr[i][13][2] + 2.5;
    }


            if(kat_wznoszenia >= 0 && kat_obrotu >= 0)
            {
                w1[0] = -x;
                w1[1] = y;
                w1[2] = z;
            }

            else if(kat_wznoszenia >= 0 && kat_obrotu < 0)
            {
                w1[0] = x;
                w1[1] = y;
                w1[2] = z;
            }

            else if(kat_wznoszenia < 0 && kat_obrotu >= 0)
            {
                w1[0] = -x;
                w1[1] = y;
                w1[2] = -z;
            }

            else if(kat_wznoszenia < 0 && kat_obrotu < 0)
            {
                w1[0] = x;
                w1[1] = y;
                w1[2] = -z;                
            }



            w2[0] =  w1[0]/100;
            w2[1] =  w1[1]/100;
            w2[2] =  w1[2]/100;
            wek_ciezkosci = wek_ciezkosci + w2;
            wek_ob = wek_ob +w2;


           
                if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[0][0],w2,Pr)) return 1;

                for(int j=1; j<5; j++)
                {
         
                    wp[j-1][0] = wp[j-1][0] + w2[0];
                    wp[j-1][1] = wp[j-1][1] + w2[1];
                    wp[j-1][2] = wp[j-1][2] + w2[2];
                    if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[j][0],w2,Gr[j-1])) return 1;
                    if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[j][0],M_obrotu2[(j-1)%2],wp[j-1],Gr[j-1])) return 1;

                    wp[j-1][0] = Gr[j-1][13][0];
                    wp[j-1][1] = Gr[j-1][13][1];
                    wp[j-1][2] = Gr[j-1][13][2] + 2.5;

                }

                


                Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                usleep(27000);
            

	return 0;

}



/*!
 * Metoda ta ma na celu rotacje Drona o zadany kat.
 * \param[in] &Lacze - referencja do lacza przestrzeni nazw PzG::LaczeDoGNUPlota
 */
int Dron::Rotacja(PzG::LaczeDoGNUPlota  &Lacze)
{
    M_obrotu2[0].set_rad(3);
    M_obrotu2[0].przelicz();
    M_obrotu2[1].set_rad(-3);
    M_obrotu2[1].przelicz();

    Macierz3x3 M_szyb[2];    // obroty do przodu
    M_szyb[0].set_rad(1);
    M_szyb[0].przelicz();
    M_szyb[1].set_rad(6);
    M_szyb[1].przelicz();

    Macierz3x3 M_szyb2[2];  // obrotu do tylu
    M_szyb2[0].set_rad(-1);
    M_szyb2[0].przelicz();
    M_szyb2[1].set_rad(-6);
    M_szyb2[1].przelicz();

    Wektor3D wp[4];
  


    for(int i=0; i<4; i++)
    {
        wp[i][0] = Gr[i][13][0];    // obliczanie srodka ciezkosci kazdego rotora Drona
        wp[i][1] = Gr[i][13][1];
        wp[i][2] = Gr[i][13][2] + 2.5;
    }

            if(kat_obrotu > 0)
            {
                M_obrotu.set_rad(1);
                M_obrotu.przelicz();

                
                    if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[0][0],M_obrotu,wek_ob,Pr)) return 1;   // obrot prostopadloscianu wokol wlasnej osi

                    for(int j=1; j<5; j++)
                    {

                        if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[j][0],M_szyb[(j-1)%2],wp[j-1],Gr[j-1])) return 1;    // obrot rotora wokol wlasnej osi
                        if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[j][0],M_obrotu,wek_ob,Gr[j-1])) return 1;         // obrot rotora wokol osi korpusu


                        wp[j-1][0] = Gr[j-1][13][0];
                        wp[j-1][1] = Gr[j-1][13][1];
                        wp[j-1][2] = Gr[j-1][13][2] + 2.5;

                    }


                    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                    usleep(30000);
                

            }
            else
            {
                M_obrotu.set_rad(-1);
                M_obrotu.przelicz();

                    if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[0][0],M_obrotu,wek_ob,Pr)) return 1;

                    for(int j=1; j<5; j++)
                    {

                        if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[j][0],M_szyb2[(j-1)%2],wp[j-1],Gr[j-1])) return 1;    // obrot rotora wokol wlasnej osi
                        if (!PrzykladZapisuWspolrzednychDoPliku(&pliki[j][0],M_obrotu,wek_ob,Gr[j-1])) return 1;         // obrot rotora wokol osi korpusu


                        wp[j-1][0] = Gr[j-1][13][0];
                        wp[j-1][1] = Gr[j-1][13][1];
                        wp[j-1][2] = Gr[j-1][13][2] + 2.5;

                    }

                    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                    usleep(30000);

                
            }
         
            return 0;
}



/*!
 * Metoda ta ma na celu wykrywanie kolizji drona z innym dronem
 * \param[in] Ob - wskaznik na obiekt klasy Dron
 * \retval true - gdy wykryto kolizje
 * \retval false - w przypadku przeciwnym.
 */
bool Dron::CzyKolizja(const shared_ptr<Dron> Ob) const
{
    double odleglosc_xy;
    odleglosc_xy = sqrt(pow((this->wek_ciezkosci[0] - Ob->wek_ciezkosci[0]),2) + pow((this->wek_ciezkosci[1] - Ob->wek_ciezkosci[1]),2));
    double odleglosc_z;
    odleglosc_z = fabs(this->wek_ciezkosci[2] - Ob->wek_ciezkosci[2]);

    if(odleglosc_xy <= ODL_XY && odleglosc_z <= ODL_Z + 2)
    {
        cout << " KOLIZJA Z INNYM DRONEM!" << endl;
        cout << " RUCH DRONA ZATRZYMANY" << endl;
        return true;
    }
        

    return false;   
}



