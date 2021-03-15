#include <unistd.h>
#include "Scena.hh"

using namespace std;

int ObiektSceny::ilosc = 0;

int main()
{
  PzG::LaczeDoGNUPlota  Lacze;

    Scena Scena1;
    Scena1.Menu(Lacze); 
}
