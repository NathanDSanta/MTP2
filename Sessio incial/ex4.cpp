#include <iostream>
using namespace std;

int capgirat(int nombre){
    int capgirat = 0;
    int nombre2 = nombre;
    while(nombre2 > 9){
        capgirat*=10;
        capgirat+=nombre2%10;
        nombre2/=10;
    }
    capgirat*=10;
    capgirat+=nombre2;
    return capgirat;
}

int mcd(int a, int b){
    int divisor = a;
    int divident = b;
    int residu = a%b;
    while(divisor != 0){
        residu = divident%divisor;
        divident = divisor;
        divisor = residu;
    }
    return divident;
}

int main(){
    cout << "INTRODUEIX UN NATURAL: ";
    int nombre;
    cin >> nombre;
    int n_capgirat = capgirat(nombre);
    bool coprimers = mcd(nombre, n_capgirat) == 1;
    cout << "EL " << nombre << " I EL " << n_capgirat;
    if(!coprimers) cout << " NO";
    cout << " SON COPRIMERS" << endl;
    return 0;
}