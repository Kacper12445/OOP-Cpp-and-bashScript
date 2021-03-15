#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH


//Struktura przechowujaca ilosc odpowiedzi dobrych oraz zlych

struct stat {
	double dobra;
	double zla;
	};

void Wyswietl(stat x);

#endif