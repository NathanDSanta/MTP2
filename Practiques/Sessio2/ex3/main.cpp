#include <iostream>
#include "Jugador.h"
using namespace std;

void introduccio(string A, string B){
    cout << "Comenca el partit" << endl;
    cout << "Menu: " << endl
         << "A: " << A << endl
         << "B: " << B << endl
         << "S: Sortir" << endl;
}

char qui_ha_guanyat(){
    char opcio;
    cout << "Qui ha guanyat (A, B, S): " << endl;
    cin >> opcio;
    return opcio; 
}

int main(){
    cout << "Inscripcio de jugadors " << endl;    
    Jugador A, B;
    introduccio(A.obtenir_nom(), B.obtenir_nom());
    bool guanyat = false, sortir = false;
    while(!guanyat && !sortir){
        char punt = qui_ha_guanyat();
        switch (punt)
        {
        case 'A':
            A.augmentar_punts(B);
            Jugador::mostrar_jugadors(A,B);
            guanyat = A.obtenir_guanyat();      
            break;
        
        case 'B':
            B.augmentar_punts(A);
            Jugador::mostrar_jugadors(A,B);      
            guanyat = B.obtenir_guanyat();      
            break;

        case 'S':
            sortir = true;
            break;

        default:
            introduccio(A.obtenir_nom(),B.obtenir_nom());
            break;
        }
    }
    
    if(guanyat){
        if(A.obtenir_guanyat()) cout << A.obtenir_nom();
        else cout << B.obtenir_nom();
        cout << " ha guanyat el partit" << endl;
    }
    else{cout << "El partit no te guanyador" << endl;}
    return 0;
}