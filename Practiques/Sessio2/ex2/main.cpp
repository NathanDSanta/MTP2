#include <iostream>
#include <iomanip>
#include "Vector.h"
using namespace std;

const int MAX_OPERACIONS = 5;

char demanar_operacio(){cout << "ENTRAR OPERACIO (s, r, m, v, f):" << endl; char op; cin >> op; return op;}
double demanar_real(string missatge){cout << missatge << endl; double op; cin >> op; return op;}

int main(){
    //Assignar decimals
    cout << fixed << setprecision(2);

    bool sortir = false;
    int operacions = 0;
    int resultats_hemis_nord = 0;
    Vector v1;
    while(!sortir && operacions < MAX_OPERACIONS){
        char operacio = demanar_operacio();
        switch (operacio)
        {
        case 's':{
            Vector v2;
            v1 = v1.suma(v2);
            v1.mostrar();
            if(v1.esta_hemisferi_nord()) resultats_hemis_nord++;
            break;
        }

        case 'r':{
            Vector v2;
            v1 = v1.resta(v2);
            v1.mostrar();
            if(v1.esta_hemisferi_nord()) resultats_hemis_nord++;
            break;
        }

        case 'm':{
            double r = demanar_real("ENTRAR UN VALOR REAL:");
            v1 = v1.multiplicacio_real(r);
            v1.mostrar();
            if(v1.esta_hemisferi_nord()) resultats_hemis_nord++;
            break;
        }

        case 'v':{
            Vector v2;
            v1 = v1.producte_vectorial(v2);
            v1.mostrar();
            if(v1.esta_hemisferi_nord()) resultats_hemis_nord++;
            break;
        }

        case 'f':
            sortir = true;
            break;
        }
        if(operacio != 'f') operacions++;
    }
    cout << "NOMBRE D'OPERACIONS: " << operacions << endl << "RESULTATS A L'HEMISFERI NORD: " << resultats_hemis_nord << endl;
    return 0;
}