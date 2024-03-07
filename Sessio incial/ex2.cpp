#include <iostream>
using namespace std;

const int EOS = -1;

bool es_triangular(int x){
    int suma = 0, i = 1;
    bool trobat = false;
    while(suma < x && !trobat){
        suma += i;
        i++;
        trobat = suma == x;
    }
    return trobat;
}

int main(){
    cout << "ENTRA NOMBRES (-1 PER ACABAR): " << endl;
    int valor, i = 0;
    cin >> valor;
    bool valor_es_triangular = es_triangular(valor);
    while(valor != EOS && !valor_es_triangular){
        i++;
        cin >> valor;
        valor_es_triangular = es_triangular(valor);
    }
    if(!valor_es_triangular) cout << "NO ";
    cout << "HI HA ";
    if(valor_es_triangular) cout << "UN ";
    else cout << "CAP ";
    cout << "NOMBRE TRIANGULAR";
    if(valor_es_triangular) cout << " A LA POSICIO " << i + 1;
    cout << endl;

    return 0;
}

int return2(){
    return 2;
}