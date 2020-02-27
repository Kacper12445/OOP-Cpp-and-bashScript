#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

std::ostream &operator<< (std::ostream &out, LZespolona A);
std::istream &operator>> (std::istream &input, LZespolona & X);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Odj1,  LZespolona  Odj2);
LZespolona  operator * (LZespolona  Cn1,  LZespolona  Cn2);
LZespolona  operator / (LZespolona  Dz1,  LZespolona  Dz2);


#endif
