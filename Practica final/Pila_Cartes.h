#ifndef PILA_CARTES_H
#define PILA_CARTES_H
#include "Baralla.h"
#include "Carta.h"


class Pila_Cartes {
private:
  // Def
  friend ostream &operator<<(ostream &o, const Pila_Cartes &p);

  struct Node {
    Carta valor;
    Node *seg;
  };

  Node *a_cim;

  // Mètodes privats
  void allibera();
  // Pre: --; Post: memòria alliberada
  void copia(const Pila_Cartes &p);
  // Pre: --; Post: pila és còpia de p

public:
  // Constr -- Destr
  Pila_Cartes();
  // Pre: --; Post: pila buida
  Pila_Cartes(const Pila_Cartes &p);
  // Pre: --; Post: pila és còpia de p
  Pila_Cartes(Baralla &b);
  // Pre: --; Post: pila formades per les cartes de b
  ~Pila_Cartes();
  // Pre: --; Post: memòria alliberada

  // Operadors
  Pila_Cartes &operator=(const Pila_Cartes &p);
  // Pre: --; Post: pila és còpia de p
  Pila_Cartes &operator=(Baralla &b);
  // Pre: --; Post: pila formada per les cartes de b
  void operator+=(const Carta &c);
  // Pre: --; Post: c afegida a pila
};

#endif // !PILA_CARTES_H