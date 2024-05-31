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
  void girar_ultima_carta(int columna);
  // Pre: --; Post: Gira la ultima carta de la columna;
  void apilar_carta(int columna, const Carta &c);
  // Pre: --; Post: col·loca la carta a la columna demanada;
  Carta desapilar_carta(int columna);
  // Pre: --; Post: desapila la ultima carta de la columna
  Pila_Cartes desempilar_multiples_cartes(int columna, int fila);
  // Pre: --; Post: retorna una pila cartes (el cim és la carta de [columna,
  // fila]) desempilada del taulell
  void empilar_multiples_cartes(int columna, Pila_Cartes &per_empilar);
  // Pre: --; Post: empila un seguit de cartes sobre a una columna

  //  Mètodes consultors
  bool columna_valida(int columna) const;
  // Pre: --; Post: retorna si la columna és vàlida
  bool columna_encaixa(int columna, const Carta &c) const;
  // Pre: --; Post: retorna si la carta encaixa a la columna
  bool columna_buida(int columna) const;
  // Pre: --; Post: retorna si la columna és buida
  bool fila_valida(int columna, int fila) const;
  // Pre: --; Post: retorna si fila és correcte
  bool carta_visible(int columna, int fila) const;
  // Pre: --; Post: retorna si una carta és visible
  bool ultima_carta_visible(int columna) const;
  // Pre: --; Post: retorna si la ultima carta de la columna és visible

  // Operadors
  Taulell &operator=(const Taulell &t);
  // Pre: --; Post: taulell còpia de t
};

#endif // !TAULELL_H