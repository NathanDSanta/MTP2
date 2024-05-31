#include "Joc.h"
#include "Pila_Cartes.h"

Joc::Joc() {
  // Pre: --; Post: demana llavor i prepara el joc.
  cout << "ENTRA LA LLAVOR: " << endl;
  unsigned llavor;
  cin >> llavor;
  if (llavor < 0)
    llavor *= -1;
  if (llavor == 0)
    llavor = 1;
  Baralla cartes(llavor);
  a_ma = a_taulell.repartir(cartes);
}

// Mètodes consultors
bool Joc::guanyada() const {
  // Pre: --; Post: retorna true si la partida està guanyada
  bool guanyada = true;
  int i = 0;
  while (guanyada && i < 4) {
    if (a_piles[i].cim().valor() != 12)
      guanyada = false;
    i++;
  }
  return guanyada;
}

bool Joc::pila_valida(int pila) const {
  // Pre: --; Post: retorna si la pila és vàlida
  return pila < 4 && pila >= 0;
}

// Mètodes modificadors
Joc &Joc::espiar_tauler() {
  // Pre: --; Post: mostra totes les cartes del tauler de cap per munt
  a_taulell = a_taulell.espiar();
  return *this;
}

void Joc::obrir_carta() {
  // Pre: --; Post: obre una carta o torna a començar
  if (a_ma.buit())
    while (!a_descartades.buit())
      a_ma += a_descartades--.girar();

  else
    a_descartades += a_ma--.girar();
}

void Joc::posar_carta_tauler() {
  // Pre: --; Post: agafa la darrera carta oberta de la mà, i la posa al tauler
  if (a_descartades.buit())
    cout << "NO HI HA CAP CARTA PER AGAFAR " << endl;
  else {
    cout << "A QUINA COLUMNA LA VOLS POSAR: " << endl;
    int columna;
    cin >> columna;
    if (!a_taulell.columna_valida(columna - 1) ||
        !a_taulell.columna_encaixa(columna - 1, a_descartades.cim())) {
      cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << columna << endl;
    } else {
      a_taulell.apilar_carta(columna - 1, a_descartades--);
    }
  }
}

void Joc::posar_carta_pila() {
  // Pre: --; Post: agafa la darrera carta oberta de la mà, i la posa a la seva
  // pila dels colls
  if (a_descartades.buit())
    cout << "NO HI HA CAP CARTA PER AGAFAR " << endl;
  else {
    Carta c = a_descartades.cim();
    if (!(c.apilable(a_piles[c.pal()].cim())))
      cout << "LA CARTA NO ES POT APILAR " << endl;
    else {
      a_piles[c.pal()] += a_descartades--;
    }
  }
}

void Joc::moure_carta_tauler() {
  // Pre: --; Post: agafa 1 o més cartes d'una columna, i les mou a una altra
  cout << "ENTRA LA COLUMNA ORIGEN I LA FILA ORIGEN: " << endl;
  int columna_0, fila;
  cin >> columna_0 >> fila;
  if (!a_taulell.columna_valida(columna_0 - 1) ||
      !a_taulell.fila_valida(columna_0 - 1, fila - 1) ||
      !a_taulell.carta_visible(columna_0 - 1, fila - 1)) {
    cout << "LA CARTA NO ES POT MOURE" << endl;
  } else {
    Pila_Cartes cartes_a_moure =
        a_taulell.desempilar_multiples_cartes(columna_0 - 1, fila - 1);
    cout << "ENTRA LA COLUMNA DESTI: " << endl;
    int columna_d;
    cin >> columna_d;
    if (!a_taulell.columna_valida(columna_d - 1) ||
        !a_taulell.columna_encaixa(columna_d - 1, cartes_a_moure.cim())) {
      cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << columna_d << endl;
      a_taulell.empilar_multiples_cartes(columna_0 - 1, cartes_a_moure);
    } else {
      a_taulell.empilar_multiples_cartes(columna_d - 1, cartes_a_moure);
      if (!a_taulell.carta_visible(columna_0 - 1, fila - 2))
        a_taulell.girar_ultima_carta(columna_0 - 1);
    }
  }
}

void Joc::moure_carta_pila() {
  // Pre: --; Post: agafa la darrera carta de la columna i la posa a la seva
  // pila dels colls
  cout << "ENTRA LA COLUMNA ORIGEN:" << endl;
  int columna;
  cin >> columna;
  if (!a_taulell.columna_valida(columna - 1) ||
      a_taulell.columna_buida(columna - 1))
    cout << "LA CARTA NO ES POT APILAR" << endl;
  else {
    Carta per_apilar = a_taulell.desapilar_carta(columna - 1);
    if (!per_apilar.apilable(a_piles[per_apilar.pal()].cim())) {
      cout << "LA CARTA NO ES POT APILAR" << endl;
      a_taulell.apilar_carta(columna - 1, per_apilar);
    } else {
      a_piles[per_apilar.pal()] += per_apilar;
      if (!a_taulell.ultima_carta_visible(columna - 1))
        a_taulell.girar_ultima_carta(columna - 1);
    }
  }
}

void Joc::recuperar_carta() {
  // Pre: --; Post: recupera una carta de la pila de colls i la torna al joc
  cout << "ENTRA LA PILA: " << endl;
  int pila;
  cin >> pila;
  if (!pila_valida(pila - 1) || a_piles[pila - 1].buit())
    cout << "A LA PILA NO HI HA CAP CARTA PER RECUPERAR" << endl;
  else {
    Carta per_apilar = a_piles[pila - 1]--;
    cout << "A QUINA COLUMNA LA VOLS POSAR:  " << endl;
    int columna;
    cin >> columna;
    if (!a_taulell.columna_valida(columna - 1) ||
        !a_taulell.columna_encaixa(columna - 1, per_apilar)) {
      cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << columna << endl;
      a_piles[pila - 1] += per_apilar;
    } else
      a_taulell.apilar_carta(columna - 1, per_apilar);
  }
}

// Misc

// Operador cout
ostream &operator<<(ostream &o, const Joc &j) {
  o << "ESTAT DEL JOC" << endl;
  for (int i = 0; i < 4; i++) {
    o << j.a_piles[i];
  }
  o << "   " << j.a_ma << j.a_descartades << endl;
  o << j.a_taulell;
  return o;
}
