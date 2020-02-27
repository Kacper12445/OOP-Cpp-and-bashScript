#include "WyrazenieZesp.hh"
#include<iostream>


LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
	LZespolona wynik;
	if (WyrZ.Op == 0)
		wynik = WyrZ.Arg1+WyrZ.Arg2;
	else if (WyrZ.Op == 1)
		wynik = WyrZ.Arg1-WyrZ.Arg2;
	else if(WyrZ.Op == 2)
		wynik=WyrZ.Arg1*WyrZ.Arg2;
	else if(WyrZ.Op ==3)
		wynik=WyrZ.Arg1/WyrZ.Arg2;
	return wynik;
	
	/*switch(WyrZ.Op)
	{
	case Op_Dodaj:
	wynik=WyrZ.Arg1+WyrZ.Arg2;
	case Op_Odejmij:
	wynik=WyrZ.Arg1-WyrZ.Arg2;
	case Op_Mnoz:
	wynik=WyrZ.Arg1*WyrZ.Arg2;
	case Op_Dziel:
	wynik=WyrZ.Arg1/WyrZ.Arg2;
	}
	return wynik;
*/
}



/*void Wyswietl(WyrazenieZesp  WyrZ){								//<--Funkcja wyswietlajaca wyrazenie zespolone
	std::cout<<":?  Podaj wynik operacji: "<<WyrZ.Arg1;
	switch(WyrZ.Op)
	{
		case Op_Dodaj: std::cout<<"+";
		break;
		case Op_Odejmij: std::cout<<"-";
		break;
		case Op_Mnoz: std::cout<<"*";
		break;
		case Op_Dziel: std::cout<<"/";
		break;
		default: std::cout<<"Niepoprawna operacja";
		break;
	}
	std:: cout<<WyrZ.Arg2<<" ="<<std::endl;
}
*/


/*!
 * Realizuje przesuniecie bitowe w prawo.
 * Argumenty:
 *    output - strumien wyjscia,
 *    WyrZ - skladnik ktora ma zostac wyswietlony.
 */
std::ostream &operator << (std::ostream &output, WyrazenieZesp &WyrZ)
{
output << WyrZ.Arg1;

switch(WyrZ.Op)
	{
		case Operator::Op_Dodaj: output<<'+';
		break;
		case Operator::Op_Odejmij: output<<'-';
		break;
		case Operator::Op_Mnoz: output<<'*';
		break;
		case Operator::Op_Dziel: output<<'/';
		break;
		default: std::cout<<"Niepoprawna operacja";
		break;
	}
	output<<WyrZ.Arg2<<" ="<<std::endl;
	return output;
}


/*!
 * Realizuje przesuniecie bitowe w prawo.
 * Argumenty:
 *    input - strumien wejscia,
 *    WyrZ - skladnik ktora ma zostac wczytany.
 */
std::istream &operator >>(std::istream &input, WyrazenieZesp &WyrZ)
{
	char wyrazenie;
	char naw;
	double liczba;


	input >> WyrZ.Arg1;
	input.get(wyrazenie);

	if(input.fail())
	return input;
	
	switch(wyrazenie)
		{
			case '+': WyrZ.Op = Op_Dodaj;
			break;

			case '-': WyrZ.Op = Op_Odejmij;
			break;

			case '*': WyrZ.Op = Op_Mnoz;
			break;

			case '/': WyrZ.Op = Op_Dziel;
			break;

			default: input.setstate(std::ios::failbit);
			return input;
			break;	
		}
		naw = input.peek();
		if(naw=='(')
		{
			input >> WyrZ.Arg2;
		}
		else
		{
			input >> liczba;
			WyrZ.Arg2.re=liczba;
			WyrZ.Arg2.im=0;
		}
		input.ignore();
		
		return input;
}







/*void Wczytaj(LZespolona Liczba,LZespolona Liczba2, WyrazenieZesp WyrZ, Operator z){
WyrZ.Arg1=Liczba;
WyrZ.Arg2=Liczba2;
WyrZ.Op=z;
}
*/

