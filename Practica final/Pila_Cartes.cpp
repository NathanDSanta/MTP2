#include "Pila_Cartes.h"

// Constructors - Destructor

Pila_Cartes::Pila_Cartes() {
  // Pre: --; Post: pila buida
  a_cim = NULL;
}

Pila_Cartes::Pila_Cartes(const Pila_Cartes &p) {
  // Pre: --; Post: pila és còpia de p
  a_cim = NULL;
  copia(p);
}

Pila_Cartes::Pila_Cartes(Baralla &b) {
  // Pre: --; Post: pila formades per les cartes de b
  a_cim = NULL;
  while (!b.buit()) {
    *this += b--;
  }
}

Pila_Cartes::~Pila_Cartes() {
  // Pre: --; Post: memòria alliberada
  allibera();
}

void Pila_Cartes::allibera() {
  // Pre: --; Post: memòria alliberada
  while (a_cim != NULL) {
    Node *aux = a_cim;
    a_cim = a_cim->seg;
    delete aux;
  }
}

// Mètodes privats

void Pila_Cartes::copia(const Pila_Cartes &p) {
  // Pre: --; Post: pila és còpia de p
  Node *i, *j = p.a_cim, *aux = NULL;
  if (j != NULL) {
    aux = new Node{j->valor, NULL};
    j = j->seg;
  }
  a_cim = aux;
  i = aux;
  while (j != NULL) {
    aux = new Node{j->valor, NULL};
    i->seg = aux;
    i = aux;
    j = j->seg;
  }
}

// Mètodes consultors
bool Pila_Cartes::buit() const {
  // Pre: --; Post: retorna si la pila està buida
  return a_cim == NULL;
}

Carta Pila_Cartes::cim() const {
  // Pre: --; Post: retorna el cim
  Carta c;
  if (a_cim != NULL)
    c = a_cim->valor;
  else {
    c = Carta('E');
  }
  return c;
}
// Operadors

Pila_Cartes &Pila_Cartes::operator=(const Pila_Cartes &p) {
  // Pre: --; Post: pila és còpia de p
  if (this != &p) {
    allibera();
    copia(p);
  }
  return *this;
}

Pila_Cartes &Pila_Cartes::operator=(Baralla &b) {
  // Pre: --; Post: pila formada per les cartes de b
  allibera();
  *this = Pila_Cartes(b);
  return *this;
}

Carta Pila_Cartes::operator--(int) {
  // Pre: --; Post: extreu la carta del cim i la retorna
  Carta carta = a_cim->valor;
  Node *aux = a_cim;
  a_cim = a_cim->seg;
  delete aux;
  return carta;
}

void Pila_Cartes::operator+=(const Carta &c) {
  // Pre: --; Post: c afegida a pila
  Node *aux = new Node{c, a_cim};
  a_cim = aux;
}

// Operador cout
ostream &operator<<(ostream &o, const Pila_Cartes &p) {
  if (p.a_cim != NULL)
    o << p.a_cim->valor;
  else
    o << "   ";
  return o;
}