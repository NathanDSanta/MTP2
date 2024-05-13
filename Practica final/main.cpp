#include "Joc.h"

char demanar_opcio() {
  cout << "OPCIO: " << endl;
  char aux;
  cin >> aux;
  return aux;
}

void menu() {
  cout << "MENU" << endl;
  cout << "1. OBRIR UNA CARTA (O TORNAR A COMENCAR)" << endl
       << "2. POSAR UNA CARTA (MA->TAULER)" << endl
       << "3. POSAR UNA CARTA (MA->PILA)" << endl
       << "4. MOURE UNA CARTA (TAULER->TAULER)" << endl
       << "5. MOURE UNA CARTA (TAULER->PILA)" << endl
       << "6. RECUPERAR UNA CARTA (PILA->TAULER)" << endl
       << "E. ESPIAR EL TAULER" << endl
       << "M. MOSTRAR EL MENU" << endl
       << "A. ABANDONAR LA PARTIDA" << endl;
}

int main() {
  Joc partida;
  cout << partida;
  menu();
  bool abandonar = false;
  while (!abandonar) {
    char opcio = demanar_opcio();
    switch (opcio) {
    case '1':

      break;

    case '2':

      break;

    case '3':

      break;

    case '4':

      break;

    case '5':

      break;

    case '6':

      break;

    case 'E':
      cout << Joc(partida).espiar_tauler();
      break;

    case 'M':
      menu();
      break;

    case 'A':
      abandonar = true;
      break;
    }
  }

  return 0;
}