#ifndef BARALLA_H
#define BARALLA_H
#include "Carta.h"

class Baralla {
private:
  // Constants i mètodes amics
  friend istream &operator>>(istream &i, Baralla &b);
  friend ostream &operator<<(ostream &o, const Baralla &b);
  static const int BARALLA_COMPLETA = 52;

  // Atributs
  Carta *a_t;
  int a_n;
  int a_max;
  unsigned a_llavor;

  // Mètodes privats
  void reserva();
  // Pre: --; Post: memòria reservada per a_max Carta
  void copia(const Baralla &b);
  // Pre: memòria alliberada; Post: aquesta baralla és còpia de la baralla b
  void expandeix_contrau(bool contrau = false);
  // Pre: --; Post: la memòria reservada s'amplia en 13.
  void contrau();
  // Pre: --; Post: la memòria reservada es contrau en 13.
  int aleatori(int valor);
  // Pre: --; Post: retorna un valor aleatori entre 0 i valor-1

public:
  // Constr - Destr
  Baralla();
  // Pre: --; Post: Baralla buida
  Baralla(unsigned llavor);
  // Pre: --; Post: Baralla barrejada
  Baralla(const Baralla &b);
  // Pre: --; Post: Baralla és una còpia de b
  ~Baralla();
  // Pre: --; Post: Memòria alliberada

  // Mètodes consultors
  bool buit() const;
  // Pre: --; Post: retorna true si la baralla és buida

  // Mètodes modificadors
  void barrejar();
  // Pre: --; Post: baralla barrejada

  // Operadors
  Baralla &operator=(const Baralla &b);
  // Pre --; Post: Baralla és còpia de b
  void operator+=(const Carta &c);
  // Pre: --; Post: C afegida al final de la baralla.
  Carta operator--(int);
  // Pre: --; Post: retorna l'últim element i l'elimina del vector
  // simultàniament
};

#endif // !BARALLA_H