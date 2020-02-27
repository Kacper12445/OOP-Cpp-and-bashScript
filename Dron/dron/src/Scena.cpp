#include "Scena.hh"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"



/*!
 * \file
 * \brief Definicje metod klasy Scena.
 *
 * Zawiera definicje metod klasy Scena
 *
 */



/*!
 * Metoda ta ma na celu zainicjalizowanie trojwymiarowej sceny wraz z obiektami klasy Dron i PrzeszkodaPr.
 */
int Scena::Inicjalizuj(PzG::LaczeDoGNUPlota  &Lacze)
{
	Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

    Lacze.UstawZakresX(0, 200);
    Lacze.UstawZakresY(0, 200);
    Lacze.UstawZakresZ(-40, 90);


    Lacze.UstawRotacjeXZ(64,65); // Tutaj ustawiany jest widok

    //Dron Dron1(0,Lacze);
    
	//roboty.back().ustaw_index(0);

	//for( list<shared_ptr<Dron>>::iterator iter = roboty.begin(); /*warunek końca pętli*/( iter != roboty.end() ); iter++)
		//*roboty[0].ustaw_index(0);
        // cout << "dupa" << endl;
	//Dron1.ustaw_index(0);
    //Dron Dron2(70,Lacze);
    //Dron2.ustaw_index(1);

	//wsk = new PrzeszkodaPr(70);
    //wsk->Inicjalizuj(0,Lacze);
   

   // wsk1 = new PrzeszkodaPr(-10);
    //wsk1->Inicjalizuj(1,Lacze);

    //Dron Dron3(40,Lacze);
    //Dron1.ustaw_index(2);

    //Dron1.Inicjalizuj();
    //Dron2.Inicjalizuj();
    //Dron3.Inicjalizuj();
	//obiekty[0]->Inicjalizuj();

	return 0;

}



/*!
 * Metoda ta ma na celu przeprowadzania konkretnych operacji na obiektach kalsy Dron, czyli translacji oraz rotacji. Zawiera zasadniczne 
 * menu calego programu.
 */
int Scena::Menu(PzG::LaczeDoGNUPlota &Lacze)
{
    Inicjalizuj(Lacze);
    int ind = 0;

    for(shared_ptr<ObiektSceny> i : obiekty)
    {
        i->Inicjalizuj(ind,Lacze);
        
        ind++;
    }
    
    

    char wybor;

    cout << " Dron narysowany :)" << endl;
    cout << " Menu programu:" << endl;
    cout << " o - obrot drona" << endl;
    cout << " j - lot na wprost" << endl;
    cout << " s - selekcja drona" << endl;
    cout << " w - wyswietl ponownie menu" << endl;
    cout << " k - koniec dzialania programu" << endl;
    cout << endl << " Twoj wybor (w - wyswietl menu) > ";
    cin >> wybor;
    cout << endl;

    while(wybor != 'k')
    {
        switch(wybor)
        {
            case 'o':
                double kat_obrotu;
                cout << " Podaj kat obrotu drona: ";
                cin >> kat_obrotu;
                akt_dron->set_kat(kat_obrotu);

                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << endl << "NIEPOPRAWNY ARGUMENT!" <<  endl << "Sprobuj jeszcze raz." << endl << endl;
                    cout << " Podaj kat obrotu drona: ";
                    cin >> kat_obrotu;
                    akt_dron->set_kat(kat_obrotu);
                }

			
                    for(int i=0; i<fabs(kat_obrotu); i++)
                    {
                        

                                       bool kolizja;
					

                        for(shared_ptr<ObiektSceny> i : obiekty)
                        {
                            if(i != akt_dron)
                            {
                                kolizja = i->CzyKolizja(akt_dron);
                                if(kolizja)
                                    break;
                            }
				
                        }

                       if(kolizja)
                            break;
                        akt_dron->Rotacja(Lacze);
                    }
                    
                    break;

            case 'j':
                double droga;
                double kat_wznoszenia;
    

                cout << "Podaj dlugosc drogi przelotu i kat wznoszena (+)/ opadania (-)." << endl;
                cout << "Dlugosc drogi: ";
                cin >> droga;
                cout << endl;

                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << endl << "NIEPOPRAWNY ARGUMENT!" <<  endl << "Sprobuj jeszcze raz." << endl << endl;
                    cout << "Dlugosc drogi: ";
                    cin >> droga;
                    cout << endl;
                }

                cout << "Kat wznoszenia/opadania [stopnie]: ";
                cin >> kat_wznoszenia;
                cout << endl;

                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << endl << "NIEPOPRAWNY ARGUMENT!" <<  endl << "Sprobuj jeszcze raz." << endl << endl;
                    cout << "Kat wznoszenia/opadania [stopnie]: ";
                    cin >> kat_wznoszenia;
                    cout << endl;
                }
                    for(int i=0;i<100;i++)
                    {
                        

                                       bool kolizja;
					

                        for(shared_ptr<ObiektSceny> i : obiekty)
                        {
                            if(i != akt_dron)
                            {
                                kolizja = i->CzyKolizja(akt_dron);
                                if(kolizja)
                                    break;
                            }
				
                        }

                       if(kolizja)
                            break;

                        akt_dron->Translacja(Lacze, kat_wznoszenia, droga);
                    }
                       
                    break;


                case 's':
                    cout << " Aktualnie wyselekcjonowanym dronem jest:" << endl;
                    cout << " Dron " << akt_dron->get_index()+1 << "     ";
                    cout << " Wspolrzedne: " << akt_dron->get_srodek() << endl << endl;
                    cout << " 0 - zaniechaj zmiany selekcji" << endl << endl;

                    int liczba;

                    for(shared_ptr<Dron> i : roboty)
                        {
                            cout << " Dron " << i->get_index()+1 << "     ";
                            cout << " Wspolrzedne: " << i->get_srodek() << endl;
                        }

                    cout << " Podaj numer drona, dla ktorego maja byc wykonane operacje sterowania." << endl;
                    cout << " Wprowadz numer drona lub 0 > ";
                    cin >> liczba;

                    while(cin.fail() || (liczba > 3 && liczba < 0))
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << endl << " NIEPOPRAWNY ARGUMENT!" <<  endl << "Sprobuj jeszcze raz." << endl << endl;
                    cout << " Wprowadz numer drona lub 0 > ";
                    cin >> liczba;
                    cout << endl;
                }

                    for(shared_ptr<Dron> i : roboty)
                    {
                        if(i->get_index() == (liczba-1))
                            akt_dron = i;
                    }

                    break;

        }

        cout << endl << " Twoj wybor (w - wyswietl menu) > ";
        cin >> wybor;
        cout << endl;
    }
	return 0;


       
}
