#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class Carta {

private:
  // Mètodes amics
  friend istream &operator>>(istream &i, Carta &c);
  friend ostream &operator<<(ostream &o, const Carta &c);

  // Atributs
  char a_pal;
  int a_valor;
  bool a_visible;
  bool a_negre;

  // Mètodes privats
  bool pal_menor(const Carta &c) const;
  // Pre: --; Post: retorna true si el pal és menor
  static int cerca_valor(char valor);
  // Pre: --; Post: número del valor en funció del char;

public:
  static const char PALS[4];
  static const char VALORS[13];

  // Constr
  Carta(char pal = 'a', int valor = 0, bool visible = false);
  // Pre: --; Post: Carta creada amb valors predeterminats modificables  {' ',
  // 0, true}

  // Mètodes modificadors
  Carta &girar();
  // Pre: --; Post: gira la carta;
  static void intercanviar(Carta &a, Carta &c);
  // Pre: a = A, c = C; post: a = C, c = A;

  // Mètodes consultors
  bool visible() const;
  // Pre: --; Post: retorna si la carta és visible
  bool encaixen(const Carta &c) const;
  // Pre: --; Post: retorna si la carta actual encaixa sota la carta c
  bool apilable(const Carta &c) const;
  // Pre: --; Post: retorna si la carta actual es pot apilar sobre c
  int pal() const;
  // Pre: --; Post: retorna l'índex del pal

  // Operadors
  bool operator<(const Carta &c) const;
  // Pre: --; Post: retorna si aquesta carta és menor que c, segons l'ordre de
  // pals i valors respectivament.
};

#endif // !CARTA_H