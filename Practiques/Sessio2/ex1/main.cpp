#include <iostream>
#include "Data.h"
using namespace std;

int main(){
    cout << "ENTRA LA DATA ACTUAL: " << endl;
    int data;
    cin >> data;
    Data actual(data);
    while(!actual.validar_data()){
        cin >> data;
        actual = Data{data};
    }
    cout << "ENTRA LA DATA DE NAIXEMENT: " << endl;
    cin >> data;
    Data naixement(data);
    while(!naixement.validar_data() || !naixement.es_menor(actual)){
        cin >> data;
        naixement = Data{data};
    }
    if(naixement.es_aniversari(actual)) cout << "AVUI ES L'ANIVERSARI! FA ";
    else cout << "TE ";
    cout << actual.calcular_edat(naixement) << " ANYS" << endl;
    return 0;
}