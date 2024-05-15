#ifndef TAULELL_H
#define TAULELL_H
#include "Pila_Cartes.h"

class Taulell {
private:
  // Friend
  friend ostream &operator<<(ostream &o, const Taulell &t);

  // Atributs
  Carta **a_mat;
  int *a_longitud;
  int a_nc;

  // Mètodes privats
  void copia(const Taulell &t);
  // Pre: --; Post: taulell és còpia de t
  void allibera();
  // Pre: --; Post: memòria alliberada
  void reserva();
  // Pre: --; Post: memòria reservada
  void expandeix_contrau_fila(int fila, bool contrau = false);
  // Pre: fila <= a_nc; Post: expandeix/contrau (contrau == false:true) la fila
  // en 1.

public:
  // Constr - Destr
  Taulell();
  // Pre: --; Post: taulell buit
  Taulell(const Taulell &t);
  // Pre: --; Post: taulell còpia de t
  ~Taulell();
  // Pre: --; Post: memòria alliberada

  // Mètodes modificadors
  Baralla &repartir(Baralla &b);
  // Pre: --; Post: cartes de b repartides al taulell i les restants retornades.
  Taulell &espiar();
  // Pre: --; Post: Gira totes les cartes del taulell
  void posar_carta_ma(int columna, const Carta &c);
  // Pre: --; Post: col·loca la carta a la columna demanada;
  void apilar_carta(const Carta &c);
  // Pre: --; Post: apil·la la carta a l'espai corresponent

  // Mètodes consultors
  bool columna_valida(int columna, const Carta &c) const;
  // Pre: --; Post: retorna si la columna és vàlida
  bool pila_valida(const Carta &c) const;

  // Operadors
  Taulell &operator=(const Taulell &t);
  // Pre: --; Post: taulell còpia de t
};

#endif // !TAULELL_H