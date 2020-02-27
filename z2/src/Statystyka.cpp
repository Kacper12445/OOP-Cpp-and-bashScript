#include "Statystyka.hh"
#include <iostream>

/*Funkcja wyswietlajaca statystyki testu
  *  A - zmienna przechowujaca wartosc liczby procentow
  *  x.zla - liczba zlych odpowiedzi
  *  x.doobra - liczba dobrych odpowiedzi
  */
void Wyswietl(stat x) 
{
	
	double a=(x.dobra/(x.dobra+x.zla))*100;
std::cout<<"Ilosc dobrych odpowiedzi: "<<x.dobra<<std::endl;
std::cout<<"Ilosc blednych odpowiedzi: "<<x.zla<<std::endl;
std::cout<<"Wynik procentowy poprawnych odpowiedzi: "<<a<<"%"<<std::endl;
}



