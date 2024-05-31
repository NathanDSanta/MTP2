#include "Carta.h"

const char Carta::PALS[4] = {'P', 'c', 'd', 'T'};
const char Carta::VALORS[13] = {'A', '2', '3', '4', '5', '6', '7',
                                '8', '9', 'D', 'J', 'Q', 'K'};

// CONSTRUCTORS

Carta::Carta(char pal, int valor, bool visible) {
  // Pre: --; Post: Carta creada amb valors predeterminats modificables  {' ',
  // 0, true}
  a_pal = pal;
  a_valor = valor;
  a_visible = visible;
  a_negre = a_pal == 'P' || a_pal == 'T';
}

// MÈTODES MODIFICADORS

void Carta::intercanviar(Carta &a, Carta &c) {
  // Pre: a = A, c = C; post: a = C, c = A;
  Carta aux = a;
  a = c;
  c = aux;
}

Carta &Carta::girar() {
  // Pre: --; Post: gira la carta;
  a_visible = !a_visible;
  return *this;
}

// MÈTODES CONSULTORS
bool Carta::visible() const {
  // Pre: --; Post: retorna si la carta és visible
  return a_visible;
}

bool Carta::apilable(const Carta &c) const {
  // Pre: --; Post: retorna si la carta actual es pot apilar sobre c
  return c.a_pal == 'E' && a_valor == 0 ||
         a_pal == c.a_pal && a_valor == c.a_valor + 1;
}

bool Carta::encaixen(const Carta &c) const {
  // Pre: --; Post: retorna si la carta actual encaixa sota la carta c
  return c.a_pal == 'E' && a_valor == 12 ||
         a_negre != c.a_negre && a_valor == c.a_valor - 1;
}

int Carta::pal() const {
  // Pre: --; Post: retorna l'índex del pal
  int i = 0;
  while (i < 4 && PALS[i] != a_pal)
    i++;
  return i;
}

int Carta::valor() const {
  // Pre: --; Post: retorna el valor de la carta
  return a_valor;
}

// OPERADORS

bool Carta::operator<(const Carta &c) const {
  // Pre: --; Post: retorna si aquesta carta és menor que c, segons l'ordre de
  // pals i valors respectivament.
  bool es_menor = pal_menor(c);
  if (a_pal == c.a_pal)
    es_menor = a_valor < c.a_valor;
  return es_menor;
}

// MÈTODES PRIVATS

bool Carta::pal_menor(const Carta &c) const {
  // Pre: --; Post: retorna true si el pal és menor
  int i = 0;
  while (i < 4 && PALS[i] != a_pal && PALS[i] != c.a_pal) {
    i++;
  }
  bool es_menor = a_pal == PALS[i];
  return es_menor;
}

int Carta::cerca_valor(char valor) {
  // Pre: --; Post: número del valor en funció del char;
  int i = 0;
  while (i < 13 && VALORS[i] != valor)
    i++;
  return i;
}

// IOSTREAM

istream &operator>>(istream &i, Carta &c) {
  char valor = ' ';
  i >> valor >> c.a_pal;
  c.a_valor = Carta::cerca_valor(valor);
  return i;
}

ostream &operator<<(ostream &o, const Carta &c) {
  if (c.a_visible)
    o << Carta::VALORS[c.a_valor] << c.a_pal << " ";
  else
    o << "** ";
  return o;
}