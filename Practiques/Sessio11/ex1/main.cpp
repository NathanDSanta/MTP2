#include <iostream>
using namespace std;

bool es_vocal(char a){
    return a == 'a' || a == 'e' || a == 'i' ||a == 'o' || a == 'u'; 
}

int i_comptar_parelles_vocals(char vec[], int n, int i){
    int num = 0;
    if(i == 1){
        if(es_vocal(vec[i]) && es_vocal(vec[i-1])) num = 1;
    } else{
        if(es_vocal(vec[i]) && es_vocal(vec[i-1])) num = 1 + i_comptar_parelles_vocals(vec, n, i-1);
        else num = i_comptar_parelles_vocals(vec, n, i - 1);
    }
    return num;
}

int comptar_parelles_vocals(char vec[], int n){
    int i = n - 1;
    return i_comptar_parelles_vocals(vec, n, i);
}

void llegir_vector(char vec[], int n){
    cout << "ENTRA ELS CARACTERS: " << endl;
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
}

int main(){
    cout << "ENTRA EL NOMBRE DE CARACTERS: " << endl;
    int n;
    cin >> n;
    char caracters[n];
    llegir_vector(caracters, n);
    int parelles = comptar_parelles_vocals(caracters, n);
    cout << "NOMBRE DE PARELLES DE VOCALS: " << parelles << endl;
    return 0;
}