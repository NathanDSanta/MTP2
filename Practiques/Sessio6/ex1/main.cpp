#include <iostream>
using namespace std;

int demanar_cadenes(){
    cout << "QUANTES CADENES TENS (>0): " << endl;
    int n;
    cin >> n;
    return n;
}

void entrar_cadenes(string *t, int n){
//Pre: n > 0 i la "taula" t té espai per n cadenes
//Post: s'han llegit n cadenes de teclat i s'han posat a la "taula" t
    for(string *i = t; i < t + n; i++){
        cin >> *i;
    }
}

void mostrar_cadenes_invers(string *t, int n){
//Pre: n > 0 i mida(t) = n
//Post: s'han mostrar les n cadenes de la "taula" t,  d'n-1 a 0
    cout << t + n - 1;
    for(string *i = t + n - 2; i >= t; i--){
        cout << ", " << *i;
    }
    cout << endl;
}

int main(){
    int n = demanar_cadenes();
    while(!(n > 0)){
        n = demanar_cadenes();
    }
    string t[n];

    cout << "ENTRA LES CADENES: " << endl;
    entrar_cadenes(t, n);
    cout << "ORDRE INVERS: " << endl;
    mostrar_cadenes_invers(t,n);
}