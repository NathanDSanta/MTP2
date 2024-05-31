#include "Taulell.h"

// Constructors - Destructor
Taulell::Taulell() {
  // Pre: --; Post: taulell buit
  a_mat = NULL;
  a_longitud = NULL;
  a_nc = 0;
}

Taulell::Taulell(const Taulell &t) {
  // Pre: --; Post: taulell còpia de t
  copia(t);
}

Taulell::~Taulell() {
  // Pre: --; Post: memòria alliberada
  allibera();
}

// Mètodes modificadors
Baralla &Taulell::repartir(Baralla &b) {
  // Pre: --; Post: cartes de b repartides al taulell i les restants retornades.
  a_nc = 7;
  a_longitud = new int[a_nc];
  for (int i = 0; i < a_nc; i++)
    a_longitud[i] = i + 1;
  reserva();
  for (int i = 0; i < a_nc; i++) {
    for (int j = 0; j < a_longitud[i]; j++) {
      a_mat[i][j] = b--;
      if (j + 1 == a_longitud[i])
        a_mat[i][j].girar();
    }
  }
  return b;
}

Taulell &Taulell::espiar() {
  // Pre: --; Post: Gira totes les cartes del taulell
  for (int i = 0; i < a_nc; i++) {
    for (int j = 0; j < a_longitud[i]; j++) {
      if (!a_mat[i][j].visible())
        a_mat[i][j].girar();
    }
  }
  return *this;
}

void Taulell::girar_ultima_carta(int columna) {
  // Pre: --; Post: Gira la ultima carta de la columna;
  if (a_longitud[columna] != 0)
    a_mat[columna][a_longitud[columna] - 1].girar();
}

void Taulell::apilar_carta(int columna, const Carta &c) {
  // Pre: --; Post: col·loca la carta a la columna demanada;
  expandeix_contrau_fila(columna);
  a_mat[columna][a_longitud[columna] - 1] = c;
}

Carta Taulell::desapilar_carta(int columna) {
  // Pre: --; Post: desapila la ultima carta de la columna
  Carta aux;
  if (a_longitud[columna] != 0) {
    aux = a_mat[columna][a_longitud[columna] - 1];
    expandeix_contrau_fila(columna, true);
  }
  return aux;
}

Pila_Cartes Taulell::desempilar_multiples_cartes(int columna, int fila) {
  // Pre: --; Post: retorna una pila cartes (el cim és la carta de [columna,
  // fila]) desempilada del taulell
  Pila_Cartes aux;
  for (int i = a_longitud[columna] - 1; i >= fila; i--) {
    aux += a_mat[columna][i];
    expandeix_contrau_fila(columna, true);
  }
  return aux;
}

void Taulell::empilar_multiples_cartes(int columna, Pila_Cartes &per_empilar) {
  // Pre: --; Post: empila un seguit de cartes sobre a una columna
  while (!per_empilar.buit()) {
    expandeix_contrau_fila(columna);
    a_mat[columna][a_longitud[columna] - 1] = per_empilar--;
  }
}

// Mètodes consultors
bool Taulell::columna_valida(int columna) const {
  // Pre: --; Post: retorna si la columna és vàlida
  return columna < a_nc && columna >= 0;
}

bool Taulell::columna_encaixa(int columna, const Carta &c) const {
  // Pre: --; Post: retorna si la carta encaixa a la columna
  if (a_longitud[columna] != 0)
    return c.encaixen(a_mat[columna][a_longitud[columna] - 1]);
  else
    return c.encaixen(Carta('E'));
}

bool Taulell::columna_buida(int columna) const {
  // Pre: --; Post: retorna si la columna és buida
  return a_longitud[columna] == 0;
}

bool Taulell::fila_valida(int columna, int fila) const {
  // Pre: --; Post: retorna si fila és correcte
  return a_longitud[columna] - fila > 0;
}

bool Taulell::carta_visible(int columna, int fila) const {
  // Pre: --; Post: retorna si una carta és visible
  return a_mat[columna][fila].visible();
}

bool Taulell::ultima_carta_visible(int columna) const {
  // Pre: --; Post: retorna si la ultima carta de la columna és visible
  return a_mat[columna][a_longitud[columna] - 1].visible();
}

// Mètodes privats
void Taulell::allibera() {
  // Pre: --; Post: memòria alliberada
  for (int i = 0; i < a_nc; i++) {
    delete[] a_mat[i];
  }
  delete[] a_mat;
  delete[] a_longitud;
}

void Taulell::copia(const Taulell &t) {
  // Pre: --; Post: taulell és còpia de t
  a_nc = t.a_nc;
  a_longitud = new int[a_nc];
  a_mat = new Carta *[a_nc];
  for (int i = 0; i < t.a_nc; i++) {
    a_longitud[i] = t.a_longitud[i];
    a_mat[i] = new Carta[a_longitud[i]];
    for (int j = 0; j < t.a_longitud[i]; j++) {
      a_mat[i][j] = t.a_mat[i][j];
    }
  }
}

void Taulell::reserva() {
  // Pre: --; Post: memòria reservada
  a_mat = new Carta *[a_nc];
  for (int i = 0; i < a_nc; i++) {
    a_mat[i] = new Carta[a_longitud[i]];
  }
}

void Taulell::expandeix_contrau_fila(int fila, bool contrau) {
  // Pre: fila <= a_nc; Post: expandeix/contrau (contrau == false:true) la fila
  // en 1.
  Carta *aux = a_mat[fila];
  if (contrau)
    a_longitud[fila]--;
  else
    a_longitud[fila]++;
  a_mat[fila] = new Carta[a_longitud[fila]];
  for (int i = 0; i < a_longitud[fila]; i++) {
    a_mat[fila][i] = aux[i];
  }
  delete[] aux;
}

// Operadors
Taulell &Taulell::operator=(const Taulell &t) {
  // Pre: --; Post: taulell còpia de t
  if (this != &t) {
    allibera();
    copia(t);
  }
  return *this;
}

// Operador cout
ostream &operator<<(ostream &o, const Taulell &t) {
  int max_long = t.a_longitud[0];
  for (int i = 1; i < t.a_nc; i++) {
    if (t.a_longitud[i] > max_long)
      max_long = t.a_longitud[i];
  }
  for (int i = 1; i <= t.a_nc; i++)
    o << "c" << i << " ";
  cout << "    " << endl;
  for (int i = 0; i < max_long; i++) {
    for (int j = 0; j < t.a_nc; j++) {
      if (t.a_longitud[j] < i + 1)
        o << "   ";
      else
        o << t.a_mat[j][i];
    }
    cout << "f" << i + 1 << endl;
  }
  return o;
}
