#include <iostream>
#include "Punt2D.h"
using namespace std;

int main(){
    cout << "Entra les coordenades x i y del punt inicial: ";
    double x,y;
    cin >> x >> y;
    Punt2D punt_inicial(x,y);
    Punt2D punt_anterior(punt_inicial);
    Punt2D punt_seguent = punt_anterior;
    double distancia = 0;
    cout << "Vols entrar un nou punt?: ";
    char car;
    cin >> car;
    while(car == 's'){
        cout << "Entra el vector (x,y): ";
        cin >> x >> y;
        punt_seguent.moure(x,y);
        cout << "Punt seguent: ";
        punt_seguent.mostrar();
        distancia+=punt_anterior.distancia(punt_seguent);
        punt_anterior = punt_seguent;
        cout << "Vols entrar un nou punt?: ";
        cin >> car;
    }
    distancia += punt_seguent.distancia(punt_inicial);
    cout << "Punt final: ";
    punt_inicial.mostrar();
    cout << "Distància trajecte= " << distancia << endl;
    return 0;
}