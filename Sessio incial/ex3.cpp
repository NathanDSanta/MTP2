#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;

typedef int vec_int[MAX];

int main(){
    cout << fixed << setprecision(1);
    vec_int puntuacions;
    cout << "QUANTES DADES TENS: " << endl;
    int n;
    cin >> n;
    cout << "ENTRA LES PUNTUACIONS: " << endl;
    for(int i = 0; i < n; i++){
        cin >> puntuacions[i];
    }    
    cout << "LLINDAR: " << endl;
    int llindar, n_memorables = 0;
    cin >> llindar;
    cout << "PARTITS MEMORABLES: " << endl;
    for(int i = 0; i < n; i++){
        if(puntuacions[i] >= llindar){ 
            cout << "PARTIT " << i+1 << ": " << puntuacions[i] << endl;
            n_memorables++;
        }
    }
    cout << "EL " << 100.0*n_memorables/n << "% DELS PARTITS HAN SIGUT MEMORABLES" << endl;
    return 0;
}