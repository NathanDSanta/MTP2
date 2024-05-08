#ifndef JOC_H
#define JOC_H
#include "Taulell.h"

class Joc {
private:
  // Misc
  friend ostream &operator<<(ostream &o, const Joc &j);

  // Atributs
  Pila_Cartes a_piles[4];
  Pila_Cartes a_ma, a_descartades;
  Taulell a_taulell;

public:
  // Constr - Destr
  Joc();
  // Pre: --; Post: demana llavor i prepara el joc.
};

#endif // !JOC_H