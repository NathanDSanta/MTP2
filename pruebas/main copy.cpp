#include <iostream>
using namespace std;

int demanar_valors(){
    cout << "QUANTS VALORS TENS (>0): " << endl;
    int n;
    cin >> n;
    return n;
}

void entrar_valors(int *t, int n){
    cout << "ENTRA ELS VALORS: " << endl;
    for(int* i = t; i < t + n; i++){
        cin >> *i;
    }
}

void intercanviar(int **a, int **b){
    int *c = *a;
    *a = *b;
    *b = c;
}

void ordenar(int *t, int n){
    int *fi = t+n;
    for(int *i = t; i < fi; i++){
        int *menor = i;
        for(int *j = i + 1; j < fi; j++){
            if(*j < *menor) menor = j;
        }
        intercanviar(&i, &menor);
    }
}

void mostrar(int *t, int n){
    cout << "ELS VALORS ORDENATS: " << endl;
    int *fi = t+n;
    cout << *t;
    for(int* i = t + 1; i < fi; i++){
        cout << ", " << *i ;
    }
    cout << "." << endl;
}

int main(){
    int n = demanar_valors();
    while(!(n > 0)) n = demanar_valors();
    int t[n];

    entrar_valors(t,n);
    ordenar(t,n);
    mostrar(t,n);
    return 0;
}