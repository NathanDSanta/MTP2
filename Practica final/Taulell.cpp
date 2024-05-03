#include "Taulell.h"

//Constructors - Destructor
Taulell::Taulell(){
//Pre: --; Post: taulell buit
    a_mat = NULL;
    a_longitud = NULL;
    a_nc = 0;
}

Taulell::Taulell(const Taulell &t){
//Pre: --; Post: taulell còpia de t
    copia(t);
}

Taulell::~Taulell(){
//Pre: --; Post: memòria alliberada
    allibera();
}

//Mètodes modificadors
Baralla& Taulell::repartir(Baralla& b){
//Pre: --; Post: cartes de b repartides al taulell i les restants retornades.
    a_nc = 7;
    a_longitud = new int[a_nc];
    for(int i = 0; i < a_nc; i++) a_longitud[i] = i+1;
    reserva();
    for(int i = 0; i < a_nc; i++){
        for(int j = 0; j < a_longitud[i]; j++){
            a_mat[i][j] = b--;
            if(j + 1 == a_longitud[i]) a_mat[i][j].girar();
        }
    }
    return b;
}

//Mètodes privats
void Taulell::allibera(){
//Pre: --; Post: memòria alliberada
    for(int i = 0; i < a_nc; i++){
        delete [] a_mat[i];
    }
    delete [] a_mat;
    delete [] a_longitud;
}

void Taulell::copia(const Taulell& t){
//Pre: --; Post: taulell és còpia de t
    a_nc = t.a_nc;
    a_longitud = new int[a_nc];
    a_mat = new Carta*[a_nc];
    for(int i = 0; i < t.a_nc; i++){
        a_longitud[i] = t.a_longitud[i];
        a_mat[i] = new Carta[a_longitud[i]];
        for(int j = 0; j < t.a_longitud[i]; j++){
            a_mat[i][j] = t.a_mat[i][j];
        }
    }
}

void Taulell::reserva(){
//Pre: --; Post: memòria reservada
    a_mat = new Carta* [a_nc];
    for(int i = 0; i < a_nc; i++){
        a_mat[i] = new Carta[a_longitud[i]];
    }
}

void Taulell::expandeix_contrau_fila(int fila, bool contrau){
//Pre: fila <= a_nc; Post: expandeix/contrau (contrau == false:true) la fila en 1.
    Carta* aux = a_mat[fila];
    if (contrau)a_longitud[fila]--;
    else a_longitud[fila]++;
    a_mat[fila] = new Carta[a_longitud[fila]];
    for(int i = 0; i < a_longitud[fila]; i++){
        a_mat[fila][i] = aux[i];
    }
    delete[] aux;
}

//Operadors
Taulell& Taulell::operator=(const Taulell& t){
//Pre: --; Post: taulell còpia de t
    if(this != &t){
        allibera();
        copia(t);
    }
    return *this;
}

ostream& operator<<(ostream& o, const Taulell& t){
    int max_long = t.a_longitud[0];
    for(int i = 1; i < t.a_nc; i++){
        if(t.a_longitud[i] > max_long) max_long = t.a_longitud[i];
    }
    for(int i = 1; i <= t.a_nc; i++) o << "c" << i << " ";
    cout << "    " << endl;
    for(int i = 0; i < max_long; i++){
        for(int j = 0; j < t.a_nc; j++){
            if(t.a_longitud[j] < i + 1) o << "   ";
            else o << t.a_mat[j][i];
        }
        cout << "f" << i+1 << endl;
    }
    return o;
}
