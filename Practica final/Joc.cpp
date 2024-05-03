#include "Joc.h"

Joc::Joc(){
//Pre: --; Post: demana llavor i prepara el joc.
    cout << "ENTRA LA LLAVOR: " << endl;
    unsigned llavor;
    cin >> llavor;
    if(llavor < 0) llavor *= -1;
    if(llavor == 0) llavor = 1;
    Baralla cartes(llavor);
    a_ma = a_taulell.repartir(cartes);
}

//Misc
ostream& operator<<(ostream& o, const Joc& j){
    o << "ESTAT DEL JOC" << endl;
    for(int i = 0; i < 4; i++){
        o << j.a_piles[i];
    }
    o << "   " << j.a_ma << j.a_descartades << endl;
    o << j.a_taulell;
    o << "JOC EN CURS" << endl;
    return o;
}