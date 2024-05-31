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

  // Mètodes consultors
  bool guanyada() const;
  // Pre: --; Post: retorna true si la partida està guanyada
  bool pila_valida(int pila) const;
  // Pre: --; Post: retorna si la pila és vàlida

  // Mètodes modificadors
  Joc &espiar_tauler();
  // Pre: --; Post: mostra totes les cartes del tauler de cap per munt
  void obrir_carta();
  // Pre: --; Post: obre una carta o torna a començar
  void posar_carta_tauler();
  // Pre: --; Post: agafa la darrera carta oberta de la mà, i la posa al tauler
  void posar_carta_pila();
  // Pre: --; Post: agafa la darrera carta oberta de la mà, i la posa a la seva
  // pila dels colls
  void moure_carta_tauler();
  // Pre: --; Post: agafa 1 o més cartes d'una columna, i les mou a una altra
  void moure_carta_pila();
  // Pre: --; Post: agafa la darrera carta de la columna i la posa a la seva
  // pila dels colls
  void recuperar_carta();
  // Pre: --; Post: recupera una carta de la pila de colls i la torna al joc
};

#endif // !JOC_H