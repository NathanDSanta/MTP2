#include "Joc.h"

char demanar_opcio() {
  // Pre: --; Post: demana una opció i retorna el char
  cout << "OPCIO: " << endl;
  char aux;
  cin >> aux;
  return aux;
}

void menu() {
  // Pre: --; Post mostra el menú
  cout << "MENU" << endl;
  cout << "1: OBRIR UNA CARTA (O TORNAR A COMENCAR)" << endl
       << "2: POSAR UNA CARTA (MA->TAULER)" << endl
       << "3: POSAR UNA CARTA (MA->PILA)" << endl
       << "4: MOURE UNA CARTA (TAULER->TAULER)" << endl
       << "5: MOURE UNA CARTA (TAULER->PILA)" << endl
       << "6: RECUPERAR UNA CARTA (PILA->TAULER)" << endl
       << "E: ESPIAR EL TAULER" << endl
       << "M: MOSTRAR EL MENU" << endl
       << "A: ABANDONAR LA PARTIDA" << endl;
}

int main() {
  Joc partida;
  cout << partida;
  cout << "JOC EN CURS" << endl;
  menu();
  bool abandonar = false, guanyat = false;
  while (!abandonar && !guanyat) {
    char opcio = demanar_opcio();
    switch (opcio) {
    case '1':
      partida.obrir_carta();
      cout << partida;
      break;

    case '2':
      partida.posar_carta_tauler();
      cout << partida;
      break;

    case '3':
      partida.posar_carta_pila();
      cout << partida;
      guanyat = partida.guanyada();
      break;

    case '4':
      partida.moure_carta_tauler();
      cout << partida;
      break;

    case '5':
      partida.moure_carta_pila();
      cout << partida;
      guanyat = partida.guanyada();
      break;

    case '6':
      partida.recuperar_carta();
      cout << partida;
      break;

    case 'E':
      cout << Joc(partida).espiar_tauler();
      break;

    case 'M':
      menu();
      break;

    case 'A':
      abandonar = true;
      cout << "HAS ABANDONAT LA PARTIDA! " << endl;
      break;

    default:
      cout << "OPCIO NO DEFINIDA " << opcio << endl;
      menu();
      cout << partida;
      break;
    }
    if (!guanyat && !abandonar && opcio != 'M')
      cout << "JOC EN CURS" << endl;
  }

  if (guanyat) {
    cout << "JOC ACABAT " << endl;
    cout << "HAS GUANYAT LA PARTIDA!" << endl;
  }
  return 0;
}