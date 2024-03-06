#include "Vec_paraules.h"

int main(){
    cout << "ENTRA EL NOM DEL FITXER: " << endl;
    string fitxer;
    cin >> fitxer;
    ifstream fin(fitxer.c_str());
    if(!fin.is_open()) cout << "NO S'HA TROBAT EL FITXER" << endl;
    cout << "ENTRA EL NOMBRE MINIM D'APARICIONS: " << endl;
    int min_aparicions;
    cin >> min_aparicions;
    Vec_paraules recompte_paraules;
    Paraula p = Paraula(fin);
    while(!fin.eof() && fin.is_open()){
        recompte_paraules.inserir_paraula(p);
        p = Paraula(fin);
    }
    recompte_paraules.mostrar_minim_aparcions(min_aparicions);
    return 0;
}