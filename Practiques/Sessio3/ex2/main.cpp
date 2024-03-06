#include <iostream>
#include "Punt2D.h"
#include "Cercle.h"
using namespace std;

int main(){
    int n=1, n_interiors = 0, n_secants = 0;
    bool exterior = false;
    Cercle a;
    while(!exterior){
        Cercle b;
        a.posicio_relativa_a(b, n_interiors,n_secants, exterior);
        n++;
        a=b;
    }
    cout << "Nombre total de circumferencies: " << n << endl
         << "Parelles de circumferencies interiors: " << n_interiors << endl
         << "Parelles de circumferencies secants: " << n_secants << endl;

    return 0;
}