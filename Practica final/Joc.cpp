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

// Mètodes modificadors
Joc &Joc::espiar_tauler() {
  a_taulell = a_taulell.espiar();
  return *this;
}

void Joc::obrir_carta() {
  if (a_ma.buit()) {
    while (!a_descartades.buit()) {
      a_ma += a_descartades--.girar();
    }
  }
  a_descartades += a_ma--.girar();
}

void Joc::posar_carta_tauler() {
  if (a_descartades.buit())
    cout << "NO HI HA CAP CARTA PER AGAFAR " << endl;
  else {
    cout << "A QUINA COLUMNA LA VOLS POSAR: " << endl;
    int columna;
    cin >> columna;
    if (!a_taulell.columna_valida(columna - 1, a_descartades.cim())) {
      cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << columna << endl;
    } else {
      a_taulell.posar_carta_ma(columna - 1, a_descartades.cim());
    }
  }
}

void Joc::posar_carta_pila() {
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

// Misc
ostream &operator<<(ostream &o, const Joc &j) {
  o << "ESTAT DEL JOC" << endl;
  for (int i = 0; i < 4; i++) {
    o << j.a_piles[i];
  }
  o << "   " << j.a_ma << j.a_descartades << endl;
  o << j.a_taulell;
  o << "JOC EN CURS" << endl;
  return o;
}
