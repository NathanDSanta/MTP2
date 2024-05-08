#include <iostream>
#include <cmath>
using namespace std;

void fractal_vicsek(int nivell, int mida, char caracter){
    if(nivell == 1){
        for(int j = 0; j < mida/3; j++){
            for(int i = 0; i < mida/3; i++) cout << " ";
            for(int i = 0; i < mida/3; i++) cout << caracter;
            for(int i = 0; i < mida/3; i++) cout << " ";
            cout << endl;
        }
        for(int i = 0; i < mida/3; i++) {
            for(int j = 0; j < mida; j++)cout << caracter;
            cout << endl;
        }
        for(int j = 0; j < mida/3; j++){
            for(int i = 0; i < mida/3; i++) cout << " ";
            for(int i = 0; i < mida/3; i++) cout << caracter;
            for(int i = 0; i < mida/3; i++) cout << " ";
            cout << endl;
        }    
    }
    else{
        for(int j = 0; j < mida/3; j++){
            for(int i = 0; i < mida/3; i++) cout << " ";
            for(int i = 0; i < mida/3; i++) fractal_vicsek(nivell - 1, mida/3, caracter);
            for(int i = 0; i < mida/3; i++) cout << " ";
            cout << endl;
        }
        for(int i = 0; i < mida/3; i++){
        for(int j = 0; j < mida; j++)fractal_vicsek(nivell - 1, mida/3, caracter);
        cout << endl;
        }
        for(int j = 0; j < mida/3; j++){
            for(int i = 0; i < mida/3; i++) cout << " ";
            for(int i = 0; i < mida/3; i++) fractal_vicsek(nivell - 1, mida/3, caracter);
            for(int i = 0; i < mida/3; i++) cout << " ";
            cout << endl;
        }    
    }
}

int main(){
    int nivell, mida;
    char caracter;
    cout << "ENTRA EL NIVELL: " << endl;
    cin >> nivell;
    while(nivell <= 0){
        cout << "ENTRA EL NIVELL: " << endl;
        cin >> nivell;
    }
    cout << "ENTRA EL CARACTER: " << endl;
    cin >> caracter;
    cout << "ENTRA LA MIDA (0 o una potencia de 3): " << endl;
    cin >> mida;
    while(mida%3 != 0 && mida != 0){
        cout << "ENTRA LA MIDA (0 o una potencia de 3): " << endl;
        cin >> mida;
    }
    if(mida == 0) mida = pow(3, nivell);
    fractal_vicsek(nivell, mida, caracter);  
    return 0;
}