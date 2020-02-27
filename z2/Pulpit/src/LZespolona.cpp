#include "LZespolona.hh"
#include <iostream>
#include <cmath>
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/*!
 * Realizuje odjecie dwoch liczb zespolonych.
 * Argumenty:
 *    Odj1 - pierwszy skladnik odejmowania,
 *    Odj2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona Odj1, LZespolona Odj2)
{
  LZespolona Wynik;

  Wynik.re = Odj1.re - Odj2.re;
  Wynik.im = Odj1.im - Odj2.im;
  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Cn1 - pierwszy skladnik mnozenia,
 *    Cn2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator * (LZespolona Cn1, LZespolona Cn2)
{
  LZespolona Wynik;

  Wynik.re = Cn1.re * Cn2.re - Cn1.im * Cn2.im;
  Wynik.im = Cn1.re * Cn2.im + Cn2.re * Cn1.im;
  return Wynik;
}

/*!
 * Realizuje przesuniecie bitowe w lewo.
 * Argumenty:
 *    output - strumien wyjscia,
 *    A - skladnik ktora ma zostac wyswietlony.
 */
std::ostream &operator<< (std::ostream &output, LZespolona A)
{
  output<<"("<< A.re;
  if(A.im>=0)
  output <<"+" <<A.im<<"i)";
  else if(A.im<0) 
    output<<A.im << "i)";
  return output;
}
/*void WyswietlLiczbe(LZespolona Liczba)
{
  std::cout<<Liczba<<std::endl;
}

*/
/*!
 * Realizuje przesuniecie bitowe w prawo.
 * Argumenty:
 *    input - strumien wejscia,
 *    X - skladnik ktora ma zostac wczytany.
 */
std::istream &operator>> (std::istream &input, LZespolona & X)
{
    char litera, nawias;
    
    input >> nawias;
    if(input.fail()) return input;
    if (nawias != '(') 
    { 
    input.setstate(std::ios::failbit); 
    return input;
    }

    input >> X.re;
    if(input.fail()) 
    return input;

    input >> X.im;
    if(input.fail()) 
    return input;

    input >> litera;
    if(input.fail()) 
    return input;
    if (nawias != 'i') 
    { 
    input.setstate(std::ios::failbit); 
    return input;
    }
    input >> nawias;
    if(input.fail()) 
    return input;
    if(nawias != ')')
    {
      input.setstate(std::ios::failbit);
      return input;
    }
    return input;
}

/*!
 * Realizuje obliczanie modulu liczby zespolonej
 * Argumenty:
    *    Liczba - Liczba znajdujaca sie w module
 */
  double modul(LZespolona Liczba){
  double Wyn=sqrt(((Liczba.re)*(Liczba.re))+((Liczba.im)*(Liczba.im)));
  return Wyn;
  }

/*!
 * Realizuje obliczenie sprzezenia liczby zespolonoej
 * Argumenty
 *    Liczba - liczba ktorej liczone jest sprzezenie   
*/
  LZespolona Sprz(LZespolona Liczba){
    LZespolona SWyn;
    SWyn.re=Liczba.re;
    SWyn.im=(-1)*Liczba.im; 
  return SWyn;
  } 

/*!
 * Realizuje dzielenie czesci rzeczywistej z liczba rzeczywista oraz dzielenie czesci urojonej z liczba rzeczywista
 * Argumenty:
 *    Dz1 - pierwszy skladnik dzielenia,
 *    Dz2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (LZespolona Dz1, double Dz2)
{
LZespolona DWyn;
DWyn.re=Dz1.re/Dz2;
DWyn.im=Dz1.im/Dz2;
return DWyn;
  }

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Dz1 - pierwszy skladnik dzielenia,
 *    Dz2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (LZespolona Dz1, LZespolona Dz2)
{
 LZespolona Wynik;
 Wynik= (Dz1*Sprz(Dz2))/((modul(Dz2))*(modul(Dz2)));
  return Wynik;
}

